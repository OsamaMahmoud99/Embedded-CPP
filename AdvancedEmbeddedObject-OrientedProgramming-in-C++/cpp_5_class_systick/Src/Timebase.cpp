/*
 * Timebase.cpp
 *
 *  Created on: Apr 5, 2025
 *      Author: Osama
 */


#include "Timebase.hpp"

#define CTRL_ENABLE   	(1U<<0)
#define CTRL_TICKINT  	(1U<<1)
#define CTRL_CLKSRC   	(1U<<2)
#define CTRL_COUNTFLAG  (1U<<16)

#define ONE_SEC_LOAD    16000000
#define MAX_DELAY       0xFFFFFFFF
#define TICK_FREQ       1


volatile uint32_t Timebase::tickcount = 0;

void Timebase::init(void)
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
/*Delay in second*/
void Timebase::delay(uint32_t delay)
{
	uint32_t tickstart = getTick();
	uint32_t wait = delay;

	if(wait < MAX_DELAY)
	{
		wait += (uint32_t)TICK_FREQ;
	}

	while((getTick() - tickstart) < wait){}
}
uint32_t Timebase::getTick(void)
{
	__disable_irq();
	uint32_t currentTick = tickcount;
	__enable_irq();

	return currentTick;
}
void Timebase::tickIncrement(void)
{
	tickcount += TICK_FREQ;
}



extern "C" void SysTick_Handler(void)
{
	Timebase::tickIncrement();
}
