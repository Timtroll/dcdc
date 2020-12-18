#include "unity_fixture.h"
#include "user_actions_internal.h"
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

//[+]charger_start
//[+]charger_stop
//[+]charger_mode
//[+]charger_akk
//[+]pulse_width


TEST (set_group, charger_start) {
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charger start"
	);

	TEST_ASSERT_EQUAL_STRING("start", set_result->command);


	parse("set charger start");
	TEST_ASSERT_EQUAL_STRING(CHARGER_START_RESPONSE, parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charger_start, parser_action());
}

TEST (set_group, charger_stop) {
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charger stop"
	);

	TEST_ASSERT_EQUAL_STRING("stop", set_result->command);


	parse("set charger stop");
	TEST_ASSERT_EQUAL_STRING(CHARGER_STOP_RESPONSE, parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charger_stop, parser_action());
}

TEST (set_group, charger_akk) {
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charger akk akk1"
	);

	TEST_ASSERT_EQUAL_STRING(" akk1", set_result->parameter);
	TEST_ASSERT_EQUAL_STRING("akk", set_result->command);


	parse("set charger akk akk1");
	TEST_ASSERT_EQUAL_STRING(" akk1", parser_parameter());
	TEST_ASSERT_EQUAL_STRING(CHARGER_AKK_RESPONSE, parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charger_akk, parser_action());
}

TEST (set_group, charger_mode) {
		dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charger mode akk"
	);

	TEST_ASSERT_EQUAL_STRING(" akk", set_result->parameter);
	TEST_ASSERT_EQUAL_STRING("mode", set_result->command);


	parse("set charger mode akk");
	TEST_ASSERT_EQUAL_STRING(" akk", parser_parameter());
	TEST_ASSERT_EQUAL_STRING(CHARGER_MODE_RESPONSE, parser_response());
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
	TEST_ASSERT_EQUAL_STRING(CHARGER_PULSE_WIDTH_RESPONSE, parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charger_pulse_width, parser_action());
}

//[+]charging_period
//[+]charging_mode
//[+]charging_akk
//[+]charging_start
//[+]charging_stop


TEST (set_group, charging_time) {
	
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charging period 456"
	);

	TEST_ASSERT_EQUAL_STRING(" 456", set_result->parameter);
	TEST_ASSERT_EQUAL_STRING("period", set_result->command);


	parse("set charging period 456");
	TEST_ASSERT_EQUAL_STRING(" 456", parser_parameter());
	TEST_ASSERT_EQUAL_STRING(CHARGING_PERIOD_RESPONSE, parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charging_period, parser_action());
}

TEST (set_group, charging_mode) {
	
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charging mode default"
	);

	TEST_ASSERT_EQUAL_STRING("mode", set_result->command);
	TEST_ASSERT_EQUAL_STRING(" default", set_result->parameter);


	parse("set charging mode default");
	TEST_ASSERT_EQUAL_STRING(" default", parser_parameter());
	TEST_ASSERT_EQUAL_STRING(CHARGING_MODE_RESPONSE, parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charging_mode, parser_action());
}

TEST (set_group, charging_akk) {
	
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charging akk akk1"
	);

	TEST_ASSERT_EQUAL_STRING("akk", set_result->command);
	TEST_ASSERT_EQUAL_STRING(" akk1", set_result->parameter);


	parse("set charging akk akk1");
	TEST_ASSERT_EQUAL_STRING(" akk1", parser_parameter());
	TEST_ASSERT_EQUAL_STRING(CHARGING_AKK_RESPONSE, parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charging_akk, parser_action());
}

TEST (set_group, charging_start) {
	
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charging start"
	);

	TEST_ASSERT_EQUAL_STRING("start", set_result->command);


	parse("set charging start");
	TEST_ASSERT_EQUAL_STRING(CHARGING_START_RESPONSE, parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charging_start, parser_action());
}

TEST (set_group, charging_stop) {
	
	dbase_record_t * set_result =
		dbase_table_find(parser_command_dbase(),
		"set charging stop"
	);

	TEST_ASSERT_EQUAL_STRING("stop", set_result->command);


	parse("set charging stop");
	TEST_ASSERT_EQUAL_STRING(CHARGING_STOP_RESPONSE, parser_response());
	TEST_ASSERT_EQUAL_PTR(set_charging_stop, parser_action());
}


TEST_GROUP (get_group);

TEST_SETUP (get_group) {
	parser_create(&groups_of_commands, MAX_CMD_LEN);
}

TEST_TEAR_DOWN (get_group) {
	parser_delete();
}

TEST (get_group, voltage_scheme) {
	dbase_record_t * get_result =
		dbase_table_find(parser_command_dbase(),
		"get voltage scheme"
	);

	TEST_ASSERT_EQUAL_STRING("scheme", get_result->command);
	TEST_ASSERT_EQUAL_STRING(VOLTAGE_SCHEME_RESPONSE, get_result->response);
	TEST_ASSERT_EQUAL_PTR(get_voltage_scheme, get_result->action);


	parse("get voltage scheme");
	TEST_ASSERT_EQUAL_STRING(VOLTAGE_SCHEME_RESPONSE, parser_response());
	TEST_ASSERT_EQUAL_PTR(get_voltage_scheme, parser_action());
}

