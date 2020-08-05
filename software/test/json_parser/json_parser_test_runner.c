#include "unity_fixture.h"

TEST_GROUP_RUNNER (json_parser) {
	RUN_TEST_CASE (json_parser, json_init_get_func);
	RUN_TEST_CASE (json_parser, get_type_screen);
	RUN_TEST_CASE (json_parser, get_cell_value);
	RUN_TEST_CASE (json_parser, safety_when_getting_cell_value);
	RUN_TEST_CASE (json_parser, create_any_json_pair);	
}
