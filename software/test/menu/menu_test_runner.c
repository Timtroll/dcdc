#include "unity_fixture.h"

TEST_GROUP_RUNNER (navigation) {
	
}

TEST_GROUP_RUNNER (linked_list){
	RUN_TEST_CASE (linked_list, create_dl_list);
	RUN_TEST_CASE (linked_list, correct_filling_dl_list_with_screen);
}