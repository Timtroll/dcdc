#include "unity_fixture.h"

#include "json_parser_internal.h"
#include <stdio.h>
#define ERROR_INDEX NULL
#define TOO_BIG_STRING "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd"

TEST_GROUP (json_parser);

char * get_type_screen(void){
	return "main";
}

char * get_cell_value(int x, int y){
	if(x == 0 && y == 0){
		return "voltage_cut_off";
	}
	else if(x == 14 && y == 12)
		return "0";
	else{
		return ERROR_INDEX;
	}
}

TEST_SETUP (json_parser) {
	parser_init_data_function(&get_type_screen, &get_cell_value);
}

TEST_TEAR_DOWN (json_parser) {

}


//[+]json_init_get_func
//[+]get_type_screen
//[+]get_cell_value
//[+]safety_when_getting_cell_value 
//[+]create_any_json_pair




TEST(json_parser, json_init_get_func){
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

    json_object_set_string(screen_object, "cell","[0][0]");
    char * test_cell_value_1 = json_serialize_to_string_pretty(screen_value);
    TEST_ASSERT_EQUAL_STRING("{\"cell\":\"voltage_cut_off\"}", parse_incoming_string(test_cell_value_1));

    json_object_set_string(screen_object, "cell","[14][12]");
    char * test_cell_value_2 = json_serialize_to_string_pretty(screen_value);
 	TEST_ASSERT_EQUAL_STRING("{\"cell\":\"0\"}", parse_incoming_string(test_cell_value_2));
}

TEST(json_parser, safety_when_getting_cell_value){
	JSON_Value *screen_value = json_value_init_object();
    JSON_Object *screen_object = json_value_get_object(screen_value);

    json_object_set_string(screen_object, "cell","[144][1564652]");
    char * test_cell_incorrect_value_1 = json_serialize_to_string_pretty(screen_value);
   	TEST_ASSERT_EQUAL_STRING(NULL, parse_incoming_string(test_cell_incorrect_value_1));

   	json_object_set_string(screen_object, "cell","dsf");
    char * test_cell_incorrect_value_2 = json_serialize_to_string_pretty(screen_value);
   	TEST_ASSERT_EQUAL_STRING(NULL, parse_incoming_string(test_cell_incorrect_value_2));

	json_object_set_string(screen_object, "err0r","screen");
    char * test_cell_incorrect_key = json_serialize_to_string_pretty(screen_value);
   	TEST_ASSERT_EQUAL_STRING(NULL, parse_incoming_string(test_cell_incorrect_key));

   	json_object_set_string(screen_object, "cell",TOO_BIG_STRING);
    char * test_cell_incorrect_lenght = json_serialize_to_string_pretty(screen_value);
   	TEST_ASSERT_EQUAL_STRING(NULL, parse_incoming_string(test_cell_incorrect_lenght));
}

TEST(json_parser, create_any_json_pair){
	JSON_Value *screen_value = json_value_init_object();
    JSON_Object *screen_object = json_value_get_object(screen_value);

    TEST_ASSERT_EQUAL_STRING("{\"some_key\":\"\"}", parser_create_any_json_pair("some_key",""));
    TEST_ASSERT_EQUAL_STRING("{\"\":\"some_value\"}", parser_create_any_json_pair("", "some_value"));
    TEST_ASSERT_EQUAL_STRING("{\"\":\"\"}", parser_create_any_json_pair("",""));
    TEST_ASSERT_EQUAL_STRING("{\"some_key\":\"some_value\"}", parser_create_any_json_pair("some_key", "some_value"));
}
