#include "unity_fixture.h"

#include "menu_internal.h"

#include "../../inc/dl_list/dl_list_internal.h"
	

TEST_GROUP (linked_list);

TEST_SETUP (linked_list) {
	menu_create();
}


TEST_TEAR_DOWN (linked_list) {

}

//[+]create_dl_list
//[+]get_information_from_block_sys_info
//[+]write_screens
//[]correct_filling_dl_list_with_screen
//[+]save_actual_screen 
//[]correct_return_data_about_actual_screen	
//[]change_info_in_screen


TEST(linked_list, create_dl_list){
	TEST_ASSERT_NOT_NULL(menu);
	TEST_ASSERT_NOT_NULL(menu->data);
	TEST_ASSERT_EQUAL_PTR(_dl_list_push, menu->push);
	TEST_ASSERT_EQUAL_PTR(_dl_list_pop, menu->pop);
	TEST_ASSERT_EQUAL_PTR(_dl_list_head, menu->head);
	TEST_ASSERT_EQUAL_PTR(_dl_list_tail, menu->tail);
	TEST_ASSERT_EQUAL_PTR(_dl_list_size, menu->size);

	TEST_ASSERT_EQUAL_INT(
		sizeof(char * [MAIN_QUANTITY_ELEMENT]),
		data_cell_size(menu->data)
	);
	TEST_ASSERT_EQUAL_INT(12, data_cell_amount(menu->data));
	
	list_cell_t 
		* head = Dl_list_head(menu),
		* tail = Dl_list_tail(menu);

	TEST_ASSERT_EQUAL_PTR(head, tail->prev);
	TEST_ASSERT_EQUAL_PTR(tail, head->next);
}

TEST(linked_list, get_information_from_block_sys_info){
	//TEST_ASSERT_EQUAL_STRING(sys_info_get_main_scr(), get_raw_data(0));
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

	TEST_ASSERT_EQUAL_INT(1, data_cell_amount(menu->data));
}


TEST(linked_list, save_actual_screen){
	TEST_ASSERT_EQUAL_PTR(get_actual_screen(), Dl_list_head(menu));

	set_actual_screen(get_actual_screen()->next);
	TEST_ASSERT_EQUAL_PTR(get_actual_screen(), Dl_list_tail(menu));
	set_actual_screen(get_actual_screen()->prev->prev);
	TEST_ASSERT_EQUAL_PTR(get_actual_screen(), Dl_list_head(menu)->prev);
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

TEST(linked_list, get_raw_data){
	//TEST_ASSERT_EQUAL_STRING("main_scr", get_raw_data(0));
	TEST_ASSERT_EQUAL_STRING("voltage_cut",get_raw_data(1));
	TEST_ASSERT_EQUAL_STRING("charging_type",get_raw_data(2));
	TEST_ASSERT_EQUAL_STRING("charge_threshold_Pb_lower",get_raw_data(3));
	TEST_ASSERT_EQUAL_STRING("charge_threshold_Pb_upper",get_raw_data(4));
	TEST_ASSERT_EQUAL_STRING("charge_threshold_others",get_raw_data(5));
	TEST_ASSERT_EQUAL_STRING("discharge_threshold",get_raw_data(6));
	TEST_ASSERT_EQUAL_STRING("quantity_cans",get_raw_data(7));
	TEST_ASSERT_EQUAL_STRING("capacity",get_raw_data(8));
	TEST_ASSERT_EQUAL_STRING("max_allowable_capacity",get_raw_data(9));
	TEST_ASSERT_EQUAL_STRING("internal_voltage_default",get_raw_data(10));
	TEST_ASSERT_EQUAL_STRING("type_battery",get_raw_data(11));
}

TEST(linked_list, get_screen_name){

	char * str_screen_name_example[QUANTITY_SCREEN] = {
	"voltage_cut",
	"charging_type",
	"charge_threshold_Pb_lower",
	"charge_threshold_Pb_upper",
	"charge_threshold_others",
	"discharge_threshold",
	"quantity_cans",
	"capacity",
	"max_allowable_capacity",
	"internal_voltage_default",
	"type_battery"
	};

	TEST_ASSERT_EQUAL_STRING_ARRAY(str_screen_name_example, get_screen_name_list(), QUANTITY_SCREEN);
}

TEST(linked_list, get_promt_list){

	char * promt_list_example[QUANTITY_SCREEN-1] = {
	"test_promt_voltage_cut",
	"test_promt_charging_type",
	"test_promt_charge_threshold_Pb_lower",
	"test_promt_charge_threshold_Pb_upper",
	"test_promt_charge_threshold_others",
	"test_promt_discharge_threshold",
	"test_promt_quantity_cans",
	"test_promt_capacity",
	"test_promt_max_allowable_capacity",
	"test_promt_internal_voltage_default",
	"test_promt_type_battery"
	};

	TEST_ASSERT_EQUAL_STRING_ARRAY(promt_list_example, get_promt_list(), QUANTITY_SCREEN-1); 
}

TEST(linked_list, get_system_info){

	char * raw_data_list_example[QUANTITY_SCREEN-1] = {
	"voltage_cut",
	"charging_type",
	"charge_threshold_Pb_lower",
	"charge_threshold_Pb_upper",
	"charge_threshold_others",
	"discharge_threshold",
	"quantity_cans",
	"capacity",
	"max_allowable_capacity",
	"internal_voltage_default",
	"type_battery"
	};

	TEST_ASSERT_EQUAL_STRING_ARRAY(raw_data_list_example, sys_info_get_main_scr(), QUANTITY_SCREEN-1); 
}

TEST_GROUP (navigation);

TEST_SETUP (navigation) {

}

TEST_TEAR_DOWN (navigation) {

}

TEST(navigation, selection_main_screen_on_start){
	// TEST_FAIL_MESSAGE("UNCORRECT TEST, return NULL ptr");
	// TEST_ASSERT_EQUAL_PTR(Dl_list_head(menu)->data, menu_get_actual_screen());
}


TEST(navigation, switch_screens_circle_right){
	char ** test_actual_data = (char **)menu_get_actual_screen();
	for (int count_scr = 0; count_scr < QUANTITY_SCREEN; count_scr++) menu_swipe_right();

	// printf("%p\n", test_actual_data[0]);
	// TEST_FAIL_MESSAGE("Pointer cannot be cast to type and cannot be addressed");
	// printf("%s\n", test_actual_data[0]);
	// TEST_FAIL_MESSAGE("A pointer cannot be cast and cannot be accessed");
	// TEST_ASSERT_EQUAL_PTR(test_actual_data,menu_get_actual_screen());
}

//[+]selection_main_screen_on_start
//[]selection_new_actual_screen
//[]switch_screens_circle_right
//[]switch_screens_circle_left




