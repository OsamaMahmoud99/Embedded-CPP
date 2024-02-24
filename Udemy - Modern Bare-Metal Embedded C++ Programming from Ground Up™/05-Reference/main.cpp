#include "uart.h"
//#include <iostream>




int main()
{
	
	uart_init();
	
	int num = 234;
	int &ref_alias = num;
	int norm_alias = num;
	
	printf("num is %d \r\n",num);
	printf("ref_alias is %d \r\n",ref_alias);
	printf("norm_alias is %d \r\n",norm_alias);
	
	ref_alias++;
	norm_alias++;
	
	//&ref_alias = num2; /* expressopn error */
	
	printf("num is %d \r\n",num);
	printf("ref_alias is %d \r\n",ref_alias);
	printf("norm_alias is %d \r\n",norm_alias);
	
	while(1){
		
		
	}
	
}
