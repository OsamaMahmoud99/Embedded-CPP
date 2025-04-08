/*
 * main.cpp
 *
 *  Created on: Apr 5, 2025
 *      Author: Osama
 */


#include "GPIO.hpp"
#include "UART.hpp"
#include "FPU.hpp"
#include "Timebase.hpp"
#include "ADC.hpp"


int main()
{
	//Enable FPU
	FPU_cp fpu;
	fpu.enable();

	//Initialize systick
	Timebase::init();

	//create an adc object for PA1 using ADC1
	ADC_MODULE adc1(ADC1, GPIOA,1);

	//PA5 as output pin
	GPIO led(GPIOA, 5, true);
	//PC13 as input pin
	GPIO button(GPIOC, 13, false);

	UART uart(USART2, 115200);

	//Initialize ADC
	adc1.init();

	//Start ADC Conversion
	adc1.startConversion();

	while(1)
	{
		if(!button.read())
		{
			led.toggle();
		}

		uart.sendString("ADC Value: ");
		uart.sendInteger(adc1.read());
		uart.sendString("\r\n ");

	}
}
