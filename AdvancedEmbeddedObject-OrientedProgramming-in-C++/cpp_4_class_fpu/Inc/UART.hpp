/*
 * UART.hpp
 *
 *  Created on: Apr 5, 2025
 *      Author: Osama
 */

#ifndef UART_HPP_
#define UART_HPP_

#include "stm32f4xx.h"

class UART{

private:
	USART_TypeDef *uart;
	uint32_t baudrate;

	void setBaudRate(uint32_t periph_clk)
	{
		uart->BRR = ((periph_clk + (baudrate/2U))/baudrate);
	}

public:
	UART(USART_TypeDef *uart, uint32_t baudrate): uart(uart),baudrate(baudrate){

		/*Enable clock access to GPIOA*/
		RCC->AHB1ENR |= (1U<<0);

		/*set the mode of PA2 to alternate function mode*/
		GPIOA->MODER &=~(1U<<4);
		GPIOA->MODER |= (1U<<5);

		/*set alternate function type tp AF7(UART2_TX)*/
		GPIOA->AFR[0] |= (1U<<8);
		GPIOA->AFR[0] |= (1U<<9);
		GPIOA->AFR[0] |= (1U<<10);
		GPIOA->AFR[0] &=~(1U<<11);

		/*Enable clock access to uart2*/
		RCC->APB1ENR |= (1U<<17);

		setBaudRate(16000000);

		/*configure transfer direction*/
		USART2->CR1 = (1U<<3);

		/*Enable uart module*/
		USART2->CR1 |= (1U<<13);
	}

	void send(char ch)
	{
		/*Make sure transmit data register is empty*/
		while(!(USART2->SR & (1U<<7)));

		/*write to transmit data register*/
		USART2->DR = (ch & 0xFF);
	}

	void sendString(const char *str)
	{
		while(*str){
			send(*str++);
		}
	}
};

#endif /* UART_HPP_ */
