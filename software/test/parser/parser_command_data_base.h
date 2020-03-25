/*
 * Copyright © 2019-2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#ifndef _PARSER_COMMAND_DATA_BASE_H_
#define _PARSER_COMMAND_DATA_BASE_H_

#include "parser.h"
#include "response_defines_army.h"
#include "stddef.h"

static inline void set_some_parameter_ParamName (void) {

}

#define SUBCMD_SET_SOME_PARAMETER_NUM 1
START_CMD_GROUP (set_some_parameter, SUBCMD_SET_SOME_PARAMETER_NUM) {
	[0] = {
		.command = SOME_PARAMETER_NAME,
		.response =  RESP_SET_SOME_PARAMETER,
		.action = set_some_parameter_ParamName
	}
	END_CMD_GROUP_WITH_RESPONSE(
		SUBCMD_SET_SOME_PARAMETER_NUM,
		RESP_INVALID_PARAMETER)
};

#define SUBCMD_SET_NUM 2
START_CMD_GROUP (set, SUBCMD_SET_NUM) {
	[0] = {
		.command = SUBCMD_SOME_PARAMETER,
		.subcommand = SUBCOMMAND(set_some_parameter)
	},
	[1] = {
		.command = SUBCMD_ANOTHER_PARAM,
	}
	END_CMD_GROUP(SUBCMD_SET_NUM)
};

static inline void send_some_parameter_value (void) {
	// send response to user
}
#define SUBCMD_GET_NUM 2
START_CMD_GROUP (get, SUBCMD_GET_NUM) {
	[0] = {
		.command = SUBCMD_ANOTHER_PARAM,
		.response = RESP_ANOTHER_PARAM
	},

	[1] = {
		.command = SUBCMD_SOME_PARAMETER,
		.response = RESP_SOME_PARAMETER,
		.action = send_some_parameter_value,
	}
	END_CMD_GROUP(SUBCMD_GET_NUM)
};

#define TEST_CMD_NUM  3
#define test_cmd_HELP 0
#define test_cmd_GET  1
#define test_cmd_SET  2
#define cmd_NOT_FOUND (TEST_CMD_NUM - 1)

START_CMD_GROUP (test_commands, TEST_CMD_NUM) {
	[test_cmd_HELP] = {
		.command = CMD_HELP,
		.response = RESP_HELP,
		.action = help,
	},
	[test_cmd_GET] = {
		.command = CMD_GET,
		.subcommand = SUBCOMMAND(get)
	},
	[test_cmd_SET] = {
		.command = CMD_SET,
		.subcommand = SUBCOMMAND(set)
	}
	END_CMD_GROUP(TEST_CMD_NUM)
};

#include <stdint.h>
static inline char * config_dbase_response (uint16_t res_NUM) {
	return
		(res_NUM < TEST_CMD_NUM) ?
			test_commands[res_NUM].response :
			NULL
	;
}

#endif//_PARSER_COMMAND_DATA_BASE_H_