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
	TEST_ASSERT_EQUAL_STRING(CHARGING_AKK_RESPONSE, parser_response());
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



//[]voltage_generator
//[]voltage_scheme
//[]voltage_output
//[]first_battery
//[]second_battery


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






TEST_GROUP (parameter_control);

//[]check_parameter_mode
//[]check_parameter_pulse_wight
//[]check_parameter_time
//[?]check_unnecessary_parameters

TEST_SETUP (parameter_control) {
	parser_create(&groups_of_commands, MAX_CMD_LEN);
}

TEST_TEAR_DOWN (parameter_control) {
	parser_delete();
}



TEST (parameter_control, check_parameter_mode) {
	parse("set charger mode akk");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(MODE_CHARGER_PARAMETER, parser_parameter()));
	
	parse("set charger mode  		  akk         ");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(MODE_CHARGER_PARAMETER, parser_parameter()));
	
	parse("set charger mode gen");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(MODE_CHARGER_PARAMETER, parser_parameter()));
	

	parse("set charger mode  		gen _d 			");
	TEST_ASSERT_EQUAL_INT(INCORRECT_PARAMETER_INPUT, check_parameter(MODE_CHARGER_PARAMETER, parser_parameter()));
	
	parse("set charger mode  		");
	TEST_ASSERT_EQUAL_INT(INCORRECT_PARAMETER_INPUT, check_parameter(MODE_CHARGER_PARAMETER, parser_parameter()));
	
	parse("set charger mode  	qqqqq		");
	TEST_ASSERT_EQUAL_INT(UNEXISTING_CHARGER, check_parameter(MODE_CHARGER_PARAMETER, parser_parameter()));
}

TEST (parameter_control, check_parameter_pulse_widht) {
	parse("set charger pulse_width 7");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(PULSE_WIDTH_PARAMETER, parser_parameter()));
	
	parse("set charger pulse_width        7    ");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(PULSE_WIDTH_PARAMETER, parser_parameter()));
	
	parse("set charger pulse_width 11 a");
	TEST_ASSERT_EQUAL_INT(INCORRECT_PARAMETER_INPUT, check_parameter(PULSE_WIDTH_PARAMETER, parser_parameter()));
	
	parse("set charger pulse_width 11aaa");
	TEST_ASSERT_EQUAL_INT(INCORRECT_PARAMETER_INPUT, check_parameter(PULSE_WIDTH_PARAMETER, parser_parameter()));
	
	parse("set charger pulse_width    		 	 	");
	TEST_ASSERT_EQUAL_INT(INCORRECT_PARAMETER_INPUT, check_parameter(PULSE_WIDTH_PARAMETER, parser_parameter()));
	
	parse("set charger pulse_width 1");
	TEST_ASSERT_EQUAL_INT(INCORRECT_PULSE_WIDTH, check_parameter(PULSE_WIDTH_PARAMETER, parser_parameter()));
	
	parse("set charger pulse_width 50000000000000000000");
	TEST_ASSERT_EQUAL_INT(INCORRECT_PULSE_WIDTH, check_parameter(PULSE_WIDTH_PARAMETER, parser_parameter()));
	
	//parse("set charger pulse_width 5555555ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd555555555555555555555555555555555555555555555555555555555555555555555555");
	//TEST_ASSERT_EQUAL_INT(INCORRECT_PARAMETER_INPUT, check_parameter(PULSE_WIDTH_PARAMETER,parser_parameter()));
	//!!VERY STRANGER RESOLT!!

	parse("set charger pulse_width            		 	 	 		");
	TEST_ASSERT_EQUAL_INT(INCORRECT_PARAMETER_INPUT, check_parameter(PULSE_WIDTH_PARAMETER, parser_parameter()));
}

TEST (parameter_control, check_parameter_time) {
	parse("set charging period 700");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(PERIOD_PARAMETER, parser_parameter()));

	parse("set charging period    700    ");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(PERIOD_PARAMETER, parser_parameter()));
	
	parse("set charging period 700 dsdfsfsdasksi ");
	TEST_ASSERT_EQUAL_INT(INCORRECT_PARAMETER_INPUT, check_parameter(PERIOD_PARAMETER, parser_parameter()));
	
	parse("set charging period 700dsdfsfsdasksi");
	TEST_ASSERT_EQUAL_INT(INCORRECT_PARAMETER_INPUT, check_parameter(PERIOD_PARAMETER, parser_parameter()));
	
	parse("set charging period 5000000000");
	TEST_ASSERT_EQUAL_INT(MORE_POSSIBLE, check_parameter(PERIOD_PARAMETER, parser_parameter()));

	parse("set charging period 5");
	TEST_ASSERT_EQUAL_INT(LESS_POSSIBLE, check_parameter(PERIOD_PARAMETER, parser_parameter()));
}

