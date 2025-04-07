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


	// overloaded assignment operator for setting GPIO output state
	void operator = (bool state);

	void operator |= (bool state);

	void operator &= (bool state);

	void operator ^= (bool state);

	operator bool() const;

};

#endif /* GPIO_HPP_ */
