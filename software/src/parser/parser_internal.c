/*
 * Copyright © 2019-2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#include "parser_internal.h"

static void stub_action (void) {

}
action_t parser_stub_action (void) {
	return stub_action;
}

static dbase_record_t _empty_cmd_dbase = {
	.command = "emty_command_dbase",
	.response = PARSER_RESPONSE_STUB,
	.action = stub_action,
	.subcommand = NULL
};

dbase_record_t * parser_empty_cmd_dbase (void) {
	return &_empty_cmd_dbase;
}

static dbase_record_t * _command_dbase = NULL;
static int _pattern_max_len = 0;
static void (* _action) (void) = stub_action;
static char
	* _response = PARSER_RESPONSE_STUB,
	* _parameter = NULL;

void parser_set_pattern_max_len (int pattern_max_len) {
	_pattern_max_len = pattern_max_len;
}

void parser_set_command_dbase (dbase_record_t ** cmd_dbase) {
	_command_dbase = (dbase_record_t *)cmd_dbase;
}

void parser_set_response (char * response) {
	_response = response;
}
void parser_set_action (void (* action)(void)) {
	_action = action;
}
void parser_set_parameter (char * parameter) {
	_parameter = parameter;
}

int parser_pattern_max_len (void) {
	return _pattern_max_len;
}
dbase_record_t * parser_command_dbase (void) {
	return _command_dbase;
}

char * parser_response (void) {
	return _response;
}
action_t parser_action (void) {
	return _action;
}
char * parser_parameter (void) {
	return _parameter;
}


dbase_record_t * _parser (const char * message) {
	if (parser_command_dbase() == NULL)
		return parser_empty_cmd_dbase();

	dbase_record_t * found_record = find_cmd(message);

	if (found_record != NULL) {
		return found_record;
	}

	return parser_not_found(); // must never occure
}
