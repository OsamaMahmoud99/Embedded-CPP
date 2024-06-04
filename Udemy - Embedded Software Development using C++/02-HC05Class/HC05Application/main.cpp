#include "hc05.h"

char bluetoothData = '\0';

int main(void)
{
	HAL_Init();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_USART1_CLK_ENABLE();
	
	pinStruct_t uartRxPin = {GPIOA,GPIO_PIN_10};
	static HC05 hc05(uartRxPin,USART1,9600,GPIO_AF7_USART1,UART_MODE_RX);
  while(1)
	{
		bluetoothData = hc05.GetChar();

	}
	
}

extern "C" void SysTick_Handler(void)
{
	HAL_IncTick();
}