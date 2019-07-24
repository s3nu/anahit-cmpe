#include <stddef.h>
#include <string.h>

#include "FreeRTOS.h"

#include "semphr.h"
#include "sys_config.h"
#include "task.h"

#include "LabGPIO.hpp"
#include "LabGPIOInterrupts.hpp"
#include "VS1053.hpp"

#define EVENT_NEW_FILE_SELECTED  (1 << 0)
#define EVENT_DREQ_HIGH          (1 << 1)
#define EVENT_STOP               (1 << 2)
#define EVENT_PAUSE              (1 << 4)
#define EVENT_RESUME             (1 << 5)

#define SM_CANCEL                (1 << 3)
#define SS_DO_NOT_JUMP           (1 << 15)

VS1053::VS1053() {}
VS1053::~VS1053() {}

bool VS1053::init(SPIController::ssp_t ssp, pin_t& reset, pin_t& data_cs, pin_t& control_cs, pin_t& dreq)
{
    mSSP = ssp;

    /* Init SPI to slow startup speed */
    if(!SPIController::getInstance().init(mSSP, SPIController::IDLE_LOW_CAPTURE_RISING, SPI_START_FREQ_HZ))
    {
        return false;
    }

    /* Configure GPIO pins */

    if(!resetPin.init(reset.port, reset.pin))
    {
        return false;
    }

    resetPin.setAsOutput();
    resetPin.setLow();

    if(!dataReq.init(dreq.port, dreq.pin))
    {
        return false;
    }

    dataReq.setAsInput();

    if(!dataCs.init(data_cs.port, data_cs.pin))
    {
        return false;
    }

    dataCs.setAsOutput();
    dataCs.setHigh();

    if(!controlCs.init(control_cs.port, control_cs.pin))
    {
        return false;
    }

    controlCs.setAsOutput();
    controlCs.setHigh();

    /* Create mutexes */
    stateMutex = xSemaphoreCreateMutex();
    currentPlayTypeMutex = xSemaphoreCreateMutex();
    byteRateMutex = xSemaphoreCreateMutex();

    if((stateMutex == NULL) || (byteRateMutex == NULL) || (currentPlayTypeMutex == NULL))
    {
        return false;
    }

    /* Create event flags */
    eventFlags = xEventGroupCreate();

    if(eventFlags == NULL)
    {
        return false;
    }

    /* Create tasks */
    if(xTaskCreate(workerTaskFunc, "VS1053w", STACK_SIZE, this, 1, &workerTask) != pdPASS)
    {
        return false;
    }

    if(xTaskCreate(updateTaskFunc, "VS1053u", 128, this, 3, &updateTask) != pdPASS)
    {
        return false;
    }

    LabGPIOInterrupts& gi = LabGPIOInterrupts::getInstance();
    gi.init();

    if(!gi.attachInterruptHandler(dreq.port, dreq.pin, handleDataReqIsr, this, BOTH))
    {
        return false;
    }

    state = HW_RESET;

    return true;
}

void VS1053::handleDataReqIsr(void* p)
{
    VS1053* dec = (VS1053*)p;
    BaseType_t higherPriorityTaskWoken = pdFALSE;

    if(dec->dataReq.getLevel())
    {
        if(xEventGroupSetBitsFromISR(dec->eventFlags, EVENT_DREQ_HIGH, &higherPriorityTaskWoken) == pdTRUE)
        {
            /* Yield if necessary */
            portYIELD_FROM_ISR(higherPriorityTaskWoken);
        }
    }
    else
    {
        xEventGroupClearBitsFromISR(dec->eventFlags, EVENT_DREQ_HIGH);
    }
}

