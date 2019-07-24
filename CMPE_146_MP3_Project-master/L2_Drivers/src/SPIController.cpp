#include "core_cm3.h"
#include "lpc_isr.h"
#include "SPIController.hpp"
#include "sys_config.h"
#include "task.h"

SPIController::state_t SPIController::ssp0_state, SPIController::ssp1_state;

SPIController::SPIController(void)
{
    ssp0_state.ssp = LPC_SSP0;
    ssp1_state.ssp = LPC_SSP1;
}

SPIController& SPIController::getInstance(void)
{
    static SPIController instance;
    return instance;
}

bool SPIController::calcDividerSettings(uint32_t pclk_hz, uint32_t sck_freq_hz, uint8_t* cpsdvsr, uint8_t* scr)
{
    /* Validate parameters */

    if((pclk_hz == 0) || (sck_freq_hz == 0))
    {
        return false;
    }

    uint32_t ratio = pclk_hz / sck_freq_hz;

    if((ratio > (254 * 255)) || (ratio < (2 * 1)))
    {
        return false;
    }

    uint32_t min_err = 0xFFFFFFFF;
    uint32_t _cpsdvsr = 2, _scr_plus_1 = 1;

    /* Search for divider parameters which minimize error w.r.t. desired
     * frequency */
    for(uint32_t i = 2; i < 256; i += 2)
    {
        for(uint32_t j = 1; j <= 256; j++)
        {
            uint32_t sck_gen_hz = pclk_hz / (i * j);

            /* Treat input frequency sck_freq_hz as hard upper bound */
            if(sck_gen_hz <= sck_freq_hz)
            {
                uint32_t err = sck_freq_hz - sck_gen_hz;

                if(err < min_err)
                {
                   min_err = err;
                   _cpsdvsr = i;
                   _scr_plus_1 = j;
                }
                if(err == 0)
                {
                    /* If an exact match was found, return it immediately */
                    *cpsdvsr = (uint8_t)_cpsdvsr;
                    *scr = ((uint8_t)_scr_plus_1) - 1;
                    return true;
                }
            }
        }
    }

    /* Otherwise, return the closest match possible */
    *cpsdvsr = _cpsdvsr;
    *scr = _scr_plus_1 - 1;
    return true;
}

bool SPIController::setSckFreq(ssp_t ssp, uint32_t sck_freq_hz)
{
    state_t* state;

    switch(ssp)
    {
        case SSP0: state = &ssp0_state; break;
        case SSP1: state = &ssp1_state; break;
        default: return false;
    }

    if(state->task == NULL)
    {
        return false;
    }

    uint8_t cpsdvsr, scr;
    uint32_t pclk = sys_get_cpu_clock();

    if(!calcDividerSettings(pclk, sck_freq_hz, &cpsdvsr, &scr))
    {
        return false;
    }

    state->ssp->CR1 &= 0xD; /* Disable the SSP, if enabled, before adjusting settings */

    state->ssp->CR0 &= 0xFF;
    state->ssp->CR0 |= (scr << 8);
    state->ssp->CPSR = (uint32_t)cpsdvsr;

    state->ssp->CR1 |= 0x2; /* Enable the SSP */

    return true;
}

