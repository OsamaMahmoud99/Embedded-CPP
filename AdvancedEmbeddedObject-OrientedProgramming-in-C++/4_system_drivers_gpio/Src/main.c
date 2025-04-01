#include <stdio.h>
#include "stm32f4xx.h"
#include "fpu.h"
#include "uart.h"
#include "timebase.h"
#include "bsp.h"


bool btn_state;

int main(void)
{
	/*Enable FPU*/
	fpu_enable();

	debug_uart_init();

	/*Initialize timebase*/
	timebase_init();

	/*Initialization LED*/
	led_init();

	/*Initialize push button*/
	button_init();


    while(1)
    {
    	btn_state = get_btn_state();
    }
}
