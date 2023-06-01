#ifndef GPIO_LIB_H
#define GPIO_LIB_H

#include "STD_TYPES.h"
#include "GPIO_Driver.h"

#define GPIO_PIN_0				((u16)0x0001)
#define GPIO_PIN_1				((u16)0x0002)
#define GPIO_PIN_2				((u16)0x0004)
#define GPIO_PIN_3				((u16)0x0008)
#define GPIO_PIN_4				((u16)0x0010)
#define GPIO_PIN_5				((u16)0x0020)
#define GPIO_PIN_6				((u16)0x0040)
#define GPIO_PIN_7				((u16)0x0080)
#define GPIO_PIN_8				((u16)0x0100)
#define GPIO_PIN_9				((u16)0x0200)
#define GPIO_PIN_10				((u16)0x0400)
#define GPIO_PIN_11				((u16)0x0800)
#define GPIO_PIN_12				((u16)0x1000)
#define GPIO_PIN_13				((u16)0x2000)
#define GPIO_PIN_14				((u16)0x4000)
#define GPIO_PIN_15				((u16)0x8000)
#define GPIO_PIN_ALL			((u16)0xFFFF)


#define		GPIO_MODE_INPUT				0x00U
#define		GPIO_MODE_OUTPUT_PP		    0x01U
#define		GPIO_MODE_AF_PP				0x02U



typedef struct{
	u32 pin;
	u32 mode;
}GPIO_InitTypedef;

typedef enum{
	GPIO_PIN_RESET = 0,
	GPIO_PIN_SET
}GPIO_PinState;


void LIB_GPIO_Init(GPIO_Typedef* GPIOx, GPIO_InitTypedef* GPIO_Init);

GPIO_PinState LIB_GPIO_ReadPin(GPIO_Typedef* GPIOx, u16 GPIO_Pin);

void LIB_GPIO_WritePin(GPIO_Typedef* GPIOx, u16 GPIO_Pin, GPIO_PinState PinState);

void LIB_GPIO_TogglePin(GPIO_Typedef* GPIOx, u16 GPIO_Pin);

void __LIB_RCC_GPIOA_CLK_ENABLE(void);
void __LIB_RCC_GPIOB_CLK_ENABLE(void);
void __LIB_RCC_GPIOC_CLK_ENABLE(void);
void __LIB_RCC_GPIOD_CLK_ENABLE(void);
void __LIB_RCC_GPIOE_CLK_ENABLE(void);

#endif
