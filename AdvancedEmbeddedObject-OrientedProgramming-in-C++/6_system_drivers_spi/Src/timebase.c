/*
 * timebase.c
 *
 *  Created on: Apr 1, 2025
 *      Author: Osama
 */

#include "timebase.h"
#include "stm32f4xx.h"


#define CTRL_ENABLE   	(1U<<0)
#define CTRL_TICKINT  	(1U<<1)
#define CTRL_CLKSRC   	(1U<<2)
#define CTRL_COUNTFLAG  (1U<<16)

#define ONE_SEC_LOAD    16000000

#define MAX_DELAY       0xFFFFFFFF
#define TICK_FREQ       1

volatile uint32_t g_curr_tick;
volatile uint32_t g_curr_tick_p;

/*Delay in second*/
void delay(uint32_t delay)
{
	uint32_t tickstart = get_tick();
	uint32_t wait = delay;

	if(wait < MAX_DELAY)
	{
		wait += (uint32_t)TICK_FREQ;
	}

	while((get_tick() - tickstart) < wait){}
}
uint32_t get_tick(void)
{
	__disable_irq();
	g_curr_tick_p = g_curr_tick;
	__enable_irq();

	return g_curr_tick_p;
}
static void tick_increment(void)
{
	g_curr_tick += TICK_FREQ;
}

void timebase_init(void)
{
	/*Disable global interrupt*/
	__disable_irq();

	/*Load the timer with number of clock cycles per second*/
	SysTick->LOAD = ONE_SEC_LOAD -1;

	/*clear systick current reguster*/
	SysTick->VAL = 0;

	/*select internal clock source*/
	SysTick->CTRL = CTRL_CLKSRC;

	/*Enable interrupt*/
	SysTick->CTRL |= CTRL_TICKINT;

	/*Enable systick*/
	SysTick->CTRL |= CTRL_ENABLE;

	/*Enable global interrupt*/
	__enable_irq();
}

void SysTick_Handler(void)
{
	tick_increment();
}
