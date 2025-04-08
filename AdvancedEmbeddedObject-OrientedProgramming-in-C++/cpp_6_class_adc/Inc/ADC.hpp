/*
 * ADC.hpp
 *
 *  Created on: Apr 8, 2025
 *      Author: Osama
 */

#ifndef ADC_HPP_
#define ADC_HPP_

#include "stm32f4xx.h"

class ADC_MODULE{
private:
	ADC_TypeDef * adc;
	GPIO_TypeDef * gpioPort;
	uint8_t pin;

public:
	ADC_MODULE(ADC_TypeDef * adc,GPIO_TypeDef * gpioPort,uint8_t pin);

	void init();
	void startConversion();
	uint32_t read();

};

#endif /* ADC_HPP_ */
