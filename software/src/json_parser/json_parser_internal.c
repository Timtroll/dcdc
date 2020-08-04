#include "json_parser_internal.h"

#define KEY_EXIST 1
#define SHIFT_FOR_COLUMNS 10

#define STOP_SYMBOL ']' 
#define X_COORDINATE 1
#define Y_COORDINATE 2

char * parse_incoming_string(char * incoming_str){

	JSON_Value *incoming_value = json_parse_string(incoming_str);
	JSON_Object *incoming_object = json_value_get_object(incoming_value);

	if(json_object_has_value(incoming_object, "screen") == KEY_EXIST){
		json_object_set_string(incoming_object, "screen", json_get_type_screen());
		return json_serialize_to_string(incoming_value);
	}
	else if (json_object_has_value(incoming_object, "cell") == KEY_EXIST){
		int index_x = find_cell_index(X_COORDINATE, json_serialize_to_string(incoming_value));
		int index_y = find_cell_index(Y_COORDINATE, json_serialize_to_string(incoming_value));
		json_object_set_string(incoming_object, "cell", json_get_cell_value(index_x, index_y));
		return json_serialize_to_string(incoming_value);
	}
}


typedef struct json_get_function{
	char * (* type_screen) (void);
	char * (* cell_value) (int index_x, int index_y);
}JSON_function;

static JSON_function special_func;

void json_init_parser(char * (* get_func_type_screen)(void), char * (* get_func_cell_value)(int index_x, int index_y)){ 
	
	special_func.type_screen = get_func_type_screen;
	special_func.cell_value = get_func_cell_value;
	
}

char * json_get_type_screen(void){
	return special_func.type_screen();
}

char * json_get_cell_value(int index_x, int index_y){
	return special_func.cell_value(index_x, index_y);
}



int find_cell_index(int coordinate, char * processed_string){

	static int shift = 0;
	char str_coordinate [80] = {0};
	switch (coordinate){
		case X_COORDINATE:
			shift = SHIFT_FOR_COLUMNS;
			while (processed_string[shift] != STOP_SYMBOL){
				strcat(str_coordinate, &processed_string[shift]);
				shift++;
			}
			return atoi(str_coordinate);
			break;

		case Y_COORDINATE:
			shift = shift+2;
			
			while (processed_string[shift] != STOP_SYMBOL){
				strcat(str_coordinate, &processed_string[shift]);
				shift++;
			}
			shift = 0;
			return atoi(str_coordinate);
			break;

		default:
			return 0;
			break;

	}
	return 0;
}