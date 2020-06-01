/*
 *******************************************************************************
 * 文件名:uart1.c
 * 文件描述：串口初始化                                  
 *******************************************************************************
 */

/* 包含头文件 ----------------------------------------------------------------*/
#include "uart1.h"

/**
  * @函数名       Uart1_Init
  * @功  能       配置UART1
  * @参  数       无
  * @返回值       无
  */
void UART1_Init(void)
{
  USART_DeInit(USART1); //将USART1的各个寄存器值恢复为缺省值
  
  /* 使能USART1时钟外设 */
  CLK_PeripheralClockConfig(CLK_Peripheral_USART1, ENABLE);
  
  /* 映射UART1的IO口：TX-->PA2  RX-->PA3 */
  SYSCFG_REMAPPinConfig(REMAP_Pin_USART1TxRxPortA, ENABLE);
  
  /* 配置UART1的RX&TX的IO口 */
  GPIO_Init(UART1_RX_PORT, UART1_RX_PINS, GPIO_Mode_In_PU_No_IT);
  GPIO_Init(UART1_TX_PORT, UART1_TX_PINS, GPIO_Mode_Out_PP_High_Slow);
  
  GPIO_ExternalPullUpConfig(UART1_RX_PORT, UART1_RX_PINS, ENABLE);
  GPIO_ExternalPullUpConfig(UART1_TX_PORT, UART1_TX_PINS, ENABLE);
  
  /* UART1初始化 */
  USART_Init(USART1, 
                (uint32_t)9600, //波特率9600
                USART_WordLength_8b,    //数据宽度8位
                USART_StopBits_1,       //一位停止位
                USART_Parity_No,        //无奇偶校验
                (USART_Mode_TypeDef)(USART_Mode_Tx | USART_Mode_Rx));//发送&接收模式
  
   USART_ClockInit(USART1,USART_Clock_Disable,USART_CPOL_Low,USART_CPHA_2Edge,USART_LastBit_Disable); //初始化UART1时钟
   USART_ClearITPendingBit(USART1,USART_IT_RXNE);  //清除UART1接收寄存器非空中断
   USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);    //使能UART1接收寄存器非空中断
   USART_Cmd(USART1,ENABLE);//使能UART1
   enableInterrupts();//使能中断 
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
