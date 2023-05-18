/**
 * @file HBLTH_program.c
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the main logic to control the Bluetooth
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
/*                                Important variables                                 */
/**************************************************************************************/

/* Global dio object is used to define the TX and RX pins */
mdioClass_t  gobj_blthTXPin(BLTH_PINMAP[0].BLTH_RX_TX_PORT , BLTH_PINMAP[0].BLTH_TX_PIN);
mdioClass_t  gobj_blthRXPin(BLTH_PINMAP[0].BLTH_RX_TX_PORT , BLTH_PINMAP[0].BLTH_RX_PIN);

/* Gloabal uart object is used to get the data from bluetooth module */
muartClass_t gobj_blthData_Nointerrupt(BAUD_9600 , NO_INTERRUPTS_USED);
muartClass_t gobj_blthData_interrupt(BAUD_9600 , USE_RX_INTERRUPT_ONLY);


/***********************************************************************************/
/*                                Function Definitions                             */
/***********************************************************************************/


hblthClass_t::hblthClass_t(void)
{
    /* set the RX pin for micro as input_float */
    gobj_blthTXPin.SetPinDirection(INPUT_FLOAT);

    /* set the TX pin for micro as output */
    gobj_blthRXPin.SetPinDirection(OUTPUT);

    /* return from constuctor */
    return;
}
          
      
void hblthClass_t::getData(u8_t* pu8_bluetoothData)
{
    /*Receive byte from bluetooth module*/
    gobj_blthData_Nointerrupt.ReceiveByte(pu8_bluetoothData);
    
    /*Return from this function*/
    return;
}

         
void hblthClass_t::getData_interrupt(u8_t* pu8_bluetoothData)
{
    
    /*Receive byte from bluetooth module (interrupt)*/
    gobj_blthData_interrupt.ReceiveByte_Interrupt(pu8_bluetoothData);

    /*Return from this function*/
    return;
}