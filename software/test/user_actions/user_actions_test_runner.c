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

TEST_GROUP_RUNNER (internal_function) {
	RUN_TEST_CASE (internal_function, find_spaces_in_string);
	RUN_TEST_CASE (internal_function, return_cleared_string);
	RUN_TEST_CASE (internal_function, check_parameter_period);
	RUN_TEST_CASE (internal_function, crop_trash_function);
}


TEST_GROUP_RUNNER (user_action) {
	RUN_TEST_CASE (user_action, analysis_error_type);
	RUN_TEST_CASE (user_action, analysis_error_hardware);
	RUN_TEST_CASE (user_action, do_action_function);
}

TEST_GROUP_RUNNER (get_function) {
	RUN_TEST_CASE (get_function, test_functions);
	RUN_TEST_CASE (get_function, invalid_response);
	RUN_TEST_CASE (get_function, other_get_functions);

}