bool SPIController::init(ssp_t ssp, frame_format_t ff, uint32_t sck_freq_hz)
{
    /* Configure CR0 */

    uint32_t cr0 = 0x0007; /* 8-bit frame size */

    switch(ff)
    {
        case IDLE_LOW_CAPTURE_RISING: /*cr0 |= (0 << 6);*/break;
        case IDLE_LOW_CAPTURE_FALLING:  cr0 |= (2 << 6);  break;
        case IDLE_HIGH_CAPTURE_FALLING: cr0 |= (1 << 6);  break;
        case IDLE_HIGH_CAPTURE_RISING:  cr0 |= (3 << 6);  break;
        default: return false;
    }

    uint8_t cpsdvsr, scr;
    uint32_t pclk = sys_get_cpu_clock();

    if(!calcDividerSettings(pclk, sck_freq_hz, &cpsdvsr, &scr))
    {
        return false;
    }

    cr0 |= (scr << 8);

    state_t* state;

    /* Power and clock */
    switch(ssp)
    {
        case SSP0:
            state = &ssp0_state;

            LPC_SC->PCONP |= (1 << 21); /* Power */

            LPC_SC->PCLKSEL1 &= ~(3 << 10); /* PCLK = CCLK */
            LPC_SC->PCLKSEL1 |=  (1 << 10);
            break;

        case SSP1:
            state = &ssp1_state;

            LPC_SC->PCONP |= (1 << 10);

            LPC_SC->PCLKSEL0 &= ~(3 << 20);
            LPC_SC->PCLKSEL0 |=  (1 << 20);
            break;

        default: return false;
    }

    /* Create SSP mutex */
    if(state->bus_lock == NULL)
    {
        state->bus_lock = xSemaphoreCreateMutex();

        if(state->bus_lock == NULL)
        {
            switch(ssp)
            {
                case SSP0: LPC_SC->PCONP &= ~(1 << 21); return false;
                case SSP1: LPC_SC->PCONP &= ~(1 << 10); return false;
                default: return false;
            }
        }
    }

    state->ssp->CR1 &= 0xD; /* Disable the SSP, if enabled, before adjusting settings */

    state->ssp->IMSC = 0x0; /* Disable all interrupts */

    /* Register interrupt handler */
    switch(ssp)
    {
        case SSP0:
            isr_register(SSP0_IRQn, SSP0ISR);
            NVIC_EnableIRQ(SSP0_IRQn);
            break;

        case SSP1:
            isr_register(SSP1_IRQn, SSP1ISR);
            NVIC_EnableIRQ(SSP1_IRQn);
            break;

        default: return false;
    }

    state->ssp->CR0  = cr0;
    state->ssp->CPSR = (uint32_t)cpsdvsr;
    state->ssp->CR1  = 0x2; /* Enable the SSP */

    return true;
}

void SPIController::SSP0ISR(void)
{
    portYIELD_FROM_ISR(ISR(&ssp0_state));
}

void SPIController::SSP1ISR(void)
{
    portYIELD_FROM_ISR(ISR(&ssp1_state));
}

BaseType_t SPIController::ISR(state_t* state)
{
    BaseType_t woken = pdFALSE;

    vTaskNotifyGiveFromISR(state->task, &woken);
    state->ssp->ICR |= (1 << 1);

    return woken;
}

void SPIController::transceive(ssp_t ssp, uint8_t* buf, uint32_t len)
{
    if(buf != NULL)
    {
        state_t* s;

        switch(ssp)
        {
            case SSP0: s = &ssp0_state; break;
            case SSP1: s = &ssp1_state; break;
            default: return;
        }

        s->task = xTaskGetCurrentTaskHandle();

        if(xSemaphoreGetMutexHolder(s->bus_lock) == s->task)
        {
            uint32_t i, tx_i = 0, rx_i = 0;

            while((tx_i < len) && (rx_i < len))
            {
                /* Write to transmit FIFO */
                for(i = 0; (i < 8) && (tx_i < len); i++, tx_i++)
                {
                    s->ssp->DR = buf[tx_i];
                }

                enableInterrupts(s->ssp);

                while(rx_i < tx_i)
                {
                    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

                    while(s->ssp->SR & (1 << 2))
                    {
                        buf[rx_i] = s->ssp->DR;
                        rx_i++;
                    }
                }

                disableInterrupts(s->ssp);
            }
        }
    }
}

void SPIController::acquire(ssp_t ssp)
{
    switch(ssp)
    {
        case SSP0: xSemaphoreTake(ssp0_state.bus_lock, portMAX_DELAY); break;
        case SSP1: xSemaphoreTake(ssp1_state.bus_lock, portMAX_DELAY); break;
        default:   break;
    }
}

void SPIController::release(ssp_t ssp)
{
    switch(ssp)
    {
        case SSP0: xSemaphoreGive(ssp0_state.bus_lock); break;
        case SSP1: xSemaphoreGive(ssp1_state.bus_lock); break;
        default:   break;
    }
}

void SPIController::disableInterrupts(volatile LPC_SSP_TypeDef* ssp) {ssp->IMSC &= ~((1 << 1));}
void SPIController::enableInterrupts(volatile LPC_SSP_TypeDef* ssp)  {ssp->IMSC |=  ((1 << 1));}
