#include "uart_data_transfer_core.h"

#ifndef DEBUG_SOFTWARE

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "uart_data_transfer_core.h"
#include "usart.h"
#include "cmsis_os.h"

#include "user_actions.h"

#define MAX_SIZE_RX_UART_DATA 99

#define RX_DATA_COMPLETE   1
#define TX_DATA_COMPLETE   2
#define NEED_TRANSMIT_DATA 4

#define MIN_LEN_COMMAND 5

uint8_t rx_uart_data[MAX_SIZE_RX_UART_DATA + 1] = {};
EventGroupHandle_t uart_data_transfer_events = 0;
_Bool enable_idle_flag_interrupt = 0,
		tx_complete = true;

void init_uart_data_transfer (void) {
	uart_data_transfer_events = xEventGroupCreate();

	enable_idle_flag_interrupt = true;
	__HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
	HAL_UART_Receive_DMA(&huart1, rx_uart_data, MAX_SIZE_RX_UART_DATA);
}

void transmit_data_by_uart (void) {
	xEventGroupSetBits(uart_data_transfer_events, NEED_TRANSMIT_DATA);
}

void event_group_set_bit_from_isr (EventGroupHandle_t event_group, uint32_t bit_to_set) {
	BaseType_t xHigherPriorityTaskWoken, xResult;
	xHigherPriorityTaskWoken = pdFALSE;

	xResult = xEventGroupSetBitsFromISR (event_group, bit_to_set, & xHigherPriorityTaskWoken);

	if (xResult != pdFAIL) {
	  portYIELD_FROM_ISR (xHigherPriorityTaskWoken);
	}
}

void HAL_UART_IDLE_Callback (UART_HandleTypeDef *huart) {
	if (huart -> Instance == USART1){
		__HAL_UART_CLEAR_IDLEFLAG(huart);

		if(enable_idle_flag_interrupt){
			enable_idle_flag_interrupt = false;
			return;
		}

		if (strlen((const char *)rx_uart_data) < MIN_LEN_COMMAND)
			return;

		uint8_t command_len = strlen((const char *)rx_uart_data);
		if (rx_uart_data[command_len - 1] != '\r')
			return;
		rx_uart_data[command_len - 1] = '\0';


		if(tx_complete == false)
			return;
		else
			tx_complete = false;

		__HAL_UART_DISABLE_IT(huart, UART_IT_IDLE);
		HAL_UART_AbortReceive_IT(huart);

		event_group_set_bit_from_isr(uart_data_transfer_events, RX_DATA_COMPLETE);
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	HAL_UART_AbortReceive_IT(huart);
	rx_uart_data[MAX_SIZE_RX_UART_DATA - 1] = '\r';
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
	event_group_set_bit_from_isr(uart_data_transfer_events, TX_DATA_COMPLETE);
}

#include <string.h>
void rx_uart_data_task (void const * argument) {
	for(;;) {
		xEventGroupWaitBits(uart_data_transfer_events, 1, pdTRUE, pdTRUE, portMAX_DELAY );

/*
	parse this

*/
// EXAMPLE:
		parse(crop_trash((const char *)rx_uart_data));
		if (strlen(rx_uart_data) > strlen("get charge_current")) {
			asm("nop");
		}
		if (strcmp((const char *)rx_uart_data, "get charge_current") ) {
			asm("nop");
		}

		memset(rx_uart_data, 0, MAX_SIZE_RX_UART_DATA);

		// while not have parse call
		xEventGroupSetBits(uart_data_transfer_events, NEED_TRANSMIT_DATA);
	}
}

void tx_uart_data_task(void const * argument) {
	uint8_t * tx_data = 0;

	for(;;) {
		xEventGroupWaitBits(uart_data_transfer_events, NEED_TRANSMIT_DATA, pdTRUE, pdTRUE, portMAX_DELAY);

		//get pointer tx_data
		//	tx_data = GET_POINTER_FUNCTION
		// EXAMPLE:
		parser_action()();
		tx_data = get_user_response();

		if(tx_data != 0)
			HAL_UART_Transmit_DMA(&huart1, tx_data, strlen((const char*)tx_data));
		else
			HAL_UART_Transmit_DMA(&huart1, (uint8_t *)"debug message or error\r\n", strlen("debug message or error\r\n"));

		xEventGroupWaitBits(uart_data_transfer_events, TX_DATA_COMPLETE, pdTRUE, pdTRUE, portMAX_DELAY );

		tx_complete = true;
		HAL_UART_Abort(&huart1);
		__HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
		HAL_UART_Receive_DMA(&huart1, rx_uart_data, MAX_SIZE_RX_UART_DATA);
	}
}
#else

void transmit_data_by_uart (void) {

}
void init_uart_data_transfer (void) {

}

#endif //DEBUG_SOFTWARE
