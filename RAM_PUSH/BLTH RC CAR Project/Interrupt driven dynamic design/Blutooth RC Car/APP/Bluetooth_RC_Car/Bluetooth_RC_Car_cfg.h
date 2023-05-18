/**
 * @file Bluetooth_RC_Car_cfg.c
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the pin configuration of bluetooth rc car application
 * @version 1.0
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _Bluetooth_RC_Car_CFG_H_
#define _Bluetooth_RC_Car_CFG_H_



/**************************************************************************************/
/*                                Application configurations                          */
/**************************************************************************************/

/*Leds configuration*/
#define FRONT_LED                 (LED2)
#define REAR_LED                  (LED1)

/*Motot configuration*/
#define RIGHT_MOTOR               (MOTOR_CHANNEL_1)        
#define LEFT_MOTOR                (MOTOR_CHANNEL_2) 

/*Bluetooth commands*/
#define FORWARD_CMD                ('F')
#define BACKWARD_CMD               ('B')
#define LEFT_CMD                   ('L')
#define RIGHT_CMD                  ('R')
#define STOP_CMD                   ('S')
#define FRONTLIGHTS_ON_CMD         ('W')
#define FRONTLIGHTS_OFF_CMD        ('w')
#define REARLIGHTS_ON_CMD          ('U')
#define REARLIGHTS_OFF_CMD         ('u')
#define HORN_ON_CMD                ('V')
#define HORN_OFF_CMD               ('v')
#define HAZARD_ON_CMD              ('X')
#define HAZARD_OFF_CMD             ('x')
#define SPEED_0_CMD                ('0')
#define SPEED_10_CMD               ('1')
#define SPEED_20_CMD               ('2')
#define SPEED_30_CMD               ('3')
#define SPEED_40_CMD               ('4')
#define SPEED_50_CMD               ('5')
#define SPEED_60_CMD               ('6')
#define SPEED_70_CMD               ('7')
#define SPEED_80_CMD               ('8')
#define SPEED_90_CMD               ('9')
#define SPEED_100_CMD              ('q')


#endif /*_Bluetooth_RC_Car_CFG_H_*/