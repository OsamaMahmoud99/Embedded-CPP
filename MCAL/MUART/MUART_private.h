/**
 * @file MUART_private.h
 * @author Osama Mahmoud (you@domain.com)
 * @brief 
 * @version 1.0
 * @date 2022-04-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* file header guard */
#ifndef _MUART_PRIVATE_H
#define _MUART_PRIVATE_H


/***********************************************************************************/
/*                                UART Registers                                   */
/***********************************************************************************/

#define MUART_UDR                 (*(volatile u8_t*)(0x2C))
#define MUART_UCSRA               (*(volatile u8_t*)(0x2B))
#define MUART_UCSRB               (*(volatile u8_t*)(0x2A))
#define MUART_UCSRC               (*(volatile u8_t*)(0x40))
#define MUART_UBRRL               (*(volatile u8_t*)(0x29))
#define MUART_UBRRH               (*(volatile u8_t*)(0x40))

/***********************************************************************************/
/*                                Important Registers bits                         */
/***********************************************************************************/

#define UCSRA_RXC_BIT             (7)
#define UCSRA_TXC_BIT             (6)
#define UCSRA_UDRE_BIT            (5)


#endif /*_MUART_PRIVATE_H*/