#include "unity_fixture.h"

TEST_GROUP_RUNNER (json_parser) {
	RUN_TEST_CASE (json_parser, json_init_get_func);
	RUN_TEST_CASE (json_parser, get_type_screen);
	RUN_TEST_CASE (json_parser, get_cell_value);
}
