/**
 * @file HBLTH_cfg.c
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the pin configuration of bluetooth
 * @version 1.0
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/***********************************************************************************/
/*                                Includes                                         */
/***********************************************************************************/
#include "HBLTH_interface.h"


/**************************************************************************************/
/*                                Buzzer configurations                               */
/**************************************************************************************/

BLTH_PinMap       BLTH_PINMAP[BLTH_Number] = 
{
            {PORTD , PIN0 , PIN1}
};