/* 包含头文件 ----------------------------------------------------------------*/
#include "stm8l15x.h"
#include "uart1.h"
#include "delay.h"
#include "dici.h"
#include "string.h"
#include "nb_iot.h"

uint8_t register_sucess = 0;
/**
  * @函数名       main
  * @功  能       主函数入口
  * @参  数       无
  * @返回值       无
  */
void main(void)
{
  /* 配置系统时钟频率为16MHz */
  CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);
  
  UART1_Init(); //UART1初始化
  dici_init(); //地磁初始化 
  nb_iot_register();//nb_iot自动注册   

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
