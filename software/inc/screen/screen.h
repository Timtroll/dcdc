#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <string.h>
#define DLM_CH "\n\n" // Delimiter character

enum screen_type {main, side};

void scr_constructor_screen (int screen_type, int number_lines, char * input_data, void * empty_screen_obj);
void scr_change_info (int line, int row, char * data, char ** screen_obj);
void scr_destructor_screen(char ** screen_obj);

// void print_table (char ** arr, int num_lines, int num_rows);

#endif//_SCREEN_H_

