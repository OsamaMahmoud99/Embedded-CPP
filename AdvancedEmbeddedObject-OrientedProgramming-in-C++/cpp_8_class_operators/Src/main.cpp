/*
 * main.cpp
 *
 *  Created on: Apr 5, 2025
 *      Author: Osama
 */


#include "GPIO.hpp"

int main()
{
	//PA5 as output pin
	GPIO led(GPIOA, 5, true);
	//PC13 as input pin
	GPIO button(GPIOC, 13, false);

	while(1)
	{
		if(!button)
		{
			led = true;
		}
	}
}
