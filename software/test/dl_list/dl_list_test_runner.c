#include "unity_fixture.h"

TEST_GROUP_RUNNER (dl_list) {
	RUN_TEST_CASE(dl_list, create_assign_all_as_defaults);
	RUN_TEST_CASE(dl_list, delete_free_cell_and_list_correctly);

	RUN_TEST_CASE(dl_list, push_increase_amount);
	RUN_TEST_CASE(dl_list, first_push_set_head_and_tail_at_the_same_cell);
}

