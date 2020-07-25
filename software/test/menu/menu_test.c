#include "unity_fixture.h"

#include "menu_internal.h"

TEST_GROUP (linked_list);

TEST_SETUP (linked_list) {

}


TEST_TEAR_DOWN (linked_list) {

}


//[+]make_header_list
//[+]make_node_list
//[+]push_node_in_list
//[+]create_start_list
//[]pull_node_from_list
//[]save_actual_cell 
//[]add_data_in_node
//[]change_info_in_data
//[]delete_node
//[]delete_header



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

	cell_insert(&header, &cell_0);
	TEST_ASSERT_EQUAL_PTR(&cell_0, header.head);
	TEST_ASSERT_EQUAL_PTR(&cell_0, header.tail);
	TEST_ASSERT_EQUAL_INT16(1, header.node_quantity);

	cell_insert(&header, &cell_1);
	TEST_ASSERT_EQUAL_PTR(&cell_1, cell_0.behind);
	TEST_ASSERT_EQUAL_PTR(&cell_0, cell_1.front);
	TEST_ASSERT_EQUAL_PTR(&cell_1, cell_0.front);
	TEST_ASSERT_EQUAL_PTR(&cell_0, cell_1.behind);
	TEST_ASSERT_EQUAL_PTR(&cell_0, header.head);
	TEST_ASSERT_EQUAL_PTR(&cell_1, header.tail);
	TEST_ASSERT_EQUAL_INT16(2, header.node_quantity);

	cell_insert(&header, &cell_2);
	TEST_ASSERT_EQUAL_PTR(&cell_2, cell_1.behind);
	TEST_ASSERT_EQUAL_PTR(&cell_1, cell_2.front);
	TEST_ASSERT_EQUAL_PTR(&cell_2, cell_0.front);
	TEST_ASSERT_EQUAL_PTR(&cell_0, cell_2.behind);
	TEST_ASSERT_EQUAL_PTR(&cell_0, header.head);
	TEST_ASSERT_EQUAL_PTR(&cell_2, header.tail);
	TEST_ASSERT_EQUAL_INT16(3, header.node_quantity);
}


TEST(linked_list, save_actual_cell){
	Constructor_cell(cell_0);
	Constructor_cell(cell_1);
	Constructor_cell(cell_2);

	cell_t * test_ptr = NULL;

	actual_cell(&cell_0, SAVE);
	actual_cell(&test_ptr, RETURN);
	TEST_ASSERT_EQUAL_PTR(&cell_0, test_ptr);

	actual_cell(&cell_1, SAVE);
	actual_cell(&test_ptr, RETURN);
	TEST_ASSERT_EQUAL_PTR(&cell_1, test_ptr);

	actual_cell(&cell_2, SAVE);
	actual_cell(&test_ptr, RETURN);
	TEST_ASSERT_EQUAL_PTR(&cell_2, test_ptr);
}

TEST(linked_list, create_start_list){
	cell_t * test_screen = NULL;
	Create_list(menu);
	actual_cell(&test_screen, RETURN);

	TEST_ASSERT_NOT_NULL(menu.head);
	TEST_ASSERT_NOT_NULL(menu.tail);
	TEST_ASSERT_EQUAL_INT16(10, menu.node_quantity);
	TEST_ASSERT_EQUAL_PTR(menu.head, test_screen);

}	

TEST(linked_list, add_data_in_node) {
	Constructor_cell(cell_0);
	Constructor_cell(cell_1);
	Constructor_cell(cell_2);
}

TEST_GROUP (navigation);

//[+]create_menu_in_func
//[+]selection_main_screen_on_start
//[+]selection_new_actual_screen
//[+]switch_screens_circle_right
//[]switch_screens_circle_left
//[]return_data_from_screen


TEST_SETUP (navigation) {
	create_menu();
}

TEST_TEAR_DOWN (navigation) {

}

TEST(navigation, create_menu_in_func){
	cell_t * screen_ptr = NULL;
	actual_cell(&screen_ptr, RETURN);

	TEST_ASSERT_NOT_NULL(screen_ptr);
}

TEST(navigation, selection_main_screen_on_start) {
	TEST_ASSERT_EQUAL_INT8(MAIN_SCREEN, menu_get_actual_screen());
}

TEST(navigation, selection_new_actual_screen){
	cell_t * screen_before = NULL;
	cell_t * screen_after = NULL;
	actual_cell(&screen_before, RETURN);
	menu_swipe_right();
	actual_cell(&screen_after, RETURN);

	TEST_ASSERT_NOT_EQUAL(screen_before, screen_after);
}

TEST(navigation, switch_screens_circle_right){
	cell_t * start = get_main_screen();
	for (int counter = 1; counter < QUANTITY_SIDE_SCREEN; counter++)
	{
		menu_swipe_right();
	}
	cell_t * finish = NULL;
	actual_cell(&finish, RETURN);

	TEST_ASSERT_EQUAL(start, finish);

}

TEST(navigation, switch_screens_circle_left){
	cell_t * start = get_main_screen();
	for (int counter = 1; counter < 5		; counter++)
	{
		menu_swipe_left();
	}
	cell_t * finish = NULL;
	actual_cell(&finish, RETURN);

	TEST_ASSERT_EQUAL(start, finish);
}



