/**
 * @file HBLTH_private.h
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the Bluetooth struct include (PORT , PIN)
 * @version 1.0
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*file header guard*/
#ifndef _HBLTH_PRIVATE_H_
#define _HBLTH_PRIVATE_H_


/**************************************************************************************/
/*                                Bluetooth Struct                                     */
/**************************************************************************************/

typedef struct 
{
    u8_t BLTH_RX_TX_PORT;          //PD
    u8_t BLTH_TX_PIN;              //PD0
    u8_t BLTH_RX_PIN;              //PD1

}BLTH_PinMap;

extern BLTH_PinMap       BLTH_PINMAP[BLTH_Number];



#endif /*_HBLTH_PRIVATE_H_*/