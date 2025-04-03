#include <stdio.h>
#include "stm32f4xx.h"
#include "fpu.h"
#include "uart.h"
#include "timebase.h"
#include "bsp.h"
#include "adc.h"


bool btn_state;

uint32_t sensor_value;

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

	/*Initialize ADC*/
	pal_adc_init();

	/*start conversion*/
	start_conversion();

    while(1)
    {
    	sensor_value = adc_read();
    }
}
