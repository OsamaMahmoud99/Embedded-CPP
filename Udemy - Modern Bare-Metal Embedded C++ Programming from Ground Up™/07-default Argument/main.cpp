#include "uart.h"


int add_tripple(int a, int b, int c=0){
	
	return a+b+c;

}	
int main()
{
	uart_init();
	
	printf("The sume is %d", add_tripple(50 , 50 ,20));
	
	// in case default argument c = 0;
  printf("The sume is %d", add_tripple(50 , 50));

	while(1){
		
		
	}
	
}
