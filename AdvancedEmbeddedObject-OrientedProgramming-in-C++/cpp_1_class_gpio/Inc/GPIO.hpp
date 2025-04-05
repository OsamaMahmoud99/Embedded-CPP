/*
 * GPIO.hpp
 *
 *  Created on: Apr 5, 2025
 *      Author: Osama
 */

#ifndef GPIO_HPP_
#define GPIO_HPP_

#include "stm32f4xx.h"

class GPIO{

private:
	GPIO_TypeDef *port;
	uint8_t pin;

public:
	//constructor
	GPIO(GPIO_TypeDef *gpioport, uint8_t gpiopin, bool isOutput = true): port(gpioport), pin(gpiopin){

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
	void toggle(){
		port->ODR ^= (1U<<pin);
	}

	//set pin low
	void setLow(){
		port->ODR &=~ (1U<<pin);
	}
	//set pin high
	void setHigh(){
		port->ODR |= (1U<<pin);
	}

	//read pin
	bool read(){
		return (port->IDR & (1U<<pin));
	}

};

#endif /* GPIO_HPP_ */
