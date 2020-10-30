#ifndef _UART_DATA_TRANSFER_CORE_H_
#define _UART_DATA_TRANSFER_CORE_H_

// #define DEBUG_SOFTWARE

void init_uart_data_transfer (void);
void transmit_data_by_uart (void);

#ifndef DEBUG_SOFTWARE
#include "usart.h"
void HAL_UART_IDLE_Callback (UART_HandleTypeDef *huart) ;

#endif//DEBUG_SOFTWARE

#endif //_UART_DATA_TRANSFER_CORE_H_
