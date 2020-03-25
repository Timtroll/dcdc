/*
 * Copyright © 2019-2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#include "find_internal.h"

dbase_record_t * find_cmd (const char * message) {
	static char msg [PARSER_PATTERN_MAX_LEN_DEFAULT] = {0};

	uint16_t len = strlen(message);
	strncpy(msg, message, len);
	if (len < PARSER_PATTERN_MAX_LEN_DEFAULT) {
		msg[len] = '\0';
	}
	return dbase_table_find(parser_command_dbase(), msg);
}