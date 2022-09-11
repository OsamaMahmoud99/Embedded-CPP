/**
 * @file HBUZZER_program.c
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the main logic to control the buzzer
 * @version 1.0
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/***********************************************************************************/
/*                                Includes                                         */
/***********************************************************************************/
#include "HBUZZER_interface.h"


/**************************************************************************************/
/*                                Important variables                                 */
/**************************************************************************************/
mdioClass_t  gobj_buzzerPin(BUZZER_PINMAP[0].BUZZER_PORT , BUZZER_PINMAP[0].BUZZER_PIN);



/***********************************************************************************/
/*                                Function Definitions                             */
/***********************************************************************************/
 
hbuzzerClass_t::hbuzzerClass_t(void)
{
    /* set pin direction to ouput */
    gobj_buzzerPin.SetPinDirection(OUTPUT);

    return;
}
      

void hbuzzerClass_t::Buzzer_On(void)
{
     /* set pin value to HIGH */
    gobj_buzzerPin.SetPinValue(HIGH);

    return;
}
      
  
void hbuzzerClass_t::Buzzer_Off(void)
{
    /* set pin value to LOW */
    gobj_buzzerPin.SetPinValue(LOW);

    return;
}