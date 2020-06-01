/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "stm8l15x.h"
#include "uart1.h"
#include "delay.h"
#include "dici.h"
#include "string.h"
#include "nb_iot.h"

uint8_t register_sucess = 0;
/**
  * @������       main
  * @��  ��       ���������
  * @��  ��       ��
  * @����ֵ       ��
  */
void main(void)
{
  /* ����ϵͳʱ��Ƶ��Ϊ16MHz */
  CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);
  
  UART1_Init(); //UART1��ʼ��
  dici_init(); //�شų�ʼ�� 
  nb_iot_register();//nb_iot�Զ�ע��   

  while (1)
  { 
    nb_iot_send();
    nb_iot_recv();
  }
}



#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
