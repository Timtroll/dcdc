#include "unity_fixture.h"

TEST_GROUP_RUNNER (navigation) {
	
}

TEST_GROUP_RUNNER (linked_list){
	RUN_TEST_CASE (linked_list, create_dl_list);
	RUN_TEST_CASE (linked_list, get_information_from_block_sys_info);
	//RUN_TEST_CASE (linked_list, correct_filling_dl_list_with_screen);
	//RUN_TEST_CASE (linked_list, save_actual_screen);
	RUN_TEST_CASE (linked_list, write_screens);
	RUN_TEST_CASE (linked_list, print_long_raw_string);
	RUN_TEST_CASE (linked_list, get_raw_data);
}