TEST (get_group, voltage_generator) {
	dbase_record_t * get_result =
		dbase_table_find(parser_command_dbase(),
		"get voltage generator"
	);

	TEST_ASSERT_EQUAL_STRING("generator", get_result->command);
	TEST_ASSERT_EQUAL_STRING(VOLTAGE_GENERATOR_RESPONSE, get_result->response);
	TEST_ASSERT_EQUAL_PTR(get_voltage_generator, get_result->action);


	parse("get voltage generator");
	TEST_ASSERT_EQUAL_STRING(VOLTAGE_GENERATOR_RESPONSE, parser_response());
	TEST_ASSERT_EQUAL_PTR(get_voltage_generator, parser_action());
}

TEST (get_group, voltage_output) {
	dbase_record_t * get_result =
		dbase_table_find(parser_command_dbase(),
		"get voltage output"
	);

	TEST_ASSERT_EQUAL_STRING("output", get_result->command);
	TEST_ASSERT_EQUAL_STRING(VOLTAGE_OUTPUT_RESPONSE, get_result->response);
	TEST_ASSERT_EQUAL_PTR(get_voltage_output, get_result->action);


	parse("get voltage output");
	TEST_ASSERT_EQUAL_STRING(VOLTAGE_OUTPUT_RESPONSE, parser_response());
	TEST_ASSERT_EQUAL_PTR(get_voltage_output, parser_action());
}

TEST (get_group, voltage_first_battery) {
	dbase_record_t * get_result =
		dbase_table_find(parser_command_dbase(),
		"get voltage first_battery"
	);

	TEST_ASSERT_EQUAL_STRING("first_battery", get_result->command);
	TEST_ASSERT_EQUAL_STRING(VOLTAGE_FIRST_BATTERY_RESPONSE, get_result->response);
	TEST_ASSERT_EQUAL_PTR(get_voltage_first_battery, get_result->action);


	parse("get voltage first_battery");
	TEST_ASSERT_EQUAL_STRING(VOLTAGE_FIRST_BATTERY_RESPONSE, parser_response());
	TEST_ASSERT_EQUAL_PTR(get_voltage_first_battery, parser_action());
}

TEST (get_group, voltage_second_battery) {
	dbase_record_t * get_result =
		dbase_table_find(parser_command_dbase(),
		"get voltage second_battery"
	);

	TEST_ASSERT_EQUAL_STRING("second_battery", get_result->command);
	TEST_ASSERT_EQUAL_STRING(VOLTAGE_SECOND_BATTERY_RESPONSE, get_result->response);
	TEST_ASSERT_EQUAL_PTR(get_voltage_second_battery, get_result->action);

	parse("get voltage second_battery");
	TEST_ASSERT_EQUAL_STRING(VOLTAGE_SECOND_BATTERY_RESPONSE, parser_response());
	TEST_ASSERT_EQUAL_PTR(get_voltage_second_battery, parser_action());
}




TEST_GROUP (internal_function);

TEST_SETUP (internal_function) {
	parser_create(&groups_of_commands, MAX_CMD_LEN);
}

TEST_TEAR_DOWN (internal_function) {
	parser_delete();
}

TEST(internal_function, crop_trash_function){
	TEST_ASSERT_EQUAL_STRING("get charging fall_pulse", crop_trash("get charging fall_pulse\nfsdfasdfas"));
	TEST_ASSERT_EQUAL_PTR(NULL , crop_trash("get charging fall_pulse\nfsdfasdfassdfjsdjfhaslkjdhflkjasdhflkjhasdflkjashkjdsfjk;sldajf;lksajdf;lksjdlfkjs;dlkfjskdjfdlfjhasksdfsadfhsdfjhsdljkfhaskjdhflasjflkashfdldjhf"));
	TEST_ASSERT_EQUAL_STRING("get charging fall_pulse", crop_trash("get charging fall_pulse\rfsdfasdfas"));
}

TEST(internal_function, find_spaces_in_string){
	TEST_ONLY();
	parse("set charging t_positive_pulse 45");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(T_POSITIVE_PULSE_PARAMETER, parser_parameter()));
	parse("set charging t_positive_pulse    45     ");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(T_POSITIVE_PULSE_PARAMETER, parser_parameter()));
	parse("set charging t_positive_pulse 45 j");
	TEST_ASSERT_EQUAL_INT(INCORRECT_PARAMETER_INPUT, check_parameter(T_POSITIVE_PULSE_PARAMETER, parser_parameter()));
	parse("set charging t_positive_pulse 45                                      j");
	TEST_ASSERT_EQUAL_INT(INCORRECT_PARAMETER_INPUT, check_parameter(T_POSITIVE_PULSE_PARAMETER, parser_parameter()));
}

