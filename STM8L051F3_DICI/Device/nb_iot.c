#include "nb_iot.h"
#include "uart1.h"
#include "delay.h"
#include "string.h"
#include "dici.h"

uint8_t recv_data[MAX_LEN];
uint8_t recv_len = 0;
uint8_t recv_over = 0;
uint8_t reset_flag = 0;
extern uint8_t register_sucess;

//nb_iot自动注册
void nb_iot_register()
{
  reset_flag = 1;
  delay_ms(1000);
  UART1_Send("AT+QREGSWT?\n",strlen("AT+QREGSWT? "));//查询注册模式
  delay_ms(1000);
  UART1_Send("AT+NCDP=180.101.147.115,5683\n",strlen("AT+NCDP=180.101.147.115,5683 "));//设置IP和端口
  delay_ms(1000);
  UART1_Send("AT+NRB\n",strlen("AT+NRB "));//重启模块 
  delay_ms(20000);
  UART1_Send("AT+CGPADDR\n",strlen("AT+CGPADDR "));//查询模块IP  
  delay_ms(1000);
  reset_flag = 0;
}

void nb_iot_send()
{
  uint8_t dici_busy_status = 0,dici_state_status = 0;
  char send_message[32];
  static uint16_t time_count = 0;
    
  delay_ms(1);
  time_count++;
  
  if(time_count<10000)//10s上传一次状态信息
    return;
  
  time_count = 0;
  
  dici_busy_status = GPIO_ReadInputDataBit(BUSY_GPIO_PORT,BUSY_GPIO_PINS);
  dici_state_status = GPIO_ReadInputDataBit(STATE_GPIO_PORT,STATE_GPIO_PINS);

  //不需要IOT平台应答
  memcpy(send_message,"AT+QLWULDATA=2,0000\n",strlen("AT+QLWULDATA=2,0000 "));
  send_message[16] = dici_busy_status+'0';
  send_message[18] = dici_state_status+'0';
  UART1_Send(send_message ,strlen("AT+QLWULDATA=2,0000 "));
      
  //需要IOT平台应答
//      memcpy(send_message,"AT+QLWULDATAEX=2,0000,0X0100\n",strlen("AT+QLWULDATAEX=2,0000,0X0100 "));      
//      send_message[18] = dici_busy_status+'0';
//      send_message[20] = dici_state_status+'0';
//      UART1_Send(send_message ,strlen("AT+QLWULDATAEX=2,0000,0X0100 "));
}

void nb_iot_recv()
{
  uint8_t iot_data;
  if(recv_over == 1)
  {
    recv_over = 0;
    
    if(strncmp(&recv_data[2],"+NNMI:1,",8)== 0)
    {
      iot_data = recv_data[11]-'0';
    }
  }
    
}