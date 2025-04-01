#include <stdio.h>
#include "stm32f4xx.h"
#include "fpu.h"
#include "uart.h"
#include "timebase.h"

#define GPIOEN    (1U<<0)
#define PIN5      (1U<<5)
#define LED_PIN   PIN5

int main(void)
{
	/*Enable FPU*/
	fpu_enable();

	debug_uart_init();

	/*Initialize timebase*/
	timebase_init();

    while(1)
    {
    	printf("Hello from STM32\n\r");

    	delay(1); // 1 second
    }
}
