/*
 * main.cpp
 *
 *  Created on: Apr 5, 2025
 *      Author: Osama
 */


#include "GPIO.hpp"
#include "UART.hpp"

int main()
{
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

		uart.sendString("Hello from Embedded c++ \n\r");
	}
}
