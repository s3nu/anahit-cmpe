#include <stddef.h>
#include <stdint.h>

#include "core_cm3.h"
#include "LabGPIOInterrupts.hpp"
#include "lpc_isr.h"

#include "uart0_min.h"

isr_ptr_t LabGPIOInterrupts::m_isr_table[2][2][31];
void* LabGPIOInterrupts::m_isr_param_table[2][2][31];

LabGPIOInterrupts& LabGPIOInterrupts::getInstance()
{
    static LabGPIOInterrupts instance;
    return instance;
}

void LabGPIOInterrupts::init() {}

bool LabGPIOInterrupts::attachInterruptHandler(uint8_t port, uint32_t pin, isr_ptr_t pin_isr, void* isr_param, InterruptCondition_E condition)
{
    /* Check for valid port and pin numbers */
    switch(port)
    {
        case 0:
            if(pin > 30 || (pin <= 14 && pin >= 12))
            {
                return false;
            }
            break;

        case 2:
            if(pin > 13)
            {
                return false;
            }
            break;

        default:
            return false;
    }

    /* Port 2 is index 1 in the table */
    port >>= 1;

    /* Install ISR */
    switch(condition)
    {
        case RISING:
            /* Add ISR to table */
            m_isr_table[port][0][pin] = pin_isr;
            m_isr_param_table[port][0][pin] = isr_param;

            /* Enable the rising-edge interrupt for this pin */
            if(port == 0)
            {
                LPC_GPIOINT->IO0IntEnR |= (1 << pin);
            }
            else
            {
                LPC_GPIOINT->IO2IntEnR |= (1 << pin);
            }
            break;

        case FALLING:
            m_isr_table[port][1][pin] = pin_isr;
            m_isr_param_table[port][1][pin] = isr_param;

            if(port == 0)
            {
                LPC_GPIOINT->IO0IntEnF |= (1 << pin);
            }
            else
            {
                LPC_GPIOINT->IO2IntEnF |= (1 << pin);
            }
            break;

        case BOTH:
            m_isr_table[port][0][pin] = pin_isr;
            m_isr_table[port][1][pin] = pin_isr;
            m_isr_param_table[port][0][pin] = isr_param;
            m_isr_param_table[port][1][pin] = isr_param;

            if(port == 0)
            {
                LPC_GPIOINT->IO0IntEnR |= (1 << pin);
                LPC_GPIOINT->IO0IntEnF |= (1 << pin);
            }
            else
            {
                LPC_GPIOINT->IO2IntEnR |= (1 << pin);
                LPC_GPIOINT->IO2IntEnF |= (1 << pin);
            }
            break;

        default:
            return false;
    }

    isr_register(EINT3_IRQn, externalIRQHandler);
    NVIC_EnableIRQ(EINT3_IRQn);

    return true;
}

void LabGPIOInterrupts::externalIRQHandler(void)
{
    uint32_t i;

    /* Loop over the bits of the GPIO interrupt status registers, clearing
     * any that are set and invoking their service routines */
    for(i = 0; (i < 31) && (LPC_GPIOINT->IntStatus != 0); i++)
    {
        uint32_t mask = 1 << i;

        if((LPC_GPIOINT->IO0IntStatR & mask) != 0)
        {
            LPC_GPIOINT->IO0IntClr |= mask;    /* Clear the interrupt */
            if(m_isr_table[0][0][i] != NULL)
            {
                m_isr_table[0][0][i](m_isr_param_table[0][0][i]);   /* Call the service routine */
            }
        }
        else if((LPC_GPIOINT->IO0IntStatF & mask) != 0)
        {
            LPC_GPIOINT->IO0IntClr |= mask;
            if(m_isr_table[0][1][i] != NULL) {
                m_isr_table[0][1][i](m_isr_param_table[0][1][i]);
            }
        }

        if((LPC_GPIOINT->IO2IntStatR & mask) != 0)
        {
            LPC_GPIOINT->IO2IntClr |= mask;
            if(m_isr_table[1][0][i] != NULL) {
                m_isr_table[1][0][i](m_isr_param_table[1][0][i]);
            }
        }
        else if((LPC_GPIOINT->IO2IntStatF & mask) != 0)
        {
            LPC_GPIOINT->IO2IntClr |= mask;
            if(m_isr_table[1][1][i] != NULL) {
                m_isr_table[1][1][i](m_isr_param_table[1][1][i]);
            }
        }
    }
}

LabGPIOInterrupts::~LabGPIOInterrupts()
{
}
