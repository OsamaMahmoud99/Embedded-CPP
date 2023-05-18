/**
 * @file HLED_private.h
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the LED struct includes the (PORT , PIN)
 * @version 1.0
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*file header guard*/
#ifndef _HLED_PRIVATE_H_
#define _HLED_PRIVATE_H_


/**************************************************************************************/
/*                                LED Struct                                          */
/**************************************************************************************/

typedef struct 
{
    u8_t LED_PORT;
    u8_t LED_PIN;

}LED_PinMap;

extern LED_PinMap       LED_PINMAP[LED_Number];


#endif /*_HLED_PRIVATE_H_*/