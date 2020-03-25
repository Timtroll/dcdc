/*
 * Copyright © 2019-2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */
#include "find_internal.h"

#include <string.h>
#include <stdint.h>	
#include <stdbool.h>


#define EXTRACT_MSG_MAX_SIZE 100 //parser_pattern_max_len


bool is_delimeter (char symbol) {
	return (symbol == ' ' || symbol == '\t' || symbol == '\0');
}


static inline bool extraction_possible (char * message, uint16_t from_here, uint16_t cmd_len) {
	register int msg_len = strlen(message);

	bool
		pos_in_message = from_here < msg_len,
		cmd_in_message = cmd_len <= msg_len,
		sym_not_delimeter = is_delimeter(message[from_here + cmd_len]);

	return
		pos_in_message &&
		cmd_in_message &&
		sym_not_delimeter &&
		cmd_len < EXTRACT_MSG_MAX_SIZE;
}

char * extract_pattern (char * message, uint16_t from_here, uint16_t cmd_len) {
	static char pattern [EXTRACT_MSG_MAX_SIZE] = {0};
	*pattern = '\0';

	if (extraction_possible(message, from_here, cmd_len)) {
		strncpy(pattern, &message[from_here], cmd_len);
		pattern[from_here + cmd_len] = '\0';
	}

	return pattern;
}

char * free_spaces (char * source) {
	char * delimeters = {" \t"};
	int del_quantity = strspn(source, delimeters);
    return (source + del_quantity);
}


static inline char * extract_pattern_from_start (char * string, uint16_t pattern_len) {
	return extract_pattern(string, 0, pattern_len);
}

static inline bool pattern_matched (char * pattern, char * template) {
	return !strcmp(pattern, template);
}

static inline bool message_payload_continue (char * message) {
	return strlen(free_spaces(message));
}


dbase_record_t * dbase_table_find (dbase_table_t table, char * message) {
	static uint16_t record;	
	static bool not_found;

	not_found = true;
	record = 0;

	while (table[record].command) {
		char * command = table[record].command;
		int cmd_len = strlen(command);
		char
			* msg_after_spaces = free_spaces(message),
			* pattern = extract_pattern_from_start(msg_after_spaces, cmd_len);

		if (pattern_matched(pattern, command)) {
			dbase_record_t * sub_table = table[record].subcommand;
			register char * msg_after_pattern = msg_after_spaces + cmd_len;

			if (sub_table || message_payload_continue(msg_after_pattern)) {
				if (sub_table == NULL) {
					 table[record].parameter = msg_after_pattern;
					return &table[record];
				}
				return dbase_table_find(sub_table, msg_after_pattern);
			}
			else { // sub-pattern matched (record was found)
				not_found = false;
				break;
			}
		}
		else if (not_found) { // look at next record
			record++;
		}
	}
	return &table[record];
}