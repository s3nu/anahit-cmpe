#include <stddef.h>

#include "core_cm3.h"
#include "FreeRTOS.h"
#include "LabUART.hpp"
#include "LPC17xx.h"
#include "lpc_isr.h"
#include "queue.h"
#include "semphr.h"
#include "sys_config.h"

LabUART::uart_data_t LabUART::uart2_data;
LabUART::uart_data_t LabUART::uart3_data;

LabUART::LabUART()
{
    clearDataStructs();
}

LabUART::LabUART(LabUART const&) {}
void LabUART::operator=(LabUART const&) {}

/* Sets data structures for UART2 and UART3 to initial values */
void LabUART::clearDataStructs(void)
{
    uart2_data.uart = LPC_UART2;
    uart2_data.rx_queue = NULL;
    uart2_data.tx_buf = NULL;
    uart2_data.tx_sem = NULL;
    uart2_data.tx_bufpos = 0;
    uart2_data.tx_bufsiz = 0;

    uart3_data.uart = LPC_UART3;
    uart3_data.rx_queue = NULL;
    uart3_data.tx_buf = NULL;
    uart3_data.tx_sem = NULL;
    uart3_data.tx_bufpos = 0;
    uart3_data.tx_bufsiz = 0;
}

LabUART& LabUART::getInstance(void)
{
    static LabUART instance;
    return instance;
}

bool LabUART::init(UARTn_t channel, uint8_t data_size, parity_t parity, uint8_t stop_bits, uint32_t baud_rate)
{
    /* Validate parameters */

    if((data_size > 8) || (data_size < 5) || (stop_bits > 2) || (stop_bits < 1))
    {
        return false;
    }

    switch(parity)
    {
        case PARITY_NONE:
        case PARITY_ODD:
        case PARITY_EVEN:
        case PARITY_SPACE:
        case PARITY_MARK:
            break;

        default:
            return false;
    }

    /* Get baud rate parameters */

    baud_rate_params_t br_params;

    if(calcBaudRateParams(baud_rate, br_params) == false)
    {
        return false;
    }

    uart_data_t* uart;

    switch(channel)
    {
        case UART2:
            uart = &uart2_data;

            if(uart->rx_queue == NULL)
            {
                /* Create receive queue */
                uart->rx_queue = xQueueCreate(RX_QUEUE_LENGTH, sizeof(uint8_t));

                if(uart->rx_queue == NULL)
                {
                    return false;
                }

                uart->tx_sem = xSemaphoreCreateBinary();

                if(uart->tx_sem == NULL)
                {
                    return false;
                }
            }

            /* Power UART2 */
            LPC_SC->PCONP |= (1 << 24);

            /* PCLK = CCLK */
            LPC_SC->PCLKSEL1 &= ~(3 << 16);
            LPC_SC->PCLKSEL1 |=  (1 << 16);

            /* Select pins (P2.8 Tx, P2.9 Rx)*/
            LPC_PINCON->PINSEL4 &= ~(3 << 16);
            LPC_PINCON->PINSEL4 |=  (2 << 16);
            LPC_PINCON->PINSEL4 &= ~(3 << 18);
            LPC_PINCON->PINSEL4 |=  (2 << 18);
            break;

        case UART3:
            uart = &uart3_data;

            if(uart->rx_queue == NULL)
            {
                /* Create receive queue */
                uart->rx_queue = xQueueCreate(RX_QUEUE_LENGTH, sizeof(uint8_t));

                if(uart->rx_queue == NULL)
                {
                    return false;
                }

                uart->tx_sem = xSemaphoreCreateBinary();

                if(uart->tx_sem == NULL)
                {
                    return false;
                }
            }

            /* Power UART3 */
            LPC_SC->PCONP |= (1 << 25);

            /* PCLK = CCLK */
            LPC_SC->PCLKSEL1 &= ~(3 << 18);
            LPC_SC->PCLKSEL1 |=  (1 << 18);

            /* Select pins (P4.28 Tx, P4.29 Rx)*/
            LPC_PINCON->PINSEL9 |= (3 << 24);
            LPC_PINCON->PINSEL9 |= (3 << 26);
            break;

        default:
            return false;
    }

    /* Configure line parameters */

    uint8_t lcr = 0;

    data_size -= 5;
    stop_bits -= 1;

    lcr |= (stop_bits << 2) | (data_size << 0);

    switch(parity)
    {
        case PARITY_NONE:
            break;

        case PARITY_ODD:
            lcr |= (0 << 4) | (1 << 3);
            break;

        case PARITY_EVEN:
            lcr |= (1 << 4) | (1 << 3);
            break;

        case PARITY_SPACE:
            lcr |= (3 << 4) | (1 << 3);
            break;

        case PARITY_MARK:
            lcr |= (2 << 4) | (1 << 3);
            break;

        default:
            return false;
    }

    uart->uart->LCR = lcr; /* Set line parameters */

    uart->uart->LCR |= (1 << 7); /* Enable divisor latch access */

    /* Set baud rate parameters */
    uart->uart->DLL = br_params.dl.dll;
    uart->uart->DLM = br_params.dl.dlm;
    uart->uart->FDR = br_params.fdr.fdr;

    uart->uart->LCR &= ~(1 << 7); /* Disable divisor latch access */

    uart->uart->FCR |= (1 << 0); /* Enable FIFO */

    switch(channel)
    {
        case UART2:
            /* Enable interrupts */
            isr_register(UART2_IRQn, handleIsr);
            NVIC_EnableIRQ(UART2_IRQn);
            break;

        case UART3:
            isr_register(UART3_IRQn, handleIsr);
            NVIC_EnableIRQ(UART3_IRQn);
            break;

        default:
            return false;
    }

    uart->uart->IER |= (1 << 0); /* Enable data receive interrupt */

    return true;
}

