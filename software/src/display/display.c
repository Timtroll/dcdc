#include "display_internal.h"

void display_start_set_data(void){
	if (DISABLE == get_permission_status())
		change_permission_status();
}
void display_stop_set_data(void){
	if (ENABLE == get_permission_status())
		change_permission_status();
}

//All functions require permission to change information in the cell
//so the user has to allow changes
void display_get_parameter(char * json_request){
	#ifdef _DEBUG_DISPLAY_
		set_transmit_string(parser_accept_json_string(json_request));
	#endif
		//There will be data transfer via UART to I/O
	//This function processes the received JSON string and uses the public methods of 
	//other blocks to pass the response to the I/O block.
}
void display_set_next_screen(uint8_t direction){
	if (DISABLE == get_permission_status()){
		if (direction == RIGHT)
			menu_swipe_right();
		else
			menu_swipe_left();
		//This function selects a new screen in the menu, depending on the selected direction.
		// Overwrites data inside the display, for return functions
	}
}
void display_set_parameter(char * cell_data){
	if (ENABLE == get_permission_status()){
		//This function rewrited cell in menu
	}
}
#ifdef _DEBUG_DISPLAY_
	static char * debug_transmit_string = NULL;

	void set_transmit_string(char * value){
		debug_transmit_string = value;
	}
	
	char * get_transmit_string(void){
		return debug_transmit_string;
	}
#endif


#define SIZE_OF_SCREENS 112

void reserve_memory(char *** pointer){
	pointer = (char***)malloc(3*sizeof(char**));

	pointer[0] = (char**)malloc(6*sizeof(char*));
	pointer[1] = (char**)malloc(4*sizeof(char*));
	pointer[2] = (char**)malloc(4*sizeof(char*));

	pointer[0][0] = (char*)malloc(4*sizeof(char*));
	pointer[0][1] = (char*)malloc(1*sizeof(char*));
	pointer[0][2] = (char*)malloc(7*sizeof(char*));
	pointer[0][3] = (char*)malloc(6*sizeof(char*));
	pointer[0][4] = (char*)malloc(7*sizeof(char*));
	pointer[0][5] = (char*)malloc(6*sizeof(char*));

	pointer[1][0] = (char*)malloc(6*sizeof(char*));
	pointer[1][1] = (char*)malloc(8*sizeof(char*));
	pointer[1][2] = (char*)malloc(6*sizeof(char*));
	pointer[1][3] = (char*)malloc(8*sizeof(char*));

	pointer[2][0] = (char*)malloc(6*sizeof(char*));
	pointer[2][1] = (char*)malloc(8*sizeof(char*));
	pointer[2][2] = (char*)malloc(6*sizeof(char*));
	pointer[2][3] = (char*)malloc(8*sizeof(char*));

}

void *menu_double_create(void *memory){
	free(memory);
	char * debug_data_main_screen_1 [] = { 
									"main","2",
									"header_1","info_1",
									"header_2","info_2"};
	char * debug_data_side_screen_1 [] ={
								  "side_1",
								  "header_1",
								  "info_1",
								  "advice_1"};
	char * debug_data_side_screen_2 [] ={
								  "side_2",
								  "header_2",
								  "info_2",
								  "advice_2"};

	char ** pointer_3_pos[] = {	debug_data_main_screen_1, \
								debug_data_side_screen_1, \
								debug_data_side_screen_2};

	reserve_memory(memory);
	memory = &pointer_3_pos;

	char *** shit = memory;
	printf("\n\n%s\n", shit[0][2]);		 
	return memory;
}

