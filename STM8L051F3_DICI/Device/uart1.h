/* 定义防止递归包含 ----------------------------------------------------------*/
#ifndef __UART1__H
#define __UART1__H

/* 包含头文件 ----------------------------------------------------------------*/
#include "stm8l15x.h"

/* 宏定义 --------------------------------------------------------------------*/
/* 定义UART1 IO PORT与PIN */
#define UART1_RX_PORT  (GPIOA)
#define UART1_RX_PINS  (GPIO_Pin_3)

#define UART1_TX_PORT  (GPIOA)
#define UART1_TX_PINS  (GPIO_Pin_2)


/* 函数声明-------------------------------------------------------------------*/
void UART1_Init(void);
void UART1_Send(char *buf,uint8_t len);

#endif
