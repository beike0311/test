/* �����ֹ�ݹ���� ----------------------------------------------------------*/
#ifndef __UART1__H
#define __UART1__H

/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "stm8l15x.h"

/* �궨�� --------------------------------------------------------------------*/
/* ����UART1 IO PORT��PIN */
#define UART1_RX_PORT  (GPIOA)
#define UART1_RX_PINS  (GPIO_Pin_3)

#define UART1_TX_PORT  (GPIOA)
#define UART1_TX_PINS  (GPIO_Pin_2)


/* ��������-------------------------------------------------------------------*/
void UART1_Init(void);
void UART1_Send(char *buf,uint8_t len);

#endif
