#include "unity_fixture.h"

#include "menu_internal.h"

TEST_GROUP (navigation);

/*
struct st_data
{
	int 
};*/

//[]indicate_pointer_on_data__block_screen
//[]selection_first_screen_start
//[]selection_new_actual_screen
//[]switch_screens_circle_right
//[]switch_screens_circle_left



TEST_SETUP (navigation) {

}

TEST_TEAR_DOWN (navigation) {

}




TEST (navigation, start_here) {

	TEST_FAIL_MESSAGE("start test menu here");
}

/*
TEST(menu, create_screen_list){
	TEST_ASSERT_EQUAL_PTR()
}*/

TEST(navigation, create_list_screen__freertos){
	TEST_ONLY();
	TEST_MESSAGE("empty test");
}


TEST_GROUP (linked_list);

TEST_SETUP (linked_list) {
	//здесь код, который уже был протестирован
	//и нужен для дальнейшей работы блока
}

TEST_TEAR_DOWN (linked_list) {

}



//[+]make_header_list
//[]make_node_list
//[]delete_node
//[]delete_header
//[]push_node_in_list
//[]pull_node_from_list 
//[]add_data_in_node
//[]change_info_in_data



TEST(linked_list, example_test){
	TEST_ONLY();
}

TEST(linked_list, make_header_list){
	Constructor_header(test_header);
	TEST_ASSERT_EQUAL_PTR(NULL, test_header.head);
	TEST_ASSERT_EQUAL_PTR(NULL, test_header.tail);
	TEST_ASSERT_EQUAL_INT16(0, test_header.node_quantity);
}

