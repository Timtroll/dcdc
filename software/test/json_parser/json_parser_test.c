#include "unity_fixture.h"

#include "json_parser_internal.h"
#include <stdio.h>

TEST_GROUP (json_parser);

char * get_type_screen(void){
	return "main";
}

char * get_cell_value(int x, int y){
	if(x == 0 && y == 0)
		return "voltage_cut_off";
	else 
		return "0";
}

TEST_SETUP (json_parser) {
	json_init_parser(&get_type_screen, &get_cell_value);
}

TEST_TEAR_DOWN (json_parser) {

}





//[+]json_init_get_func
//[+]get_type_screen
//[]get_cell_value




TEST(json_parser, json_init_get_func){
	json_init_parser(&get_type_screen, &get_cell_value);
	TEST_ASSERT_EQUAL_STRING(get_type_screen(), json_get_type_screen());
	TEST_ASSERT_EQUAL_STRING(get_cell_value(0,0), json_get_cell_value(0,0));
}


TEST(json_parser, get_type_screen){
	JSON_Value *screen_value = json_value_init_object();
    JSON_Object *screen_object = json_value_get_object(screen_value);

    json_object_set_string(screen_object, "screen","some_value");
    char * test_main_scr = json_serialize_to_string_pretty(screen_value);

   	TEST_ASSERT_EQUAL_STRING("{\"screen\":\"main\"}", parse_incoming_string(test_main_scr));
}

TEST(json_parser, get_cell_value){
	JSON_Value *screen_value = json_value_init_object();
    JSON_Object *screen_object = json_value_get_object(screen_value);

    json_object_set_string(screen_object, "cell","some_value");

    //in progress
}