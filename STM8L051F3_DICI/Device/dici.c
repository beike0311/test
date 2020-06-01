#include "dici.h"

/**
  * @������       dici_init
  * @��  ��       �شų�ʼ��  
  * @��  ��       ��
  * @����ֵ       ��
  */
void dici_init()
{
  GPIO_Init(CSH_GPIO_PORT, CSH_GPIO_PINS, GPIO_Mode_Out_PP_High_Fast);
  GPIO_Init(SEL1_GPIO_PORT, SEL1_GPIO_PINS, GPIO_Mode_Out_PP_High_Fast);
  GPIO_Init(SEL2_GPIO_PORT, SEL2_GPIO_PINS, GPIO_Mode_Out_PP_High_Fast);
  GPIO_Init(BUSY_GPIO_PORT, BUSY_GPIO_PINS, GPIO_Mode_In_FL_No_IT);//BUSY=1������ģʽ
  GPIO_Init(STATE_GPIO_PORT, STATE_GPIO_PINS, GPIO_Mode_In_FL_No_IT);//��λ״ָ̬ʾ��STATE=1�г���STATE=0�޳�

  //��ʼ���ų����ݣ��͵�ƽ��Ч
  GPIO_ResetBits(CSH_GPIO_PORT, CSH_GPIO_PINS);
  //SEL1=1,SEL2=1,10S���һ��
  GPIO_SetBits(SEL1_GPIO_PORT,SEL1_GPIO_PINS);
  GPIO_SetBits(SEL2_GPIO_PORT,SEL2_GPIO_PINS);
}
  
BitStatus dici_query(GPIO_TypeDef* GPIOx,GPIO_Pin_TypeDef GPIO_Pin)
{
  return GPIO_ReadInputDataBit(GPIOx,GPIO_Pin);
}  
  