void VS1053::updateTaskFunc(void* p)
{
    VS1053* dec = (VS1053*)p;

    while(1)
    {
        vTaskDelay(1000);

        xSemaphoreTake(dec->stateMutex, portMAX_DELAY);
        switch(dec->state)
        {
            case PLAYING:
                xSemaphoreGive(dec->stateMutex);

                xSemaphoreTake(dec->currentPlayTypeMutex, portMAX_DELAY);
                if(dec->currentPlayType == PLAY)
                {
                    xSemaphoreGive(dec->currentPlayTypeMutex);

                    /* Update the byte rate of the playing song */
                    xSemaphoreTake(dec->byteRateMutex, portMAX_DELAY);
                    dec->byteRate = getByteRate(dec);
                    xSemaphoreGive(dec->byteRateMutex);
                }
                else
                {
                    xSemaphoreGive(dec->currentPlayTypeMutex);
                }
                break;

            case HW_RESET:
            case SW_RESET:
            case INIT:
            case IDLE:
            case PAUSED:
            default:
                xSemaphoreGive(dec->stateMutex);
                break;
        }
    }
}

void VS1053::workerTaskFunc(void* p)
{
    VS1053* dec = (VS1053*)p;

    EventBits_t bits;
    uint32_t seek_ofs, i;
    uint8_t efb;

    while(1)
    {
        xSemaphoreTake(dec->stateMutex, portMAX_DELAY);
        switch(dec->state)
        {
            case HW_RESET:
                xSemaphoreGive(dec->stateMutex);

                dec->resetPin.setLow();
                vTaskDelay(5);
                dec->resetPin.setHigh();

                SPIController::getInstance().setSckFreq(dec->mSSP, SPI_START_FREQ_HZ);

                setState(dec, INIT);
                break;

            case SW_RESET:
                xSemaphoreGive(dec->stateMutex);

                controlRegSet(dec, MODE, (1 << 2)); /* Do a soft reset */
                waitForDReq(dec);

                SPIController::getInstance().setSckFreq(dec->mSSP, SPI_START_FREQ_HZ);

                setState(dec, INIT);
                break;

            case INIT:
                xSemaphoreGive(dec->stateMutex);

                controlRegWrite(dec, MODE, 0x0800, true); /* Set mode register */
                setVolumeInternal(dec, 0x18); /* Set initial volume to -12dB */

                controlRegWrite(dec, CLOCKF, 0xc000, true); /* Set clock control register */
                waitForDReq(dec); /* Wait for clock to settle */

                SPIController::getInstance().setSckFreq(dec->mSSP, SPI_FREQ_HZ);

                setState(dec, IDLE);
                break;

            case IDLE:
                xSemaphoreGive(dec->stateMutex);

                if(xEventGroupWaitBits(dec->eventFlags, EVENT_NEW_FILE_SELECTED, pdTRUE, pdTRUE, portMAX_DELAY))
                {
                    /* New file was selected, reset variables */

                    dec->bufferIndex  = 0;
                    dec->bufferLen = 0;

                    xEventGroupClearBits(dec->eventFlags, EVENT_PAUSE | EVENT_STOP | EVENT_RESUME);

                    setState(dec, PLAYING);
                }
                break;

            case PLAYING:
                xSemaphoreGive(dec->stateMutex);

                bits = xEventGroupGetBits(dec->eventFlags);

                /* Check for stop request */
                if(bits & EVENT_STOP)
                {
                    xEventGroupClearBits(dec->eventFlags, EVENT_STOP);
                    setState(dec, HW_RESET);
                }

                /* Check for pause */
                else if(bits & EVENT_PAUSE)
                {
                    xEventGroupClearBits(dec->eventFlags, EVENT_PAUSE);
                    setState(dec, PAUSED);
                }

                else
                {
                    xSemaphoreTake(dec->currentPlayTypeMutex, portMAX_DELAY);

                    /* Switch modes if necessary */
                    if(dec->currentPlayType != dec->requestedPlayType)
                    {
                        switch(dec->requestedPlayType)
                        {
                            case FF:
                            case REW:
                                xSemaphoreGive(dec->currentPlayTypeMutex);

                                /* Check if jumping in file is okay */
                                if(!(controlRegRead(dec, STATUS, true) & SS_DO_NOT_JUMP))
                                {
                                    xSemaphoreTake(dec->byteRateMutex, portMAX_DELAY);

                                    /* Check that byte rate has been updated */
                                    if(dec->byteRate != 0)
                                    {
                                        xSemaphoreTake(dec->currentPlayTypeMutex, portMAX_DELAY);
                                        dec->currentPlayType = dec->requestedPlayType;
                                        xSemaphoreGive(dec->currentPlayTypeMutex);

                                        /* Send 2048 of endFillByte */
                                        efb = getEndFillByte(dec);

                                        for(i = 0; i < 2048; i++)
                                        {
                                            dataWrite(dec, &efb, 1);
                                        }
                                    }

                                    xSemaphoreGive(dec->byteRateMutex);
                                }
                                break;

                            case PLAY:
                            default:
                                dec->currentPlayType = dec->requestedPlayType;
                                xSemaphoreGive(dec->currentPlayTypeMutex);
                                break;
                        }
                    }
                    else
                    {
                        xSemaphoreGive(dec->currentPlayTypeMutex);
                    }

                    switch(dec->currentPlayType)
                    {
                        case PLAY:
                            if(!sendNextDataPacket(dec))
                            {
                                setState(dec, HW_RESET);
                            }
                            break;

                        case FF:
                            /* Jump ahead a bit in the file at the fast-forward speed */
                            seek_ofs = f_tell(&(dec->currentFile));

                            xSemaphoreTake(dec->byteRateMutex, portMAX_DELAY);
                            seek_ofs += dec->byteRate * SEEK_SPEED * SEEK_TICK_PERIOD_MS / 1000;
                            xSemaphoreGive(dec->byteRateMutex);

                            f_lseek(&(dec->currentFile), seek_ofs);

                            vTaskDelay(SEEK_TICK_PERIOD_MS);
                            break;

                        case REW:
                            seek_ofs = f_tell(&(dec->currentFile));

                            xSemaphoreTake(dec->byteRateMutex, portMAX_DELAY);

                            /* Handle underflow on backwards seek, FatFS doesn't do it automatically */
                            if(seek_ofs > dec->byteRate * SEEK_SPEED * SEEK_TICK_PERIOD_MS / 1000)
                            {
                                seek_ofs -= dec->byteRate * SEEK_SPEED * SEEK_TICK_PERIOD_MS / 1000;
                            }
                            else
                            {
                                seek_ofs = 0;
                            }

                            xSemaphoreGive(dec->byteRateMutex);

                            f_lseek(&(dec->currentFile), seek_ofs);

                            vTaskDelay(SEEK_TICK_PERIOD_MS);
                            break;

                        default:
                            setState(dec, HW_RESET);
                            break;
                    }

                    /* Check for end-of-file */
                    if(f_eof(&(dec->currentFile)))
                    {
                        setState(dec, HW_RESET);
                    }
                }
                break;

            case PAUSED:
                xSemaphoreGive(dec->stateMutex);

                bits = xEventGroupWaitBits(dec->eventFlags, EVENT_STOP | EVENT_RESUME, pdTRUE, pdFALSE, portMAX_DELAY);

                if(bits & EVENT_STOP)
                {
                    setState(dec, HW_RESET);
                }
                else if(bits & EVENT_RESUME)
                {
                    setState(dec, PLAYING);
                }
                break;

            default:
                xSemaphoreGive(dec->stateMutex);

                setState(dec, HW_RESET);
                break;
        }
    }
}

