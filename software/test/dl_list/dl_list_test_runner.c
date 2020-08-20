#include "unity_fixture.h"

TEST_GROUP_RUNNER (dl_list) {
	// RUN_TEST_CASE(dl_list, create_assign_all_as_defaults);
	// RUN_TEST_CASE(dl_list, delete_and_make_list_null);
	RUN_TEST_CASE(dl_list, delete_and_free_all_cells);

	RUN_TEST_CASE(dl_list, push_increase_amount_if_possible);
	RUN_TEST_CASE(dl_list, first_push_set_head_and_tail_at_the_same_cell);
	RUN_TEST_CASE(dl_list, next_push_set_head_at_new_elt);
	RUN_TEST_CASE(dl_list, first_push_assign_cell_pointers_to_NULL);
	RUN_TEST_CASE(dl_list, next_assign_cell_pointers_correctly);

	// RUN_TEST_CASE(dl_list, pop_decrease_amount_if_possible);
	// RUN_TEST_CASE(dl_list, last_pop_set_head_and_tail_at_the_same_cell);
	// RUN_TEST_CASE(dl_list, last_pop_assign_cell_pointers_to_NULL);
	// RUN_TEST_CASE(dl_list, next_pop_reassign_cell_pointers_correctly);
}

