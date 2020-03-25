/*
 * Copyright © 2019-2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#include "unity_fixture.h"
#include "parser_command_data_base.h"


//need to connect this file with "parser_internal.h"

#include "find_internal.h"

#include "../inc/parser/parser_internal.h"
// #include "../src/parser/parser_internal.c"

#define _TEST_MESSAGE_ "find me please"

TEST_GROUP (parser);

TEST_SETUP (parser)
{
	parser_create(&test_commands, MAX_CMD_LEN);
}

TEST_TEAR_DOWN (parser)
{
	parser_delete();
}



TEST (parser, create_store_command_dbase_correctly) {
	parser_create(&test_commands, 0);

	TEST_ASSERT_TRUE_MESSAGE(parser_command_dbase() == test_commands,
		"stored pointer invalid");
}

TEST (parser, create_store_max_pattern_len_correctly) {
	parser_create(NULL, 1731);

	TEST_ASSERT_TRUE(1731 == parser_pattern_max_len());
}

TEST (parser, delete_clear_command_dbase) {
	parser_delete();

	TEST_ASSERT_TRUE_MESSAGE(parser_command_dbase() == NULL,
		"command tree not deleted");
}

TEST (parser, delete_clear_pettern_max_len_correctly) {
	parser_set_pattern_max_len(1432);

	parser_delete();

	TEST_ASSERT_TRUE(0 == parser_pattern_max_len());
}

TEST (parser, _parser_return_stub_response_if_cmd_dbase_empty) {
	parser_delete();
	dbase_record_t * result = _parser(_TEST_MESSAGE_);

	TEST_ASSERT_EQUAL_STRING(parser_response_stub(), result->response);
}

TEST (parser, _parser_return_stub_action_if_cmd_dbase_empty) {
	parser_delete();
	dbase_record_t * result = _parser(_TEST_MESSAGE_);

	TEST_ASSERT_TRUE_MESSAGE(parser_stub_action() == result->action,
		"expected.action not equal result->action");
}

/*
[v] parse_install_stub_RESPONSE_if_cmd_NOT_found
[v] parse_install_stub_ACTION_if_cmd_NOT_found
[v] parse_install_correct_RESPONSE_if_cmd_found
[v] parse_install_correct_ACTION_if_cmd_found
[v] parse_install_stub_RESPONSE_if_cmd_found_with_empty_response
[v] parse_install_stub_ACTION_if_cmd_found_with_empty_action
*/

#define cmd_dbase_STARTED_FROM(cmd_NUM) ( \
	(command_dbase_t)&test_commands[cmd_NUM] \
)
#define PARSER_CREATE(dbase) parser_create(dbase, MAX_CMD_LEN)

TEST (parser, parse_install_correct_RESPONSE_if_cmd_found) {
	PARSER_CREATE(cmd_dbase_STARTED_FROM(test_cmd_HELP));
	parse(CMD_HELP);

	TEST_ASSERT_EQUAL_STRING(RESP_HELP, parser_response());
}

TEST (parser, parse_install_correct_ACTION_if_cmd_found) {
	PARSER_CREATE(cmd_dbase_STARTED_FROM(test_cmd_HELP));
	parse(CMD_HELP);

	TEST_ASSERT_EQUAL_PTR(test_commands[test_cmd_HELP].action, parser_action());
}

TEST (parser, parse_install_stub_ACTION_if_cmd_found_with_empty_action) {
	PARSER_CREATE(cmd_dbase_STARTED_FROM(test_cmd_SET));
	parse(CMD_SET);

	TEST_ASSERT_EQUAL_PTR(parser_stub_action(), parser_action());
}

TEST (parser, parse_install_stub_RESPONSE_if_cmd_found_with_empty_response) {
	PARSER_CREATE(cmd_dbase_STARTED_FROM(test_cmd_SET));
	parse(CMD_SET);

	TEST_ASSERT_EQUAL_STRING(parser_response_stub(), parser_response());
}

TEST (parser, parse_install_stub_RESPONSE_if_cmd_NOT_found) {
	parser_set_response("not a stub");
	PARSER_CREATE(cmd_dbase_STARTED_FROM(cmd_NOT_FOUND));
	parse(_TEST_MESSAGE_);

	TEST_ASSERT_EQUAL_STRING(parser_response_stub(), parser_response());
}

TEST (parser, parse_install_stub_ACTION_if_cmd_NOT_found) {
	parser_set_action(test_commands[test_cmd_HELP].action);
	PARSER_CREATE(cmd_dbase_STARTED_FROM(cmd_NOT_FOUND));
	parse(_TEST_MESSAGE_);

	TEST_ASSERT_EQUAL_PTR(parser_stub_action(), parser_action());
}

TEST_GROUP (find_cmd);

TEST_SETUP (find_cmd)
{
	PARSER_CREATE(&test_commands);
}

TEST_TEAR_DOWN (find_cmd)
{
	parser_delete();
}

/*
[v] extract_pattern_return_empty_string_if_len_owerflows
[v] extract_pattern_return_empty_string_if_cmd_len_bigger_than_msg_len
[v] extract_pattern_return_empty_string_if_extracting_BEFORE_msg
[v] extract_pattern_return_empty_string_if_extracting_AFTER_msg
[v] extract_pattern_return_pattern_if_len_valid
*/
#include <string.h>
static char * some_string = "some_string";

