#include "unity_fixture.h"

TEST_GROUP_RUNNER (static_malloc) {
	RUN_TEST_CASE (static_malloc,
		create_assign_to_the_passed_struct_fields_the_generated_values);
	RUN_TEST_CASE (static_malloc,
		create_set_the_status_of_all_blocks_as_free);
	RUN_TEST_CASE (static_malloc,
		create_clear_allocated_memory);
	RUN_TEST_CASE (static_malloc,
		delete_reset_the_passed_box_fields);
	RUN_TEST_CASE (static_malloc,
		balloc_return_the_pointer_to_the_first_free_block);
	RUN_TEST_CASE (static_malloc,
		balloc_return_null_if_the_free_blocks_does_not_exist_enough);
	RUN_TEST_CASE (static_malloc,
		bfree_set_busy_block_status_as_free);
	RUN_TEST_CASE (static_malloc,
		bfree_random_block_when_not_enough_blocks_and_ballock_it_again);
	RUN_TEST_CASE (static_malloc,
		coorrect_free_when_box_deleted);
	RUN_TEST_CASE (static_malloc,
		create_memory_for_uint8_t_array);
}

