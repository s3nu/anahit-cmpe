
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
void masterTask(void *p)
{
    A.transfer(5);
    A.transfer(7);
    A.transfer('+');
    while (1) {
        {
            if (xQueueReceive(my_queue, &received1, portMAX_DELAY))
                received[j] = received1;
            printf("received: %x\n",
                    received[j]);
            j++; }
        if(j==2){
            total = received[0]*10  + received[1];
            LD.setNumber(total);
            printf("value: %i\n", total);
        } }
}
// void slaveTask(void *p)
// {
//     while (1) {
//         if (xQueueReceive(my_queue, &received1,portMAX_DELAY)) {
//             received[i] = received1;
//             printf("Value received from master %x\n", received[i]);
//             i++;
//         }
//         if(i==3){
//             int myFinal = calculate(received[0],received[1],received[2]);
//             printf("Calculated value is %x ", myFinal);
//             MSB = myFinal/10;
//             LSB = myFinal%10;
//             LD.setNumber((int)myFinal);
//             A.transfer(MSB);
//             A.transfer(LSB);
//         }
//     }
// }

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

    //    A.init(SSP1, 8, SPI, 0x80);
    //    while(1){
    //    A.read_sig();
    //    }

    //    xTaskCreate(task_sig_reader, (const char*)"task_read_sig", STACK_BYTES(2048), 0, 1, 0);
    //    xTaskCreate(task_page_reader, (const char*)"task_read_page", STACK_BYTES(2048), 0, 1, 0);

    A.init_my_uart2(2);
    isr_register(UART2_IRQn, my_uart2_rx_intr);
    my_queue = xQueueCreate(3, sizeof(int));
    xTaskCreate(masterTask, (const char*)"trc", STACK_BYTES(2048), 0, 1, 0);
    //xTaskCreate(slaveTask, (const char*)"trc", STACK_BYTES(2048), 0, 1, 0);

    scheduler_start();
    vTaskStartScheduler();
    return 0;
}