TEST (find_cmd, extract_pattern_return_empty_string_if_len_owerflows) {
	char * result = extract_pattern(some_string, 0, 100);

	TEST_ASSERT_EQUAL_STRING("", result);
}

TEST (find_cmd, extract_pattern_return_null_if_cmd_len_bigger_than_msg_len) {
	char * result = extract_pattern(some_string, 0, strlen(some_string) + 1);

	TEST_ASSERT_EQUAL_STRING("", result);
}

TEST (find_cmd, extract_pattern_return_empty_string_if_extracting_BEFORE_msg) {
	char * result = extract_pattern(some_string, -1, strlen(some_string));

	TEST_ASSERT_EQUAL_STRING("", result);
}

TEST (find_cmd, extract_pattern_return_empty_string_if_extracting_AFTER_msg) {
	char * result = extract_pattern(some_string, strlen(some_string) + 1, strlen(some_string));

	TEST_ASSERT_EQUAL_STRING("", result);
}

TEST (find_cmd, extract_pattern_return_pattern_if_len_valid) {
	char * result = extract_pattern(some_string, 0, strlen(some_string));

	TEST_ASSERT_EQUAL_STRING(some_string, result);
}

static inline char * _extract (char * str, uint16_t len) {
	return extract_pattern(str, 0, len);
}

TEST (find_cmd, recursive_handling_model) {
	char * input = "	set some_parameter 1";

	char * msg = free_spaces(input);
	char * pattern1 = _extract(msg, strlen("set"));
	TEST_ASSERT_EQUAL_STRING("set", pattern1);

	msg = free_spaces(msg + strlen("set"));
	char * pattern2 = _extract(msg, strlen("some_parameter"));
	TEST_ASSERT_EQUAL_STRING("some_parameter", pattern2);

	msg = free_spaces(msg + strlen("some_parameter"));
	char * pattern3 = _extract(msg, strlen("1"));
	TEST_ASSERT_EQUAL_STRING("1", pattern3);
}

/*
[v] dbase_table_find_return_null_if_not_found
[v] dbase_table_find_return_correct_record_in_not_nested_table
[v] dbase_table_find_return_correct_record_in_two_tables
[v] dbase_table_find_return_correct_record_in_nested_tables
*/

TEST (find_cmd, dbase_table_find_return_null_if_not_found) {
	dbase_record_t * result =
		dbase_table_find(parser_command_dbase(), some_string);

	TEST_ASSERT_NULL(result->command);
}

TEST (find_cmd, dbase_table_find_return_correct_record_in_not_nested_table) {
	dbase_record_t * result =
		dbase_table_find(parser_command_dbase(), CMD_HELP);

	TEST_ASSERT_EQUAL_STRING(CMD_HELP, result->command);
}

/*
[v] free_spaces_handle_str_started_with_space_and_tabs
[v] free_spaces_handle_str_started_with_no_space_no_tabs

*/

TEST (find_cmd, free_spaces_handle_str_started_with_space_and_tabs) {
	char * result = free_spaces("  	 	here spase exist and	tab at start");

	TEST_ASSERT_EQUAL_STRING("here spase exist and	tab at start", result);
}

TEST (find_cmd, free_spaces_handle_str_started_with_no_space_no_tabs) {
	char * result = free_spaces("here no spase no tabs at start");

	TEST_ASSERT_EQUAL_STRING("here no spase no tabs at start", result);
}

TEST (find_cmd, dbase_table_find_return_null_command_if_command_not_full) {
	char * not_full_command = CMD_SET" "SUBCMD_SOME_PARAMETER;
	dbase_record_t * result =
		dbase_table_find(parser_command_dbase(), not_full_command);

	TEST_ASSERT_NULL(result->command);
	TEST_ASSERT_EQUAL_STRING(
		RESP_INVALID_PARAMETER,
		result->response
	);
}

/* now return exit_point, but it is temporary */
IGNORE_TEST (find_cmd, dbase_table_find_return_null_if_incorrect_command) {
	dbase_record_t * result =
		dbase_table_find(parser_command_dbase(),
			CMD_SET" "SUBCMD_ANOTHER_PARAM" some_incorrect_end  ");

	TEST_ASSERT_NULL(result);
}

TEST (find_cmd, dbase_table_find_return_correct_record_in_two_tables) {
	dbase_record_t * result =
		dbase_table_find(parser_command_dbase(),
			CMD_SET" "SUBCMD_ANOTHER_PARAM);

	TEST_ASSERT_EQUAL_STRING(SUBCMD_ANOTHER_PARAM, result->command);
}

TEST (find_cmd, dbase_table_find_return_correct_record_in_nested_tables) {
	dbase_record_t * result =
		dbase_table_find(parser_command_dbase(),
			CMD_SET" "SUBCMD_SOME_PARAMETER" "SOME_PARAMETER_NAME);

	TEST_ASSERT_EQUAL_STRING(SOME_PARAMETER_NAME, result->command);
}

TEST (find_cmd, set_parameter_if_message_continue_without_subcommand) {
	dbase_record_t * result =
		dbase_table_find(parser_command_dbase(),
			"set another_param 0x12");
		TEST_ASSERT_EQUAL_STRING(" 0x12", result->parameter);
}
