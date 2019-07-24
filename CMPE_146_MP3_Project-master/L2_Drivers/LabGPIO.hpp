#ifndef LABGPIO_H
#define LABGPIO_H

#include "LPC17xx.h"

class LabGPIO
{
private:
    volatile LPC_GPIO_TypeDef* m_port;
    uint8_t m_pin;

public:
    LabGPIO();

    bool init(uint8_t port, uint8_t pin);
    void setAsInput();
    void setAsOutput();
    void setDirection(bool output);
    void setHigh();
    void setLow();
    void set(bool high);
    bool getLevel();
    ~LabGPIO();
};

#endif
