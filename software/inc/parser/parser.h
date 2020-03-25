/*
 * Copyright © 2019-2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */
#ifndef _PARSER_H_
#define _PARSER_H_

#include "d_base.h"

void parser_create (command_dbase_t cmd_dbase, int pattern_max_len);
void parser_delete (void);
void parse (const char * user_message);

char * parser_response (void);
action_t parser_action (void);
char * parser_parameter (void);

#endif//_PARSER_H_
