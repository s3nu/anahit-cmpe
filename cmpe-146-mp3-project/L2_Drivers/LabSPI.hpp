#ifndef LABSPI_H
#define LABSPI_H

#include "FreeRTOS.h"
#include "LPC17xx.h"
#include "semphr.h"

class LabSPI
{
private:
    // SSP register lookup table structure
    static volatile LPC_SSP_TypeDef* SSP[];
    uint8_t mPeripheral;

public:
    static SemaphoreHandle_t bus_lock;

    enum FrameModes
    {
        IDLE_LOW_CAPTURE_RISING,    /* CPOL, CPHA = 0, 0 */
        IDLE_LOW_CAPTURE_FALLING,   /* CPOL, CPHA = 0, 1 */
        IDLE_HIGH_CAPTURE_FALLING,  /* CPOL, CPHA = 1, 0 */
        IDLE_HIGH_CAPTURE_RISING    /* CPOL, CPHA = 1, 1 */
    };

    enum Peripheral
    {
        SSP0 = 0,
        SSP1 = 1
    };

    /**
     * 1) Powers on SPPn peripheral
     * 2) Set peripheral clock
     * 3) Sets pins for specified peripheral to MOSI, MISO, and SCK
     *
     * @param peripheral which peripheral SSP0 or SSP1 you want to select.
     * @param data_size_select transfer size data width; To optimize the code, look for a pattern in the datasheet
     * @param format is the code format for which synchronous serial protocol you want to use.
     * @param divide is the how much to divide the clock for SSP; take care of error cases such as the value of 0, 1, and odd numbers
     *
     * @return true if initialization was successful
     */
    bool init(Peripheral peripheral, uint8_t data_size_select, FrameModes format, uint8_t divide);

    /**
     * Transfers a byte via SSP to an external device using the SSP data register.
     * This region must be protected by a mutex static to this class.
     *
     * @return received byte from external device via SSP data register.
     */
    uint8_t transfer(uint8_t send);

    LabSPI();
    ~LabSPI();
};

extern LabSPI spi;

#endif
