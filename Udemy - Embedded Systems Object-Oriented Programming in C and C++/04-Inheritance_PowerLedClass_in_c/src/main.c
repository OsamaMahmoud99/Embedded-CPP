
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "Led.h"
#include "PowerLed.h"



PowerLed_Type pled1 , pled2;

led_elec_type led1_power;
led_elec_type led2_power;

int main()
{
	RCC_voidInitSysClock();
	
	PowerLed_ctor(&pled1 , RED , ON , DIAM_5MM , CURR_NORMAL, VOL_NORMAL);
	
	PowerLed_ctor(&pled2 , YELLOW , ON , DIAM_7MM , CURR_HIGH, VOL_NORMAL);

    led1_power = PowerLed_computePower(&pled1);
    led2_power = PowerLed_computePower(&pled2);

	while(1)
	{
		
		
	}
	
}
