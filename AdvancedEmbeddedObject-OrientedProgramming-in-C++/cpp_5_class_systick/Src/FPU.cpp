/*
 * FPU.cpp
 *
 *  Created on: Apr 5, 2025
 *      Author: Osama
 */


#include "FPU.hpp"

void FPU_cp::enable(void)
{
	/*Enable floating point unit: enable CP10 and CP11 full access*/
	SCB->CPACR |= (1<<20);
	SCB->CPACR |= (1<<21);
	SCB->CPACR |= (1<<22);
	SCB->CPACR |= (1<<23);

}
