#ifndef PINMAP_H
#define PINMAP_H

#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common

typedef struct
{
	GPIO_TypeDef* port;
	uint16_t selectedPin;
}pinStruct_t;

#endif //PINMAP_H
