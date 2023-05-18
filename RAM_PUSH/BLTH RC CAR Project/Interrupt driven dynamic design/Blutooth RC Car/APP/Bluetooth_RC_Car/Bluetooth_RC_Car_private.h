/**
 * @file Bluetooth_RC_Car_private.h
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains a private information for bluetooth rc car module
 * @version 1.0
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*file header guard*/
#ifndef _BLTH_RC_CAR_PRIVATE_H_
#define _BLTH_RC_CAR_PRIVATE_H_


/***********************************************************************************/
/*                                   Important macros                              */
/***********************************************************************************/

//Bits 6..4 – SM2..0: Sleep Mode Select Bits 2, 1, and 0
#define IDLE_MODE                (0)
#define ADC_NOISE_REDUCTION      (1)
#define POWER_DOWN_MODE          (2)
#define POWER_SAVE_MODE          (3)
#define STAND_BY_MODE            (6)


/***********************************************************************************/
/*                                   control registers                             */
/***********************************************************************************/

#define MCUCR            (*(u8_t*)(0x55))

/*Sleep enable bit*/
#define SE               (7)                    


/***********************************************************************************/
/*                              Operations on control registers                    */
/***********************************************************************************/

#define SELECT_SLEEP_MODE(mode)                  MCUCR |= ((1<<SE)|mode << 4)

// it is recommended to set the Sleep Enable (SE) bit just before the execution of theSLEEP instruction.
#define MCU_GTS()                                asm("sleep \r \n");
                                                 
                                                 







#endif /*_BLTH_RC_CAR_PRIVATE_H_*/