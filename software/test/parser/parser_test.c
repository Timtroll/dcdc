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
