
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "Led.h"
#include "PowerLed.h"
#include "MedicalLed.h"

int main()
{
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2 , 2);  // for GPIOA

	MedicalLed_Type mled1;
	PowerLed_Type pled1;
	Led_Type led1;

	MedicalLed_ctor(&mled1 , INFRARED , (LedColor_Type)INFRARED , ON);
	PowerLed_ctor(&pled1 , RED , ON , DIAM_5MM , CURR_NORMAL , VOL_NORMAL);
	Led_ctor(&led1 , BLUE , ON);

	Led_Type const * sys_leds[] = {&led1 , (Led_Type*)&pled1 , (Led_Type*)&mled1 , (Led_Type*)0};



	while(1)
	{

		runSystemDiagnostics(sys_leds);
	}

}
