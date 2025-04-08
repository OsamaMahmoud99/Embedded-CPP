/*
 * ADC.cpp
 *
 *  Created on: Apr 8, 2025
 *      Author: Osama
 */


#include "ADC.hpp"

#define GPIOAEN   (1U<<0)
#define ADC1EN    (1U<<8)
#define ADC_CH1   (1U<<0)
#define ADC_SEQ_LEN_1 0x00
#define CR2_ADCON  (1U<<0)
#define CR2_CONT   (1U<<1)
#define CR2_SWSTART (1U<<30)
#define SR_EOC      (1U<<1)

ADC_MODULE::ADC_MODULE(ADC_TypeDef * adc,GPIO_TypeDef * gpioPort,uint8_t pin)
	:adc(adc),gpioPort(gpioPort),pin(pin){}


void ADC_MODULE::init()
{
	/****Configure the adc gpio pin****/
	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;

	/*Set PA1 mode to analog mode*/
	GPIOA->MODER |= (1U<<(2*pin));
	GPIOA->MODER |= (1U<<(2*pin+1));

	/****Configure the adc module****/
	/*Enable clock access to the adc module*/
	RCC->APB2ENR |= ADC1EN;

	/*Set conversion sequence start*/
	adc->SQR3 = ADC_CH1;

	/*Set conversion sequence length*/
	adc->SQR1 = ADC_SEQ_LEN_1;

	/*Enable adc module*/
	adc->CR2 |= CR2_ADCON;
}

void ADC_MODULE::startConversion()
{
	/*Enable continuous conversion*/
	adc->CR2 |= CR2_CONT;

	/*Start ADC conversion*/
	adc->CR2 |= CR2_SWSTART;
}

uint32_t ADC_MODULE::read()
{
	/*wait for conversion to be complete*/
	while(!(adc->SR & SR_EOC));

	/*Read converted value*/
	return (adc->DR);
}
