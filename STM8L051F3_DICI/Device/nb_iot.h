#ifndef __HW_NB_IOT_H__
#define __HW_NB_IOT_H__

#include "stm8l15x.h"

#define MAX_LEN                 32

extern uint8_t recv_data[MAX_LEN];
extern uint8_t recv_len;
extern uint8_t recv_over;
extern uint8_t reset_flag;
void nb_iot_register();
void nb_iot_send();
void nb_iot_recv();
#endif
