/**
 * @file    MDIO_interface.h
 * @author  Osama Mahmoud (you@domain.com)
 * @brief   This file contains interfacing information for Dio module
 * @version 1.0
 * @date    2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* Header file guard */
#ifndef _MDIO_INTERFACE_H
#define _MDIO_INTERFACE_H


/***********************************************************************************/
/*                                Interfacing macros                               */
/***********************************************************************************/

/* Dio Ports */
#define PORTB           (0)
#define PORTC           (1)
#define PORTD           (2)

/* Dio Pins */
#define PIN0            (0)
#define PIN1            (1)
#define PIN2            (2)
#define PIN3            (3)
#define PIN4            (4)
#define PIN5            (5)
#define PIN6            (6)
#define PIN7            (7)

/* Dio Pin status */
#define OUTPUT          (0)
#define INPUT_FLOAT     (1)
#define INPUT_PULLUP    (2)

/*Dio Pin Value */
#define LOW             (0)
#define HIGH            (1)

/***********************************************************************************/
/*                                DIO Class                                        */
/***********************************************************************************/

class mdioClass_t
{
    public:
      
           /**
            * @brief DIO Class constructor that will be called after creating an object from the class
            * 
            * @param au8_dioport 
            * @param au8_diopin 
            */
           mdioClass_t(u8_t au8_dioport, u8_t au8_diopin)
           {
               au8_prv_dioport = au8_dioport;
               au8_prv_diopin  = au8_diopin; 
           }
           
           /**
            * @brief This function is used to set the chosen Dio pin direction [OUTPUT - INPUT_Float - INPUT_PULLUP]
            * 
            * @param au8_pinDirection 
            */
           void SetPinDirection(u8_t au8_pinDirection); 
           
           /**
            * @brief This function is used to set Dio pin value [High - Low]
            * 
            * @param au8_pinValue 
            */
           void SetPinValue(u8_t au8_pinValue); 
           
           /**
            * @brief This function is used to toggle Dio pin value [High - Low]
            * 
            */
           void TogglePinValue(void); 
           
           /**
            * @brief This function is used to get Dio pin value [High - Low]
            * 
            * @param pu8_pinValue 
            */
           void GetPinValue(u8_t* pu8_pinValue);

    private:
           
           /* private local variable used to carry Dio Port */
           u8_t au8_prv_dioport;

           /* private local variable used to carry Dio Pin  */
           u8_t au8_prv_diopin;


};



#endif /*_MDIO_INTERFACE_H*/