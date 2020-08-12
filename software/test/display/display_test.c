#include "unity_fixture.h"

#include "display_internal.h"

TEST_GROUP (display);

TEST_SETUP (display) {
	init_json_parser();
}

TEST_TEAR_DOWN (display) {

}



//[+]control_of_data change
//[+]response_json_request
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
	strcat(test_type_screen, compute_type_screen());
	strcat(test_type_screen, "\"}");

	TEST_ASSERT_EQUAL_STRING(test_type_screen, parser_accept_json_string("{\"screen\":\"0\"}"));

	char test_cell_value[1000] = "{\"cell\":\"";
	strcat(test_cell_value, compute_cell_value(1,1));
	strcat(test_cell_value, "\"}");

	TEST_ASSERT_EQUAL_STRING(test_cell_value, parser_accept_json_string("{\"cell\":\"[0][0]\"}"));

}


