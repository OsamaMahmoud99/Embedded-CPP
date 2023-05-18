/**
 * @file HBUZZER_interface.h
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the interfacing information for buzzer
 * @version 1.0
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* file header guard */
#ifndef _HBUZZER_INTERFACE_H_
#define _HBUZZER_INTERFACE_H_

/***********************************************************************************/
/*                                Includes                                         */
/***********************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HBUZZER_cfg.h"
#include "HBUZZER_private.h"



/***********************************************************************************/
/*                                Interfacing Class                                */
/***********************************************************************************/

class hbuzzerClass_t
{
    public:
      
      /**
       * @brief Construct a new hbuzzer Class object to configure the buzzer pin
       * 
       */
      hbuzzerClass_t(void);
      
      /**
       * @brief this function is used to turn on the buzzer
       * 
       */
      void Buzzer_On(void);
      
      /**
       * @brief this function is used to turn off the buzzer
       * 
       */
      void Buzzer_Off(void);
};

#endif /*_HBUZZER_INTERFACE_H_*/