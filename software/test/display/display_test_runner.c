#include "unity_fixture.h"

TEST_GROUP_RUNNER (display) {
	RUN_TEST_CASE (display, control_of_data_changes);
	RUN_TEST_CASE (display, response_json_request);
 	RUN_TEST_CASE (display, compute_data_array_main_screen);
}

