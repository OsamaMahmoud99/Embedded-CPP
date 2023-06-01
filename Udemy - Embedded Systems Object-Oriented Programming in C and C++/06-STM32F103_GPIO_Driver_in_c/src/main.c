
#include "STD_TYPES.h"
#include "GPIO_Lib.h"

GPIO_InitTypedef my_GPIO_InitStruct;
int main()
{
	__LIB_RCC_GPIOA_CLK_ENABLE();

	my_GPIO_InitStruct.mode = GPIO_MODE_OUTPUT_PP;
	my_GPIO_InitStruct.pin = GPIO_PIN_0;

	LIB_GPIO_Init(GPIOA, &my_GPIO_InitStruct);

	while(1)
	{
		for(int i =0;i< 900000;i++){
			LIB_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
		}
	}

}
