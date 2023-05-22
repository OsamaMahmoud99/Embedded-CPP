/**************************************************************************************/
/*    Author  : OsamaMahmoud                                                          */
/*    Date    : 13/8/2020                                                             */
/*    Version : V01                                                                   */
/**************************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


#define  GPIOA  0
#define  GPIOB  1
#define  GPIOC  2

#define  GPIO_LOW       0
#define  GPIO_HIGH      1

#define  INPUT_ANALOG         0b0000
#define  INPUT_FLOTING        0b0100
#define  INPUT_PP_PD          0b1000
/* OUTPUT MODE For 10MHZ */
#define  OUTPUT_PP_10MHZ      0b0001
#define  OUTPUT_OD_10MHZ      0b0101
#define  OUTPUT_AF_PP_10MHZ   0b1001
#define  OUTPUT_AF_OD_10MHZ   0b1101
/* OUTPUT MODE For 2MHZ */
#define  OUTPUT_PP_2MHZ       0b0010
#define  OUTPUT_OD_2MHZ       0b0110
#define  OUTPUT_AF_PP_2MHZ    0b1010
#define  OUTPUT_AF_OD_2MHZ    0b1110
/* OUTPUT MODE For 50MHZ */
#define  OUTPUT_PP_50MHZ      0b0011
#define  OUTPUT_OD_50MHZ      0b0111
#define  OUTPUT_AF_PP_50MHZ   0b1011
#define  OUTPUT_AF_OD_50MHZ   0b1111


void DIO_voidSetDirection(u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8mode);
void DIO_voidSetValue    (u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8value);
void DIO_voidTogPin      (u8 Copy_u8port, u8 Copy_u8pin);
u8   DIO_u8GEtValue      (u8 Copy_u8port, u8 Copy_u8pin);


#endif
