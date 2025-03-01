#include <stdint.h>
#include <iostream>
#include "printf_lib.h"
#include "LabSPI.hpp"
#include "LPC17xx.h"
#include "stdio.h"

// *
//  * 1) Powers on SPPn peripheral
//  * 2) Set peripheral clock
//  * 3) Sets pins for specified peripheral to MOSI, MISO, and SCK
//  *
//  * @param peripheral which peripheral SSP0 or SSP1 you want to select.
//  * @param data_size_select transfer size data width; To optimize the code, look for a pattern in the datasheet
//  * @param format is the code format for which synchronous serial protocol you want to use.
//  * @param divide is the how much to divide the clock for SSP; take care of error cases such as the value of 0, 1, and odd numbers
//  *
//  * @return true if initialization was successful

bool LabSPI::init(Peripheral peripheral, uint8_t data_size_select, FrameModes format, uint8_t divide){
    LPC_PINCON->PINSEL0 &= ~(0x3F<<14); //Clear SCK1, MISO1, MOSI1
    LPC_PINCON->PINSEL0 &= ~(0x3<<30);  //Clear SCK0
    LPC_PINCON->PINSEL1 &= ~(0xF<<2);   //Clear MISO0, MOSI0
    switch(peripheral){
        case SSP0:
            LPC_SC->PCONP|= (1<<21);         	//set PCSPI in PCONP SPP1
            LPC_PINCON->PINSEL0 |= (0x2<<30);  	//Set SCK0
            LPC_PINCON->PINSEL1 |= (0xA<<2);   	//Set MISO0, MOSI0
            break;
        case SSP1:
            LPC_SC->PCONP|= (1<<10);         	//set PCSPI in PCONP SPP1
            LPC_PINCON->PINSEL0 |= (0x2A<<14); 	//Set SCK1, MISO1, MOSI1
            break;
    }
    LPC_SC->PCLKSEL0 &= ~(3 << 20);   //Clear clock
    LPC_SC->PCLKSEL0 |= (1<<20);      //Set SPI clock
    switch(format){
        case SPI:
            LPC_SSP1->CR0 |= (0<<4);
            break;
        case TI:
            LPC_SSP1->CR0 |= (1<<4);
            break;
        case Microwire:
            LPC_SSP1->CR0 |= (2<<4);
            break;
    }
    LPC_SSP1-> CR0 |= ((data_size_select-1)<<0);          //Set bit size
    LPC_SSP1-> CR1 = (1<<1);							//SSP Enable
    LPC_SSP1-> CPSR = divide;							//Divde clock by value
    LPC_PINCON->PINSEL0 &= ~(3 << 12);  //Set P0.6 as GPIO
    LPC_GPIO0->FIODIR |= (1 << 6);      //Set P0.6 as Output
    return true;
}

// *
//  * Transfers a byte via SSP to an external device using the SSP data register.
//  * This region must be protected by a mutex static to this class.
//  *
//  * @return received byte from external device via SSP data register.

uint8_t LabSPI::transfer(uint8_t send){
    LPC_SSP1->DR = send;
    while (LPC_SSP1->SR & (1 << 4)); // Wait for SSP to be busy
    return LPC_SSP1->DR;
}

void LabSPI::read_sig(void){
    uint8_t d[2];
    uint8_t status_reg;

    // The simplest test is to try to read the signature of the Adesto flash and print it out
    LPC_GPIO0->FIOCLR = (1 << 6);     //adesto_cs();
    {
        d[0] = transfer(0xD7); // TODO: Find what to send to read Adesto flash signature
        status_reg = transfer(0x00);
        d[1] = transfer(0x00);
    }
    LPC_GPIO0->FIOSET = (1 << 6);     //adesto_ds();

    adlx_t status;
    status.byte = status_reg;

    if(status.data_ready) {
        printf("not busy\n");
    }
    else if(!status.data_ready){
        {printf("not is busy\n");
        }

        if(status.main_mem_match){
            printf("data==buffer\n");
        }
        else if(!status.main_mem_match){
            printf("data not buffer\n");
        }

        if(status.sector_protection){
            printf("sector protection enables\n");
        }
        else if(!status.sector_protection){
            printf("sector protection disabled\n");
        }

        if(status.byte_size){
            printf("page count 512\n");
        }
        else if(!status.byte_size){
            printf("page count 512\n");
        }
    }
}


LabSPI::LabSPI(){}
LabSPI::~LabSPI(){}
