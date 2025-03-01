/*
 * uartDriver.hpp
 *
 *  Created on: Jul 4, 2018
 *      Author: anahit
 */

#ifndef UARTDRIVER_HPP_
#define UARTDRIVER_HPP_
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include "FreeRTOS.h"
#include "queue.h"
#include "lpc_isr.h"
#include "handlers.hpp"
#ifndef LABUART_H
#define LABUART_H

class LabUART
{
private:
public:
    uint8_t resultMSB, resultLSB, received;
    char operatorVal;
    void init_my_uart2(int portValue);
    void transfer(uint8_t value);
    LabUART();
    ~LabUART();
};
#endif
#endif /* UARTDRIVER_HPP_ */
