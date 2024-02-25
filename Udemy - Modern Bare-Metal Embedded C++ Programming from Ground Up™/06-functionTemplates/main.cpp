#include "uart.h"


/*
int int_adder(int a , int b){
	
	return a+b;
}

float float_adder(float a , float b){
	return a+b;
}
*/

template<class T>

T adder(T a , T b)
{
	return a+b;
}
int main()
{
	uart_init();
	
	int num1 = 45;
	int num2 = 67;
	int ans;
	float fnum1 = 78.9;
	float fnum2 = 54.78;
	float f_ans;
	
	/*ans = int_adder(num1 , num2);
	f_ans = float_adder(fnum1 , fnum2);
	*/
	
	ans = adder(num1 , num2);
	f_ans =adder(fnum1 , fnum2);
	printf("The int res is %d  \n\r",ans);
	printf("The float res is %f  \n\r",f_ans);
	

	

	while(1){
		
		
	}
	
}
