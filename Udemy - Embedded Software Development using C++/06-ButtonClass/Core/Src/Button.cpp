/*
 * Button.cpp
 *
 *  Created on: Jun 5, 2024
 *      Author: Osama
 */

#include "Button.h"

bool Button::IsDebounced(void)
{
	if(HAL_GPIO_ReadPin(pinStruct.port, pinStruct.selectedPin) == GPIO_PIN_RESET)
	{
		HAL_Delay(10);
		if(HAL_GPIO_ReadPin(pinStruct.port, pinStruct.selectedPin) == GPIO_PIN_RESET)
		{
			return true;
		}
	}
	return false;

}

bool Button::IsPressed(void)
{
	if(Button::IsDebounced() && !prevPressed)
	{
		prevPressed = true;
		return true;
	}
	else if(!Button::IsDebounced() && prevPressed)
	{
		prevPressed = false;
	}
	return false;
}
Button::Button(pinStruct_t& gpioPinStruct)
{
	  GPIO_InitTypeDef GPIO_InitStruct = {0};
	  pinStruct = gpioPinStruct;
	  prevPressed = false;
	  /*Configure GPIO pin : PC13 */
	  GPIO_InitStruct.Pin = pinStruct.selectedPin;
	  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	  GPIO_InitStruct.Pull = GPIO_PULLUP;
	  HAL_GPIO_Init(pinStruct.port, &GPIO_InitStruct);

	  /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET);

	  /*Configure GPIO pin : PA13 */
	  GPIO_InitStruct.Pin = GPIO_PIN_13;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}
