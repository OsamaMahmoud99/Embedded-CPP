/*
 * Timebase.hpp
 *
 *  Created on: Apr 5, 2025
 *      Author: Osama
 */

#ifndef TIMEBASE_HPP_
#define TIMEBASE_HPP_

#include "stm32f4xx.h"

class Timebase {

private:
	static volatile uint32_t tickcount;

public:

	static void init();

	static void delay(uint32_t delay);

	static uint32_t getTick();

	static void tickIncrement();
};


#endif /* TIMEBASE_HPP_ */
