#include "LPC17xx.h"
#include "PWMDriver.hpp"
#include "sys_config.h"

PWMDriver::PWMDriver()
{

}

void PWMDriver::pwmSelectAllPins()
{
    pwmSelectPin(PWM_PIN_2_0);
    pwmSelectPin(PWM_PIN_2_1);
    pwmSelectPin(PWM_PIN_2_2);
    pwmSelectPin(PWM_PIN_2_3);
    pwmSelectPin(PWM_PIN_2_4);
    pwmSelectPin(PWM_PIN_2_5);
}

void PWMDriver::pwmSelectPin(PWM_PIN pwm_pin_arg)
{
    switch(pwm_pin_arg)
    {
        case PWM_PIN_2_0:
            LPC_PINCON->PINSEL4 &= ~(3 << 0);
            LPC_PINCON->PINSEL4 |= (1 << 0);
            LPC_PWM1->PCR |= (1 << 9);          /* Enable PWM1.1 */
            break;

        case PWM_PIN_2_1:
            LPC_PINCON->PINSEL4 &= ~(3 << 2);
            LPC_PINCON->PINSEL4 |= (1 << 2);    /* Set PWM mode for pin */
            LPC_PWM1->PCR |= (1 << 10);         /* Set single-edged and enabled */
            break;

        case PWM_PIN_2_2:
            LPC_PINCON->PINSEL4 &= ~(3 << 4);
            LPC_PINCON->PINSEL4 |= (1 << 4);
            LPC_PWM1->PCR |= (1 << 11);
            break;

        case PWM_PIN_2_3:
            LPC_PINCON->PINSEL4 &= ~(3 << 6);
            LPC_PINCON->PINSEL4 |= (1 << 6);
            LPC_PWM1->PCR |= (1 << 12);
            break;

        case PWM_PIN_2_4:
            LPC_PINCON->PINSEL4 &= ~(3 << 8);
            LPC_PINCON->PINSEL4 |= (1 << 8);
            LPC_PWM1->PCR |= (1 << 13);
            break;

        case PWM_PIN_2_5:
            LPC_PINCON->PINSEL4 &= ~(3 << 10);
            LPC_PINCON->PINSEL4 |= (1 << 10);
            LPC_PWM1->PCR |= (1 << 14);
            break;

        default:
            break;
    }
}

void PWMDriver::pwmInitSingleEdgeMode(uint32_t frequency_Hz)
{
    /* Power PWM module */
    LPC_SC->PCONP |= (1 << 6);

    /* Use highest clock frequency possible for better temporal resolution */
    LPC_SC->PCLKSEL0 &= ~(3 << 12);
    LPC_SC->PCLKSEL0 |= (1 << 12);

    setFrequency(frequency_Hz);

    /* Set all pins to 0% duty cycle */
    setDutyCycle(PWM_PIN_2_0, 0.0);
    setDutyCycle(PWM_PIN_2_1, 0.0);
    setDutyCycle(PWM_PIN_2_2, 0.0);
    setDutyCycle(PWM_PIN_2_3, 0.0);
    setDutyCycle(PWM_PIN_2_4, 0.0);
    setDutyCycle(PWM_PIN_2_5, 0.0);

    /* Enable the counter register and PWM mode*/
    LPC_PWM1->TCR = 9;
}

void PWMDriver::setDutyCycle(PWM_PIN pwm_pin_arg, float duty_cycle_percentage)
{
    uint32_t sys_clk_ticks_per_cycle = LPC_PWM1->MR0;

    if(duty_cycle_percentage > 100.0)
    {
        duty_cycle_percentage = 100.0;
    }
    else if(duty_cycle_percentage < 0.0)
    {
        duty_cycle_percentage = 0.0;
    }

    duty_cycle_percentage /= 100.0;

    uint32_t pwm_ticks = (uint32_t)(duty_cycle_percentage * ((float)sys_clk_ticks_per_cycle));

    switch(pwm_pin_arg)
    {
        case PWM_PIN_2_0:
            LPC_PWM1->MR1 = pwm_ticks;  /* Set pulse width of PWM1.1 in cycles */
            LPC_PWM1->LER |= (1 << 1);  /* Latch MR1 */
            break;

        case PWM_PIN_2_1:
            LPC_PWM1->MR2 = pwm_ticks;
            LPC_PWM1->LER |= (1 << 2);
            break;

        case PWM_PIN_2_2:
            LPC_PWM1->MR3 = pwm_ticks;
            LPC_PWM1->LER |= (1 << 3);
            break;

        case PWM_PIN_2_3:
            LPC_PWM1->MR4 = pwm_ticks;
            LPC_PWM1->LER |= (1 << 4);
            break;

        case PWM_PIN_2_4:
            LPC_PWM1->MR5 = pwm_ticks;
            LPC_PWM1->LER |= (1 << 5);
            break;

        case PWM_PIN_2_5:
            LPC_PWM1->MR6 = pwm_ticks;
            LPC_PWM1->LER |= (1 << 6);
            break;

        default:
            break;
    }
}

void PWMDriver::setFrequency(uint32_t frequency_Hz)
{
    uint32_t sys_clk = sys_get_cpu_clock();

    uint32_t sys_clk_ticks_per_cycle = sys_clk / frequency_Hz;

    LPC_PWM1->MR0 = sys_clk_ticks_per_cycle;
    LPC_PWM1->LER |= (1 << 0);  /* Latch MR0 */
}

float PWMDriver::getDutyCycle(PWM_PIN pwm_pin)
{
    uint32_t pulse_width, period;

    switch(pwm_pin)
    {
        case PWM_PIN_2_0:
            pulse_width = LPC_PWM1->MR1;
            break;

        case PWM_PIN_2_1:
            pulse_width = LPC_PWM1->MR2;
            break;

        case PWM_PIN_2_2:
            pulse_width = LPC_PWM1->MR3;
            break;

        case PWM_PIN_2_3:
            pulse_width = LPC_PWM1->MR4;
            break;

        case PWM_PIN_2_4:
            pulse_width = LPC_PWM1->MR5;
            break;

        case PWM_PIN_2_5:
            pulse_width = LPC_PWM1->MR6;
            break;

        default:
            return 0.0;
    }

    period = LPC_PWM1->MR0;

    return 100.0 * ((float)pulse_width) / ((float)period);
}