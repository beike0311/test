#include "dici.h"

/**
  * @函数名       dici_init
  * @功  能       地磁初始化  
  * @参  数       无
  * @返回值       无
  */
void dici_init()
{
  GPIO_Init(CSH_GPIO_PORT, CSH_GPIO_PINS, GPIO_Mode_Out_PP_High_Fast);
  GPIO_Init(SEL1_GPIO_PORT, SEL1_GPIO_PINS, GPIO_Mode_Out_PP_High_Fast);
  GPIO_Init(SEL2_GPIO_PORT, SEL2_GPIO_PINS, GPIO_Mode_Out_PP_High_Fast);
  GPIO_Init(BUSY_GPIO_PORT, BUSY_GPIO_PINS, GPIO_Mode_In_FL_No_IT);//BUSY=1，工作模式
  GPIO_Init(STATE_GPIO_PORT, STATE_GPIO_PINS, GPIO_Mode_In_FL_No_IT);//车位状态指示，STATE=1有车，STATE=0无车

  //初始化磁场数据，低电平有效
  GPIO_ResetBits(CSH_GPIO_PORT, CSH_GPIO_PINS);
  //SEL1=1,SEL2=1,10S检测一次
  GPIO_SetBits(SEL1_GPIO_PORT,SEL1_GPIO_PINS);
  GPIO_SetBits(SEL2_GPIO_PORT,SEL2_GPIO_PINS);
}
  
BitStatus dici_query(GPIO_TypeDef* GPIOx,GPIO_Pin_TypeDef GPIO_Pin)
{
  return GPIO_ReadInputDataBit(GPIOx,GPIO_Pin);
}  
  