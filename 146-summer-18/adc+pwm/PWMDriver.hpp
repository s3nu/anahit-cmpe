#ifndef PWM_DRIVER_H_
#define PWM_DRIVER_H_

#include <stdint.h>

class PWMDriver
{
public:
    enum PWM_PIN
    {
        PWM_PIN_2_0,    // PWM1.1
        PWM_PIN_2_1,    // PWM1.2
        PWM_PIN_2_2,    // PWM1.3
        PWM_PIN_2_3,    // PWM1.4
        PWM_PIN_2_4,    // PWM1.5
        PWM_PIN_2_5,    // PWM1.6
    };

    /// Nothing needs to be done within the default constructor
    PWMDriver();

    /**
    * 1) Select PWM functionality on all PWM-able pins.
    */
    void pwmSelectAllPins();

    /**
    * 1) Select PWM functionality of pwm_pin_arg
    *
    * @param pwm_pin_arg is the PWM_PIN enumeration of the desired pin.
    */
    void pwmSelectPin(PWM_PIN pwm_pin_arg);

    /**
    * Initialize your PWM peripherals.  See the notes here:
    * http://books.socialledge.com/books/embedded-drivers-real-time-operating-systems/page/pwm-%28pulse-width-modulation%29
    *
    * In general, you init the PWM peripheral, its frequency, and initialize your PWM channels and set them to 0% duty cycle
    *
    * @param frequency_Hz is the initial frequency in Hz.
    */
    void pwmInitSingleEdgeMode(uint32_t frequency_Hz);

    /**
    * 1) Convert duty_cycle_percentage to the appropriate match register value (depends on current frequency)
    * 2) Assign the above value to the appropriate MRn register (depends on pwm_pin_arg)
    *
    * @param pwm_pin_arg is the PWM_PIN enumeration of the desired pin.
    * @param duty_cycle_percentage is the desired duty cycle percentage.
    */
    void setDutyCycle(PWM_PIN pwm_pin_arg, float duty_cycle_percentage);

    /**
    * Optional:
    * 1) Convert frequency_Hz to the appropriate match register value
    * 2) Assign the above value to MR0
    *
    * @param frequency_hz is the desired frequency of all pwm pins
    */
    void setFrequency(uint32_t frequency_Hz);

    float getDutyCycle(PWM_PIN pwm_pin);
};

#endif