#ifndef _MENU_H_
#define _MENU_H_
#define _DEBUG_DISPLAY_ 

#include <stdint.h>

void menu_swipe_right(void);
void menu_swipe_left(void);
void * menu_get_actual_screen(void);
void menu_set_info(char * new_data);

// void * screen_test_data;
#ifdef _DEBUG_DISPLAY_
	
	void * screen_test_data;
	
	static char * debug_data_main_screen_1 [] = { 
									"main","2",
									"header_1","info_1",
									"header_2","info_2"};
	static char * debug_data_side_screen_1 [] ={
								  "side_1",
								  "header_1",
								  "info_1",
								  "advice_1"};
	static char * debug_data_side_screen_2 [] ={
								  "side_2",
								  "header_2",
								  "info_2",
								  "advice_2"};

	static int initital_state = 0;
#endif
	//3 тестовых экрана, идущих в памяти друг за другом 
	

#endif//_MENU_H_