/*
 * pinmap.h
 *
 *  Created on: Jun 5, 2024
 *      Author: Osama
 */

#ifndef INC_PINMAP_H_
#define INC_PINMAP_H_



#include "stm32f4xx_hal.h"

typedef struct
{
	GPIO_TypeDef* port;
	uint16_t selectedPin;

}pinStruct_t;



#endif /* INC_PINMAP_H_ */
