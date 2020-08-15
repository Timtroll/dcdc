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
	char *** screen = keeper_data();
	return screen[SHIFT_FOR_POINTER][TYPES_SCREEN];
}


char * display_get_cell_value(int index_x, int index_y){
	
	char *** cell_value = keeper_data();

	switch (get_type()){
		case MAIN:
			Get_value(MAIN, cell_value, index_x, index_y);
			break;
		case SIDE:
			Get_value(SIDE, cell_value, index_x, index_y);
			break;
		default:
			return NULL;
	}		

}

void init_json_parser (void){
	static uint8_t init_flag = DEINIT;
	if(init_flag == DEINIT){
		parser_init_data_function(&display_get_type_screen, &display_get_cell_value);
		init_flag = INIT;
	}
}


void set_screen_parameters(char ** data_array){
	char *** screen = keeper_data();
	*screen = data_array;
}


char *** keeper_data(void){
	static char ** _screen ;
	return &_screen;
}

uint8_t get_type(void){
	if (strcmp(display_get_type_screen(), "main") == STRING_EQUAL)
		return MAIN;
	else if (strcmp(display_get_type_screen(), "side") == STRING_EQUAL)
		return SIDE;
	else return ERROR;
}
