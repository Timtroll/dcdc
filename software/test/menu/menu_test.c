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

TEST(linked_list, print_long_raw_string){
	char * template[QUANTITY_SCREEN] = { \
		"str_screen_name\n\nmain_scr\n\nget_raw_data\n\nnmain_scr", \
		"str_screen_name\n\nvoltage_cut\n\nget_raw_data\n\nvoltage_cut\n\npromt_list\n\ntest_promt_voltage_cut", \
		"str_screen_name\n\ncharging_type\n\nget_raw_data\n\ncharging_type\n\npromt_list\n\ntest_promt_charging_type", \
		"str_screen_name\n\ncharge_threshold_Pb_lower\n\nget_raw_data\n\ncharge_threshold_Pb_lower\n\npromt_list\n\ntest_promt_charge_threshold_Pb_lower", \
		"str_screen_name\n\ncharge_threshold_Pb_upper\n\nget_raw_data\n\ncharge_threshold_Pb_upper\n\npromt_list\n\ntest_promt_charge_threshold_Pb_upper", \
		"str_screen_name\n\ncharge_threshold_others\n\nget_raw_data\n\ncharge_threshold_others\n\npromt_list\n\ntest_promt_charge_threshold_others", \
		"str_screen_name\n\ndischarge_threshold\n\nget_raw_data\n\ndischarge_threshold\n\npromt_list\n\ntest_promt_discharge_threshold", \
		"str_screen_name\n\nquantity_cans\n\nget_raw_data\n\nquantity_cans\n\npromt_list\n\ntest_promt_quantity_cans", \
		"str_screen_name\n\ncapacity\n\nget_raw_data\n\ncapacity\n\npromt_list\n\ntest_promt_capacity", \
		"str_screen_name\n\nmax_allowable_capacity\n\nget_raw_data\n\nmax_allowable_capacity\n\npromt_list\n\ntest_promt_max_allowable_capacity", \
		"str_screen_name\n\ninternal_voltage_default\n\nget_raw_data\n\ninternal_voltage_default\n\npromt_list\n\ntest_promt_internal_voltage_default", \
		"str_screen_name\n\ntype_battery\n\nget_raw_data\n\ntype_battery\n\npromt_list\n\ntest_promt_type_battery" };
	

	//TEST_ASSERT_EQUAL_STRING(template[main_scr] , full_screen_string_forming(main_scr));
	TEST_ASSERT_EQUAL_STRING(template[voltage_cut] , full_screen_string_forming(voltage_cut));
	TEST_ASSERT_EQUAL_STRING(template[charging_type] , full_screen_string_forming(charging_type));
	TEST_ASSERT_EQUAL_STRING(template[charge_threshold_Pb_lower] , full_screen_string_forming(charge_threshold_Pb_lower));
	TEST_ASSERT_EQUAL_STRING(template[charge_threshold_Pb_upper] , full_screen_string_forming(charge_threshold_Pb_upper));
	TEST_ASSERT_EQUAL_STRING(template[charge_threshold_others] , full_screen_string_forming(charge_threshold_others));
	TEST_ASSERT_EQUAL_STRING(template[discharge_threshold] , full_screen_string_forming(discharge_threshold));
	TEST_ASSERT_EQUAL_STRING(template[quantity_cans] , full_screen_string_forming(quantity_cans));
	TEST_ASSERT_EQUAL_STRING(template[capacity] , full_screen_string_forming(capacity));
	TEST_ASSERT_EQUAL_STRING(template[max_allowable_capacity] , full_screen_string_forming(max_allowable_capacity));
	TEST_ASSERT_EQUAL_STRING(template[internal_voltage_default] , full_screen_string_forming(internal_voltage_default));
	TEST_ASSERT_EQUAL_STRING(template[type_battery] , full_screen_string_forming(type_battery));
}

TEST_GROUP (navigation);

TEST_SETUP (navigation) {

}

TEST_TEAR_DOWN (navigation) {

}

TEST(navigation, selection_main_screen_on_start){
	TEST_ASSERT_EQUAL_PTR(Dl_list_head(menu)->data, menu_get_actual_screen());
}


TEST(navigation, switch_screens_circle_right){
	char ** test_actual_data = (char **)menu_get_actual_screen();
	for (int count_scr = 0; count_scr < QUANTITY_SCREEN; count_scr++) menu_swipe_right();

	//printf("%p\n", test_actual_data[0]);
	TEST_FAIL_MESSAGE("Pointer cannot be cast to type and cannot be addressed");
	//printf("%s\n", test_actual_data[0]);
	TEST_FAIL_MESSAGE("A pointer cannot be cast and cannot be accessed");
	// TEST_ASSERT_EQUAL_PTR(test_actual_data,menu_get_actual_screen());

}

//[+]selection_main_screen_on_start
//[]selection_new_actual_screen
//[]switch_screens_circle_right
//[]switch_screens_circle_left




