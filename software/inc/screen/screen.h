#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <string.h>
#define DLM_CH "\n\n" // Delimiter character

int scr_constructor_screen (char * data, char ** screen_obj);
void scr_change_info (int line, int row, char * data, char ** screen_obj);
void scr_destructor_screen(char ** screen_obj);

// void print_table (char ** arr, int num_lines, int num_rows);

#endif//_SCREEN_H_