void VS1053::setState(VS1053* dec, state_t s)
{
    xSemaphoreTake(dec->stateMutex, portMAX_DELAY);
    dec->state = s;
    xSemaphoreGive(dec->stateMutex);
}

bool VS1053::play(const char* path)
{
    if(path == NULL)
    {
        return false;
    }

    stop();
    setPlayType(PLAY); /* Disable FF / Rew, if enabled */

    /* Save the file */
    if(f_open(&currentFile, path, FA_READ) != FR_OK)
    {
        return false;
    }

    /* Notify the state machine that the new file is ready */
    xEventGroupSetBits(eventFlags, EVENT_NEW_FILE_SELECTED);

    return true;
}


void VS1053::stop()
{
    xSemaphoreTake(stateMutex, portMAX_DELAY);

    if((state == PLAYING) || (state == PAUSED))
    {
        xEventGroupSetBits(eventFlags, EVENT_STOP);
    }

    xSemaphoreGive(stateMutex);
}

void VS1053::setVolume(uint8_t vol)
{
    setVolumeInternal(this, vol);
}

void VS1053::setVolumeInternal(VS1053* dec, uint8_t vol)
{
    controlRegWrite(dec, VOL, ((uint16_t)(vol << 8)) | ((uint16_t)(vol)), true);
}


