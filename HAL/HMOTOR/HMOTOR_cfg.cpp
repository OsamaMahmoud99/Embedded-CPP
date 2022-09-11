/**
 * @file HMOTOR_cfg.c
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the pin configuration of MOTOR
 * @version 1.0
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/***********************************************************************************/
/*                                Includes                                         */
/***********************************************************************************/
#include "HMOTOR_interface.h"


/**************************************************************************************/
/*                                MOTOR configurations                                */
/**************************************************************************************/

MOTOR_PinMap       MOTOR_PINMAP[MOTOR_Number] = 
{
            {PWM_CHANNEL_1 , PORTB , PIN1 , PORTD , PIN2 , PIN3},         // Channel1 
            {PWM_CHANNEL_2 , PORTB , PIN2 , PORTD , PIN4 , PIN5}          // Channel2
};