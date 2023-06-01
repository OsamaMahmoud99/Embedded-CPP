/**************************************************************************************/
/*    Author  : OsamaMahmoud                                                          */
/*    Date    : 13/8/2020                                                             */
/*    Version : V01                                                                   */
/**************************************************************************************/
#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "STD_TYPES.h"

#define PERIPH_BASE           0x40000000U
#define AHBPERIPH_BASE       (PERIPH_BASE + 0x20000U)         /*start base from DMA1 0x4002 0000*/
#define RCC_BASE             (AHBPERIPH_BASE + 0x1000U)

#define APB2PERIPH_BASE      (PERIPH_BASE + 0x10000U)
#define GPIOA_BASE           (APB2PERIPH_BASE + 0x0800U)
#define GPIOB_BASE           (APB2PERIPH_BASE + 0x0C00U)
#define GPIOC_BASE           (APB2PERIPH_BASE + 0x1000U)
#define GPIOD_BASE           (APB2PERIPH_BASE + 0x1400U)
#define GPIOE_BASE           (APB2PERIPH_BASE + 0x1800U)
#define GPIOF_BASE           (APB2PERIPH_BASE + 0x1C00U)

#define __IO                 volatile

typedef struct{

	__IO  u32 CRL;
	__IO  u32 CRH;
	__IO  u32 IDR;
	__IO  u32 ODR;
	__IO  u32 BSRR;
	__IO  u32 BRR;
	__IO  u32 LCKR;

}GPIO_Typedef;

typedef struct{
	__IO u32 CR;
	__IO u32 CFGR;
	__IO u32 CIR;
	__IO u32 APB2RSTR;
	__IO u32 APB1RSTR;
	__IO u32 AHBENR;
	__IO u32 APB2ENR;
	__IO u32 APB1ENR;
	__IO u32 BDCR;
	__IO u32 CSR;
	__IO u32 AHBSTR;
	__IO u32 CFGR2;
}RCC_Typedef;


#define RCC     ((RCC_Typedef *)RCC_BASE)
#define GPIOA   ((GPIO_Typedef *)GPIOA_BASE)
#define GPIOB   ((GPIO_Typedef *)GPIOB_BASE)
#define GPIOC   ((GPIO_Typedef *)GPIOC_BASE)
#define GPIOD   ((GPIO_Typedef *)GPIOD_BASE)
#define GPIOE   ((GPIO_Typedef *)GPIOE_BASE)
#define GPIOF   ((GPIO_Typedef *)GPIOF_BASE)



#define 	GPIOA_EN			1<<2
#define		GPIOB_EN			1<<3
#define		GPIOC_EN			1<<4
#define		GPIOD_EN			1<<5
#define		GPIOE_EN			1<<6


#endif
