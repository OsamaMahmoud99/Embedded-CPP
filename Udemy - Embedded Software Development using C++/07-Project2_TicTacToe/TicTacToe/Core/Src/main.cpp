#include "game.h"

int main(void)
{
	HAL_Init();
	  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();	
	
	pinStruct_t rowPins[NUMBER_OF_ROWS] =
	{
		{GPIOC,GPIO_PIN_6},
		{GPIOA,GPIO_PIN_6},
		{GPIOA,GPIO_PIN_7},
		{GPIOB,GPIO_PIN_6}
	};
	pinStruct_t columnPins[NUMBER_OF_COLUMNS] =
	{
		{GPIOA,GPIO_PIN_0},
		{GPIOA,GPIO_PIN_1},
		{GPIOA,GPIO_PIN_4},
		{GPIOB,GPIO_PIN_0}			
	};
	
	pinStruct_t rs = {GPIOC,GPIO_PIN_0};
	pinStruct_t en = {GPIOC,GPIO_PIN_1};
	pinStruct_t d4 = {GPIOC,GPIO_PIN_2};
	pinStruct_t d5 = {GPIOC,GPIO_PIN_3};
	pinStruct_t d6 = {GPIOC,GPIO_PIN_4};
	pinStruct_t d7 = {GPIOC,GPIO_PIN_5};
	
	static Keypad keypad(rowPins,columnPins);
	static LCD lcd(rs,en,d4,d5,d6,d7);
	
	//Game startup
	Game_DisplayIntro(lcd);
	HAL_Delay(1500);
	Game_DisplayMenu(lcd);
	
	while(1)
	{
		char pressedKey = keypad.GetCharShortPress();
		
		switch(pressedKey)
		{
			case 'A':
				Game_Start(lcd,keypad);
				break;
			case 'B':
				Game_DisplayMenu(lcd);
				break;
			case '=':
				Game_DisplayRules(lcd);
				break;
		}
	}
}	

extern "C" void SysTick_Handler(void)
{
  HAL_IncTick();
}

