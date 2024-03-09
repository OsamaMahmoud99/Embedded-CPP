#include "uart.h"
#include "led.h"


int main()
{
	uart_init();
	
	
	Led *pt_led;
	
	pt_led = new MedicalLed(2,3.3,200,990);
	
	printf("Voltage : %f\n\r",pt_led->getVoltage());
	while(1){
		
		
	}
	
}
