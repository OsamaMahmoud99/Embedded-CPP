#include "uart.h"


class Led{
	
	public:
		virtual void getType() =0;
		virtual void ledState() =0;
};



class DisplayLed:public Led{
	
	public:
		void getType();
		void ledState();
};

void DisplayLed::getType(){
	
	printf("This is a Display LED \n\r");
}

void DisplayLed::ledState(){
	printf("Display LED is displaying \n\r");
}

class MedicalLed:public Led{
	
	public:
		void getType();
		void ledState();
};

void MedicalLed::getType(){
	
	printf("This is a Medical LED \n\r");
}

void MedicalLed::ledState(){
	printf("Medical LED is SCANNING \n\r");
}

int main()
{
	
	uart_init();
	
	Led *mled_pt;
	Led *dled_pt;
	
	mled_pt = new MedicalLed();
	dled_pt = new DisplayLed();
	
	mled_pt->getType();
	dled_pt->getType();
	
	while(1){
		
		
	}
	
}
