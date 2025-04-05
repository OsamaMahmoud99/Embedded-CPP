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

int main()
{
	//Enable FPU
	FPU_cp fpu;
	fpu.enable();

	//Initialize systick
	Timebase::init();

	//PA5 as output pin
	GPIO led(GPIOA, 5, true);
	//PC13 as input pin
	GPIO button(GPIOC, 13, false);

	UART uart(USART2, 115200);

	while(1)
	{
		if(!button.read())
		{
			led.toggle();
		}

		uart.sendString("One second \n\r");
		Timebase::delay(1);
	}
}
