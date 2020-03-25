/*
 * Copyright © 2019-2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#include "parser_internal.h"


/*
1. cells of command, option and required parammesers are the same.
2. parser_create takes pointer to parser_command_data_base that
   extern hard-coded by parser user.
3. each cell which contains one of the end-commmand parts chain
   have a null pointer in subcommand cell field.
4. each one-level command table ends by a cell with null-command.
5. each command is a string which null terminated.
6. find function returns found cell address.
7. when not enough cells found find function returns a stub
   empty-body function and "invalid  syntax" response.
*/

void parser_create (command_dbase_t cmd_dbase, int pattern_max_len) {
	parser_set_command_dbase((dbase_record_t **)cmd_dbase);
	parser_set_pattern_max_len(pattern_max_len);
}

void parser_delete (void) {
	parser_set_command_dbase(NULL);
	parser_set_pattern_max_len(0);
}

void parse (const char * user_message) {
	dbase_record_t * command = _parser(user_message);
	parser_set_response(command->response ?
		command->response :
		PARSER_RESPONSE_STUB
	);
	parser_set_action(command->action ?
		command->action :
		parser_stub_action()
	);
	parser_set_parameter(command->parameter);
}