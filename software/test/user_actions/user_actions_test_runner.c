#include "unity_fixture.h"

TEST_GROUP_RUNNER (set_group) {
	RUN_TEST_CASE (set_group, charger_start);
	RUN_TEST_CASE (set_group, charger_stop);
	RUN_TEST_CASE (set_group, charger_mode);
	RUN_TEST_CASE (set_group, charger_akk);
	RUN_TEST_CASE (set_group, charger_pulse_width);

	RUN_TEST_CASE (set_group, charging_time);
	RUN_TEST_CASE (set_group, charging_mode);
	RUN_TEST_CASE (set_group, charging_akk);
	RUN_TEST_CASE (set_group, charging_start);
	RUN_TEST_CASE (set_group, charging_stop);
}

TEST_GROUP_RUNNER (get_group) {
	RUN_TEST_CASE (get_group, voltage_scheme);
	RUN_TEST_CASE (get_group, voltage_generator);
	RUN_TEST_CASE (get_group, voltage_output);
	RUN_TEST_CASE (get_group, voltage_first_battery);
	RUN_TEST_CASE (get_group, voltage_second_battery);
}

TEST_GROUP_RUNNER (parameter_control) {
	// RUN_TEST_CASE (parameter_control, check_parameter_mode);
	// RUN_TEST_CASE (parameter_control, check_parameter_pulse_widht);
	// RUN_TEST_CASE (parameter_control, check_parameter_time);
	// RUN_TEST_CASE (parameter_control, check_unnecessary_parameters);
}

TEST_GROUP_RUNNER (user_action) {
	//RUN_TEST_CASE (user_action, write_in_response_string);
	RUN_TEST_CASE (user_action, analysis_error_type);
	RUN_TEST_CASE (user_action, set_charger_actions);
	RUN_TEST_CASE (user_action, set_charging_actions);
	RUN_TEST_CASE (user_action, get_actions);
}
