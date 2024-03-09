#ifndef __UART_H
#define __UART_H

#include "stm32f4xx.h"
#include <stdio.h>

void uart_init(void);
int uart_write(int ch);
int uart_read(void);



#endif
