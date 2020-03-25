/*
 * Copyright © 2019-2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#ifndef _PARSER_INTERNAL_H_
#define _PARSER_INTERNAL_H_

#include "stddef.h"
#include "parser.h"
#include "../inc/find/find.h"


#define NEWLINE "\r"
#define PARSER_RESPONSE_STUB "invalid syntax!"NEWLINE
#define PARSER_PATTERN_MAX_LEN_DEFAULT 100

void parser_set_command_dbase (dbase_record_t ** cmd_dbase);
void parser_set_pattern_max_len (int pattern_max_len);
void parser_set_response (char * response);
void parser_set_action (void (* action)(void));
void parser_set_parameter (char * parameter);

dbase_record_t * parser_command_dbase (void);
int parser_pattern_max_len (void);
char * parser_response (void);
action_t parser_action (void);

static inline const char * parser_response_stub (void) {
	return PARSER_RESPONSE_STUB;
}

action_t parser_stub_action (void);
dbase_record_t * parser_empty_cmd_dbase (void);

static inline dbase_record_t * parser_not_found (void) {
	return parser_empty_cmd_dbase();
}

dbase_record_t * _parser (const char * message);

#endif// _PARSER_INTERNAL_H_
