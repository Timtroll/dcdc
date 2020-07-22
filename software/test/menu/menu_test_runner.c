#include "unity_fixture.h"

TEST_GROUP_RUNNER (navigation) {
	//RUN_TEST_CASE (navigation, start_here);
	RUN_TEST_CASE (navigation, create_list_screen__freertos)
}

TEST_GROUP_RUNNER (linked_list){
	RUN_TEST_CASE(linked_list, example_test);
	RUN_TEST_CASE(linked_list, make_header_list);
}