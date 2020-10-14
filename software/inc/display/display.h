#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#define END_TABLE "\0"
#define RIGHT 0
 
#include <stdint.h>

void display_start_set_data(void);
void display_stop_set_data(void);
void display_get_parameter(char * json_request);
void display_set_next_screen(uint8_t direction);
void display_set_parameter(char * cell_data);

#endif//_DISPLAY_H_

