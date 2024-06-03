#include "servo.h"


Servo::Servo(pinStruct_t& servoPin,
             TIM_TypeDef* TIMx,
						 uint8_t gpioAFSelTIMx,
						 uint8_t pwmChannel)
{
		pwmCh = pwmChannel;
		GPIO_InitTypeDef GPIO_InitStruct = {0};
	    /**TIM4 GPIO Configuration
    PB8     ------> TIM4_CH3
    */
    GPIO_InitStruct.Pin = servoPin.selectedPin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = gpioAFSelTIMx;
    HAL_GPIO_Init(servoPin.port, &GPIO_InitStruct);
	
	  TIM_MasterConfigTypeDef sMasterConfig = {0};
		TIM_OC_InitTypeDef sConfigOC = {0};

		
		htim.Instance = TIMx;
		htim.Init.Prescaler = 10 - 1;
		htim.Init.CounterMode = TIM_COUNTERMODE_UP;
		htim.Init.Period = 32000 - 1;
		htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
		htim.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
		HAL_TIM_PWM_Init(&htim);
	

		sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
		sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
		HAL_TIMEx_MasterConfigSynchronization(&htim, &sMasterConfig);
	
		sConfigOC.OCMode = TIM_OCMODE_PWM1;
		sConfigOC.Pulse = SERVO_MIDPOSITION;
		sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
		sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
		HAL_TIM_PWM_ConfigChannel(&htim, &sConfigOC, pwmChannel);
		
		HAL_TIM_PWM_Start(&htim , pwmChannel);
		
}

void Servo::TurnShaft(uint32_t position)
{
	__HAL_TIM_SET_COMPARE(&htim , pwmCh, position);
}