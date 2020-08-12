#include "display_internal.h"

uint8_t permission_status = DISABLE;

uint8_t get_permission_status(void){
	return permission_status;
}

void change_permission_status(void){

	if (permission_status == DISABLE)
		permission_status = ENABLE;
	else if (permission_status == ENABLE)
		permission_status = DISABLE;
	else
		permission_status = DISABLE;
}

char * display_get_type_screen(void){
	return compute_type_screen();
}
char * display_get_cell_value(int index_x,
			   			 	  int index_y){
	return compute_cell_value(index_x, index_y);
}


char * compute_type_screen(void){
	return "main";
}
char * compute_cell_value(int index_x,
			   			  int index_y){
	return "0";
}

void init_json_parser (void){
	
	static uint8_t init_flag = DEINIT;
	if(init_flag == DEINIT){
		parser_init_data_function(&display_get_type_screen, &display_get_cell_value);
		init_flag = INIT;
	}
}