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
#include "ADCDriver.hpp"
#include "PWMDriver.hpp"
#include "LabSPI.hpp"
#include "uartDriver.hpp"
#include "io.hpp"

ADCDriver light_sensor;

class vReadLightSensor : public scheduler_task {

public:
    vReadLightSensor():scheduler_task("vReadLightSensor", 2048, 1, NULL) {

    }
    bool init(void) {
        light_sensor.adcInitBurstMode();
        light_sensor.adcSelectPin(ADCDriver::ADC_PIN_0_26);
        return true;
    }

    bool run( void *p) {
        uint16_t rvalue = light_sensor.readADCVoltageByChannel(3);
        printf("rvalue %d\n", rvalue);
        vTaskDelay(1000);
        return true;
    }

private:
};

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

TaskHandle_t xhandler;

//SPI Lab2
class lab2: public scheduler_task {
public:
    lab2() :
        scheduler_task("lab2", 2000, PRIORITY_LOW) {
    }

    void spi1_Init() {
        LPC_SC->PCONP |= (1 << 10);             // SPI1 Power Enable
        LPC_SC->PCLKSEL0 &= ~(3 << 20);         // Clear clock Bits
        LPC_SC->PCLKSEL0 |= (1 << 20);      // CLK / 1

        // Select MISO, MOSI, and SCK pin-select functionality
        LPC_PINCON->PINSEL0 &= ~((3 << 14) | (3 << 16) | (3 << 18));
        LPC_PINCON->PINSEL0 |= ((2 << 14) | (2 << 16) | (2 << 18));
        LPC_SSP1->CR0 = 7;                      // 8-bit mode
        LPC_SSP1->CR1 = (1 << 1);               // Enable SSP as Master
        LPC_SSP1->CPSR = 8;                     // SCK speed = CPU / 8
        //      LPC_PINCON->PINSEL0 &= ~( (1 << 13)|(1 << 12) ); //Select CS
        LPC_PINCON->PINSEL0 &= ~(3 << 13); //Select CS
        LPC_GPIO0->FIODIR |= (1 << 6);      //CS output
        LPC_GPIO0->FIOSET = (1 << 6);           //CS high (not selected)
    }

    bool run(void *p) {
        /*
         * Main task for Lab2 handler
         */
        vTaskDelay(1000);                       //Delay

        printf("\nDevice ID\n");
        LPC_GPIO0->FIOCLR = (1 << 6);           //CS low
        spi1_ExchangeByte(0x9F);                //Opcode for Device ID
        for (int i = 0; i < 5; i++) {
            printf("\n %d\t %x", i, spi1_ExchangeByte(0x00));
        }
        LPC_GPIO0->FIOSET = (1 << 6);               //CS high
        vTaskDelay(1000);                       //Delay
        printf(
                "\n******************************************************************************\n");

        printf("Memory's Status Register\n");
        LPC_GPIO0->FIOCLR = (1 << 6);           //CS low
        spi1_ExchangeByte(0xD7);                //Opcode for Status Register
        uint16_t temp, temp1;
        temp = spi1_ExchangeByte(0x00);
        printf("\n %x\t", temp);
        temp1 = spi1_ExchangeByte(0x00);
        printf("\n %x\t", temp1);
        LPC_GPIO0->FIOSET = (1 << 6);               //CS high
        vTaskDelay(1000);                       //Delay
        return true;
    }

    char spi1_ExchangeByte(char out) {
        LPC_SSP1->DR = out;
        while (LPC_SSP1->SR & (1 << 4))
            ; // Wait until SSP is busy
        return LPC_SSP1->DR;
    }
};

LabSPI A;
int main(void)
{

    //    xSemaphore = xSemaphoreCreateBinary();
    //    xTaskCreate(vControlLED, (const char*)"control external LED", STACK_BYTES(2048), (void*)&LEDptr, 1, 0);
    //    gpio_intr_instance.init();
    //    gpio_intr_instance.attachInterruptHandler(2, 3, user_callback, rising_edge);
    //    gpio_intr_instance.attachInterruptHandler(0, 0, user_callback, both_edges);
    //    isr_register(EINT3_IRQn, c_eint3_handler);
    //    xTaskCreate(ReadLED, "Read light", 2048, (void *) 0, PRIORITY_MEDIUM, &xhandler);
    //    scheduler_add_task(new vReadLightSensor());

		scheduler_add_task(new lab2());
		A.init(SSP1, 8, SPI, 0x80);
		while(1){
			A.read_sig();
			delay_ms(1000);
		}
    scheduler_start();
    vTaskStartScheduler();
    return 0;
}
