#include <stddef.h>

#include "LabGPIO.hpp"
#include "LPC17xx.h"

LabGPIO::LabGPIO()
{
    m_port = NULL;
    m_pin = 0;
}

bool LabGPIO::init(uint8_t port, uint8_t pin)
{
    m_pin = pin;

    /* Find GPIO port pointer and configure pin as GPIO */
    switch(port)
    {
        case 0:
            m_port = LPC_GPIO0;

            if(pin < 16)
            {
                LPC_PINCON->PINSEL0 &= ~(3 << (pin << 1));
            }
            else
            {
                LPC_PINCON->PINSEL1 &= ~(3 << (pin << 1));
            }

            break;

        case 1:
            m_port = LPC_GPIO1;

            if(pin < 16)
            {
                LPC_PINCON->PINSEL2 &= ~(3 << (pin << 1));
            }
            else
            {
                LPC_PINCON->PINSEL3 &= ~(3 << (pin << 1));
            }

            break;

        case 2:
            m_port = LPC_GPIO2;

            if(pin < 16)
            {
                LPC_PINCON->PINSEL4 &= ~(3 << (pin << 1));
            }
            else
            {
                LPC_PINCON->PINSEL5 &= ~(3 << (pin << 1));
            }

            break;

        case 3:
            m_port = LPC_GPIO3;

            if(pin < 16)
            {
                LPC_PINCON->PINSEL6 &= ~(3 << (pin << 1));
            }
            else
            {
                LPC_PINCON->PINSEL7 &= ~(3 << (pin << 1));
            }

            break;

        case 4:
            m_port = LPC_GPIO4;

            if(pin < 16)
            {
                LPC_PINCON->PINSEL8 &= ~(3 << (pin << 1));
            }
            else
            {
                LPC_PINCON->PINSEL9 &= ~(3 << (pin << 1));
            }

            break;

        default:
            return false;
    }

    return true;
}

void LabGPIO::setAsInput()
{
    m_port->FIODIR &= ~(1 << m_pin);
}

void LabGPIO::setAsOutput()
{
    m_port->FIODIR |= 1 << m_pin;
}

void LabGPIO::setDirection(bool output)
{
    if(output)
    {
        setAsOutput();
    }
    else
    {
        setAsInput();
    }
}

void LabGPIO::setHigh()
{
    m_port->FIOSET |= 1 << m_pin;
}

void LabGPIO::setLow()
{
    m_port->FIOCLR |= 1 << m_pin;
}

void LabGPIO::set(bool high)
{
    if(high)
    {
        setHigh();
    }
    else
    {
        setLow();
    }
}

bool LabGPIO::getLevel()
{
    if((m_port->FIOPIN & (1 << m_pin)) == 0)
    {
        return false;
    }

    return true;
}

LabGPIO::~LabGPIO()
{
}
