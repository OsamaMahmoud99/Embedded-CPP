/**
 * @file HBLTH_interface.h
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the interfacing information for Bluetooth
 * @version 1.0
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* file header guard */
#ifndef _HBLTH_INTERFACE_H_
#define _HBLTH_INTERFACE_H_

/***********************************************************************************/
/*                                Includes                                         */
/***********************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MUART_interface.h"
#include "HBLTH_cfg.h"
#include "HBLTH_private.h"



/***********************************************************************************/
/*                                Interfacing Class                                */
/***********************************************************************************/

class hblthClass_t
{
    public:
          
          /**
           * @brief Construct a new hblthClass object to initialize the TX and RX pins
           * 
           */
          hblthClass_t(void);
          
          /**
           * @brief this function is used to get the data from the bluetooth module without interrupt
           * 
           * @param pu8_bluetoothData 
           */
          void getData(u8_t* pu8_bluetoothData);

          /**
           * @brief this function is used to get the data from the bluetooth module with interrupt
           * 
           * @param pu8_bluetoothData 
           */
          void getData_interrupt(u8_t* pu8_bluetoothData);
};

#endif /*_HBLTH_INTERFACE_H_*/