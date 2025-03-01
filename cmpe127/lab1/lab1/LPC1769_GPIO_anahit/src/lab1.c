/*
===============================================================================
 Name        : lab1.c
 Author      : Anahit Sarao
 Version     : 1.0.1
 Copyright   : TeamStandy
 Description : main definition
===============================================================================
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <stdio.h>

void GPIOinitOut(uint8_t portNum, uint32_t pinNum)
{
	if (portNum == 0)
	{
		LPC_GPIO0->FIODIR |= (1 << pinNum);
	}
	else if (portNum == 1)
	{
		LPC_GPIO1->FIODIR |= (1 << pinNum);
	}
	else if (portNum == 2)
	{
		LPC_GPIO2->FIODIR |= (1 << pinNum);
	}
	else
	{
		printf("Not a valid port!\n");
	}
}

void GPIOinitInput(uint8_t portNum, uint32_t pinNum)
{
	if (portNum == 0)
	{
		LPC_GPIO0->FIODIR &= ~(1 << pinNum);
	}
	else if (portNum == 1)
	{
		LPC_GPIO1->FIODIR &= ~(1 << pinNum);
	}
	else if (portNum == 2)
	{
		LPC_GPIO2->FIODIR &= ~(1 << pinNum);
	}
	else
	{
		printf("Not a valid port!\n");
	}
}

void setGPIO(uint8_t portNum, uint32_t pinNum)
{
	if (portNum == 0)
	{
		LPC_GPIO0->FIOSET = (1 << pinNum);
		printf("Pin 0.%d has been set.\n",pinNum);
	}
	else
	{
		printf("Only port 0 is used, try again!\n");
	}
}

void clearGPIO(uint8_t portNum, uint32_t pinNum)
{
	if (portNum == 0)
	{
		LPC_GPIO0->FIOCLR = (1 << pinNum);
		printf("Pin 0.%d has been cleared.\n", pinNum);
	}
	else
	{
		printf("Only port 0 is used, try again!\n");
	}
}
/*
 * initialize input and output
 * 	while 1:
 * 		if input pin is set:
 * 			set output high
 * 			print status
 * 		else:
 * 			set output low
 * 			print status
 *
 */
int main(void)
{
	clearGPIO(0, 2);
	GPIOinitOut(0,2);
	GPIOinitInput(0,3);

	while(1)
	{
		if(LPC_GPIO0->FIOPIN & (1 << 3))
		{
			setGPIO(0, 2);
		}
		else
		{
			clearGPIO(0, 2);
		}
	}
	return 0;
}
