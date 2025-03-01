#include "interrupts.h"
#include "io.hpp"
#include "LPC17xx.h"
#include "lpc_isr.h"
#include <iostream>

using namespace std;

LabGPIOInterrupts::LabGPIOInterrupts(){
	int i;
	for(i = 0; i<32; i++){
		p0_rising[i] = NULL;
		p0_falling[i] = NULL;
		p2_rising[i] = NULL;
		p2_falling[i] = NULL;
	}
}

void LabGPIOInterrupts::init(){
	NVIC_EnableIRQ(EINT3_IRQn);
}

bool LabGPIOInterrupts::attachInterruptHandler(uint8_t port, uint32_t pin, void (*pin_isr)(void), InterruptCondition_E condition){
	if(port == 0){
		if(condition == rising_edge){
			p0_rising[pin] = pin_isr;
			LPC_GPIOINT -> IO0IntEnR |= (1 << pin);
			return true;
		}
		else if(condition == falling_edge){
			p0_falling[pin] = pin_isr;
			LPC_GPIOINT -> IO0IntEnF |= (1 << pin);
			return true;
		}
		else if(condition == both_edges){
			p0_rising[pin] = pin_isr;
			p0_falling[pin] = pin_isr;
			LPC_GPIOINT -> IO0IntEnR |= (1 << pin);
			LPC_GPIOINT -> IO0IntEnF |= (1 << pin);
			return true;
		}
		else{
			return false;
		}
	}
	else if(port == 2){
		if(condition == rising_edge){
			p2_rising[pin] = pin_isr;
			LPC_GPIOINT -> IO2IntEnR |= (1 << pin);
			return true;
		}
		else if(condition == falling_edge){
			p2_falling[pin] = pin_isr;
			LPC_GPIOINT -> IO2IntEnF |= (1 << pin);
			return true;
		}
		else if(condition == both_edges){
			p2_rising[pin] = pin_isr;
			p2_falling[pin] = pin_isr;

			LPC_GPIOINT -> IO2IntEnR |= (1 << pin);
			LPC_GPIOINT -> IO2IntEnF |= (1 << pin);
			return true;
		}
		else{
			return false;
		}
	}	
	else{
		return false;
	}
}

void LabGPIOInterrupts::handle_interrupt(void){
	uint32_t p0_rising_bits = LPC_GPIOINT -> IO0IntStatR;
	uint32_t p0_falling_bits = LPC_GPIOINT -> IO0IntStatF;
	uint32_t p2_rising_bits = LPC_GPIOINT -> IO2IntStatR;
	uint32_t p2_falling_bits = LPC_GPIOINT -> IO2IntStatF;

	int i;
	for(i=0; i<32; i++){
		if(p0_rising_bits & (1 << i)){
			if(p0_rising[i] != NULL){
				LPC_GPIOINT->IO0IntClr |= (1 << i);
				p0_rising[i]();
			}
		}
		else if(p0_falling_bits & (1 << i)){
			if(p0_falling[i] != NULL){
				LPC_GPIOINT->IO0IntClr |= (1 << i);
				p0_falling[i]();
			}
		}
		else if(p2_rising_bits & (1 << i)){
			if(p2_rising[i] != NULL){
				LPC_GPIOINT->IO2IntClr |= (1 << i);
				p2_rising[i]();
			}
		}
		else if(p2_falling_bits & (1 << i)){
			if(p2_falling[i] != NULL){
				LPC_GPIOINT->IO2IntClr |= (1 << i);
				p2_falling[i]();
			}
		}
		LPC_GPIOINT->IO0IntClr = 0xFFFFFFFF;
		LPC_GPIOINT->IO2IntClr = 0xFFFFFFFF;
	}
}
    
    // Optional destructor
LabGPIOInterrupts::~LabGPIOInterrupts(){

}
