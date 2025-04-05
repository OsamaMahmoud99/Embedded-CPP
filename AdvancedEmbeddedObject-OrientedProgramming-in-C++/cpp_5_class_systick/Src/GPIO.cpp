/*
 * GPIO.cpp
 *
 *  Created on: Apr 5, 2025
 *      Author: Osama
 */


#include "GPIO.hpp"

//Constructor
GPIO::GPIO(GPIO_TypeDef *gpioport, uint8_t gpiopin, bool isOutput): port(gpioport), pin(gpiopin){
	/*Enable clock access to GPIO*/
	if(gpioport == GPIOA){
		RCC->AHB1ENR |= (1U<<0);
	}
	if(gpioport == GPIOC){
		RCC->AHB1ENR |= (1U<<2);
	}

	/*Configure the pin*/
	if(isOutput)
	{
		gpioport->MODER |= (1 << (gpiopin*2));
		gpioport->MODER &=~(1 << (gpiopin*2 + 1));
	}
	else
	{
		gpioport->MODER &=~(3 << (gpiopin*2));
	}
}

//Toggle pin state
void GPIO::toggle(){
	port->ODR ^= (1U<<pin);
}

//set pin low
void GPIO::setLow(){
	port->ODR &=~ (1U<<pin);
}
//set pin high
void GPIO::setHigh(){
	port->ODR |= (1U<<pin);
}

//read pin
bool GPIO::read(){
	return (port->IDR & (1U<<pin));
}
