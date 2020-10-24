#include "unity_fixture.h"

#include "user_comand.h"
#include "../../inc/parser/parser.h"
#include "../../inc/find/find_internal.h"

TEST_GROUP (set_group);

TEST_SETUP (set_group) {
	parser_create(&groups_of_commands, MAX_CMD_LEN);
}

TEST_TEAR_DOWN (set_group) {
	parser_delete();
}

TEST (set_group, charger_start) {
	
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charger start 123"
	);

	TEST_ASSERT_EQUAL_STRING(" 123", set_result->parameter);
	TEST_ASSERT_EQUAL_STRING("start", set_result->command);


	parse("set charger start 123");
	TEST_ASSERT_EQUAL_STRING(" 123", parser_parameter());
	TEST_ASSERT_EQUAL_STRING("charger start was set", parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charger_start, parser_action());
}

TEST (set_group, charger_stop) {
	
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charger stop 120"
	);

	TEST_ASSERT_EQUAL_STRING(" 120", set_result->parameter);
	TEST_ASSERT_EQUAL_STRING("stop", set_result->command);


	parse("set charger stop 120");
	TEST_ASSERT_EQUAL_STRING(" 120", parser_parameter());
	TEST_ASSERT_EQUAL_STRING("charger stop was set", parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charger_stop, parser_action());
}

TEST (set_group, charger_mode) {
	
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charger mode 234"
	);

	TEST_ASSERT_EQUAL_STRING(" 234", set_result->parameter);
	TEST_ASSERT_EQUAL_STRING("mode", set_result->command);


	parse("set charger mode 234");
	TEST_ASSERT_EQUAL_STRING(" 234", parser_parameter());
	TEST_ASSERT_EQUAL_STRING("charger mode was set", parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charger_mode, parser_action());
}

TEST (set_group, charger_pulse_width) {
	
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charger pulse_width 345"
	);

	TEST_ASSERT_EQUAL_STRING(" 345", set_result->parameter);
	TEST_ASSERT_EQUAL_STRING("pulse_width", set_result->command);


	parse("set charger pulse_width 345");
	TEST_ASSERT_EQUAL_STRING(" 345", parser_parameter());
	TEST_ASSERT_EQUAL_STRING("charger pulse_width was set", parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charger_pulse_width, parser_action());
}

TEST (set_group, charging_time) {
	
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charging time 456"
	);

	TEST_ASSERT_EQUAL_STRING(" 456", set_result->parameter);
	TEST_ASSERT_EQUAL_STRING("time", set_result->command);


	parse("set charging time 456");
	TEST_ASSERT_EQUAL_STRING(" 456", parser_parameter());
	TEST_ASSERT_EQUAL_STRING("charging time was set", parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charging_time, parser_action());
}

TEST (set_group, charging_start_akk_1) {
	
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charging start_akk_1 567"
	);

	TEST_ASSERT_EQUAL_STRING(" 567", set_result->parameter);
	TEST_ASSERT_EQUAL_STRING("start_akk_1", set_result->command);


	parse("set charging start_akk_1 567");
	TEST_ASSERT_EQUAL_STRING(" 567", parser_parameter());
	TEST_ASSERT_EQUAL_STRING("charging start_akk_1 was set", parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charging_start_akk_1, parser_action());
}

TEST (set_group, charging_start_akk_2) {
	
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charging start_akk_2 678"
	);

	TEST_ASSERT_EQUAL_STRING(" 678", set_result->parameter);
	TEST_ASSERT_EQUAL_STRING("start_akk_2", set_result->command);


	parse("set charging start_akk_2 678");
	TEST_ASSERT_EQUAL_STRING(" 678", parser_parameter());
	TEST_ASSERT_EQUAL_STRING("charging start_akk_2 was set", parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charging_start_akk_2, parser_action());
}

TEST (set_group, charging_stop) {
	
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charging stop 789"
	);

	TEST_ASSERT_EQUAL_STRING(" 789", set_result->parameter);
	TEST_ASSERT_EQUAL_STRING("stop", set_result->command);


	parse("set charging stop 789");
	TEST_ASSERT_EQUAL_STRING(" 789", parser_parameter());
	TEST_ASSERT_EQUAL_STRING("charging stop was set", parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charging_stop, parser_action());
}







TEST_GROUP (get_group);

TEST_SETUP (get_group) {
	parser_create(&groups_of_commands, MAX_CMD_LEN);
}

TEST_TEAR_DOWN (get_group) {
	parser_delete();
}

TEST (get_group, voltage_scheme_generator) {
	dbase_record_t * get_result =
		dbase_table_find(parser_command_dbase(),
		"get voltage scheme_generator"
	);

	TEST_ASSERT_EQUAL_STRING("scheme_generator", get_result->command);
	TEST_ASSERT_EQUAL_STRING("voltage scheme_generator was got", get_result->response);
	TEST_ASSERT_EQUAL_PTR(get_voltage_scheme_generator, get_result->action);


	parse("get voltage scheme_generator");
	TEST_ASSERT_EQUAL_STRING("voltage scheme_generator was got", parser_response());
	TEST_ASSERT_EQUAL_PTR(get_voltage_scheme_generator, parser_action());
}

TEST (get_group, voltage_output) {
	dbase_record_t * get_result =
		dbase_table_find(parser_command_dbase(),
		"get voltage output"
	);

	TEST_ASSERT_EQUAL_STRING("output", get_result->command);
	TEST_ASSERT_EQUAL_STRING("voltage output was got", get_result->response);
	TEST_ASSERT_EQUAL_PTR(get_voltage_output, get_result->action);


	parse("get voltage output");
	TEST_ASSERT_EQUAL_STRING("voltage output was got", parser_response());
	TEST_ASSERT_EQUAL_PTR(get_voltage_output, parser_action());
}

TEST (get_group, voltage_first_battery) {
	dbase_record_t * get_result =
		dbase_table_find(parser_command_dbase(),
		"get voltage first_battery"
	);

	TEST_ASSERT_EQUAL_STRING("first_battery", get_result->command);
	TEST_ASSERT_EQUAL_STRING("voltage of first battery was got", get_result->response);
	TEST_ASSERT_EQUAL_PTR(get_voltage_first_battery, get_result->action);


	parse("get voltage first_battery");
	TEST_ASSERT_EQUAL_STRING("voltage of first battery was got", parser_response());
	TEST_ASSERT_EQUAL_PTR(get_voltage_first_battery, parser_action());
}

TEST (get_group, voltage_second_battery) {
	dbase_record_t * get_result =
		dbase_table_find(parser_command_dbase(),
		"get voltage second_battery"
	);

	TEST_ASSERT_EQUAL_STRING("second_battery", get_result->command);
	TEST_ASSERT_EQUAL_STRING("voltage of second battery was got", get_result->response);
	TEST_ASSERT_EQUAL_PTR(get_voltage_second_battery, get_result->action);


	parse("get voltage second_battery");
	TEST_ASSERT_EQUAL_STRING("voltage of second battery was got", parser_response());
	TEST_ASSERT_EQUAL_PTR(get_voltage_second_battery, parser_action());
}
