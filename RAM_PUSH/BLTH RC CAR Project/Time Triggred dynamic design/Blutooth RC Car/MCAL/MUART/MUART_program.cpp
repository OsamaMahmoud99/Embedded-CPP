/**
 * @file MUART_program.cpp
 * @author Osama Mahmoud (you@domain.com)
 * @brief 
 * @version 1.0
 * @date 2022-04-16
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
#include "MUART_private.h"
#include "MUART_interface.h"


/**************************************************************************************/
/*                                Important macros                                    */
/**************************************************************************************/

#define ENABLE_TX_RX_OPERATION                 (0x18)
#define ASYNCH_1SB_8BCS_NO_PARITY              (0x86)
#define SHIFTING_BY_8                          (8)
#define NEW_DATA_RECEIVED                      (1)
#define NEW_DATA_TRANSIMITTED                  (1)
#define RESET_FLAG                             (0)


/**************************************************************************************/
/*                                Important variables                                 */
/**************************************************************************************/

/* Global variable used to indicate if the data has transimitted or not */
static volatile u8_t gu8_transFlag = NEW_DATA_TRANSIMITTED;

/* Global variable used to indicate if the data has received or not */
static volatile u8_t gu8_recvFlag = RESET_FLAG;

/* Global variable used to get the received data */
static volatile u8_t gu8_receivedData;


/***********************************************************************************/
/*                                Function Definitions                             */
/***********************************************************************************/

muartClass_t::muartClass_t(u16_t au16_baudRate, u8_t au8_useInterruptOption)
{
    /* Enabling TX and RX Pins */
    MUART_UCSRB = ENABLE_TX_RX_OPERATION;

    /* setting the passed interrupt option */
    MUART_UCSRB |= au8_useInterruptOption;
    
    /* setting the synchronous mode, 1 stop bit, 8 bit character size and no parity bit used */
    MUART_UCSRC = ASYNCH_1SB_8BCS_NO_PARITY;

    /* setting the baud rate value */
    MUART_UBRRH = (u8_t)(au16_baudRate >> SHIFTING_BY_8);
    MUART_UBRRL = (u8_t)(au16_baudRate);
    
    /* Return from this constructor */ 
    return;
}


void muartClass_t::SendByte(u8_t au8_dataByte)
{
    /* checking if the UDR Register is empty or not */
    if(CHECK_BIT(MUART_UCSRA,UCSRA_UDRE_BIT))
    {
        /* setting the data byte to be sent */
        MUART_UDR = au8_dataByte;

        //This flag bit is set when the entire frame in the Transmit Shift Register has been shifted out a
        //there are no new data currently present in the transmit buffer (UDR).
        /* waiting until the data sending is complete */
        while(!CHECK_BIT(MUART_UCSRC,UCSRA_TXC_BIT)); 

        /* clearing the TX complete flag */
        SET_BIT(MUART_UCSRA, UCSRA_TXC_BIT);
    }
    else
    {
        /*Do nothing*/
    }
    
    /*Return from this function*/
    return;
}
    
void muartClass_t::SendStream(u8_t* pu8_dataStream, u8_t au8_dataSize)
{
    while(au8_dataSize--)
    {
          /* checking if the UDR Register is empty or not */
          if(CHECK_BIT(MUART_UCSRA,UCSRA_UDRE_BIT))
          {
             /* setting the data byte to be sent */
             MUART_UDR = *pu8_dataStream;

             //This flag bit is set when the entire frame in the Transmit Shift Register has been shifted out a
             //there are no new data currently present in the transmit buffer (UDR).
             /* waiting until the data sending is complete */
             while(!CHECK_BIT(MUART_UCSRC,UCSRA_TXC_BIT)); 

             /* clearing the TX complete flag */
             SET_BIT(MUART_UCSRA, UCSRA_TXC_BIT);
             
             /* incrementing the data pointer */
             pu8_dataStream++;
            
           }
           else
           {
            /*Do nothing*/
           }
    }

    return;

}

      
void muartClass_t::ReceiveByte(u8_t* pu8_dataByte)
{
    /* checking if there is a data to be received or not */
    if(CHECK_BIT(MUART_UCSRA,UCSRA_RXC_BIT))
    {
        /*Getting the received data byte*/
        *pu8_dataByte = MUART_UDR;
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

void muartClass_t::SendByte_Interrupt(u8_t au8_dataByte)
{
    /*checking if the data is transmitted or not*/
    if(gu8_transFlag == NEW_DATA_TRANSIMITTED)
    {
        /*Resetting the transmit flag*/
        gu8_transFlag = RESET_FLAG;
        
        /*setting the data byte to be sent*/
        MUART_UDR = au8_dataByte;
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

void muartClass_t::ReceiveByte_Interrupt(u8_t* pu8_dataByte)
{
     /*checking if there is a data to be received or not*/
    if(gu8_recvFlag == NEW_DATA_RECEIVED)
    {
        /*Resetting the receive flag*/
        gu8_recvFlag = RESET_FLAG;
        
        /*Getting the received data byte*/
        *pu8_dataByte = gu8_receivedData;
    }
    else
    {
        /*Do nothing*/
    }

    return;

}



/***********************************************************************************/
/*                                   UART ISR                                      */
/***********************************************************************************/

/* TX complete ISR */
ISR(USART_TXC_VECT)
{   
    /*Assuring that the data has been transimitted*/
    gu8_transFlag = NEW_DATA_TRANSIMITTED;
}

/* RX complete ISR */
ISR(USART_RXC_VECT)
{   
    /* Reading the data register */
    gu8_receivedData = MUART_UDR;

    /*Assuring that there is a new data to be received*/
    gu8_recvFlag = NEW_DATA_RECEIVED;
}