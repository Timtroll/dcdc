#ifndef _DISPLAY_INTERNAL_H_
#define _DISPLAY_INTERNAL_H_

#include "display.h"
#include "../json_parser/json_parser.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define ENABLE 1
#define DISABLE 0

#define INIT 1
#define DEINIT 0

#define TYPES_SCREEN 0

#define ERROR 0

#define MAIN 1
#define MAIN_WIDTH_LIMIT 2

#define SIDE 2
#define SIDE_WIDTH_LIMIT 1
#define SIDE_LENGTH_LIMIT 3


void change_permission_status(void);
uint8_t get_permission_status(void);

char * display_get_type_screen(void);
char * display_get_cell_value(int index_x, int index_y);

void init_json_parser (void);
void set_screen_parameters(char ** data_array);

static char *** keeper_data(void);
uint8_t get_type(void);

#define Cell_MAIN(x, y) (y * 2 + 2 + x) 
#define Cell_SIDE(x, y) (x + y + 1)


#define QUANTITY_STRINGS 1
#define SHIFT_FOR_POINTER 0

#define Get_value(type, cell, collum, string) \
	if ((string >=  atoi(cell[SHIFT_FOR_POINTER][QUANTITY_STRINGS]) && \
		collum < type ## _WIDTH_LIMIT) && type == MAIN) \
		return END_TABLE; \
	else if (collum >= type ## _WIDTH_LIMIT || \
		(type == SIDE && string >= SIDE_LENGTH_LIMIT)) \
		return NULL; \
	else if (collum < 0 || string < 0) \
		return NULL; \
	return cell[SHIFT_FOR_POINTER][Cell_ ## type (index_x, index_y)]; \

#endif//_DISPLAY_INTERNAL_H_

