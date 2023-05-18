/**
 * @file HLED_program.c
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the main logic to control the Led
 * @version 1.0
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/***********************************************************************************/
/*                                Includes                                         */
/***********************************************************************************/
#include "HLED_interface.h"


/**************************************************************************************/
/*                                Important variables                                 */
/**************************************************************************************/
mdioClass_t  gobj_Led1Pin(LED_PINMAP[LED1].LED_PORT , LED_PINMAP[LED1].LED_PIN);
mdioClass_t  gobj_Led2Pin(LED_PINMAP[LED2].LED_PORT , LED_PINMAP[LED2].LED_PIN);


/***********************************************************************************/
/*                                Function Definitions                             */
/***********************************************************************************/
 
hledClass_t::hledClass_t(u8_t au8_LedNumber):au8_prv_LedNumber(au8_LedNumber)
{
    switch(au8_LedNumber)
    {
        case LED1:
            /* set pin direction to ouput */
            gobj_Led1Pin.SetPinDirection(OUTPUT);
            break;

        case LED2:
            /* set pin direction to ouput */
            gobj_Led2Pin.SetPinDirection(OUTPUT);
            break;

        default:
            break;
    }

    return;
}
      

void hledClass_t::LED_On(void)
{
    switch(au8_prv_LedNumber)
    {
        case LED1:
            /* set pin value to HIGH */
            gobj_Led1Pin.SetPinValue(HIGH);
            break;

        case LED2:
            /* set pin value to HIGH */
            gobj_Led2Pin.SetPinValue(HIGH);
            break;

        default:
            break;
    }

    return;
}
      
  
void hledClass_t::LED_Off(void)
{
    switch(au8_prv_LedNumber)
    {
        case LED1:
            /* set pin value to LOW */
            gobj_Led1Pin.SetPinValue(LOW);
            break;

        case LED2:
            /* set pin value to LOW */
            gobj_Led2Pin.SetPinValue(LOW);
            break;

        default:
            break;
    }

    return;
}

void hledClass_t::LED_toggle(void)
{
    switch(au8_prv_LedNumber)
    {
        case LED1:
            /* set pin value to LOW */
            gobj_Led1Pin.TogglePinValue();
            break;

        case LED2:
            /* set pin value to LOW */
            gobj_Led2Pin.TogglePinValue();
            break;

        default:
            break;
    }

    return;   
}