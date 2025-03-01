#include <stdint.h>
#ifndef LABGPIOINTERRUPTS_H
#define LABGPIOINTERRUPTS_H

typedef void (*void_func_t) (void);

typedef enum {
  rising_edge,
  falling_edge,
  both_edges,
} InterruptCondition_E;

class LabGPIOInterrupts
{
private:

    void_func_t p0_rising [32],
                p0_falling [32],
                p2_rising[32],
                p2_falling[32];
    /**
     * Allocate a lookup table matrix here of function pointers (avoid dynamic allocation)
     * Upon attachInterruptHandler(), you will store the user's function callback
     * Upon the EINT3 interrupt, you will find out which callback to invoke based on Port/Pin status
     * Be clever here. How can you do this such that you and the cpu do the least amount of work.
     */

public:
    /**
     * Optional: LabGPIOInterrupts could be a singleton class, meaning, only one instance can exist at a time.
     * Look up how to implement this. It is best to not allocate memory in the constructor and leave complex
     * code to the init() that you call in your main()
     */
    LabGPIOInterrupts();

    /**
     * This should configure NVIC to notice EINT3 IRQs; use NVIC_EnableIRQ()
     */
    void init();

    /**
     * This handler should place a function pointer within the lookup table for the handle_interrupt() to find.
     *
     * @param[in] port         specify the GPIO port
     * @param[in] pin          specify the GPIO pin to assign an ISR to
     * @param[in] pin_isr      function to run when the interrupt event occurs
     * @param[in] condition    condition for the interrupt to occur on. RISING, FALLING or BOTH edges.
     * @return should return true if valid ports, pins, isrs were supplied and pin isr insertion was sucessful
     */
    bool attachInterruptHandler(uint8_t port, uint32_t pin, void (*pin_isr)(void), InterruptCondition_E condition);
    
    /**
     * This function is invoked by the CPU (through c_eint3_handler) asynchronously when a Port/Pin
     * interrupt occurs. This function is where you will check the Port status, such as IO0IntStatF,
     * and then invoke the user's registered callback and find the entry in your lookup table.
     *
     * VERY IMPORTANT!
     *  - Be sure to clear the interrupt flag that caused this interrupt, or this function will be called
     *    repetitively and lock your system.
     *  - NOTE that your code needs to be able to handle two GPIO interrupts occurring at the same time.
     */
    void handle_interrupt(void);
    
    // Optional destructor
    ~LabGPIOInterrupts();
};

#endif


  
