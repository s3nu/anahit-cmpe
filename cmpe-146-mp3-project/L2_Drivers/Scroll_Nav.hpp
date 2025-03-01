#ifndef __SCROLL_NAV_HPP
#define __SCROLL_NAV_HPP

#include <stddef.h>

#include "FreeRTOS.h"

#include "queue.h"

#include "LabGPIO.hpp"
#include "pin_t.hpp"

class Scroll_Nav
{
public:
    typedef enum
    {
        NONE,
        WHEEL_CW,
        WHEEL_CCW,
        S1_DOWN,
        S1_UP,
        S2_DOWN,
        S2_UP,
        S3_DOWN,
        S3_UP,
        S4_DOWN,
        S4_UP,
        S5_DOWN,
        S5_UP
    } event_t;

    Scroll_Nav();

    bool init(pin_t* s1, pin_t* s2, pin_t* s3, pin_t* s4, pin_t* s5, pin_t* wheel_a, pin_t* wheel_b);

    event_t waitForNextEvent(TickType_t ticksToWait);

private:
    LabGPIO gpioS1, gpioS2, gpioS3, gpioS4, gpioS5, gpioWheelA, gpioWheelB;
    QueueHandle_t queue = NULL;
    bool aPrev = false;

    static BaseType_t enqueue(Scroll_Nav* dev, event_t event);

    static void wheelISR(void* p);

    static void S1ISR(void* p);
    static void S2ISR(void* p);
    static void S3ISR(void* p);
    static void S4ISR(void* p);
    static void S5ISR(void* p);
};

#endif
