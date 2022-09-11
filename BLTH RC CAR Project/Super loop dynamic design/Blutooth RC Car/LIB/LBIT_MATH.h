/**
 * @file LBIT_MATH.h
 * @author Osama Mahmoud (you@domain.com)
 * @brief  This file contains the bit manipulation macros
 * @version 1.0
 * @date 2022-04-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* header file guard */
#ifndef LBIT_MATH_H_
#define LBIT_MATH_H_

#define SET_REG(Reg) Reg=0xFF
#define CLEAR_REG(Reg) Reg=0x00
#define TOGGLE_REG(Reg) Reg^=0xFF
#define ASSIGN_REG(Reg,Value) Reg=Value
#define SET_BITS_REG(Reg,Mask) Reg|=(Mask)
#define CLEAR_BITS_REG(Reg,Mask) Reg=(Reg&(~Mask))									
#define SET_BIT(Reg,bit) Reg|=(1<<bit)
#define CLEAR_BIT(Reg,bit) Reg=(Reg&(~(1<<bit)))
#define TOGGLE_BIT(Reg,bit) Reg^=(1<<bit)
#define CHECK_BIT(Reg,bit) ((Reg>>bit)&1)

/*lower nibble 0-3*/
#define   lower_nibble_high(Reg)             Reg=(Reg&0xf0)|0x0f
#define   lower_nibble_value(Reg,Value)      Reg=(Reg&0xf0)|(Value&0x0f)
#define   get_lower_nibble(Reg)              Reg&0x0f
/*higher nibble 4-7*/
#define   higher_nibble_high(Reg)            Reg=(Reg&0x0f)|(0xf0)
#define   higher_nibble_value(Reg,Value)     Reg=(Reg&0x0f)|(Value<<4)
#define   get_higher_nibble(Reg)             Reg&0xf0


#endif /*LBIT_MATH_H_*/
