/**
 * @file HBLTH_program.c
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the main logic to control the Bluetooth
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
#include "LINTERRUPTS.h"
#include "STTS_private.h"
#include "STTS_interface.h"
#include "STTS_cfg.h"

/***********************************************************************************/
/*                                Important variables                              */
/***********************************************************************************/

/*Global array used as a task pool*/
static task_t gst_TaskArr[NUMBER_OF_TASKS];

/*Global variable used to count tasks*/
static u8_t gu8_tasksCounter = 0;

/*Global variable used to count ticks*/
static u32_t gu32_tickCounter = 0;

/***********************************************************************************/
/*                                Important macros                                 */
/***********************************************************************************/

#define ENABLE_CTC_MODE                     (0x08)
#define TICK_TIME_VALUE_CONVERT_FACTOR      (4)
#define TIMER_PRESCALER_1024                (0x07)

#define TASK_TIME                           (0)


/***********************************************************************************/
/*                                Function Definitions                             */
/***********************************************************************************/

static void stts_scheduler(void)
{
    /*local variable used in looping operations*/
    u8_t au8_Taskcounter = 0;

    if(gu8_tasksCounter == NUMBER_OF_TASKS && gst_TaskArr[au8_Taskcounter].State == TASK_READY)
    {
        for(au8_Taskcounter=0; au8_Taskcounter<NUMBER_OF_TASKS; ++au8_Taskcounter)
        {
            /*checking that task time has come or not*/
            if(gu32_tickCounter % gst_TaskArr[au8_Taskcounter].au8_priodicity == TASK_TIME)
            {
                /*Excute the task*/
                gst_TaskArr[au8_Taskcounter].TaskHandler();
            }
            else
            {
                /*Do no thing*/
            }
        }
    }


}

sttsClass_t::sttsClass_t(u8_t au8_systemTickMs)
{
    /*ُEnable CTC Mode in timer2*/
    STTS_TCCR2 = ENABLE_CTC_MODE;
    
    /*Set the tick time value up to 63ms @ 4MHZ and 1024 prescaler (4 = ((1 ms * 1000)us / 256 us))*/
    STTS_OCR2 = au8_systemTickMs * TICK_TIME_VALUE_CONVERT_FACTOR;

    return;

}

    
void sttsClass_t::CreateTask(task_t ast_newTask)
{
    /*Add new Task to the system*/
    gst_TaskArr[gu8_tasksCounter] = ast_newTask;

    /*Increment the tasks counter*/
    gu8_tasksCounter++;

    return;
}

            
void sttsClass_t::schedulerRun(void)
{
    /*Enable global interrupt*/
    ENABLE_INTERRUPTS;

    /*Enable timer2 CTC mode interrupt*/
    SET_BIT(STTS_TIMSK,TIMSK_OCIE2_BIT);

    /*Run timer2 with 256us timer tick*/
    STTS_TCCR2 |= TIMER_PRESCALER_1024;

    return;
}


void SuspendTask(u8_t au8_TaskID)
{
    gst_TaskArr[au8_TaskID].State = TASK_SUSPENDED;

    return;
}
          
       
void ResumeTask(u8_t au8_TaskID)
{
    gst_TaskArr[au8_TaskID].State = TASK_READY;

    return;
}


/***********************************************************************************/
/*                                system tick timer                                */
/***********************************************************************************/

ISR(TIMER2_COMP_VECT)
{
    /*Increment tick counter*/
    gu32_tickCounter++;

    /*Execute system scheduler*/
    stts_scheduler();
}