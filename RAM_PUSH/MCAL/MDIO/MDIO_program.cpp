/**
 * @file    MDIO_program.cpp
 * @author  Osama Mahmoud (you@domain.com)
 * @brief   This file contains the main logic for Dio module
 * @version 1.0
 * @date    2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/***********************************************************************************/
/*                                Includes                                         */
/***********************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"

/**************************************************************************************/
/*                                Important macros                                    */
/**************************************************************************************/

#define PORTS_NUMBER    (3)

/**************************************************************************************/
/*                                Important variables                                 */
/**************************************************************************************/

/*Global arrays used to carry ports [B - C - D] registers*/
u8_t* gu8Arr_ddrArray[PORTS_NUMBER] = {MDIO_DDRB_ADDRESS, MDIO_DDRC_ADDRESS, MDIO_DDRD_ADDRESS};
u8_t* gu8Arr_portArray[PORTS_NUMBER] = {MDIO_PORTB_ADDRESS, MDIO_PORTC_ADDRESS, MDIO_PORTD_ADDRESS};
u8_t* gu8Arr_pinArray[PORTS_NUMBER] = {MDIO_PINB_ADDRESS, MDIO_PINC_ADDRESS, MDIO_PIND_ADDRESS};

/***********************************************************************************/
/*                                Function Definitions                             */
/***********************************************************************************/

void mdioClass_t::SetPinDirection(u8_t au8_pinDirection)
{
    switch (au8_pinDirection)
    {
    case OUTPUT:
        /* setting the Dio pin to output */
        SET_BIT(*gu8Arr_ddrArray[au8_prv_dioport], au8_prv_diopin);

        break;

    case INPUT_FLOAT:
        /* setting the Dio pin to input floating */
        CLEAR_BIT(*gu8Arr_ddrArray[au8_prv_dioport], au8_prv_diopin);

        break;

    case INPUT_PULLUP:
        /* setting the Dio pin to input floating */
        CLEAR_BIT(*gu8Arr_ddrArray[au8_prv_dioport], au8_prv_diopin);

        /* Enabling the pullup resistor */
        SET_BIT(*gu8Arr_portArray[au8_prv_dioport], au8_prv_diopin);

        break;

    
    default:
        break;
    }

    return;

}            
          
void mdioClass_t::SetPinValue(u8_t au8_pinValue)
{
    switch (au8_pinValue)
    {
    case HIGH:
        /* setting the Dio pin to HIGH */
        SET_BIT(*gu8Arr_portArray[au8_prv_dioport], au8_prv_diopin);

        break;

    case LOW:
        /* setting the Dio pin to LOW */
        CLEAR_BIT(*gu8Arr_portArray[au8_prv_dioport], au8_prv_diopin);

        break;
    
    default:
        break;
    }

    return;

} 

void mdioClass_t::TogglePinValue(void)
{
    TOGGLE_BIT(*gu8Arr_portArray[au8_prv_dioport], au8_prv_diopin);

    return;
} 
                   
void mdioClass_t::GetPinValue(u8_t* pu8_pinValue)
{
    if (CHECK_BIT(*gu8Arr_pinArray[au8_prv_dioport], au8_prv_diopin))
    {
        *pu8_pinValue = HIGH;
    }
    else
    {
        *pu8_pinValue = LOW;
    }
    
    return;
}