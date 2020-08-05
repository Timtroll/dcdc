#include "json_parser_internal.h"

char * parser_create_any_json_pair(char * key, char * value){
	return create_json_pair(key, value);
}

char * parser_accept_json_string(char * some_json_string){
	return parse_incoming_string(some_json_string);
}

void parser_init_data_function(char * (* data_function_type_screen)(void), 
							   char * (* data_function_cell_value)(int index_x, int index_y)){

	json_init_parser(data_function_type_screen, data_function_cell_value);
}