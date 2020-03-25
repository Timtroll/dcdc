/*
 * Copyright © 2019-2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#ifndef _RESPONSE_DEFINES_ARMY_H_
#define _RESPONSE_DEFINES_ARMY_H_

#define MAX_CMD_LEN      30//100

#define NEWLINE "\r"
#define NO_RESPONSE ""

static inline void help (void) {/*help action*/}

//___COMMANDS___//
#define COMMAND_LIST \
"1. help "NEWLINE \
"2. get   [ some_parameter | another_param]"NEWLINE \
"3. set   [ some_parameter | another_param]"NEWLINE \

#define CMD_HELP                     "help"
	#define RESP_HELP NO_RESPONSE

#define CMD_SET                      "set"
	#define SUBCMD_SOME_PARAMETER       "some_parameter"
		#define RESP_SET_SOME_PARAMETER \
		"valid parameters:"NEWLINE \
		"1. val 1"NEWLINE \
		"2. val 2"NEWLINE \
		"3. val 3"NEWLINE
		#define RESP_INVALID_PARAMETER  "invalid (must be 0 - 255)"NEWLINE
	#define SUBCMD_ANOTHER_PARAM        "another_param"

#define SOME_PARAMETER_NAME   "some_parameter_name"

#define CMD_GET                       "get"
	//      SUBCMD_ANOTHER_PARAM      "another_param"
		#define RESP_ANOTHER_PARAM    "another parameter: "
	//      SUBCMD_SOME_PARAMETER     "some_parameter"
		#define RESP_SOME_PARAMETER   "some parameter: "

#endif//_RESPONSE_DEFINES_ARMY_H_
