#ifndef _JSON_PARSER_INTERNAL_H_
#define _JSON_PARSER_INTERNAL_H_

#include <string.h>
#include "json_parser.h"
#include "parson.h"


void json_init_parser(char * (* get_func_type_screen)(void), char * (* get_func_cell_value)(int index_x, int index_y));
char * json_get_type_screen(void);
char * json_get_cell_value(int index_x, int index_y);

char * parse_incoming_string(char * incoming_str);

#endif//_JSON_PARSER_INTERNAL_H_

