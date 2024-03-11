#include "uart.h"


//led diagnostics

namespace Led{
void diagnosticsReport(){
	
	
	printf("Led module is working within normal parameters \n\r");
	
}

}
//Motor diagnostics

namespace Motor{
void diagnosticsReport(){
	
	printf("Motor module is working within normal parameters \n\r");
}
}

using namespace Led;

int main()
{
	
	uart_init();
	
	Motor::diagnosticsReport();
	Led::diagnosticsReport();
	
	/* using global namespace Led*/
	
	diagnosticsReport();
	diagnosticsReport();
	diagnosticsReport();

	while(1){
		
		
	}
	
}
