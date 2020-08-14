#include "unity_fixture.h"

#include "display_internal.h"

#define MAX_COUNTER 9
#define MAIN 1
#define SIDE 2

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
//[]compute_data_array_main_screen
//[]compute_data_array_side_screen
//[]get_pointer_data_from_menu
//[]switch_next_screen
//[]change_pointer_on_data
//[]get_screen_type_from_menu
//[]get_cell_value_from_menu
//[]answer_request_with_menu_data




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
}
	

	/*

TEST(display, compute_data_array_side_screen){
	set_screen_parameters(return_array(SIDE));
}	*/