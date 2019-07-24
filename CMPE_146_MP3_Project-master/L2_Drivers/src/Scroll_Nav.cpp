#include "LabGPIOInterrupts.hpp"
#include "Scroll_Nav.hpp"

Scroll_Nav::Scroll_Nav() {}

bool Scroll_Nav::init(pin_t* s1, pin_t* s2, pin_t* s3, pin_t* s4, pin_t* s5, pin_t* wheel_a, pin_t* wheel_b)
{
    LabGPIOInterrupts& gi = LabGPIOInterrupts::getInstance();
    gi.init();

    /* Create the event queue */
    queue = xQueueCreate(32, sizeof(event_t));

    if(queue == NULL)
    {
        return false;
    }

    /* Initialize the buttons */

    if(s1 != NULL)
    {
        if(!gpioS1.init(s1->port, s1->pin))
        {
            return false;
        }

        gpioS1.setAsInput();

        if(!gi.attachInterruptHandler(s1->port, s1->pin, S1ISR, this, BOTH))
        {
            return false;
        }
    }

    if(s2 != NULL)
    {
        if(!gpioS2.init(s2->port, s2->pin))
        {
            return false;
        }

        gpioS2.setAsInput();

        if(!gi.attachInterruptHandler(s2->port, s2->pin, S2ISR, this, BOTH))
        {
            return false;
        }
    }

    if(s3 != NULL)
    {
        if(!gpioS3.init(s3->port, s3->pin))
        {
            return false;
        }

        gpioS3.setAsInput();

        if(!gi.attachInterruptHandler(s3->port, s3->pin, S3ISR, this, BOTH))
        {
            return false;
        }
    }

    if(s4 != NULL)
    {
        if(!gpioS4.init(s4->port, s4->pin))
        {
            return false;
        }

        gpioS4.setAsInput();

        if(!gi.attachInterruptHandler(s4->port, s4->pin, S4ISR, this, BOTH))
        {
            return false;
        }
    }

    if(s5 != NULL)
    {
        if(!gpioS5.init(s5->port, s5->pin))
        {
            return false;
        }

        gpioS5.setAsInput();

        if(!gi.attachInterruptHandler(s5->port, s5->pin, S5ISR, this, BOTH))
        {
            return false;
        }
    }

    /* Initialize the wheel */

    if((wheel_a != NULL) && (wheel_b != NULL))
    {
        if(!gpioWheelA.init(wheel_a->port, wheel_a->pin))
        {
            return false;
        }

        if(!gpioWheelB.init(wheel_b->port, wheel_b->pin))
        {
            return false;
        }

        gpioWheelA.setAsInput();
        gpioWheelB.setAsInput();

        if(!gi.attachInterruptHandler(wheel_a->port, wheel_a->pin, wheelISR, this, BOTH))
        {
            return false;
        }

        aPrev = gpioWheelA.getLevel();
    }

    return true;
}

Scroll_Nav::event_t Scroll_Nav::waitForNextEvent(TickType_t ticksToWait)
{
    event_t ev;

    xQueueReceive(queue, &ev, ticksToWait);

    return ev;
}

BaseType_t Scroll_Nav::enqueue(Scroll_Nav* dev, event_t event)
{
    BaseType_t res = pdFALSE;

    xQueueSendFromISR(dev->queue, &event, &res);

    return res;
}

void Scroll_Nav::wheelISR(void* p)
{
    Scroll_Nav* dev = (Scroll_Nav*)p;

    bool a = dev->gpioWheelA.getLevel();
    bool b = dev->gpioWheelB.getLevel();

    if(a && !(dev->aPrev))
    {
        /* A rising edge */

        if(b)
        {
            /* CCW */
            enqueue(dev, WHEEL_CCW);
        }
        else
        {
            /* CW */
            enqueue(dev, WHEEL_CW);
        }
    }

    else if(!a && (dev->aPrev))
    {
        /* A falling edge */

        if(b)
        {
            /* CW */
            enqueue(dev, WHEEL_CW);
        }
        else
        {
            /* CCW */
            enqueue(dev, WHEEL_CCW);
        }
    }

    dev->aPrev = a;
}

void Scroll_Nav::S1ISR(void* p)
{
    Scroll_Nav* dev = (Scroll_Nav*)p;

    if(dev->gpioS1.getLevel())
    {
        enqueue(dev, S1_DOWN);
    }
    else
    {
        enqueue(dev, S1_UP);
    }
}

void Scroll_Nav::S2ISR(void* p)
{
    Scroll_Nav* dev = (Scroll_Nav*)p;

    if(dev->gpioS2.getLevel())
    {
        enqueue(dev, S2_DOWN);
    }
    else
    {
        enqueue(dev, S2_UP);
    }
}

void Scroll_Nav::S3ISR(void* p)
{
    Scroll_Nav* dev = (Scroll_Nav*)p;

    if(dev->gpioS3.getLevel())
    {
        enqueue(dev, S3_DOWN);
    }
    else
    {
        enqueue(dev, S3_UP);
    }
}

void Scroll_Nav::S4ISR(void* p)
{
    Scroll_Nav* dev = (Scroll_Nav*)p;

    if(dev->gpioS4.getLevel())
    {
        enqueue(dev, S4_DOWN);
    }
    else
    {
        enqueue(dev, S4_UP);
    }
}

void Scroll_Nav::S5ISR(void* p)
{
    Scroll_Nav* dev = (Scroll_Nav*)p;

    if(dev->gpioS5.getLevel())
    {
        enqueue(dev, S5_DOWN);
    }
    else
    {
        enqueue(dev, S5_UP);
    }
}
