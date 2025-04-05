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
	GPIO(GPIO_TypeDef *gpioport, uint8_t gpiopin, bool isOutput = true);


	//Toggle pin state
	void toggle();

	//set pin low
	void setLow();

	//set pin high
	void setHigh();

	//read pin
	bool read();

};

#endif /* GPIO_HPP_ */
