#ifndef _SCREEN_INTERNAL_H_
#define _SCREEN_INTERNAL_H_

#include "screen.h"
#include <string.h>

#define MAX_CELL_SIZE 100 // string length
#define MAX_CELLS_NUM (10*2) // lines * rows
#define DLM_CH "\n\n" // Delimiter character

void itoa(int n, char s[]);

//==========_FOR_TESTS_===============
char ** create_empty_screen_obj(void);
void free_screen_obj(void * scr_obj);
void show_addrs(void * obj);

#endif//_SCREEN_INTERNAL_H_

