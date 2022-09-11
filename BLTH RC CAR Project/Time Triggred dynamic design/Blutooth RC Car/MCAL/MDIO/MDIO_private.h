/**
 * @file    MDIO_private.h
 * @author  Osama Mahmoud (you@domain.com)
 * @brief   This file contains private information for Dio module
 * @version 1.0
 * @date    2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* Header file guard */
#ifndef _MDIO_PRIVATE_H
#define _MDIO_PRIVATE_H

/***********************************************************************************/
/*                                DIO Registers                                    */
/***********************************************************************************/

/* PORTB Registers */
#define MDIO_PORTB_ADDRESS             ((u8_t*)(0x38))
#define MDIO_DDRB_ADDRESS              ((u8_t*)(0x37))
#define MDIO_PINB_ADDRESS              ((u8_t*)(0x36))

/* PORTC Registers */
#define MDIO_PORTC_ADDRESS             ((u8_t*)(0x35))
#define MDIO_DDRC_ADDRESS              ((u8_t*)(0x34))
#define MDIO_PINC_ADDRESS              ((u8_t*)(0x33))

/* PORTD Registers */
#define MDIO_PORTD_ADDRESS             ((u8_t*)(0x32))
#define MDIO_DDRD_ADDRESS              ((u8_t*)(0x31))
#define MDIO_PIND_ADDRESS              ((u8_t*)(0x30))


#endif /*_MDIO_PRIVATE_H*/