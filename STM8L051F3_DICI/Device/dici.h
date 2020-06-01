#ifndef __HW_DICI_H__
#define __HW_DICI_H__

/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "stm8l15x.h"

/* �궨�� --------------------------------------------------------------------*/
//NC-100�������ģ��
#define CSH_GPIO_PORT  (GPIOC)
#define CSH_GPIO_PINS  (GPIO_Pin_1)

#define STATE_GPIO_PORT  (GPIOC)
#define STATE_GPIO_PINS  (GPIO_Pin_0)

#define BUSY_GPIO_PORT  (GPIOB)
#define BUSY_GPIO_PINS  (GPIO_Pin_7)

#define SEL2_GPIO_PORT  (GPIOB)
#define SEL2_GPIO_PINS  (GPIO_Pin_6)

#define SEL1_GPIO_PORT  (GPIOB)
#define SEL1_GPIO_PINS  (GPIO_Pin_5)

/* ��������-------------------------------------------------------------------*/
void dici_init();
BitStatus dici_query(GPIO_TypeDef* GPIOx,GPIO_Pin_TypeDef GPIO_Pin);
#endif