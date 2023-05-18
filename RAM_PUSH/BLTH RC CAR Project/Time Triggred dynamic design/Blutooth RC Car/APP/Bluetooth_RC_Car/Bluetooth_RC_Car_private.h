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

/*sleep modes*/
//Bits 6..4 – SM2..0: Sleep Mode Select Bits 2, 1, and 0
#define IDLE_MODE                (0)
#define ADC_NOISE_REDUCTION      (1)
#define POWER_DOWN_MODE          (2)
#define POWER_SAVE_MODE          (3)
#define STAND_BY_MODE            (6)

/*WDT reset modes*/
#define RESET_16_3_MS            (0)
#define RESET_32_5_MS            (1)
#define RESET_65_0_MS            (2)
#define RESET_0_13_S             (3)
#define RESET_0_26_S             (4)
#define RESET_0_52_S             (5)
#define RESET_1_0_S              (6)
#define RESET_2_1_S              (7)



/***********************************************************************************/
/*                                   control registers                             */
/***********************************************************************************/

#define MCUCR            (*(volatile u8_t*)(0x55))
#define WDTCR            (*(volatile u8_t*)(0x41))

/*Sleep enable bit*/
#define SE               (7) 

/*WDT Enable bit*/
#define WDE              (3)
#define WDCE             (4)


/***********************************************************************************/
/*                              Operations on control registers                    */
/***********************************************************************************/

/* sleep mode operations */
#define SELECT_SLEEP_MODE(mode)                  MCUCR |= ((1<<SE)|(mode << 4))

// it is recommended to set the Sleep Enable (SE) bit just before the execution of theSLEEP instruction.
#define MCU_GTS()                                asm("sleep \r \n")

/* WDT operations */
#define WDT_ENABLE(TIME_TO_RESET)                WDTCR |= (1<<WDE) | (TIME_TO_RESET)
#define WDT_REFRESH()                            asm("wdr \r \n")
#define WDT_DISABLE()                            WDTCR |= (1<<WDCE)|(1<<WDE);        \
                                                 WDTCR = 0x00;                        \
                                                 asm("wdr \r \n")
 
                                                 
                                                 







#endif /*_BLTH_RC_CAR_PRIVATE_H_*/