/**
 * @file HMOTOR_interface.h
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the interfacing information for MOTOR
 * @version 1.0
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* file header guard */
#ifndef _HMOTOR_INTERFACE_H_
#define _HMOTOR_INTERFACE_H_

/***********************************************************************************/
/*                                Includes                                         */
/***********************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MPWM_interface.h"
#include "HMOTOR_cfg.h"
#include "HMOTOR_private.h"

/***********************************************************************************/
/*                                Interfacing Macros                               */
/***********************************************************************************/

/* Motor interfacing channels */
#define MOTOR_CHANNEL_1        (1)
#define MOTOR_CHANNEL_2        (2)

/* Motor directions */
#define MOTOR_MAIN_DIR         (1)
#define MOTOR_OTHER_DIR        (2)
#define MOTOR_STOP             (3)

/***********************************************************************************/
/*                                Interfacing Class                                */
/***********************************************************************************/

class hmotorClass_t
{
    public:
      
      /**
       * @brief Construct a new hmotor Class object to configure the motor pin
       * 
       * @param au8_motorChannel 
       */
      hmotorClass_t(u8_t au8_motorChannel);
      
      /**
       * @brief this function is used to ubdate motor with a specific seed(0 -> 0%, 255 -> 100%) and direction
       * 
       * @param au8_speed 
       * @param au8_direction 
       */
      void UpdateMotor(u8_t au8_speed , u8_t au8_direction);

    private:
      /* private variable used to save the selected motor channel */
      u8_t au8_prv_motorChannel;

};



#endif /*_HMOTOR_INTERFACE_H_*/