/**
 * @file HMOTOR_program.c
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the main logic to control the MOTOR
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
/*                                Important Macros                                    */
/**************************************************************************************/

#define NO_DUTY_CYCLE            (0)

/**************************************************************************************/
/*                                Important variables                                 */
/**************************************************************************************/

/* Global objects used to define PWMchannel pins */
mpwmClass_t gobj_Motor1_PWMChannel1(MOTOR_PINMAP[0].MOTOR_PWM_Channel);
mpwmClass_t gobj_Motor2_PWMChannel2(MOTOR_PINMAP[1].MOTOR_PWM_Channel);

/* Global objects used to define PWM_EN pins */
mdioClass_t gobj_Motor1_PWM_EN1Pin(MOTOR_PINMAP[0].MOTOR_PWM_PORT,MOTOR_PINMAP[0].MOTOR_PWM_PIN);
mdioClass_t gobj_Motor2_PWM_EN2Pin(MOTOR_PINMAP[1].MOTOR_PWM_PORT,MOTOR_PINMAP[1].MOTOR_PWM_PIN);

/* Global objects used to define direction pins */
mdioClass_t gobj_Motor1_DIR_IN1Pin(MOTOR_PINMAP[0].MOTOR_DIR_PORT , MOTOR_PINMAP[0].MOTOR_DIR_IN1);
mdioClass_t gobj_Motor1_DIR_IN2Pin(MOTOR_PINMAP[0].MOTOR_DIR_PORT , MOTOR_PINMAP[0].MOTOR_DIR_IN2);
mdioClass_t gobj_Motor2_DIR_IN3Pin(MOTOR_PINMAP[1].MOTOR_DIR_PORT , MOTOR_PINMAP[1].MOTOR_DIR_IN1);
mdioClass_t gobj_Motor2_DIR_IN4Pin(MOTOR_PINMAP[1].MOTOR_DIR_PORT , MOTOR_PINMAP[1].MOTOR_DIR_IN2);

/***********************************************************************************/
/*                                Function Definitions                             */
/***********************************************************************************/



hmotorClass_t::hmotorClass_t(u8_t au8_motorChannel):au8_prv_motorChannel(au8_motorChannel)
{
    switch(au8_motorChannel)
    {
        case MOTOR_CHANNEL_1:
             
             /* Motor 1 pins configuration as output */
             gobj_Motor1_PWM_EN1Pin.SetPinDirection(OUTPUT);
             gobj_Motor1_DIR_IN1Pin.SetPinDirection(OUTPUT);
             gobj_Motor1_DIR_IN2Pin.SetPinDirection(OUTPUT);
             
             /* setting pwm for motor1 with freq=2KHZ and speed=0 */ 
             gobj_Motor1_PWMChannel1.updatepwm(PWM_2KHZ , NO_DUTY_CYCLE);

             break;

        case MOTOR_CHANNEL_2:

             /* Motor 2 pins configuration as output */
             gobj_Motor2_PWM_EN2Pin.SetPinDirection(OUTPUT);
             gobj_Motor2_DIR_IN3Pin.SetPinDirection(OUTPUT);
             gobj_Motor2_DIR_IN4Pin.SetPinDirection(OUTPUT);

             
             /* setting pwm for motor2 with freq=2KHZ and speed=0 */ 
             gobj_Motor2_PWMChannel2.updatepwm(PWM_2KHZ , NO_DUTY_CYCLE);

             break;

        default:
             break;
    }

    return;
}
      
 

void hmotorClass_t::UpdateMotor(u8_t au8_speed , u8_t au8_direction)
{
    switch(au8_prv_motorChannel)
    {
        case MOTOR_CHANNEL_1:
             
             switch(au8_direction)
             {
                 case MOTOR_MAIN_DIR:
                      /* Motor 1 main direction */
                      gobj_Motor1_DIR_IN1Pin.SetPinValue(HIGH);
                      gobj_Motor1_DIR_IN2Pin.SetPinValue(LOW);
                      break;

                case MOTOR_OTHER_DIR:
                     /* Motor 1 other direction */
                     gobj_Motor1_DIR_IN1Pin.SetPinValue(LOW);
                     gobj_Motor1_DIR_IN2Pin.SetPinValue(HIGH);
                     break;

                case MOTOR_STOP:
                     /* Motor 1 Stop */
                     gobj_Motor1_DIR_IN1Pin.SetPinValue(LOW);
                     gobj_Motor1_DIR_IN2Pin.SetPinValue(LOW);
                     break;

                default:
                     
                     break;
             }
             /* setting pwm for motor1 with freq=2KHZ and speed=au8_speed */ 
             gobj_Motor1_PWMChannel1.updatepwm(PWM_2KHZ , au8_speed);

             break;

        case MOTOR_CHANNEL_2:
             
             switch(au8_direction)
             {
                 case MOTOR_MAIN_DIR:
                      /* Motor 2 main direction */
                      gobj_Motor2_DIR_IN3Pin.SetPinValue(HIGH);
                      gobj_Motor2_DIR_IN4Pin.SetPinValue(LOW);
                      break;

                case MOTOR_OTHER_DIR:
                     /* Motor 2 other direction */
                     gobj_Motor2_DIR_IN3Pin.SetPinValue(LOW);
                     gobj_Motor2_DIR_IN4Pin.SetPinValue(HIGH);
                     break;

                case MOTOR_STOP:
                     /* Motor 1 Stop */
                     gobj_Motor2_DIR_IN3Pin.SetPinValue(LOW);
                     gobj_Motor2_DIR_IN4Pin.SetPinValue(LOW);
                     break;

                default:
                     
                     break;
             }
             /* setting pwm for motor2 with freq=2KHZ and speed= au8_speed */ 
             gobj_Motor2_PWMChannel2.updatepwm(PWM_2KHZ , au8_speed);

             break;

        default:
             break;
    }

    return;

}