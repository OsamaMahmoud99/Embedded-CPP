#include "uart.h"
//#include <iostream>


class Led
{
	public:
		
		int diameter;
		float voltage;
		float current;
		
		float power(){
			
			return voltage*current;
		}
	
};

int main()
{
	
	uart_init();
	
	Led green_led , red_led;
	Led *pt_green , *pt_red;
	
	pt_green = &green_led;
	pt_green->current = 0.8;
	pt_green->voltage = 3.3;
	green_led.diameter = 2;
	
	printf("The power of green led is %f ",green_led.power());
	
	
	while(1){
		
		
	}
	
}
