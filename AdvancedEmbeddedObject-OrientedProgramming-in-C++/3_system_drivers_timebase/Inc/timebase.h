/*
 * timebase.h
 *
 *  Created on: Apr 1, 2025
 *      Author: Osama
 */

#ifndef TIMEBASE_H_
#define TIMEBASE_H_
#include <stdint.h>

uint32_t get_tick(void);
void delay(uint32_t delay);
void timebase_init(void);

#endif /* TIMEBASE_H_ */
