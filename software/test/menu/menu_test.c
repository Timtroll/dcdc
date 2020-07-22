#include "unity_fixture.h"

#include "menu_internal.h"

TEST_GROUP (linked_list);

TEST_SETUP (linked_list) {
	//здесь код, который уже был протестирован
	//и нужен для дальнейшей работы блока
	

}


TEST_TEAR_DOWN (linked_list) {

}



//[+]make_header_list
//[+]make_node_list
//[+]push_node_in_list
//[]pull_node_from_list 
//[]add_data_in_node
//[]change_info_in_data
//[]delete_node
//[]delete_header


TEST(linked_list, example_test){
	TEST_ONLY();
}

TEST(linked_list, make_header_list){
	Constructor_header(test_header);
	TEST_ASSERT_EQUAL_PTR(NULL, test_header.head);
	TEST_ASSERT_EQUAL_PTR(NULL, test_header.tail);
	TEST_ASSERT_EQUAL_INT16(0, test_header.node_quantity);
}


TEST(linked_list, make_node_list){
	Constructor_cell(test_cell);
	TEST_ASSERT_EQUAL_PTR(NULL, test_cell.front);
	TEST_ASSERT_EQUAL_PTR(NULL, test_cell.behind);
	TEST_ASSERT_EQUAL_PTR(NULL, test_cell.data);
}


TEST(linked_list, push_node_in_list){
	Constructor_header(header);
	Constructor_cell(cell_0);
	Constructor_cell(cell_1);
	Constructor_cell(cell_2);

	insert_cell(&header, &cell_0);
	TEST_ASSERT_EQUAL_PTR(&cell_0, header.head);
	TEST_ASSERT_EQUAL_PTR(&cell_0, header.tail);
	TEST_ASSERT_EQUAL_INT16(1, header.node_quantity);

	insert_cell(&header, &cell_1);
	TEST_ASSERT_EQUAL_PTR(&cell_1, cell_0.behind);
	TEST_ASSERT_EQUAL_PTR(&cell_0, cell_1.front);
	TEST_ASSERT_EQUAL_PTR(&cell_0, header.head);
	TEST_ASSERT_EQUAL_PTR(&cell_1, header.tail);
	TEST_ASSERT_EQUAL_INT16(2, header.node_quantity);

	insert_cell(&header, &cell_2);
	TEST_ASSERT_EQUAL_PTR(&cell_2, cell_1.behind);
	TEST_ASSERT_EQUAL_PTR(&cell_1, cell_2.front);
	TEST_ASSERT_EQUAL_PTR(&cell_0, header.head);
	TEST_ASSERT_EQUAL_PTR(&cell_2, header.tail);
	TEST_ASSERT_EQUAL_INT16(3, header.node_quantity);

}


TEST(linked_list, add_data_in_node) {
	Constructor_cell(cell_0);
	Constructor_cell(cell_1);
	Constructor_cell(cell_2);

}

TEST_GROUP (navigation);


//[]indicate_pointer_on_data_block_screen
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

}


