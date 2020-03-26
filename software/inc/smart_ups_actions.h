/*
 * Copyright © 2019-2020 Daniil D. Ryabinin (ryabiko1953@gmail.com)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */
#ifndef _ACTION_H
#define _ACTION_H

#include "stddef.h"
#include "stdio.h"

#include "parser/d_base.h"
#include "parser/parser.h"

//создать струкутуру с данными, которые будут браться в гет для тест
char * get_test = "123456789";

struct parser_memory
{
	char * parameter;
	char * response;
	action_t action;
}memory;

void save_data_from_set(void){
	memory.parameter = parser_parameter();
	memory.response = parser_response();
	memory.action = parser_action();
}

void save_data_from_get(char * para){
	memory.parameter = para;
	memory.response = parser_response();
	memory.action = parser_action();
}
#endif //_ACTION_H