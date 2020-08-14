#include "unity_fixture.h"

#include "dl_list_internal.h"
#include "dl_list_test_helpers.h"

TEST_GROUP (dl_list);

TEST_SETUP (dl_list) {
	create_with_assert(sizeof(test_cell_val_t));
}

TEST_TEAR_DOWN (dl_list) {
	delete_with_assert();
}

/*
[v] create_assign_all_as_defaults
[v] delete_and_make_list_null
[] delete_and_free_all_cells

[v] push_increase_amount_if_possible
[v] first_push_set_head_and_tail_at_the_same_cell
[v] next_push_set_head_at_new_elt 
[v] first_push_assign_cell_pointers_to_NULL
[v] next_assign_cell_pointers_correctly

[] pop_decrease_amount_if_possible
[] last_pop_set_head_and_tail_at_the_same_cell
[] last_pop_assign_cell_pointers_to_NULL
[] next_pop_reassign_cell_pointers_correctly
*/
TEST (dl_list, create_assign_all_as_defaults) {
	TEST_ASSERT_NOT_NULL(test_list);
	TEST_ASSERT_NOT_NULL(test_list->data);

	TEST_ASSERT_NULL(Dl_list_head(test_list));
	TEST_ASSERT_NULL(Dl_list_tail(test_list));
	TEST_ASSERT_EQUAL_INT(
		sizeof(test_cell_val_t),
		data_cell_size(test_list->data)
	);
	TEST_ASSERT_EQUAL_INT(0, data_cell_amount(test_list->data));

	TEST_ASSERT_EQUAL_PTR(_dl_list_push, test_list->push);
	TEST_ASSERT_EQUAL_PTR(_dl_list_pop, test_list->pop);
	TEST_ASSERT_EQUAL_PTR(_dl_list_head, test_list->head);
	TEST_ASSERT_EQUAL_PTR(_dl_list_tail, test_list->tail);
	TEST_ASSERT_EQUAL_PTR(_dl_list_size, test_list->size);
}

TEST (dl_list, delete_and_make_list_null) {
	dl_list_t * test_list_2 = dl_list_create(sizeof(test_cell_val_t));

	TEST_ASSERT_NOT_NULL(test_list_2);

	dl_list_delete(&test_list_2);

	TEST_ASSERT_NULL(test_list_2);
}

TEST (dl_list, delete_and_free_all_cells) {
	test_list_push_3_differ_cells();

	printf("\ntest_list %p\n", test_list);

	list_cell_t
		* head = Dl_list_head(test_list),
		* cells [3] = {};

	TEST_ASSERT_NOT_NULL_MESSAGE(head->data, "head->data is NULL...");
	TEST_ASSERT_NOT_NULL_MESSAGE(head, "head is NULL");

	for (int cell = 0; head; cell++, head = head->next)
		cells[cell] = head;

	dl_list_delete(&test_list);

	TEST_ASSERT_NULL_MESSAGE(cells[0], "cells[0] is not NULL");
	TEST_ASSERT_NULL(cells[1]);
	TEST_ASSERT_NULL(cells[2]);

}

TEST (dl_list, push_increase_amount_if_possible) {
	Dl_list_push(test_list, &test_val_1);
	TEST_ASSERT_EQUAL_INT(1, data_cell_amount(test_list->data));

	Dl_list_push(test_list, &test_val_1);
	TEST_ASSERT_EQUAL_INT(2, data_cell_amount(test_list->data));

	TODO();
	// was "increase amount" now "increase if possible" !
}

TEST (dl_list, first_push_set_head_and_tail_at_the_same_cell) {
	data_set_head(test_list->data, (list_cell_t *)1); // make different because of zeroing at assign

	Dl_list_push(test_list, &test_val_1);
	TEST_ASSERT_EQUAL_PTR(
		Dl_list_head(test_list),
		Dl_list_tail(test_list)
	);
}

TEST (dl_list, next_push_set_head_at_new_elt) {
	Dl_list_push(test_list, &test_val_1);
	TEST_ASSERT_EQUAL_INT(1, data_cell_amount(test_list->data));

	Dl_list_push(test_list, &test_val_2);
	TEST_ASSERT_EQUAL_INT(2, data_cell_amount(test_list->data));

	Dl_list_push(test_list, &test_val_3);
	TEST_ASSERT_EQUAL_INT(3, data_cell_amount(test_list->data));
}

TEST (dl_list, first_push_assign_cell_pointers_to_NULL) {
	Dl_list_push(test_list, &test_val_1);
	
	list_cell_t
		* head = Dl_list_head(test_list),
		* tail = Dl_list_tail(test_list);

	TEST_ASSERT_NULL(head->next);
	TEST_ASSERT_NULL(head->prev);
	TEST_ASSERT_NULL(tail->next);
	TEST_ASSERT_NULL(tail->prev);
}

TEST (dl_list, next_assign_cell_pointers_correctly) {
	Dl_list_push(test_list, &test_val_1);
	Dl_list_push(test_list, &test_val_2);

	list_cell_t
		* head = Dl_list_head(test_list),
		* tail = Dl_list_tail(test_list),
		* middle = NULL;

	TEST_ASSERT_EQUAL_PTR(head, tail->next);
	TEST_ASSERT_NULL(tail->prev);
	TEST_ASSERT_NULL(head->next);
	TEST_ASSERT_EQUAL_PTR(tail, head->prev);

	Dl_list_push(test_list, &test_val_3);

	head = Dl_list_head(test_list);
	tail = Dl_list_tail(test_list);
	middle = tail->next;

	TEST_ASSERT_EQUAL_PTR(NULL, tail->prev);
	TEST_ASSERT_EQUAL_PTR(middle, tail->next);
	TEST_ASSERT_EQUAL_PTR(tail, middle->prev);
	TEST_ASSERT_EQUAL_PTR(head, middle->next);
	TEST_ASSERT_EQUAL_PTR(middle, head->prev);
	TEST_ASSERT_EQUAL_PTR(NULL, head->next);

}

TEST (dl_list, pop_decrease_amount_if_possible) {
	TODO();
}

TEST (dl_list, last_pop_set_head_and_tail_at_the_same_cell) {
	TODO();
}

TEST (dl_list, last_pop_assign_cell_pointers_to_NULL) {
	TODO();
}

TEST (dl_list, next_pop_reassign_cell_pointers_correctly) {
	TODO();
}