/*
 * main.cpp
 *
 *  Created on: May 22, 2023
 *      Author: Osama
 */



#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"
#include "Led.h"
#include "PowerLed.h"




PowerLed pled1(RED , ON , DIAM_5MM , CURR_NORMAL , VOL_NORMAL);

LedState_Type power_led1_state;
led_elec_type power_led2_power;
led_elec_type power_led3_current;

int main()
{
	RCC_voidInitSysClock();

	// static allocation
	PowerLed pled2(GREEN , ON , DIAM_7MM , CURR_HIGH , VOL_NORMAL);



	// dynamic allocation
	PowerLed *pled3 = new PowerLed(YELLOW,ON, DIAM_7MM , CURR_VERY_HIGH ,VOL_HIGH);


	power_led1_state = pled1.getState();

	power_led2_power = pled2.PowerLed_computePower();

	power_led3_current = pled3->PowerLed_getCurrent();

	MSTK_voidSetBusyWait(5000); // 5 sec

	pled1.setState(OFF);
	pled2.setState(OFF);
	pled3->setState(OFF);

	delete pled3;


	while(1)
	{


	}

}
