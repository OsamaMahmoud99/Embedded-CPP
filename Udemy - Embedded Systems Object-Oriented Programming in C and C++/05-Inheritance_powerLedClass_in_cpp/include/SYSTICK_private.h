/*************************************************************************************************/
/*   Author    :   Osama Mahmoud                                                                 */
/*   Date      :   25/8/2020                                                                     */
/*   Version   :   V01                                                                           */
/*************************************************************************************************/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H


/*   Base Address :     0xE000E010    */

/* Register   Definition  */
#define    STK_CTRL     *((volatile u32*)0xE000E010)
#define    STK_LOAD     *((volatile u32*)0xE000E014)
#define    STK_VAL      *((volatile u32*)0xE000E018)
#define    STK_CALIB    *((volatile u32*)0xE000E01C)


#define  AHB_DIV_8    0
#define  AHB          1

#define  MSTK_SINGLE_INTERVAL    0
#define  MSTK_PERIOD_INTERVAL    1

/* Bits of  CTRL Register */
#define  ENABLE       0
#define  TICKINT      1
#define  CLKSOURCE    2
#define  COUNTFLAG    16





#endif