#include "unity_fixture.h"

#include "find_internal.h"
#include "../parser/parser_command_data_base.h"


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