#include "hc05.h"



HC05::HC05(pinStruct_t& uartpin,
           USART_TypeDef* USARTx ,
					 uint32_t baudrate,
           uint32_t gpioAFSelUSARTx,
					 uint32_t mode)
{
	
	//GPIO config
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = uartpin.selectedPin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = gpioAFSelUSARTx;
  HAL_GPIO_Init(uartpin.port, &GPIO_InitStruct);
	
	//uart config
	huart.Instance = USARTx;
  huart.Init.BaudRate = baudrate;
  huart.Init.WordLength = UART_WORDLENGTH_8B;
  huart.Init.StopBits = UART_STOPBITS_1;
  huart.Init.Parity = UART_PARITY_NONE;
  huart.Init.Mode = mode;
  huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart);
 

	
}

char HC05::GetChar(void)
{
	// wait for rx buffer to be full then read data
	while((huart.Instance->SR & USART_SR_RXNE) != USART_SR_RXNE);
	return huart.Instance->DR;
	
}