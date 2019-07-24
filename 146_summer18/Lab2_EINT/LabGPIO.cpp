#include "LabGPIO.hpp"
#include "io.hpp"
#include <iostream>
using namespace std;

/**
 * You should not modify any hardware registers at this point
 * You should store the port and pin using the constructor.
 *
 * @param {uint8_t} pin  - pin number between 0 and 32
 */
LabGPIO_0::LabGPIO_0(int portIn, int pinIn){
    int bitMask;
    switch(portIn){
        case 0:
            {
                if(pinIn<16){
                    bitMask = pinIn * 2;
                    LPC_PINCON->PINSEL0 &= ~(3 << bitMask);
                }
                else{
                    bitMask = (pinIn - 16)*2;
                    LPC_PINCON->PINSEL1 &= ~(3 << bitMask);
                }
                break;
            }
        case 1:
            {
                if(pinIn<16){
                    bitMask = pinIn * 2;
                    LPC_PINCON->PINSEL2 &= ~(3 << bitMask);
                }
                else{
                    bitMask = (pinIn-16) * 2;
                    LPC_PINCON->PINSEL3 &= ~(3 << bitMask);
                }
                break;
            }
        case 2:
            {
                bitMask = pinIn * 2;
                LPC_PINCON->PINSEL4 &= ~(3 << bitMask);
                break;
            }
    }
    this->port = portIn;
    this->pin = pinIn;
}
/**
 * Should alter the hardware registers to set the pin as an input
 */
void LabGPIO_0::setAsInput(){
    switch(this-> port){
        case 0:
        {
            LPC_GPIO0->FIODIR &=~ (1 << this-> pin);
            break;  
        }
        case 1:
        {
            LPC_GPIO1->FIODIR &=~ (1 << this-> pin);
            break;
        } 
        case 2:
        { 
            LPC_GPIO2->FIODIR &=~ (1 << this-> pin);
            break;
        } 
    }
    
}
/**
 * Should alter the hardware registers to set the pin as an output
 */
void LabGPIO_0::setAsOutput(){
    switch(this-> port){
        case 0:
            {
                LPC_GPIO0->FIODIR |= (1 << this-> pin);
                break;  
            }
        case 1:
            {
                LPC_GPIO1->FIODIR |= (1 << this-> pin);
                break; 
            }
        case 2: 
            {
                LPC_GPIO2->FIODIR |= (1 << this-> pin);
                break; 
            }
    }
}
/**
 * Should alter the set the direction output or input depending on the input.
 *
 * @param {bool} output - true => output, false => set pin to input
 */
void LabGPIO_0::setDirection(bool output){
    if(output){
        switch(this-> port){
            case 0:
            {
                LPC_GPIO0->FIODIR |= (1 << this-> pin);
                break;
            }  
            case 1:
            {
                LPC_GPIO1->FIODIR |= (1 << this-> pin);
                break;
            } 
            case 2: 
            {
                LPC_GPIO2->FIODIR |= (1 << this-> pin);
                break; 
            }
        }
    }
    else{
        switch(this-> port){
            case 0:
            {
                LPC_GPIO0->FIODIR &=~ (1 << this-> pin);
                break; 
            } 
            case 1:
            {
                LPC_GPIO1->FIODIR &=~ (1 << this-> pin);
                break; 
            }
            case 2: 
            {
                LPC_GPIO2->FIODIR &=~ (1 << this-> pin); 
                break;
            }
        }
    }
}
/**
 * Should alter the hardware registers to set the pin as high
 */
void LabGPIO_0::setHigh(){
    switch(this-> port){
        case 0:
        {
            LPC_GPIO0->FIOSET = (1 << this-> pin);
            break; 
        } 
        case 1:
        {
            LPC_GPIO1->FIOSET = (1 << this-> pin);
            break;
        } 
        case 2: 
        {
            LPC_GPIO2->FIOSET = (1 << this-> pin);
            break;
        } 
    }
}
/**
 * Should alter the hardware registers to set the pin as low
 */
void LabGPIO_0::setLow(){
    switch(this-> port){
        case 0:
        {
            LPC_GPIO0->FIOCLR = (1 << this-> pin);
            break; 
        } 
        case 1:
        {
            LPC_GPIO1->FIOCLR = (1 << this-> pin);
            break; 
        }
        case 2: 
        {
            LPC_GPIO2->FIOCLR = (1 << this-> pin);
            break; 
        }
    }
}
/**
 * Should alter the hardware registers to set the pin as low
 *
 * @param {bool} high - true => pin high, false => pin low
 */
void LabGPIO_0::set(bool high){
    if(high){
        switch(this-> port){
            case 0:
            {
                LPC_GPIO0->FIOSET = (1 << this-> pin);
                break; 
            } 
            case 1:
            {
                LPC_GPIO1->FIOSET = (1 << this-> pin);
                break; 
            }
            case 2: 
            {
                LPC_GPIO2->FIOSET = (1 << this-> pin);
                break;
            } 
        }
    }
    else{
        switch(this-> port){
            case 0:
            {
                LPC_GPIO0->FIOCLR = (1 << this-> pin);
                break;  
            }
            case 1:
            {
                LPC_GPIO1->FIOCLR = (1 << this-> pin);
                break; 
            }
            case 2: 
            {
                LPC_GPIO2->FIOCLR = (1 << this-> pin);
                break; 
            }
        }
    }
}
/**
 * Should return the state of the pin (input or output, doesn't matter)
 *
 * @return {bool} level of pin high => true, low => false
 */
bool LabGPIO_0::getLevel(){
    switch(this -> port){
        case 0:
            {
                if (LPC_GPIO0->FIOPIN & (1 << this -> pin)){
                    return true;
                }
                else{
                    return false;
                }
            }
            break;
        case 1:
            {
                if (LPC_GPIO1->FIOPIN & (1 << this -> pin)){
                    return true;
                }
                else{
                    return false;
                }
                break;
            }
        case 2:
            {
                if (LPC_GPIO2->FIOPIN & (1 << this -> pin)){
                    return true;
                }
                else{
                    return false;
                }
                break;
            }
    }
}
LabGPIO_0::~LabGPIO_0(){
    this-> port = 0;
    this-> pin = 0;
}


