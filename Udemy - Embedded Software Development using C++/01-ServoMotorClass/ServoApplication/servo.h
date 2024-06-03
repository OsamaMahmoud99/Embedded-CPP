#ifndef SERVO_H
#define SERVO_H

#include "pinmap.h"

enum
{
	
	SERVO_RIGHTPOSITION = 1200,
	SERVO_MIDPOSITION = 2250,
	SERVO_LEFTPOSITION = 3350
	
};
class Servo
{
	private:
		TIM_HandleTypeDef htim;
		uint8_t pwmCh;
		
	public:
		Servo(pinStruct_t& servoPin,
          TIM_TypeDef* TIMx,
					uint8_t gpioAFSelTIMx,
					uint8_t pwmChannel);
		void TurnShaft(uint32_t position);
	
};


#endif