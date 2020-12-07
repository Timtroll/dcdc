#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#define _DEBUG_DISPLAY_	
#define END_TABLE "\0"
#define RIGHT 0
#define LEFT 1
 
#include <stdint.h>
#include "../inc/menu/menu.h"

void display_start_set_data(void);
void display_stop_set_data(void);
void display_get_parameter(char * json_request);
void display_set_next_screen(uint8_t direction);
void display_set_parameter(char * cell_data);

void menu_double_create(void * memory);

#ifdef _DEBUG_DISPLAY_
	void set_transmit_string(char * value);
	char * get_transmit_string(void);
#endif
#endif//_DISPLAY_H_

