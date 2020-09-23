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
	TEST_ASSERT_EQUAL_INT(9, data_cell_amount(menu->data));
	
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
		"main_scr\n\nmain_scr", \
		"voltage_cut\n\nvoltage_cut\n\ntest_promt_voltage_cut", \
		"charging_type\n\ncharging_type\n\ntest_promt_charging_type", \
		"charge_threshold_Pb_lower\n\ncharge_threshold_Pb_lower\n\ntest_promt_charge_threshold_Pb_lower", \
		"charge_threshold_Pb_upper\n\ncharge_threshold_Pb_upper\n\ntest_promt_charge_threshold_Pb_upper", \
		"charge_threshold_others\n\ncharge_threshold_others\n\ntest_promt_charge_threshold_others", \
		"discharge_threshold\n\ndischarge_threshold\n\ntest_promt_discharge_threshold", \
		"quantity_cans\n\nquantity_cans\n\ntest_promt_quantity_cans", \
		"capacity\n\ncapacity\n\ntest_promt_capacity", \
		"max_allowable_capacity\n\nmax_allowable_capacity\n\ntest_promt_max_allowable_capacity", \
		"internal_voltage_default\n\ninternal_voltage_default\n\ntest_promt_internal_voltage_default", \
		"type_battery\n\ntype_battery\n\ntest_promt_type_battery" };
	

	// TEST_ASSERT_EQUAL_STRING(template[main_scr] , full_screen_string_forming(main_scr));
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
	
	//printf("%p\n", test_actual_data[0]);
	// menu_swipe_left();
	// printf("%p\n", menu_get_actual_screen());
	// TEST_ASSERT_EQUAL_PTR(test_actual_data,menu_get_actual_screen());

}

//[+]selection_main_screen_on_start
//[]selection_new_actual_screen
//[]switch_screens_circle_right
//[]switch_screens_circle_left