TEST(internal_function, return_cleared_string){
	parse("set charging t_positive_pulse 45\n");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(T_POSITIVE_PULSE_PARAMETER, parser_parameter()));
	parse("set charger mode akk{}\n");
	TEST_ASSERT_EQUAL_INT(INCORRECT_PARAMETER_INPUT, check_parameter(MODE_CHARGER_PARAMETER, parser_parameter()));
	parse("set charger mode akk\n{}");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(MODE_CHARGER_PARAMETER, parser_parameter()));
}

TEST(internal_function, check_parameter_period){
	parse("set charging period 700\n");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(PERIOD_PARAMETER, parser_parameter()));	
	parse("set charging period 7a00\n");
	TEST_ASSERT_EQUAL_INT(INCORRECT_PARAMETER_INPUT, check_parameter(PERIOD_PARAMETER, parser_parameter()));	
	parse("set charging period 7{00\n");
	TEST_ASSERT_EQUAL_INT(INCORRECT_PARAMETER_INPUT, check_parameter(PERIOD_PARAMETER, parser_parameter()));	
	parse("set charging period 1\n");
	TEST_ASSERT_EQUAL_INT(LESS_POSSIBLE, check_parameter(PERIOD_PARAMETER, parser_parameter()));	
	parse("set charging period 64000\n");
	TEST_ASSERT_EQUAL_INT(MORE_POSSIBLE, check_parameter(PERIOD_PARAMETER, parser_parameter()));	
}




TEST_GROUP (user_action);

//[+]analysis_error_type
//[+]analysis_error_hardware
//[+]do_action_function


TEST_SETUP (user_action) {
	parser_create(&groups_of_commands, MAX_CMD_LEN);
}

TEST_TEAR_DOWN (user_action) {
	parser_delete();
}

TEST(user_action, analysis_error_type){
	parse("set charging period 7фф00\n");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Your error: Invalid parameter\n\r", get_user_response());

	parse("set charger mode akk4\n");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Your error: Non-existent charger\n\r", get_user_response());

	parse("set charger pulse_width 99999999\n");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Your error: Incorrect pulse width\n\r", get_user_response());

	parse("set charging period 1\n");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Your error: The entered value is less than acceptable\n\r", get_user_response());

	parse("set charging period 64000\n");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Your error: The entered value is more than acceptable\n\r", get_user_response());
}

TEST(user_action, analysis_error_hardware){
	parse("set charger mode akk");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("You set the mode:akk\n\r", get_user_response());

	parse("set charging period 700.5");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("You set the period:700.5\n\r", get_user_response());

	parse("set charger pulse_width 50");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("You set the pulse width:50\n\r", get_user_response());

	parse("set charging mode default");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("You set the charging mode:default\n\r", get_user_response());

	parse("set charging need_disch_pulse true");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("The need for negative pulse:true\n\r", get_user_response());

	parse("set charging t_positive_pulse 100");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Duration + pulse:100\n\r", get_user_response());

	parse("set charging t_negative_pulse 100");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Duration - pulse:100\n\r", get_user_response());
}

TEST(user_action, do_action_function){

	parse("set charger start");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Status: Start\n\r", get_user_response());

	parse("set charger stop");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Status: Stop\n\r", get_user_response());

	parse("set charger mode akk");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("You set the mode:akk\n\r", get_user_response());

	parse("set charging akk akk1");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Now charging:akk1\n\r", get_user_response());

	parse("set charging start");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Charging: Start\n\r", get_user_response());

	parse("set charging stop");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Charging: Stop\n\r", get_user_response());
}




TEST_GROUP (get_function);




TEST_SETUP (get_function) {
	parser_create(&groups_of_commands, MAX_CMD_LEN);
}

TEST_TEAR_DOWN (get_function) {
	parser_delete();
}

TEST(get_function, test_functions){
	parse("get charging t_positive_pulse");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("The positive pulse is now: 0\n\r", get_user_response());

	parse("get charging t_negative_pulse");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("The negative pulse is now: 0\n\r", get_user_response());

	parse("get charging need_disch_pulse");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("The need for negative pulse: false\n\r", get_user_response());

	parse("get charging pulse_power");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("The amount of charge transferred: 0.100\n\r", get_user_response());

	parse("get charging fall_pulse");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Voltage drop ratio: 0.100\n\r", get_user_response());
}

TEST(get_function, invalid_response){
	parse("set charging mode default");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("You set the charging mode:default\n\r", get_user_response());
	
	parse("set charging mode default");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("You set the charging mode:default\n\r", get_user_response());
	
	parse("set chargng stop");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Incorrect syntax\n\r", get_user_response());

}


TEST(get_function, other_get_functions){
	parse("get charger mode");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Operating mode: AKK\n\r", get_user_response());

	parse("get charger output_akk");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("The battery is discharging: AKK1\n\r", get_user_response());

	parse("get charger output_pw");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Output pulse width: 0\n\r", get_user_response());

	parse("get charging pulse_power");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("The amount of charge transferred: 0.100\n\r", get_user_response());

	parse("get charging pulse_power");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("The amount of charge transferred: 0.100\n\r", get_user_response());

}