TEST (parameter_control, check_unnecessary_parameters){
	parse("set charger start");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(OTHERS, parser_parameter()));		
	parse("set charger stop");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(OTHERS, parser_parameter()));		

	parse("set charging start_akk1");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(OTHERS, parser_parameter()));
	parse("set charging start_akk2");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(OTHERS, parser_parameter()));
	parse("set charging stop");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(OTHERS, parser_parameter()));

	parse("get voltage output  some_value");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(OTHERS, parser_parameter()));		
	parse("get voltage scheme  some_value");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(OTHERS, parser_parameter()));		
	parse("get voltage generator  some_value");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(OTHERS, parser_parameter()));		
	parse("get voltage first_battery  some_value");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(OTHERS, parser_parameter()));		
	parse("get voltage second_battery  some_value");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(OTHERS, parser_parameter()));		
	parse("get voltage output");
	TEST_ASSERT_EQUAL_INT(SUCCESSFUL, check_parameter(OTHERS, parser_parameter()));		
	
}

TEST_GROUP (user_action);

//[?]write_in_response_string
//[+]analysis_error_type
//[+]set_charger_actions
//[+]set_charging_actions
//[]get_actions


TEST_SETUP (user_action) {
	parser_create(&groups_of_commands, MAX_CMD_LEN);
}

TEST_TEAR_DOWN (user_action) {
	parser_delete();
}

// TEST (user_action, write_in_response_string){
// 	prepare_response("test string");
// 	TEST_ASSERT_EQUAL_STRING("test string", get_user_response());
// 	prepare_response("____");
// 	TEST_ASSERT_EQUAL_STRING("____", get_user_response());
// 	prepare_response("ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd");
// 	TEST_ASSERT_EQUAL_STRING("", get_user_response());
// }

TEST (user_action, analysis_error_type){
	parse("set charger mode no_gen");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Your error: Invalid parameter", get_user_response());
	
	parse("set charger mode unexist");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Your error: Non-existent charger", get_user_response());

	parse("set charger pulse_width 50000000000000000000000000000");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Your error: Incorrect pulse width", get_user_response());

	parse("set charging period 5");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Your error: The entered value is less than acceptable", get_user_response());

	parse("set charging period 5000000000");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Your error: The entered value is more than acceptable", get_user_response());
}

TEST(user_action, set_charger_actions){
	parse("set charger start");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING(CHARGER_START_RESPONSE, get_user_response());

	parse("set charger stop");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING(CHARGER_STOP_RESPONSE, get_user_response());

	parse("set charger mode akk");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("You set the mode: akk", get_user_response());

	parse("set charger mode akk");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("You set the mode: akk", get_user_response());		

	parse("set charger mode gen");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("You set the mode: gen", get_user_response());		
}

TEST(user_action, set_charging_actions){
	parse("set charging period 754");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("You set the time: 754", get_user_response());		

	parse("set charging mode default");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("You set the charging mode: default", get_user_response());	

	parse("set charging akk akk1");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Now charging: akk1", get_user_response());	

	parse("set charging start");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Charging: Start", get_user_response());	

	parse("set charging stop");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Charging: Stop", get_user_response());

	parse("set charging t_positive_pulse 45");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Duration + pulse: 45", get_user_response());	

	parse("set charging t_negative_pulse 45");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Duration - pulse: 45", get_user_response());		

	parse("set charging need_disch_pulse false");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("The need for negative pulse: false", get_user_response());

	parse("set charging need_disch_pulse true");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("The need for negative pulse: true", get_user_response());
	
}

TEST(user_action, get_actions){
	parse("get voltage generator");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Voltage generator: 1", get_user_response());

	parse("get voltage scheme");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Voltage scheme: 2", get_user_response());

	parse("get voltage output");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Voltage output: 3", get_user_response());

	parse("get voltage first_battery");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Voltage first_battery: 4", get_user_response());

	parse("get voltage second_battery");
	parser_action()();
	TEST_ASSERT_EQUAL_STRING("Voltage second_battery: 5", get_user_response());


}