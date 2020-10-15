#include "unity_fixture.h"

#include "display_internal.h"
#include "../inc/menu/menu.h"
#define _DISPLAY_H_
#define MAX_COUNTER 9
#define MAIN 1
#define SIDE 2
#define DEBUG_MAIN_SCR debug_data_main_screen_1
#define DEBUG_SIDE_SCR_1 debug_data_side_screen_1
#define DEBUG_SIDE_SCR_2 debug_data_side_screen_2

char ** return_array(int type){
	
	static char * test_data_main_screen [] = { "main","4",
									"A","a",
									"B","b",
									"C","c",
									"D","d"};

	static char * test_data_side_screen [] ={"side",
								  "header",
								  "info",
								  "advice"};
	
	if (type == MAIN)
		return &test_data_main_screen;
	else if (type == SIDE)
		return &test_data_side_screen;
}

TEST_GROUP (display);

TEST_SETUP (display) {
	init_json_parser();//будет вызываться при каждой приёме данных
	set_screen_parameters(return_array(MAIN));//вызывается при каждой смене экрана
}

TEST_TEAR_DOWN (display) {

}


//[+]control_of_data change
//[+]response_json_request
//[+]compute_data_array_main_screen
//[+]compute_data_array_side_screen
//[+]get_pointer_data_from_menu
//[+]switch_next_screen
//[+]answer_request_with_menu_data
//[]change_info_with_control_function
//[]change_info_in_side_and_then_main_screen




TEST(display, control_of_data_changes){
	TEST_ASSERT_EQUAL_INT8(DISABLE, get_permission_status());
	change_permission_status();
	TEST_ASSERT_EQUAL_INT8(ENABLE, get_permission_status());
	change_permission_status();
	TEST_ASSERT_EQUAL_INT8(DISABLE, get_permission_status());
}


TEST(display, response_json_request){
	char test_type_screen[1000] = "{\"screen\":\"";
	strcat(test_type_screen, display_get_type_screen());
	strcat(test_type_screen, "\"}");

	TEST_ASSERT_EQUAL_STRING(test_type_screen, parser_accept_json_string("{\"screen\":\"0\"}"));

	char test_cell_value[1000] = "{\"cell\":\"";
	strcat(test_cell_value, display_get_cell_value(0,0));
	strcat(test_cell_value, "\"}");

	TEST_ASSERT_EQUAL_STRING(test_cell_value, parser_accept_json_string("{\"cell\":\"[0][0]\"}"));

}

TEST(display, compute_data_array_main_screen){
	char ** test_screen = return_array(MAIN);

	TEST_ASSERT_EQUAL_STRING(test_screen[0], display_get_type_screen());
	TEST_ASSERT_EQUAL_STRING(test_screen[2], display_get_cell_value(0,0));
	TEST_ASSERT_EQUAL_STRING(test_screen[9], display_get_cell_value(1,3));
	TEST_ASSERT_EQUAL_STRING(END_TABLE, display_get_cell_value(0, 4));

	TEST_ASSERT_EQUAL_STRING(NULL, display_get_cell_value(2, 0));
	TEST_ASSERT_EQUAL_STRING(NULL, display_get_cell_value(-1 , 0));
	TEST_ASSERT_EQUAL_STRING(NULL, display_get_cell_value("d", 1));
	TEST_ASSERT_EQUAL_STRING(NULL, display_get_cell_value(0, -1));
}
	


TEST(display, compute_data_array_side_screen){
	set_screen_parameters(return_array(SIDE));

	char ** test_screen = return_array(SIDE);
	TEST_ASSERT_EQUAL_STRING(test_screen[0], display_get_type_screen());
	TEST_ASSERT_EQUAL_STRING(test_screen[1], display_get_cell_value(0,0));
	TEST_ASSERT_EQUAL_STRING(test_screen[2], display_get_cell_value(0,1));
	TEST_ASSERT_EQUAL_STRING(test_screen[3], display_get_cell_value(0,2));

	TEST_ASSERT_EQUAL_STRING(NULL, display_get_cell_value(0,3));
}	

TEST(display, get_pointer_data_from_menu){
	set_screen_parameters(menu_get_actual_screen());
	char ** test_screen = &DEBUG_MAIN_SCR;
	TEST_ASSERT_EQUAL_STRING(test_screen[0], display_get_type_screen());
	TEST_ASSERT_EQUAL_STRING(test_screen[2], display_get_cell_value(0,0));
	TEST_ASSERT_EQUAL_STRING(test_screen[9], display_get_cell_value(1,3));
	TEST_ASSERT_EQUAL_STRING(END_TABLE, display_get_cell_value(0, 4));
}

TEST(display, switch_next_screen){
	set_screen_parameters(menu_get_actual_screen());
	char * test_scr_type = display_get_type_screen();
	char * test_cell_value_1 = display_get_cell_value(0,0);
	char * test_cell_value_2 = display_get_cell_value(0,1);
	
	display_set_next_screen(RIGHT);
	set_screen_parameters(menu_get_actual_screen());
	TEST_ASSERT_NOT_EQUAL(test_scr_type, display_get_type_screen());
	TEST_ASSERT_NOT_EQUAL(test_cell_value_1, display_get_cell_value(0,0));
	TEST_ASSERT_NOT_EQUAL(test_cell_value_2, display_get_cell_value(0,1));
	test_scr_type = display_get_type_screen();
	test_cell_value_1 = display_get_cell_value(0,0);
	test_cell_value_2 = display_get_cell_value(0,1);

	display_set_next_screen(LEFT);//Switching from 1 screen, through 0 to 11 screen, because a doubly linked list.
	display_set_next_screen(LEFT);
	set_screen_parameters(menu_get_actual_screen());
	TEST_ASSERT_EQUAL(test_scr_type, display_get_type_screen());
	TEST_ASSERT_NOT_EQUAL(test_cell_value_1, display_get_cell_value(0,0));
	TEST_ASSERT_NOT_EQUAL(test_cell_value_2, display_get_cell_value(0,1));
	set_screen_parameters(debug_data_main_screen_1);
}

TEST(display, answer_request_with_menu_data){
	set_screen_parameters(menu_get_actual_screen());
	display_get_parameter("{\"screen\":\"0\"}");

	char test_type_screen[1000] = "{\"screen\":\"";
	strcat(test_type_screen, display_get_type_screen());
	strcat(test_type_screen, "\"}");
	TEST_ASSERT_EQUAL_STRING(test_type_screen, get_transmit_string());

	display_get_parameter("{\"cell\":\"[0][2]\"}");
	char test_cell_value_1 [1000] = "{\"cell\":\"";
	strcat(test_cell_value_1, display_get_cell_value(0,2));
	strcat(test_cell_value_1, "\"}");
	TEST_ASSERT_EQUAL_STRING(test_cell_value_1, get_transmit_string());

	display_get_parameter("{\"cell\":\"[0][100]\"}");
	char test_cell_value_2 [1000] = "{\"cell\":\"";
	strcat(test_cell_value_2, display_get_cell_value(0,100));
	strcat(test_cell_value_2, "\"}");
	TEST_ASSERT_EQUAL_STRING(test_cell_value_2, get_transmit_string());
}

TEST(display, change_info_with_control_function){

}