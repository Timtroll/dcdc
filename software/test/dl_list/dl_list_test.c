#include "unity_fixture.h"

#include "dl_list_internal.h"
#include "dl_list_test_helpers.h"

TEST_GROUP (dl_list);

dl_list_t * test_list = NULL;
test_screen_t screen = {
	.attr1 = 1,
	.attr2 = 2,
	.attr3 = 3
};

list_cell_t expected_cell = {
	.data = &screen,
	.next = NULL,
	.prev = NULL
};

TEST_SETUP (dl_list) {
	create_with_assert(sizeof(test_screen_t));
}

TEST_TEAR_DOWN (dl_list) {
	delete_with_assert();
}

/*
[v] create_assign_all_as_defaults

[v] push_increase_amount
[] first_push_set_head_and_tail_at_the_same_cell
*/
TEST (dl_list, create_assign_all_as_defaults) {
	TEST_ASSERT_NOT_NULL(test_list);
	TEST_ASSERT_NOT_NULL(test_list->data);

	TEST_ASSERT_NULL(Dl_list_head(test_list));
	TEST_ASSERT_NULL(Dl_list_tail(test_list));
	TEST_ASSERT_EQUAL_INT(
		sizeof(test_screen_t),
		data_cell_size(test_list->data)
	);
	TEST_ASSERT_EQUAL_INT(0, data_cell_amount(test_list->data));

	TEST_ASSERT_EQUAL_PTR(_dl_list_push, test_list->push);
	TEST_ASSERT_EQUAL_PTR(_dl_list_pop, test_list->pop);
	TEST_ASSERT_EQUAL_PTR(_dl_list_head, test_list->head);
	TEST_ASSERT_EQUAL_PTR(_dl_list_tail, test_list->tail);
	TEST_ASSERT_EQUAL_PTR(_dl_list_size, test_list->size);
}

TEST (dl_list, delete_free_cell_and_list_correctly) {
	dl_list_t * test_list_2 = dl_list_create(sizeof(test_screen_t));

	dl_list_delete(test_list_2);

	TEST_ASSERT_NULL(test_list_2);
}

TEST (dl_list, push_increase_amount) {
	Dl_list_push(test_list, &screen);
	TEST_ASSERT_EQUAL_INT(1, data_cell_amount(test_list->data));

	Dl_list_push(test_list, &screen);
	TEST_ASSERT_EQUAL_INT(2, data_cell_amount(test_list->data));
}

TEST (dl_list, first_push_set_head_and_tail_at_the_same_cell) {
	data_set_head(test_list->data, (list_cell_t *)1); // make different because of zeroing at assign

	Dl_list_push(test_list, &screen);
	TEST_ASSERT_EQUAL_PTR(
		Dl_list_head(test_list),
		Dl_list_tail(test_list)
	);
}
