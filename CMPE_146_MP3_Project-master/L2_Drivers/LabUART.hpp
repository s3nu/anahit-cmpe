#ifndef _LAB_UART_HPP
#define _LAB_UART_HPP

#include <stddef.h>
#include <stdint.h>

#include "queue.h"
#include "semphr.h"
#include "LPC17xx.h"

class LabUART {
public:
    /**
     * Enumeration for UART channel
     */
    typedef enum {UART2, UART3} UARTn_t;

private:
    static const uint32_t RX_QUEUE_LENGTH = 16;

    typedef struct
    {
        union
        {
            uint16_t dl;
            struct
            {
              uint8_t dll;
              uint8_t dlm;
            } __attribute__((packed));
        } dl;

        union
        {
            uint8_t fdr;
            struct
            {
                uint8_t div_add_val:4;
                uint8_t mul_val:4;
            } __attribute__((packed));
        } fdr;
    } __attribute__((packed)) baud_rate_params_t;

    typedef struct {
        volatile LPC_UART_TypeDef* uart;
        const uint8_t* tx_buf;
        uint32_t tx_bufsiz;
        uint32_t tx_bufpos;
        QueueHandle_t rx_queue;
        SemaphoreHandle_t tx_sem;
    } uart_data_t;

    static uart_data_t uart2_data;
    static uart_data_t uart3_data;

    LabUART();
    LabUART(LabUART const&);
    void operator=(LabUART const&);

    ~LabUART() {}

    void clearDataStructs(void);

    bool calcBaudRateParams(uint32_t baud_rate, baud_rate_params_t& params);
    static void handleIsr(void);
    static void handleIsrChannel(UARTn_t channel);
    static void txNextByte(uart_data_t* uart);

public:
    /**
     * Enumeration for parity type
     */
    typedef enum {PARITY_NONE, PARITY_ODD, PARITY_EVEN, PARITY_SPACE, PARITY_MARK} parity_t;

    /**
     * Returns the global instance of this class
     */
    static LabUART& getInstance(void);

    /**
     * Initializes the UART hardware for the given channel and line properties
     *
     * Parameters:
     *  channel: UART channel to operate on (UART2 or UART3)
     *  data_size: Size of a word on the line. May be 5, 6, 7, or 8.
     *  parity: Parity configuration
     *  stop_bits: Number of stop bits. May be 1 or 2.
     *  baud_rate: Baud rate on the line.
     *
     * Returns true on success, false on failure
     */
    bool init(UARTn_t channel, uint8_t data_size, parity_t parity, uint8_t stop_bits, uint32_t baud_rate);

    /**
     * Sends a string of characters over the serial line. Does not block for I/O.
     *
     * Parameters:
     *  channel: UART channel to operate on (UART2 or UART3)
     *  buf: Buffer containing bytes to be sent. Must be accessible at static/global scope.
     *  bufsiz: Length of buffer in characters
     */
    void transmit(UARTn_t channel, const uint8_t* buf, uint32_t bufsiz);

    /**
     * Blocks until a character is received
     *
     * Parameters:
     *  channel: UART channel to operate on (UART2 or UART3)
     *
     * Returns the oldest received byte from the receive queue
     */
    uint8_t receive(UARTn_t channel);
};

#endif
