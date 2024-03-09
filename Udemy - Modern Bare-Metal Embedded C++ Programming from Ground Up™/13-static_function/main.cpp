#include "uart.h"


class Led{
	
	private:
		float diameter;
	protected:
		float noOfpins;
	public:
		float current;
		float voltage;
		
		static int totalcount;
		
		Led(){
			totalcount++;
		}
		
		/*static function has only access to static variables*/
		static int getTotalLedcount(){
			return totalcount;
		}
};

int Led::totalcount = 0;


int main()
{
	
	uart_init();
	
	Led led1,led2,led3;
	
	printf("Total number of LEDS created: %d\n\r",led1.getTotalLedcount());
	
	printf("Total number of LEDS created: %d\n\r",led2.getTotalLedcount());
	
	printf("Total number of LEDS created: %d\n\r",led3.getTotalLedcount());
	
	Led led4,led5,led6;
	
		printf("Total number of LEDS created: %d\n\r",led1.getTotalLedcount());
	
	while(1){
		
		
	}
	
}
