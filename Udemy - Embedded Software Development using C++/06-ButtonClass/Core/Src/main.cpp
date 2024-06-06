#include "Button.h"

uint8_t var = 0;
int main(void)
{

	HAL_Init();
	/* GPIO Ports Clock Enable */
	 __HAL_RCC_GPIOC_CLK_ENABLE();
	 __HAL_RCC_GPIOA_CLK_ENABLE();

	pinStruct_t PC13 = {GPIOC , GPIO_PIN_13};
	static Button onboardButton(PC13);

	while(1)
	{
		if(onboardButton.IsPressed())
		{
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
		}


	}
}
