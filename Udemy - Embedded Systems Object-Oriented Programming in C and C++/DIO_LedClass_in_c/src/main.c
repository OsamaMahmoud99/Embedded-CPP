
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "Led.h"



Led_Type led1;
Led_Type led2;

int main()
{
	RCC_voidInitSysClock();
	Led_ctor(&led1 , RED , OFF);

	Led_ctor(&led2 , BLUE , ON);
	
	
	Led_setState(&led1 , ON);
	Led_setState(&led1 , OFF);
	
	while(1)
	{
		
		
	}
	
}
