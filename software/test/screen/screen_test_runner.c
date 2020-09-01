#include "unity_fixture.h"

TEST_GROUP_RUNNER (screen) {
	RUN_TEST_CASE (screen, check_number_lines);
	RUN_TEST_CASE (screen, scr_constructor_screen_main);
	RUN_TEST_CASE (screen, scr_change_info_main);
    RUN_TEST_CASE (screen, scr_constructor_screen_side);
    RUN_TEST_CASE (screen, scr_change_info_side);
    RUN_TEST_CASE (screen, scr_destructor_screen);
}


