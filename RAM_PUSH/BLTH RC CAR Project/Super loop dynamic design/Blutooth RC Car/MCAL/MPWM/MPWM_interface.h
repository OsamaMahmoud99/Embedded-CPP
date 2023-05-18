/**
 * @file MPWM_interface.h
 * @author Osama Mahmoud (you@domain.com)
 * @brief  This file contains the interfacing informaton of pwm module
 * @version 1.0
 * @date 2022-04-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _MPWM_INTERFACE_H
#define _MPWM_INTERFACE_H

/***********************************************************************************/
/*                                Interfacing macros                               */
/***********************************************************************************/

/* PWM Channels */
#define PWM_CHANNEL_1          (0)
#define PWM_CHANNEL_2          (1)
#define PWM_CHANNEL_3          (2)

/* PWM Frequencies at 8MHZ CLK */
#define PWM_STOP               (0)   //	TIMER1_STOP=0
#define PWM_15KHZ              (1)   // TIMER1_SCALER_1
#define PWM_2KHZ               (2)   // TIMER1_SCALER_8
#define PWM_244KHZ             (3)   // TIMER1_SCALER_64
#define PWM_60KHZ              (4)   // TIMER1_SCALER_256
#define PWM_14KHZ              (5)   // TIMER1_SCALER_1024

/***********************************************************************************/
/*                                PWM Class                                        */
/***********************************************************************************/

class mpwmClass_t
{
    public:
         
         /**
          * @brief Construct a new pwm class object with 2KHZ frequency and 0% duty cycle by default
          * 
          * @param au8_channel 
          */
         mpwmClass_t(u8_t au8_channel);

         
         /**
          * @brief this function is used to update a specific pwm channel with specific frequnecy and duty cycle
          * 
          * @param au8_frequency 
          * @param au8_dutycycle 
          */
         void updatepwm(u8_t au8_frequency, u8_t au8_dutycycle);

    private:

         u8_t au8_prv_channel;

};




#endif /*_MPWM_INTERFACE_H*/