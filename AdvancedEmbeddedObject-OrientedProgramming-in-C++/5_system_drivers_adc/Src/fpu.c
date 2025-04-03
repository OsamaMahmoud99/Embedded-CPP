/*
 * fpu.c
 *
 *  Created on: Feb 25, 2025
 *      Author: Osama
 */


#include "stm32f4xx.h"
#include "fpu.h"

void fpu_enable(void)
{
	/*Enable floating point unit: enable CP10 and CP11 full access*/
	SCB->CPACR |= (1<<20);
	SCB->CPACR |= (1<<21);
	SCB->CPACR |= (1<<22);
	SCB->CPACR |= (1<<23);

}
