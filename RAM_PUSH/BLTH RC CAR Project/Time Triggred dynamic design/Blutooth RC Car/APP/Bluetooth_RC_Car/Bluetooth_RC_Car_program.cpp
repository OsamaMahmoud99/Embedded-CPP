/**
 * @file Bluetooth_RC_Car_program.c
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the main logic to control the Bluetooth RC Car Application
 * @version 1.0
 * @date 2022-04-22
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
#include "STTS_interface.h"
#include "Bluetooth_RC_Car_private.h"
#include "Bluetooth_RC_Car_interface.h"
#include "Bluetooth_RC_Car_cfg.h"





/***********************************************************************************/
/*                               Important Macros                                  */
/***********************************************************************************/

/* speed section value  = ((.9*255)/10) */
#define SPEED_SECTION_VALUE           (23)

/* Max speed at duty cycle equal 255 */
#define MAX_MOTOR_SPEED               (255)

#define HAZARD_STATUS_ON              (1)
#define HAZARD_STATUS_OFF             (2)

/* update task come each 50ms then if i want to toggle led each 1s. Timing=1000ms/50ms = 20 */
#define HAZARD_TIMING                 (20)


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

/* global object to control the time triggered system */
sttsClass_t gobj_tts(SYSTEM_TICK_TIME);

/* global variable used to hold the bluetooth command data received */
static u8_t gu8_blthData;

/* global variable used to hold the hazard enable status */
static u8_t gu8_hazardStatus;

/* global variable used to hold the hazard timer counter */
static u8_t gu8_hazardTimerCounter;

/***********************************************************************************/
/*                                Functions Definitions                            */
/***********************************************************************************/


void system_init(void)
{

    /*selecting sleep mode*/ 
    SELECT_SLEEP_MODE(IDLE_MODE); 

    return;
}


static void system_getInput(void)
{
    /* Getting the bluetooth Data */
    gobj_bluetoothcommunication.getData_interrupt(&gu8_blthData);

    /* Return from this function */
    return;
}


static void system_processing_update(void)
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
             
             gu8_hazardStatus = HAZARD_STATUS_ON;
             break;

        case HAZARD_OFF_CMD:
             
             gu8_hazardStatus = HAZARD_STATUS_OFF;
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

    if (gu8_hazardStatus == HAZARD_STATUS_ON)
    {
         gu8_hazardTimerCounter++;

         if(gu8_hazardTimerCounter >= HAZARD_TIMING)
         {
              gobj_rearLeds.LED_toggle();
              gu8_hazardTimerCounter = 0;
         }
         else
         {
              /* Do nothing */
         }
    }
    else if(gu8_hazardStatus == HAZARD_STATUS_OFF)
    {
         gobj_rearLeds.LED_Off();
         gu8_hazardTimerCounter = 0;
         gu8_hazardStatus = 0;
    }
    else
    {
         /* Do no thing */
    }
    

    /*Reset bluetooth data*/
    gu8_blthData = 0;
    

    return;
}

void system_run(void)
{
     /* static Local variables used to hold the system tasks */
      static task_t str_Task1 = {system_getInput , TASK1_PRIODICITY , TASK_READY};
      static task_t str_Task2 = {system_processing_update , TASK2_PRIODICITY , TASK_READY};
      
      /*high priority task*/
      gobj_tts.CreateTask(str_Task1);

      /*low priority task*/
      gobj_tts.CreateTask(str_Task2);
      
      /*Run scheduler*/
      gobj_tts.schedulerRun();

     /* Enable WDT with 65ms time to reset */
      WDT_ENABLE(RESET_65_0_MS);

      /*system infinite loop*/
      while(1)
      {
         /*Refresh WDT*/
         WDT_REFRESH();
         
        // gobj_frontLeds.LED_toggle(); // for test sleep mode
        /*sending the mcu to  sleep mode*/
         MCU_GTS();

      }

      return;
}