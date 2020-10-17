#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <string.h>

enum screen_type {e_main, e_side};

void scr_constructor_screen (
	int screen_type, 
	int number_lines, 
	char ** field_name,
	char ** value,
	char ** hint, 
	void * empty_screen_obj
);
void scr_change_info (
	int line, 
	int row, 
	char * data, 
	void * screen_obj
);
void scr_destructor_screen (void * screen_obj);

#endif//_SCREEN_H_

