LabUART A;
uint8_t received[3], final, received1, MSB, LSB, total;
int i = 0;
int j = 0;
QueueHandle_t my_queue;
void my_uart2_rx_intr(void)
{
    if(LPC_UART2->IIR & (4<<0)){
        received1 = LPC_UART2->RBR;
        xQueueSendFromISR(my_queue, &received1, NULL);
    }
}
uint8_t calculate(uint8_t receivedVal1, uint8_t receivedVal2,
        uint8_t receivedChar){
    switch(receivedChar){
        case(0x2B):
                                                        return final = receivedVal1 + receivedVal2;
        break;
        case(0x2D):
                                                        return final = receivedVal1 - receivedVal2;
        break;
        case(0x2A):
                                                        return final = receivedVal1 * receivedVal2;
        break; }
}
void master(void *p)
{
    A.transfer(5);
    A.transfer(7);
    A.transfer('+');
    while (1) {
        {
            if (xQueueReceive(my_queue, &received1, portMAX_DELAY))
                received[j] = received1;
            printf("received from slave: %x\n",
                    received[j]);
            j++; }
        if(j==2){
            total = received[0]*10  + received[1];
            LD.setNumber(total);
            printf("value from master: %i\n", total);
        } }
}
void slave(void *p)
{
    while (1) {
        if (xQueueReceive(my_queue, &received1,portMAX_DELAY)) {
            received[i] = received1;
            printf("value from master %x\n", received[i]);
            i++;
        }
        if(i==3){
            int myFinal = calculate(received[0],received[1],received[2]);
            printf("final values %x ", myFinal);
            MSB = myFinal/10;
            LSB = myFinal%10;
            LD.setNumber((int)myFinal);
            A.transfer(MSB);
            A.transfer(LSB);
        }
    }
}

//UART Lab 3
class lab3: public scheduler_task {
public:
    lab3() :
        scheduler_task("lab3", 2000, PRIORITY_LOW) {
    }

    bool init(void) {
        //UART driver
        LPC_SC->PCONP |= (1 << 25); //UART3 Power Enable
        LPC_SC->PCLKSEL1 &= ~(3 << 19); //CLR CLK
        LPC_SC->PCLKSEL1 |= (1 << 18); // SET CLK
        LPC_UART3->LCR = 0x03; //bits 7:0 -- parity
        LPC_UART3->LCR |= (1 << 7); //DLAB is enabled
        uint16_t dll = 48000000 / (16 * 4800); //calculating the baud
        LPC_UART3->DLL = dll; // setting baud rate
        LPC_UART3->LCR = 3; //DLAB is disable -- set to 8bit transfer
        LPC_PINCON->PINSEL9 |= ((1 << 25) | (1 << 24)); //set bit 25:24 11 for TXD3
        LPC_PINCON->PINSEL9 |= ((1 << 27) | (1 << 26)); //set bit 27:26 11 for RXD3
        LPC_PINCON->PINMODE9 &= ~((1 << 13) | (1 << 12)); //set bit 25:24 for 00 pull up -- disable pull-down resistor
        LPC_PINCON->PINMODE9 &= ~((1 << 13) | (1 << 12)); //set bit 27:26 for 00 pull up

        return true;
    }

    bool run(void *p) {
        char userinput = '0';
        printf("\n 1: board send");
        printf("\n 2: board receive");
        scanf("%c", &userinput);
        uart3_putchar('q');
        vTaskDelay(1000);
        printf("\n********** %c", uart3_getchar());
        if (userinput == '1') {
            for (int i = 0; i < 10; i++) {
                uart3_putchar('a');
                uart3_putchar('n');
                uart3_putchar('a');
                uart3_putchar('h');
                uart3_putchar('i');
                uart3_putchar('t');
            }
            printf(
                    "\n******************************************************************************\n");
        }

        if (userinput == '2') {
            for (int i = 0; i < 10; i++) {
                printf("\n %c", uart3_getchar());
            }
            printf(
                    "\n******************************************************************************\n");
        }
        return true;
    }

    char uart3_getchar() {
        while (!(LPC_UART3->LSR & (1 << 6)))
            ;
        return LPC_UART3->RBR;
    }

    char uart3_putchar(char out) {
        while (!(LPC_UART3->LSR & (1 << 6)))
            ;
        LPC_UART3->THR = out;
        return 1;
    }
};

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

    //    scheduler_add_task(new lab2());

    //        A.init(SSP1, 8, SPI, 0x80);
    //        while(1){
    //        A.read_sig();
    //        delay_ms(1000);
    //        }

    A.init_my_uart2(2);
    isr_register(UART2_IRQn, my_uart2_rx_intr);
    my_queue = xQueueCreate(3, sizeof(int));
    xTaskCreate(master, (const char*)"trc", STACK_BYTES(2048), 0, 1, 0);
    xTaskCreate(slave, (const char*)"trc", STACK_BYTES(2048), 0, 1, 0);
    scheduler_add_task(new lab3());
    scheduler_start();
    vTaskStartScheduler();
    return 0;
}