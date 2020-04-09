#include "system_info_internal.h"

void save_data_from_set (void) {
	memory.parameter = parser_parameter();
	memory.response = parser_response();
	memory.action = parser_action();
}

void save_data_from_get (char * parameter) {
	memory.parameter = parameter;
	memory.response = parser_response();
	memory.action = parser_action();
}