uint16_t VS1053::controlRegRead(VS1053* dec, control_reg_t reg, bool acquireBus)
{
    uint8_t cmd_buffer[4];

    cmd_buffer[0] = 0x03;
    cmd_buffer[1] = (uint8_t)reg;
    cmd_buffer[2] = 0x00;
    cmd_buffer[3] = 0x00;

    SPIController& spi = SPIController::getInstance();

    if(acquireBus)
    {
        spi.acquire(dec->mSSP);
    }

    waitForDReq(dec);

    dec->controlCs.setLow();
    spi.transceive(dec->mSSP, cmd_buffer, 4);
    dec->controlCs.setHigh();

    if(acquireBus)
    {
        spi.release(dec->mSSP);
    }

    return ((((uint16_t)cmd_buffer[2]) << 8) | ((uint16_t)cmd_buffer[3]));
}


void VS1053::controlRegWrite(VS1053* dec, control_reg_t reg, uint16_t val, bool acquireBus)
{
    uint8_t cmd_buffer[4];

    cmd_buffer[0] = 0x02;
    cmd_buffer[1] = (uint8_t)reg;
    cmd_buffer[2] = (uint8_t)(val >> 8);
    cmd_buffer[3] = (uint8_t)(val);

    SPIController& spi = SPIController::getInstance();

    if(acquireBus)
    {
        spi.acquire(dec->mSSP);
    }

    waitForDReq(dec);

    dec->controlCs.setLow();
    spi.transceive(dec->mSSP, cmd_buffer, 4);
    dec->controlCs.setHigh();

    if(acquireBus)
    {
        spi.release(dec->mSSP);
    }
}


void VS1053::controlRegSet(VS1053* dec, control_reg_t reg, uint16_t bits)
{
    uint16_t val;
    SPIController& spi = SPIController::getInstance();

    spi.acquire(dec->mSSP);

    val = controlRegRead(dec, reg, false);

    val |= bits;

    controlRegWrite(dec, reg, val, false);

    spi.release(dec->mSSP);
}


void VS1053::controlRegClear(VS1053* dec, control_reg_t reg, uint16_t bits)
{
    uint16_t val;
    SPIController& spi = SPIController::getInstance();

    spi.acquire(dec->mSSP);

    val = controlRegRead(dec, reg, false);

    val &= ~bits;

    controlRegWrite(dec, reg, val, false);

    spi.release(dec->mSSP);
}


void VS1053::waitForDReq(VS1053* dec) {
    if(!(dec->dataReq.getLevel()))
    {
        xEventGroupWaitBits(dec->eventFlags, EVENT_DREQ_HIGH, pdTRUE, pdTRUE, portMAX_DELAY);
    }
}

bool VS1053::sendNextDataPacket(VS1053* dec)
{
    if(dec->bufferIndex >= dec->bufferLen)
    {
        dec->bufferIndex = 0;

        /* Refill buffer */
        if(f_read(&(dec->currentFile), dec->fileBuffer, BUFFER_SIZE, (UINT*)(&(dec->bufferLen))) != FR_OK)
        {
            return false;
        }
        else if(dec->bufferLen == 0)
        {
            return true;
        }
    }

    uint8_t* buf = &(dec->fileBuffer[dec->bufferIndex]);
    uint32_t len = ((dec->bufferLen - dec->bufferIndex) > MAX_TRANSCEIVE_SIZE) ?
            MAX_TRANSCEIVE_SIZE : dec->bufferLen - dec->bufferIndex;

    dataWrite(dec, buf, len);

    /* Update indexes */
    dec->bufferIndex += len;

    return true;
}

