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