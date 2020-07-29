//#define DEBUG_SOFTWARE
#ifndef DEBUG_SOFTWARE

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "uart_data_transfer_core.h"
#include "usart.h"
#include "cmsis_os.h"

#define MAX_SIZE_RX_UART_DATA 100

#define RX_DATA_COMPLETE   0x1
#define TX_DATA_COMPLETE   0x2
#define NEED_TRANSMIT_DATA 0x4


uint8_t rx_uart_data[MAX_SIZE_RX_UART_DATA] = {};
EventGroupHandle_t uart_data_transfer_events = 0;
_Bool enable_idle_flag_interrupt = 0;

void init_uart_data_transfer (void) {
	enable_idle_flag_interrupt = true;
	__HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
	HAL_UART_Receive_DMA(&huart1, rx_uart_data, MAX_SIZE_RX_UART_DATA);
}

//void function_for_call_transmit_data (void) {
//	xEventGroupSetBits(uart_data_transfer_events, NEED_TRANSMIT_DATA);
//}


void HAL_UART_IDLE_Callback (UART_HandleTypeDef *huart) {
	__HAL_UART_CLEAR_IDLEFLAG(huart);

	if(enable_idle_flag_interrupt){
		enable_idle_flag_interrupt = false;
		return;
	}
	HAL_UART_AbortReceive(huart);
	__HAL_UART_DISABLE_IT(huart, UART_IT_IDLE);

	xEventGroupSetBits(uart_data_transfer_events, RX_DATA_COMPLETE);
}

void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart) {
	xEventGroupSetBits(uart_data_transfer_events, TX_DATA_COMPLETE);
}

void rx_uart_data_task (void const * argument) {
	xEventGroupWaitBits(uart_data_transfer_events, RX_DATA_COMPLETE, pdTRUE, pdTRUE, portMAX_DELAY );

	asm("nop");
	/*parse this



	*/
	// while not have parse call
	xEventGroupSetBits(uart_data_transfer_events, NEED_TRANSMIT_DATA);
}

void tx_uart_data_task(void const * argument) {
	uint8_t * tx_data = 0;

	xEventGroupWaitBits(uart_data_transfer_events, TX_DATA_COMPLETE, pdTRUE, pdTRUE, NEED_TRANSMIT_DATA);

	//get pointer tx_data
//	tx_data = GET_POINTER_FUNCTION

	if(tx_data != 0)
		HAL_UART_Transmit_DMA(&huart1, tx_data, strlen((const char*)tx_data));
	else
		HAL_UART_Transmit_DMA(&huart1, (uint8_t *)"debug message or error", strlen("debug message or error"));

	xEventGroupWaitBits(uart_data_transfer_events, TX_DATA_COMPLETE, pdTRUE, pdTRUE, portMAX_DELAY );

	enable_idle_flag_interrupt = true;
	__HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
	HAL_UART_Receive_DMA(&huart1, rx_uart_data, MAX_SIZE_RX_UART_DATA);
}

#endif //DEBUG_SOFTWARE
