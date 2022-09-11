/**
 * @file HLED_cfg.c
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the pin configuration of LED
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
/*                               LED configurations                                   */
/**************************************************************************************/

LED_PinMap       LED_PINMAP[LED_Number] = 
{
            {PORTC , PIN2},
            {PORTC , PIN3}
};