void VS1053::dataWrite(VS1053* dec, uint8_t* buf, uint32_t len)
{
    SPIController& spi = SPIController::getInstance();

    spi.acquire(dec->mSSP);

    waitForDReq(dec);

    dec->dataCs.setLow();
    spi.transceive(dec->mSSP, buf, len);
    dec->dataCs.setHigh();

    spi.release(dec->mSSP);
}


uint8_t VS1053::getEndFillByte(VS1053* dec)
{
    SPIController& spi = SPIController::getInstance();

    spi.acquire(dec->mSSP);

    /* Write address of endFillByte to WRAMADDR */
    controlRegWrite(dec, WRAMADDR, 0x1e06, false);

    /* Read value at address */
    uint16_t val = controlRegRead(dec, WRAM, false);

    spi.release(dec->mSSP);

    return (uint8_t)val;
}


void VS1053::setPlayType(PLAY_TYPE t)
{
    xSemaphoreTake(currentPlayTypeMutex, portMAX_DELAY);
    requestedPlayType = t;
    xSemaphoreGive(currentPlayTypeMutex);
}


uint16_t VS1053::getByteRate(VS1053* dec)
{
    SPIController& spi = SPIController::getInstance();

    spi.acquire(dec->mSSP);

    /* Write address of byteRate to WRAMADDR */
    controlRegWrite(dec, WRAMADDR, 0x1e05, false);

    /* Read value at address */
    uint16_t val = controlRegRead(dec, WRAM, false);

    spi.release(dec->mSSP);

    return val;
}

void VS1053::pause(void)
{
    xSemaphoreTake(stateMutex, portMAX_DELAY);

    if(state == PLAYING)
    {
        xEventGroupSetBits(eventFlags, EVENT_PAUSE);
    }

    xSemaphoreGive(stateMutex);
}

void VS1053::resume(void)
{
    xSemaphoreTake(stateMutex, portMAX_DELAY);

    if(state == PAUSED)
    {
        xEventGroupSetBits(eventFlags, EVENT_RESUME);
    }

    xSemaphoreGive(stateMutex);
}


void VS1053::sendEndFillByte(VS1053* dec, uint32_t count)
{
    uint8_t endFillByte = getEndFillByte(dec);
    uint8_t efbBuffer[4];
    efbBuffer[0] = endFillByte;
    efbBuffer[1] = endFillByte;
    efbBuffer[2] = endFillByte;
    efbBuffer[3] = endFillByte;

    SPIController& spi = SPIController::getInstance();

    spi.acquire(dec->mSSP);

    /* Send 4 at a time until there's less than 4 remaining */
    for(; count >= 4; count -= 4)
    {
        waitForDReq(dec);

        dec->dataCs.setLow();
        spi.transceive(dec->mSSP, efbBuffer, 4);
        dec->dataCs.setHigh();
    }

    /* Send the remaining bytes */
    for(; count > 0; count--)
    {
        waitForDReq(dec);

        dec->dataCs.setLow();
        spi.transceive(dec->mSSP, &endFillByte, 1);
        dec->dataCs.setHigh();
    }

    spi.release(dec->mSSP);
}

bool VS1053::getTime(uint32_t* position_secs, uint32_t* length_secs)
{
    xSemaphoreTake(stateMutex, portMAX_DELAY);

    if((state != PLAYING) && (state != PAUSED))
    {
        xSemaphoreGive(stateMutex);
        return false;
    }

    xSemaphoreGive(stateMutex);

    xSemaphoreTake(byteRateMutex, portMAX_DELAY);

    if(byteRate == 0)
    {
        xSemaphoreGive(byteRateMutex);

        if(position_secs != NULL)
        {
            *position_secs = 0;
        }

        if(length_secs != NULL)
        {
            *length_secs = 0;
        }
    }
    else
    {
        if(position_secs != NULL)
        {
            *position_secs = f_tell(&currentFile) / byteRate;
        }

        if(length_secs != NULL)
        {
            *length_secs = f_size(&currentFile) / byteRate;
        }

        xSemaphoreGive(byteRateMutex);
    }

    return true;
}
