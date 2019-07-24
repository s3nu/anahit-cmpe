#ifndef LABGPIOINTERRUPTS_H
#define LABGPIOINTERRUPTS_H

#include <stdint.h>

typedef enum
{
    RISING,
    FALLING,
    BOTH
} InterruptCondition_E;

typedef void (*isr_ptr_t)(void*);

class LabGPIOInterrupts
{
private:
    LabGPIOInterrupts() {}
    LabGPIOInterrupts(LabGPIOInterrupts const&) {}
    void operator=(LabGPIOInterrupts const&) {}

    /**
     * The ISR table has three dimensions: isr_table[x][y][z]
     *  x: port number: 0 for P0, 1 for P2
     *  y: 0 for rising-edge routine, 1 for falling-edge
     *  z: pin number
     */
    static isr_ptr_t m_isr_table[2][2][31];
    static void*     m_isr_param_table[2][2][31];

public:
    static LabGPIOInterrupts& getInstance();

    void init();

    bool attachInterruptHandler(uint8_t port, uint32_t pin, isr_ptr_t pin_isr, void* isr_param, InterruptCondition_E condition);

    static void externalIRQHandler(void);
    ~LabGPIOInterrupts();
};

#endif
