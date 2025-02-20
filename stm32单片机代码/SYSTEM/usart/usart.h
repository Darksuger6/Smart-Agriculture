#ifndef _USART_H_
#define _USART_H_


#include "stm32f10x.h"


#define USART_DEBUG		USART1		//???????????
#define USART_WIFI		USART2

void Usart1_Init(unsigned int baud);

void Usart2_Init(unsigned int baud);

void UART_Send_Byte(USART_TypeDef *USARTx,unsigned char ch);

void Usart_SendString(USART_TypeDef *USARTx, unsigned char *str, unsigned short len);

void UsartPrintf(USART_TypeDef *USARTx, char *fmt,...);

#endif
