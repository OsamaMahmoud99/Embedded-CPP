/**
 * @file MUART_interface.h
 * @author Osama Mahmoud (you@domain.com)
 * @brief 
 * @version 1.0
 * @date 2022-04-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* header file guard */
#ifndef _MUART_INTERFACE_H
#define _MUART_INTERFACE_H


/***********************************************************************************/
/*                                Interfacing macros                               */
/***********************************************************************************/

/* baud rate at f=4MHZ */
#define  BAUD_2400       (103)
#define  BAUD_4800       (51)
#define  BAUD_9600       (25)
#define  BAUD_14400      (16)
#define  BAUD_19200      (12)
#define  BAUD_28800      (8)

/* interrupt options */
#define  NO_INTERRUPTS_USED         (0x00)
#define  USE_TX_INTERRUPT_ONLY      (0x40)
#define  USE_RX_INTERRUPT_ONLY      (0x80)
#define  USE_TX_RX_INTERRUPTS       (0xC0)


/***********************************************************************************/
/*                                UART Class                                       */
/***********************************************************************************/

class muartClass_t
{
    public:
        
        /**
         * @brief Construct a new UART object with a specific baudrate and with/without using interrrupts
         * 
         * @param au16_baudRate 
         * @param au8_useInterruptOption 
         */
        muartClass_t(u16_t au16_baudRate, u8_t au8_useInterruptOption);

        /**
         * @brief This function is used to send one byte of data over uart protocol
         * 
         * @param au8_dataByte 
         */
        void SendByte(u8_t au8_dataByte);
        
        /**
         * @brief This function is used to send stream of data bytes with certain size over uart protocol
         * 
         * @param pu8_dataStream 
         * @param au8_dataSize 
         */
        void SendStream(u8_t* pu8_dataStream, u8_t au8_dataSize);

        /**
         * @brief This function is used to receive on data byte over uart protocol
         * @param pu8_dataByte 
         */
        void ReceiveByte(u8_t* pu8_dataByte);

        /**
         * @brief This function is used to send one byte of data over uart protocol by using TX interrupt
         * 
         * @param au8_dataByte 
         */
        void SendByte_Interrupt(u8_t au8_dataByte);

        /**
         * @brief This function is used to receive on data byte over uart protocol by using RX interrupt
         * 
         * @param pu8_dataByte 
         */
        void ReceiveByte_Interrupt(u8_t* pu8_dataByte);

};




#endif /*_MUART_INTERFACE_H*/