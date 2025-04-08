/*
 * spi.h
 *
 *  Created on: Apr 3, 2025
 *      Author: Osama
 */

#ifndef SPI_H_
#define SPI_H_

#include "stm32f4xx.h"
#include "timebase.h"
#include <stdint.h>


typedef struct
{
	uint32_t Mode;
	uint32_t Direction;
	uint32_t DataSize;
	uint32_t CLKPolarity;
	uint32_t CLKPhase;
	uint32_t NSS;
	uint32_t BaudRatePrescaler;
	uint32_t FirstBit;
	uint32_t CRCCalculation;

}SPI_InitTypeDef;

typedef enum
{
	SPI_STATE_RESET = 0x00U,
	SPI_STATE_READY = 0x01U,
	SPI_STATE_BUSY  = 0x02U,
	SPI_STATE_BUSY_TX = 0x03U,
	SPI_STATE_BUSY_RX = 0x04U,

}SPI_StateTypeDef;

typedef enum
{
	DEV_OK = 0x00U,
	DEV_ERROR = 0x01,
	DEV_BUSY  = 0x02U,
	DEV_TIMEOUT = 0x03U,

}StatusTypeDef;

typedef struct
{
	SPI_TypeDef *Instance;
	SPI_InitTypeDef Init;
	uint8_t *pTxBuffer;
	uint16_t TxXferSize;
	__IO uint16_t TxXferCount;
	uint8_t *pRxBuffer;
	uint16_t RxXferSize;
	__IO uint16_t RxXferCount;
	SPI_StateTypeDef State;
	__IO uint32_t Errorcode;

}SPI_HandleTypeDef;

#define SPI_ERROR_NONE      (0x00000000U)

#define SPI_MODE_SLAVE      (0x00000000U)
#define SPI_MODE_MASTER     (SPI_CR1_MSTR | SPI_CR1_SSI)

#define SPI_DIRECTION_2LINES  (0x00000000U)
#define SPI_DIRECTION_1LINE   (SPI_CR1_BIDIMODE)

#define SPI_DATASIZE_8BIT     (0x00000000U)
#define SPI_DATASIZE_16BIT    SPI_CR1_DFF
#define SPI_POLARITY_LOW      (0x00000000U)
#define SPI_POLARITY_HIGH     SPI_CR1_CPOL

#define SPI_PHASE_1EDGE		  (0x00000000U)
#define SPI_NSS_SOFT		  SPI_CR1_SSM

#define SPI_BAUDRATEPRESCALER_4		(SPI_CR1_BR_0)
#define SPI_FIRSTBIT_MSB	        (0x00000000U)
#define SPI_TIMEOUT_DISABLE			(0x00000000U)

#define SPI_CRCCALCULATION_DISABLE	(0x00000000U)

#define SPI_FLAG_RXNE				SPI_SR_RXNE
#define SPI_FLAG_TXE				SPI_SR_TXE
#define SPI_FLAG_BSY				SPI_SR_BSY
#define SPI_FLAG_OVR				SPI_SR_OVR

StatusTypeDef spi_init(SPI_HandleTypeDef *hspi);
StatusTypeDef spi_transmit(SPI_HandleTypeDef *hspi, uint8_t *p_data, uint16_t size, uint32_t timeout);
StatusTypeDef spi_receive(SPI_HandleTypeDef *hspi,uint8_t *p_data, uint16_t size, uint32_t timeout);

#endif /* SPI_H_ */