void LabUART::transmit(UARTn_t channel, const uint8_t* buf, uint32_t bufsiz)
{
    uart_data_t* uart;

    switch(channel)
    {
        case UART2:
            uart = &uart2_data;
            break;

        case UART3:
            uart = &uart3_data;
            break;

        default:
            return;
    }

    if((buf == NULL) || (bufsiz == 0))
    {
        return;
    }

    /* Save transmit buffer information */
    uart->tx_buf = buf;
    uart->tx_bufsiz = bufsiz;
    uart->tx_bufpos = 0;

    uart->uart->IER |= (1 << 1); /* Enable transmit empty interrupt */

    txNextByte(uart);
    xSemaphoreTake(uart->tx_sem, portMAX_DELAY);
}

uint8_t LabUART::receive(UARTn_t channel)
{
    uart_data_t* uart;

    switch(channel)
    {
        case UART2:
            uart = &uart2_data;
            break;

        case UART3:
            uart = &uart3_data;
            break;

        default:
            return 0;
    }

    uint8_t byte;

    xQueueReceive(uart->rx_queue, &byte, portMAX_DELAY);

    return byte;
}

bool LabUART::calcBaudRateParams(uint32_t baud_rate, baud_rate_params_t& params)
{
    uint32_t cclk = sys_get_cpu_clock();

    /* Make sure the baud rate is possible */
    if((baud_rate > cclk) || ((baud_rate << 4) > cclk))
    {
        return false;
    }

    params.fdr.div_add_val = 0;
    params.fdr.mul_val = 1;

    params.dl.dl = cclk / (baud_rate << 4);

    return true;
}

void LabUART::handleIsr(void)
{
    if(NVIC_GetActive(UART2_IRQn))
    {
        handleIsrChannel(UART2);
    }
    if(NVIC_GetActive(UART3_IRQn))
    {
        handleIsrChannel(UART3);
    }
}

void LabUART::handleIsrChannel(UARTn_t channel)
{
    uart_data_t* uart;

    switch(channel)
    {
        case UART2:
            uart = &uart2_data;
            break;

        case UART3:
            uart = &uart3_data;
            break;

        default:
            return;
    }

    uint8_t byte;
    BaseType_t woken = pdFALSE;

    switch((uart->uart->IIR >> 1) & 7)
    {
        case 1: /* Transmit empty */
            txNextByte(uart);

            if(uart->tx_bufpos == uart->tx_bufsiz)
            {
                xSemaphoreGiveFromISR(uart->tx_sem, &woken);
            }
            break;

        case 6:
        case 2: /* Receive available */
            byte = uart->uart->RBR;

            xQueueSendToBackFromISR(uart->rx_queue, &byte, &woken);
            break;

        default:
            break;
    }

    portYIELD_FROM_ISR(woken);
}

void LabUART::txNextByte(uart_data_t* uart)
{
    if(uart->tx_bufpos == uart->tx_bufsiz)
    {
        uart->uart->IER &= ~(1 << 1); /* Disable transmit empty interrupt */
        return;
    }

    uart->uart->THR = uart->tx_buf[uart->tx_bufpos];
    uart->tx_bufpos++;
}
