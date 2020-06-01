/*
 *******************************************************************************
 * �ļ���:uart1.c
 * �ļ����������ڳ�ʼ��                                  
 *******************************************************************************
 */

/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "uart1.h"

/**
  * @������       Uart1_Init
  * @��  ��       ����UART1
  * @��  ��       ��
  * @����ֵ       ��
  */
void UART1_Init(void)
{
  USART_DeInit(USART1); //��USART1�ĸ����Ĵ���ֵ�ָ�Ϊȱʡֵ
  
  /* ʹ��USART1ʱ������ */
  CLK_PeripheralClockConfig(CLK_Peripheral_USART1, ENABLE);
  
  /* ӳ��UART1��IO�ڣ�TX-->PA2  RX-->PA3 */
  SYSCFG_REMAPPinConfig(REMAP_Pin_USART1TxRxPortA, ENABLE);
  
  /* ����UART1��RX&TX��IO�� */
  GPIO_Init(UART1_RX_PORT, UART1_RX_PINS, GPIO_Mode_In_PU_No_IT);
  GPIO_Init(UART1_TX_PORT, UART1_TX_PINS, GPIO_Mode_Out_PP_High_Slow);
  
  GPIO_ExternalPullUpConfig(UART1_RX_PORT, UART1_RX_PINS, ENABLE);
  GPIO_ExternalPullUpConfig(UART1_TX_PORT, UART1_TX_PINS, ENABLE);
  
  /* UART1��ʼ�� */
  USART_Init(USART1, 
                (uint32_t)9600, //������9600
                USART_WordLength_8b,    //���ݿ��8λ
                USART_StopBits_1,       //һλֹͣλ
                USART_Parity_No,        //����żУ��
                (USART_Mode_TypeDef)(USART_Mode_Tx | USART_Mode_Rx));//����&����ģʽ
  
   USART_ClockInit(USART1,USART_Clock_Disable,USART_CPOL_Low,USART_CPHA_2Edge,USART_LastBit_Disable); //��ʼ��UART1ʱ��
   USART_ClearITPendingBit(USART1,USART_IT_RXNE);  //���UART1���ռĴ����ǿ��ж�
   USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);    //ʹ��UART1���ռĴ����ǿ��ж�
   USART_Cmd(USART1,ENABLE);//ʹ��UART1
   enableInterrupts();//ʹ���ж� 
}

void UART1_Send(char *buf,uint8_t len)
{
  while(len--)
  {  
    USART_SendData8(USART1, (uint8_t)*buf);
    buf++;
    while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);    
  }
}
