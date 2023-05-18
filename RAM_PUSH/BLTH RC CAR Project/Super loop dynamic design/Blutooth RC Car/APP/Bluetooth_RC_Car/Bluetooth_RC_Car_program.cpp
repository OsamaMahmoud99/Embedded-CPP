/**
 * @file Bluetooth_RC_Car_program.c
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the main logic to control the Bluetooth RC Car Application
 * @version 1.0
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/***********************************************************************************/
/*                                Includes                                         */
/***********************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HBLTH_interface.h"
#include "HLED_interface.h"
#include "HBUZZER_interface.h"
#include "HMOTOR_interface.h"
#include "Bluetooth_RC_Car_cfg.h"
#include "Bluetooth_RC_Car_interface.h"




/***********************************************************************************/
/*                               Important Macros                                  */
/***********************************************************************************/

/* speed section value  = ((.9*255)/10) */
#define SPEED_SECTION_VALUE           (23)

/* Max speed at duty cycle equal 255 */
#define MAX_MOTOR_SPEED               (255)

/***********************************************************************************/
/*                          Important Class objects  and variables                 */
/***********************************************************************************/

/* global object to get the command from bluetooth module */
hblthClass_t gobj_bluetoothcommunication;

/* global object to control the buzzer*/
hbuzzerClass_t gobj_buzzer;

/* global object to control the Leds */
hledClass_t gobj_frontLeds(FRONT_LED);
hledClass_t gobj_rearLeds(REAR_LED);

/* global object to control the Motors */
hmotorClass_t gobj_rightMotor(RIGHT_MOTOR);
hmotorClass_t gobj_leftMotor(LEFT_MOTOR);

/* global variable used to hold the bluetooth command data received */
static u8_t gu8_blthData;


/***********************************************************************************/
/*                                Functions Definitions                            */
/***********************************************************************************/


void system_init(void)
{
    return;
}


void system_getInput(void)
{
    /* Getting the bluetooth Data */
    gobj_bluetoothcommunication.getData(&gu8_blthData);

    /* Return from this function */
    return;
}


void system_processing_update(void)
{
    /* Local static variable used to hold the speed of motor */
    static u8_t au8_motorSpeed = 0;

    switch(gu8_blthData)
    {
        case FORWARD_CMD:
             gobj_rightMotor.UpdateMotor(au8_motorSpeed , MOTOR_MAIN_DIR);
             gobj_leftMotor.UpdateMotor(au8_motorSpeed , MOTOR_MAIN_DIR);
             break;

        case BACKWARD_CMD:
             gobj_rightMotor.UpdateMotor(au8_motorSpeed , MOTOR_OTHER_DIR);
             gobj_leftMotor.UpdateMotor(au8_motorSpeed , MOTOR_OTHER_DIR);
             break;

        case LEFT_CMD:
             gobj_rightMotor.UpdateMotor(au8_motorSpeed , MOTOR_MAIN_DIR);
             gobj_leftMotor.UpdateMotor(au8_motorSpeed , MOTOR_STOP);
             break;

        case RIGHT_CMD:
             gobj_rightMotor.UpdateMotor(au8_motorSpeed , MOTOR_STOP);
             gobj_leftMotor.UpdateMotor(au8_motorSpeed , MOTOR_MAIN_DIR);
             break;

        case STOP_CMD:
             gobj_rightMotor.UpdateMotor(au8_motorSpeed , MOTOR_STOP);
             gobj_leftMotor.UpdateMotor(au8_motorSpeed , MOTOR_STOP);
             break;

        case FRONTLIGHTS_ON_CMD:
             gobj_frontLeds.LED_On();
             break;

        case FRONTLIGHTS_OFF_CMD:
             gobj_frontLeds.LED_Off();
             break;

        case REARLIGHTS_ON_CMD:
             gobj_rearLeds.LED_On();
             break;

        case REARLIGHTS_OFF_CMD:
             gobj_rearLeds.LED_Off();
             break;

        case HORN_ON_CMD:
             gobj_buzzer.Buzzer_On();
             break;

        case HORN_OFF_CMD:
             gobj_buzzer.Buzzer_Off();
             break;

        case HAZARD_ON_CMD:
             
			 /* it will be handled in time triggered design*/
             break;

        case HAZARD_OFF_CMD:
             
             break;

        case SPEED_0_CMD...SPEED_90_CMD:
             au8_motorSpeed = (gu8_blthData-'0') * SPEED_SECTION_VALUE;
             break;

        case SPEED_100_CMD:
             au8_motorSpeed = MAX_MOTOR_SPEED;
             break;

        default:
             break;

    }

    /*Reset bluetooth data*/
    gu8_blthData = 0;

    return;
}