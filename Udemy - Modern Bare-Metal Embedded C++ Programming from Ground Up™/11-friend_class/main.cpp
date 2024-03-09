#include "uart.h"

class CarLamp;

class Led{
	
	private:
		float diameter;
	protected:
		float noOfpins;
	public:
		float current;
		float voltage;
		
		friend CarLamp;
};

class CarLamp
{
	public:
		Led mled;
		
		void setCarLamp()
		{
			mled.current = 0.8;
			mled.voltage = 3.3;
			mled.noOfpins = 6;
			mled.diameter = 0.5;
			
			printf("The power of the lamp is %f \n\r",mled.current*mled.voltage);
		}
	
};




int main()
{
	
	uart_init();
	
	CarLamp m_carlamp;
	
	m_carlamp.setCarLamp();
	
	while(1){
		
		
	}
	
}
