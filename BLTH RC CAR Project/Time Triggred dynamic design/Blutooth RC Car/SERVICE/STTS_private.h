/**
 * @file STTS_private.h
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the private information of TTS Module
 * @version 1.0
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*file header guard*/
#ifndef _STTS_PRIVATE_H_
#define _STTS_PRIVATE_H_


/**************************************************************************************/
/*                                TTS used Registers                                  */
/**************************************************************************************/

/*Timer2 Registers*/
#define STTS_TCCR2       (*(volatile u8_t*)(0x45))
#define STTS_TCNT2       (*(volatile u8_t*)(0x44))
#define STTS_OCR2        (*(volatile u8_t*)(0x43))
#define STTS_TIMSK       (*(volatile u8_t*)(0x59))


/**************************************************************************************/
/*                                 Registers Bits                                     */
/**************************************************************************************/

#define TIMSK_OCIE2_BIT         (7)


#endif /*_STTS_PRIVATE_H_*/