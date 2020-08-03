#include "json_parser_internal.h"

#define KEY_EXIST 1

char * parse_incoming_string(char * incoming_str){

	JSON_Value *incoming_value = json_parse_string(incoming_str);
	JSON_Object *incoming_object = json_value_get_object(incoming_value);

	if(json_object_has_value(incoming_object, "screen") == KEY_EXIST){
		json_object_set_string(incoming_object, "screen", json_get_type_screen());
		return json_serialize_to_string(incoming_value);
	}
	else{
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
