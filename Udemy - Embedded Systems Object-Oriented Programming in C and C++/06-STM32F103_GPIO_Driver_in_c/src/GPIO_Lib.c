/*
 * GPIO_Lib.c
 *
 *  Created on: Jun 1, 2023
 *      Author: Osama
 */


#include "GPIO_Lib.h"

#define GPIO_NUMBER             16U

#define	GPIO_CRL_MODE0			0x01U<<0
#define	GPIO_MODE			    0x01U

#define	GPIO_CRH_MODE8			0x01U<<0

void LIB_GPIO_Init(GPIO_Typedef* GPIOx, GPIO_InitTypedef* GPIO_Init)
{
	u32 position;
	u32 temp = 0x00U;
	u32 ioposition = 0x00U;
	u32 iocurrent = 0x00U;

	for(position=0U; position<GPIO_NUMBER; ++position){

		ioposition = 0x01U << position;
		iocurrent = (u32)(GPIO_Init->pin) & ioposition;

		if(iocurrent == ioposition){

			if(position <=  7){
				temp = GPIOx->CRL;
				temp &= ~(GPIO_CRL_MODE0 << (position * 4U));
				temp |= (GPIO_Init->mode & GPIO_MODE) << (position * 4U);
				GPIOx->CRL = temp;
			}
			else if(position <= 15){
				temp = GPIOx->CRH;
				temp &= ~(GPIO_CRH_MODE8 << (position * 4U));
				temp |= (GPIO_Init->mode & GPIO_MODE) << (position * 4U);
				GPIOx->CRH = temp;
			}
		}
	}
}

GPIO_PinState LIB_GPIO_ReadPin(GPIO_Typedef* GPIOx, u16 GPIO_Pin)
{
	GPIO_PinState bitstatus;

	if((GPIOx->IDR & GPIO_Pin) != GPIO_PIN_RESET){
		bitstatus = GPIO_PIN_SET;
	}
	else{
		bitstatus = GPIO_PIN_RESET;
	}

	return bitstatus;
}

void LIB_GPIO_WritePin(GPIO_Typedef* GPIOx, u16 GPIO_Pin, GPIO_PinState PinState)
{
	if(PinState != GPIO_PIN_RESET){
		GPIOx->BSRR = GPIO_Pin;
	}
	else{
		GPIOx->BSRR = (u32)GPIO_Pin<<16;
	}
}

void LIB_GPIO_TogglePin(GPIO_Typedef* GPIOx, u16 GPIO_Pin)
{
	GPIOx->ODR ^= GPIO_Pin;
}

void __LIB_RCC_GPIOA_CLK_ENABLE(void)
{
	RCC->APB2ENR |= GPIOA_EN;
}
void __LIB_RCC_GPIOB_CLK_ENABLE(void)
{
	RCC->APB2ENR |= GPIOB_EN;
}
void __LIB_RCC_GPIOC_CLK_ENABLE(void)
{
	RCC->APB2ENR |= GPIOC_EN;
}
void __LIB_RCC_GPIOD_CLK_ENABLE(void)
{
	RCC->APB2ENR |= GPIOD_EN;
}
void __LIB_RCC_GPIOE_CLK_ENABLE(void)
{
	RCC->APB2ENR |= GPIOE_EN;
}
