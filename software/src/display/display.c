#include "display_internal.h"

void display_start_set_data(void){
	//permission
	if (DISABLE == get_permission_status())
	{
		change_permission_status();
	}
}
void display_stop_set_data(void){
	//unpermisson
	if (ENABLE == get_permission_status())
	{
		change_permission_status();
	}
}

//All functions require permission to change information in the cell
//so the user has to allow changes
void display_get_parameter(char * json_request){
	if (ENABLE == get_permission_status()){
		//This function processes the received json string and uses the public methods of 
		//other blocks to pass the response to the I/O block.
	}
}
void display_set_next_screen(uint8_t direction){
	if (ENABLE == get_permission_status()){
		if (direction == RIGHT)
		{
			menu_swipe_right();

		} else
		{
			menu_swipe_left();
		}
		//This function selects a new screen in the menu, depending on the selected direction.
		// Overwrites data inside the display, for return functions
	}
}
void display_set_parameter(char * cell_data){
	if (ENABLE == get_permission_status()){
		//This function rewrited cell in menu
	}
}
