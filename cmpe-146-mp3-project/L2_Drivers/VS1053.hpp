#ifndef __VS1053_HPP
#define __VS1053_HPP

#include <stdint.h>

#include "FreeRTOS.h"

#include "event_groups.h"
#include "semphr.h"

#include "ff.h"
#include "pin_t.hpp"

#include "LabGPIO.hpp"
#include "SPIController.hpp"

class VS1053
{
public:
    static const uint32_t MAX_TRANSCEIVE_SIZE = 32; /* From datasheet */

    VS1053();
    ~VS1053();

    typedef enum {PLAY, FF, REW} PLAY_TYPE;

    /**
     * Initializes the VS1053 decoder
     *
     * @param spi_channel  The SPI device the decoder is connected to
     * @param reset        Port and pin numbers of the reset pin (XRESET)
     * @param data_cs      Port and pin numbers of the data chip select (XDCS)
     * @param control_cs   Port and pin numbers of the control chip select (XCS)
     * @param dreq         Port and pin numbers of the data request pin (DREQ)
     *
     * @return Retuns true on success, false otherwise
     */
    bool init(SPIController::ssp_t ssp, pin_t& reset, pin_t& data_cs, pin_t& control_cs, pin_t& dreq);

    /**
     * Loads a file and begins playing it
     *
     * @param path  Path to the file
     *
     * @return Returns true on success, false otherwise
     */
    bool play(const char* path);

    /**
     * Pauses the current file
     */
    void pause(void);

    /**
     * Resumes playback of a paused file
     */
    void resume(void);

    /**
     * Stops the current file
     */
    void stop(void);

    /**
     * Selects between normal playback, fast-forward, and rewind
     *
     * @param t  Playback type
     */
    void setPlayType(PLAY_TYPE t);

    /**
     * Sets the playback volume
     *
     * @param vol  Offset from full volume in -0.5dB increments; 0x00 is full volume,
     *             0xfe is silence, and 0xff powers off the amplifier
     */
    void setVolume(uint8_t vol);

    /**
     * Get the position in and length of the current file in seconds
     *
     * @param position_secs  Pointer to buffer for current playback position
     * @param length_secs    Pointer to buffer for total length of current file
     *
     * @return Returns true on success, false otherwise
     */
    bool getTime(uint32_t* position_secs, uint32_t* length_secs);

private:
    static const uint32_t SPI_START_FREQ_HZ = 1200000;
    static const uint32_t SPI_FREQ_HZ = 7899000;
    static const uint32_t STACK_SIZE = 1024;
    static const uint32_t BUFFER_SIZE = 1024;
    static const uint32_t SEEK_SPEED = 4; /* Speed multiplier for FF / Rew */
    static const uint32_t SEEK_TICK_PERIOD_MS = 20;

    /* From datasheet */
    typedef enum
    {
        MODE        = 0x00,
        STATUS      = 0x01,
        BASS        = 0x02,
        CLOCKF      = 0x03,
        DECODE_TIME = 0x04,
        AUDATA      = 0x05,
        WRAM        = 0x06,
        WRAMADDR    = 0x07,
        HDAT0       = 0x08,
        HDAT1       = 0x09,
        AIADDR      = 0x0a,
        VOL         = 0x0b,
        AICTRL0     = 0x0c,
        AICTRL1     = 0x0d,
        AICTRL2     = 0x0e,
        AICTRL3     = 0x0f
    } control_reg_t;

    typedef enum
    {
        HW_RESET,
        SW_RESET,
        INIT,
        IDLE,
        PLAYING,
        PAUSED
    } state_t;

    state_t state = INIT;

    SPIController::ssp_t mSSP = SPIController::SSP0;

    /* Pins */
    LabGPIO resetPin;
    LabGPIO dataReq;
    LabGPIO dataCs;
    LabGPIO controlCs;

    PLAY_TYPE currentPlayType = PLAY; /* Play, FF, or rewind */
    PLAY_TYPE requestedPlayType = PLAY;

    TaskHandle_t workerTask = NULL;
    TaskHandle_t updateTask = NULL;

    SemaphoreHandle_t stateMutex = NULL;
    SemaphoreHandle_t currentPlayTypeMutex = NULL;
    SemaphoreHandle_t byteRateMutex = NULL;

    FIL currentFile;
    uint8_t fileBuffer[BUFFER_SIZE];
    uint32_t bufferLen = 0;
    uint32_t bufferIndex = 0;

    uint16_t byteRate = 0;

    EventGroupHandle_t eventFlags = NULL;

    static void handleDataReqIsr(void* p);

    static void workerTaskFunc(void* p);
    static void updateTaskFunc(void* p);

    static void setState(VS1053* dec, state_t s);

    static uint16_t controlRegRead(VS1053* dec, control_reg_t reg, bool acquireBus);
    static void controlRegWrite(VS1053* dec, control_reg_t reg, uint16_t val, bool acquireBus);
    static void controlRegSet(VS1053* dec, control_reg_t reg, uint16_t bits);
    static void controlRegClear(VS1053* dec, control_reg_t reg, uint16_t bits);

    static void setVolumeInternal(VS1053* dec, uint8_t vol);

    static void waitForDReq(VS1053* dec);

    static bool sendNextDataPacket(VS1053* dec);
    static void dataWrite(VS1053* dec, uint8_t* buf, uint32_t len);

    static uint8_t getEndFillByte(VS1053* dec);
    static uint16_t getByteRate(VS1053* dec);

    static void sendEndFillByte(VS1053* dec, uint32_t count);
};

#endif
