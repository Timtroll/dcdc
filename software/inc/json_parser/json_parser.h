#ifndef _JSON_PARSER_H_
#define _JSON_PARSER_H_

void parser_init_data_function(char * (* data_function_type_screen)(void), 
							   char * (* data_function_cell_value)(int index_x, int index_y));
char * parser_accept_json_string(char * some_json_string);
char * parser_create_any_json_pair(char * key, char * value);

#endif//_JSON_PARSER_H_

