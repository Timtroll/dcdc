#include "unity_fixture.h"

#include "menu_internal.h"

TEST_GROUP (linked_list);

TEST_SETUP (linked_list) {

}


TEST_TEAR_DOWN (linked_list) {

}

//[+]create_dl_list
//[]get_information_from_block_sys_info
//[]correct_filling_dl_list_with_screen
//[]save_actual_screen 
//[]correct_return_data_about_actual_screen	
//[]change_info_in_screen


TEST(linked_list, create_dl_list){
	menu_create();

	TEST_ASSERT_NOT_NULL(menu);
	TEST_ASSERT_NOT_NULL(menu->data);

	TEST_ASSERT_NULL(Dl_list_head(menu));
	TEST_ASSERT_NULL(Dl_list_tail(menu));
	TEST_ASSERT_EQUAL_INT(
		sizeof(MAIN_SCREEN),
		data_cell_size(menu->data)
	);
	TEST_ASSERT_EQUAL_INT(0, data_cell_amount(menu->data));

	TEST_ASSERT_NOT_NULL(menu->push);
	TEST_ASSERT_NOT_NULL(menu->pop);
	TEST_ASSERT_NOT_NULL(menu->head);
	TEST_ASSERT_NOT_NULL(menu->tail);
	TEST_ASSERT_NOT_NULL(menu->size);
}

TEST(linked_list, get_information_from_block_sys_info){
	TEST_ASSERT_EQUAL_STRING(sys_info_get_voltage_cut(), _get_raw_data(1));
}

TEST(linked_list, correct_filling_dl_list_with_screen){
	menu_create();
	fill_with_data();

	TEST_ASSERT_EQUAL_INT(1, data_cell_amount(menu->data));
}

TEST_GROUP (navigation);



TEST_SETUP (navigation) {

}

TEST_TEAR_DOWN (navigation) {

}



//[]selection_main_screen_on_start
//[]selection_new_actual_screen
//[]switch_screens_circle_right
//[]switch_screens_circle_left


