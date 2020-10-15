#include "unity_fixture.h"

TEST_GROUP_RUNNER (display) {
	RUN_TEST_CASE (display, control_of_data_changes);
	RUN_TEST_CASE (display, response_json_request);
 	RUN_TEST_CASE (display, compute_data_array_main_screen);
 	RUN_TEST_CASE (display, compute_data_array_side_screen);
 	RUN_TEST_CASE (display, get_pointer_data_from_menu);
 	RUN_TEST_CASE (display, answer_request_with_menu_data);
 	RUN_TEST_CASE (display, switch_next_screen);
 	RUN_TEST_CASE (display, change_info_with_control_function);
}

