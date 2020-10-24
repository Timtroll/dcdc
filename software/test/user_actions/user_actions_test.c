#include "unity_fixture.h"

#include "user_comand.h"
#include "../../inc/parser/parser.h"
#include "../../inc/find/find_internal.h"

TEST_GROUP (user_actions);

TEST_SETUP (user_actions) {
	parser_create(&groups_of_commands, MAX_CMD_LEN);
}

TEST_TEAR_DOWN (user_actions) {
	parser_delete();
}

TEST (user_actions, right_extract_of_set_command) {
	
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charger start 120"
	);

	TEST_ASSERT_EQUAL_STRING(" 120", set_result->parameter);
	TEST_ASSERT_EQUAL_STRING("start", set_result->command);

	parse("set charger start 120");
	TEST_ASSERT_EQUAL_STRING(" 120", parser_parameter());
	TEST_ASSERT_EQUAL_STRING("charger start was set", parser_response());
	// TEST_ASSERT_EQUAL_STRING(" 120", parser_parameter());
}


