#include "hc05.h"
#include "servo.h"

char bluetoothData = '\0';

int main(void)
{
	HAL_Init();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_USART1_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_TIM4_CLK_ENABLE();
	
	pinStruct_t servoPin = {GPIOB,GPIO_PIN_8};
	static Servo servo(servoPin,TIM4,GPIO_AF2_TIM4,TIM_CHANNEL_3);
	
	pinStruct_t uartRxPin = {GPIOA,GPIO_PIN_10};
	static HC05 hc05(uartRxPin,USART1,9600,GPIO_AF7_USART1,UART_MODE_RX);
  while(1)
	{
		bluetoothData = hc05.GetChar();
		
		switch(bluetoothData)
		{
			case 'l':
			case 'L':
				servo.TurnShaft(SERVO_LEFTPOSITION);
				break;
			case 'm':
			case 'M':
				servo.TurnShaft(SERVO_MIDPOSITION);
				break;
			case 'r':
			case 'R':
				servo.TurnShaft(SERVO_RIGHTPOSITION);
				break;
		}

	}
	
}

extern "C" void SysTick_Handler(void)
{
	HAL_IncTick();
}