/*
 * main.cpp
 *
 *  Created on: May 19, 2023
 *      Author: Osama
 */



#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "Led.h"




Led led1(RED , ON);



int main()
{
	RCC_voidInitSysClock();

	// static allocation
	Led led2(YELLOW , ON);


	// dynamic allocation
	Led *led3 = new Led(GREEN,OFF);

	led3->Led_setState(ON);


	led3->Led_setState(OFF);

	delete led3;

	while(1)
	{


	}

}
