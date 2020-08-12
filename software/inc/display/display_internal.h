#ifndef _DISPLAY_INTERNAL_H_
#define _DISPLAY_INTERNAL_H_

#include "display.h"
#include "../json_parser/json_parser.h"
#include <stdint.h>
#include <string.h>

#define ENABLE 1
#define DISABLE 0
#define INIT 1
#define DEINIT 0


void change_permission_status(void);
uint8_t get_permission_status(void);


char * display_get_type_screen(void);
char * display_get_cell_value(int index_x,
			   			 	  int index_y);
char * compute_type_screen(void);
char * compute_cell_value(int index_x,
			   			  int index_y);

void init_json_parser (void);

#endif//_DISPLAY_INTERNAL_H_

