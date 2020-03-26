/*
 * Copyright © 2019-2020 Daniil D. Ryabinin (ryabiko1953@gmail.com)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#include "unity_fixture.h"
#include "../../inc/smart_ups_data_base.h"
#include "../../inc/find/find_internal.h"


TEST_GROUP (charger);

TEST_SETUP (charger)
{
	parser_create(&smart_charger_commands, MAX_CMD_LEN);
}

TEST_TEAR_DOWN (charger)
{
	parser_delete();
}

// #include "action.h"
TEST (charger, right_extract_of_set_command) {
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set voltage_cut_off 120"
	);

	TEST_ASSERT_EQUAL_STRING(" 120", set_result->parameter);
	TEST_ASSERT_EQUAL_STRING("voltage_cut_off", set_result->command);

	parse("set voltage_cut_off 120");
	TEST_ASSERT_EQUAL_STRING(" 120", parser_parameter());
}

TEST (charger, right_extract_of_get_command) {
	dbase_record_t * get_result =
		dbase_table_find(parser_command_dbase(),
		"get voltage_cut_off"
	);

	TEST_ASSERT_EQUAL_STRING("voltage_cut_off", get_result->command);
	TEST_ASSERT_EQUAL_STRING("", get_result->response);
}

TEST (charger, right_work_with_structure) {
	parse("set voltage_cut_off 120");
	parser_action()();

	TEST_ASSERT_EQUAL_STRING(" 120", memory.parameter);
	TEST_ASSERT_EQUAL_STRING("", memory.response);

	parse("set charge_current 534");
	parser_action()();

	TEST_ASSERT_EQUAL_STRING(" 534", memory.parameter);
	TEST_ASSERT_EQUAL_STRING("", memory.response);
}

TEST (charger, right_getting) {
	parse("get voltage_cut_off");
	parser_action()();

	TEST_ASSERT_EQUAL_STRING("123456789", memory.parameter);
}