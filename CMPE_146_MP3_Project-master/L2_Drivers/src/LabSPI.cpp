#include <stdint.h>

#include "LabSPI.hpp"
#include "semphr.h"

#define SSP_IS_BUSY(p) ((SSP[p]->SR & (1 << 4)) != 0)

LabSPI spi;

volatile LPC_SSP_TypeDef* LabSPI::SSP[] = {LPC_SSP0, LPC_SSP1};
SemaphoreHandle_t LabSPI::bus_lock;

LabSPI::LabSPI()
{
    bus_lock = xSemaphoreCreateMutex();
    xSemaphoreGive(bus_lock);
    mPeripheral = 0;
}

LabSPI::~LabSPI()
{

}

bool LabSPI::init(Peripheral peripheral, uint8_t data_size_select, FrameModes format, uint8_t divide)
{
    /* Validate parameters */

    if((divide & 1) || (divide < 2) || (divide > 254))
    {
        return false;
    }

    if((data_size_select < 4) || (data_size_select > 16))
    {
        return false;
    }

    /* Configure CR0 */

    uint32_t control_reg_0 = 0;

    switch(format)
    {
        case IDLE_LOW_CAPTURE_RISING:
            /* CPOL, CPHA = 0, 0 */
            break;

        case IDLE_LOW_CAPTURE_FALLING:
            /* CPOL, CPHA = 0, 1 */
            control_reg_0 |= (1 << 7);
            break;

        case IDLE_HIGH_CAPTURE_FALLING:
            /* CPOL, CPHA = 1, 0 */
            control_reg_0 |= (1 << 6);
            break;

        case IDLE_HIGH_CAPTURE_RISING:
            /* CPOL, CPHA = 1, 1 */
            control_reg_0 |= (3 << 6);
            break;

        default:
            return false;
    }

    data_size_select--;
    control_reg_0 |= (data_size_select << 0);

    /* Power on SSPn, set clock  to system clock, and select
     * SSP functions for CLK, MISO, and MOSI pins */

    switch(peripheral)
    {
        case SSP0:
            mPeripheral = 0;

            LPC_SC->PCONP |= (1 << 21);

            LPC_SC->PCLKSEL1 &= ~(3 << 10);
            LPC_SC->PCLKSEL1 |=  (1 << 10);

            /* Select function 2 for P0.15 */
            LPC_PINCON->PINSEL0 &= ~(3 << 30);
            LPC_PINCON->PINSEL0 |=  (2 << 30);

            /* Select function 2 for P0.17 and P0.18 */
            LPC_PINCON->PINSEL1 &= ~((3 << 2) | (3 << 4));
            LPC_PINCON->PINSEL1 |=  ((2 << 2) | (2 << 4));
            break;

        case SSP1:
            mPeripheral = 1;

            LPC_SC->PCONP |= (1 << 10);

            LPC_SC->PCLKSEL0 &= ~(3 << 20);
            LPC_SC->PCLKSEL0 |=  (1 << 20);

            /* Select function 2 for P0.7, P0.8, and P0.9 */
            LPC_PINCON->PINSEL0 &= ~((3 << 14) | (3 << 16) | (3 << 18));
            LPC_PINCON->PINSEL0 |=  ((2 << 14) | (2 << 16) | (2 << 18));
            break;

        default:
            return false;
    }

    /* Set config registers */

    SSP[mPeripheral]->CR0 = control_reg_0;
    SSP[mPeripheral]->CPSR = divide;
    SSP[mPeripheral]->CR1 = 0x2;

    return true;
}

uint8_t LabSPI::transfer(uint8_t send)
{
    while(SSP_IS_BUSY(mPeripheral))
    {
        ;
    }

    SSP[mPeripheral]->DR = (uint32_t)send;

    while(SSP_IS_BUSY(mPeripheral))
    {
        ;
    }

    uint8_t recv = (uint8_t)(SSP[mPeripheral]->DR);

    return recv;
}
