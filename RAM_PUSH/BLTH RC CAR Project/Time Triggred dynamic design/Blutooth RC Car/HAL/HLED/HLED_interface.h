/**
 * @file HLED_interface.h
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the interfacing information for LED
 * @version 1.0
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* file header guard */
#ifndef _HLED_INTERFACE_H_
#define _HLED_INTERFACE_H_

/***********************************************************************************/
/*                                Includes                                         */
/***********************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HLED_cfg.h"
#include "HLED_private.h"


/***********************************************************************************/
/*                                Important Macros                                 */
/***********************************************************************************/

#define  LED1            0
#define  LED2            1

/***********************************************************************************/
/*                                Interfacing Class                                */
/***********************************************************************************/

class hledClass_t
{
    public:
      
      /**
       * @brief Construct a new hbuzzer Class object to configure the led pin
       * 
       * @param au8Led_Number 
       */
      hledClass_t(u8_t au8_LedNumber);
      
      /**
       * @brief this function is used to turn on the LED
       * 
       */
      void LED_On(void);
      
      /**
       * @brief this function is used to turn off the LED
       * 
       */
      void LED_Off(void);
       
      /**
       * @brief this function is used to toggle the LED
       * 
       */
      void LED_toggle(void);

    private:

      u8_t au8_prv_LedNumber;
      
};

#endif /*_HLED_INTERFACE_H_*/