#include "tasks.hpp"
#include "examples/examples.hpp"
#include "periodic_scheduler/periodic_callback.h"
#include "uart2.hpp"
#include "uart3.hpp"
#include "utilities.h"
#include "uart0_min.h"
#include "handlers.hpp"
#include "printf_lib.h"
#include "stdio.h"
#include "LabGPIO.hpp"
#include "interrupts.h"

bool switch0bool;
SemaphoreHandle_t xSemaphore;

int LEDptr = 1;
int ptrSwitchParam = 0;


void vControlLED(void * pvParameters )
{

    uint32_t paramLED = *((uint32_t*)pvParameters);
    uint32_t portParamLED = 100;
    if(paramLED<100){
        portParamLED = 0;
    }
    else if((paramLED>= 100)&& (paramLED <200)){
        portParamLED = 1;
        paramLED = paramLED -100;
    }
    else{
        portParamLED = 2;
        paramLED = paramLED -200;
    }
    LabGPIO_0 LED0 (1,0);

    LED0.setAsOutput();
    while(1)
    {
        if(xSemaphoreTake(xSemaphore, 500)){
            LED0.setLow();
            vTaskDelay(500);
        }
        else{
            LED0.setHigh();
        }
    }
    vTaskDelete(NULL);
}

LabGPIOInterrupts gpio_intr_instance;
void c_eint3_handler(void)
{
    gpio_intr_instance.handle_interrupt();
}
// Init things once

void user_callback(void)
{
    xSemaphoreGive(xSemaphore);
    u0_dbg_printf("Calling port 0, pin 0\n");
}


int main(void)
{
    xSemaphore = xSemaphoreCreateBinary();
    xTaskCreate(vControlLED, (const char*)"control external LED", STACK_BYTES(2048), (void*)&LEDptr, 1, 0);
    gpio_intr_instance.init();
    gpio_intr_instance.attachInterruptHandler(2, 3, user_callback, rising_edge);
    //gpio_intr_instance.attachInterruptHandler(0, 0, user_callback, both_edges);
    isr_register(EINT3_IRQn, c_eint3_handler);
    vTaskStartScheduler();
    return 0;
}
