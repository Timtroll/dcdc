#include "unity_fixture.h"

TEST_GROUP_RUNNER (navigation) {
	RUN_TEST_CASE(navigation, create_menu_in_func);
	RUN_TEST_CASE(navigation, selection_main_screen_on_start);
	RUN_TEST_CASE(navigation, selection_new_actual_screen);
	RUN_TEST_CASE(navigation, switch_screens_circle_right);
	//RUN_TEST_CASE(navigation, switch_screens_circle_left);
}

TEST_GROUP_RUNNER (linked_list){
	RUN_TEST_CASE(linked_list, make_header_list);
	RUN_TEST_CASE(linked_list, make_node_list);
	RUN_TEST_CASE(linked_list, push_node_in_list);
	RUN_TEST_CASE(linked_list, save_actual_cell);
	RUN_TEST_CASE(linked_list, create_start_list);

}