#include "unity_fixture.h"

#include "menu_internal.h"

TEST_GROUP (linked_list);

TEST_SETUP (linked_list) {

}


TEST_TEAR_DOWN (linked_list) {

}

//[+]create_dl_list
//[+]get_information_from_block_sys_info
//[+]write_screens
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
	TEST_ASSERT_EQUAL_STRING(sys_info_get_main_scr(), get_raw_data(0));
	TEST_ASSERT_EQUAL_STRING(sys_info_get_voltage_cut(), get_raw_data(1));
	TEST_ASSERT_EQUAL_STRING(sys_info_get_charging_type(), get_raw_data(2));
	TEST_ASSERT_EQUAL_STRING(sys_info_get_charge_threshold_Pb_lower(), get_raw_data(3));
	TEST_ASSERT_EQUAL_STRING(sys_info_get_charge_threshold_Pb_upper(), get_raw_data(4));
	TEST_ASSERT_EQUAL_STRING(sys_info_get_charge_threshold_others(), get_raw_data(5));
	TEST_ASSERT_EQUAL_STRING(sys_info_get_discharge_threshold(), get_raw_data(6));
	TEST_ASSERT_EQUAL_STRING(sys_info_get_quantity_cans(),get_raw_data(7));
	TEST_ASSERT_EQUAL_STRING(sys_info_get_capacity(),get_raw_data(8));
	TEST_ASSERT_EQUAL_STRING(sys_info_get_max_allowable_capacity(),get_raw_data(9));
	TEST_ASSERT_EQUAL_STRING(sys_info_get_internal_voltage_default(),get_raw_data(10));
	TEST_ASSERT_EQUAL_STRING(sys_info_get_type_battery(), get_raw_data(11));
}

TEST(linked_list, correct_filling_dl_list_with_screen){
	menu_create();

	TEST_ASSERT_EQUAL_INT(1, data_cell_amount(menu->data));
}


TEST(linked_list, save_actual_screen){
	fill_with_data();
}

TEST(linked_list, write_screens){
	char ** p = sys_info_get_main_scr();
	
	TEST_ASSERT_EQUAL_STRING(get_raw_data(1), p[0] );
	TEST_ASSERT_EQUAL_STRING(get_raw_data(2), p[1] );
	TEST_ASSERT_EQUAL_STRING(get_raw_data(3), p[2] );
	TEST_ASSERT_EQUAL_STRING(get_raw_data(4), p[3] );
	TEST_ASSERT_EQUAL_STRING(get_raw_data(5), p[4] );
	TEST_ASSERT_EQUAL_STRING(get_raw_data(6), p[5] );
	TEST_ASSERT_EQUAL_STRING(get_raw_data(7), p[6] );
	TEST_ASSERT_EQUAL_STRING(get_raw_data(8), p[7] );
	TEST_ASSERT_EQUAL_STRING(get_raw_data(9), p[8] );
	TEST_ASSERT_EQUAL_STRING(get_raw_data(10), p[9] );
	TEST_ASSERT_EQUAL_STRING(get_raw_data(11), p[10] );
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




