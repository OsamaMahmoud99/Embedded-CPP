#include "uart.h"
//#include <iostream>


int main()
{
	
	uart_init();
	
	
	while(1){
		
		//uart_write('Y');
		printf("osama\r\n");
		for(int i=0; i<180000; i++){}
		
		
	}
	
}
