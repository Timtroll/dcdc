#include "unity_fixture.h"

#include "static_malloc_internal.h"

TEST_GROUP (static_malloc);

#define TEST_BLOCK_QUANTITY 100

TEST_SETUP (static_malloc) {

}

TEST_TEAR_DOWN (static_malloc) {

}

/*
[v] create_assign_to_the_passed_struct_fields_the_generated_values
[v] create_set_the_status_of_all_blocks_as_free
[v] create_clear_allocated_memory
[v] delete_reset_the_passed_box_fields
[v] balloc_return_the_pointer_to_the_first_free_block
[v] balloc_set_the_first_free_block_status_as_busy
[v] balloc_return_null_if_the_free_blocks_does_not_exist_enough
[v] bfree_set_busy_block_status_as_free
[v] bfree_random_block_when_not_enough_blocks_and_ballock_it_again
*/

TEST (static_malloc, create_assign_to_the_passed_struct_fields_the_generated_values) {
	Block_box_create(create_test, uint16_t, TEST_BLOCK_QUANTITY);

	TEST_ASSERT_EQUAL(sizeof(uint16_t), create_test.block_size);
	TEST_ASSERT_EQUAL(TEST_BLOCK_QUANTITY, create_test.block_quantity);
	TEST_ASSERT_EQUAL_PTR(create_test_box_block_status, create_test.block_status);
	TEST_ASSERT_EQUAL_PTR(create_test_box, create_test.block_box);
}

TEST (static_malloc, create_set_the_status_of_all_blocks_as_free) {
	Block_box_create(create_test, uint16_t, TEST_BLOCK_QUANTITY);

	for (bsize_t block = 0; block < TEST_BLOCK_QUANTITY; block++) {
		TEST_ASSERT_TRUE(create_test.block_status[block]);
	}
}

TEST (static_malloc, create_clear_allocated_memory) {
	Block_box_create(create_test, uint16_t, TEST_BLOCK_QUANTITY);

	for (bsize_t byte = 0; byte < TEST_BLOCK_QUANTITY * sizeof(uint16_t); byte++) {
		TEST_ASSERT_EQUAL_UINT8(0, ((uint8_t *)create_test.block_box)[byte]);
	}		
}

TEST (static_malloc, delete_reset_the_passed_box_fields) {
	Block_box_create(delete_test, uint16_t, TEST_BLOCK_QUANTITY);
	Block_box_delete(&delete_test);

	TEST_ASSERT_EQUAL(0, delete_test.block_size);
	TEST_ASSERT_EQUAL(0, delete_test.block_quantity);
	TEST_ASSERT_EQUAL_PTR(NULL, delete_test.block_status);
	TEST_ASSERT_EQUAL_PTR(NULL, delete_test.block_box);
}

TEST (static_malloc, balloc_return_the_pointer_to_the_first_free_block) {
	Block_box_create(balloc_test, uint16_t, TEST_BLOCK_QUANTITY);

	uint16_t
		* expected = &((uint16_t *)balloc_test.block_box)[0],
		* first_block = balloc(&balloc_test);

	TEST_ASSERT_EQUAL_PTR(expected, first_block);
	TEST_ASSERT_FALSE(balloc_test.block_status[0]);
	TEST_ASSERT_TRUE(balloc_test.block_status[1]);

	expected = &((uint16_t *)balloc_test.block_box)[1];
	uint16_t * second_block = balloc(&balloc_test);

	TEST_ASSERT_EQUAL_PTR(expected, second_block);
	TEST_ASSERT_FALSE(balloc_test.block_status[0]);
	TEST_ASSERT_FALSE(balloc_test.block_status[1]);

	bfree(&balloc_test, first_block);
	bfree(&balloc_test, second_block);
}

TEST (static_malloc, balloc_return_null_if_the_free_blocks_does_not_exist_enough) {
	Block_box_create(balloc_test, uint32_t, TEST_BLOCK_QUANTITY);

	uint32_t * allocked_blocks [TEST_BLOCK_QUANTITY] = {NULL};

	for (bsize_t block = 0; block < TEST_BLOCK_QUANTITY; block++) {
		TEST_ASSERT_TRUE(balloc_test.block_status[block]);
		allocked_blocks[block] = balloc(&balloc_test);
		TEST_ASSERT_FALSE(balloc_test.block_status[block]);
		TEST_ASSERT_NOT_NULL(allocked_blocks[block]);
	}

	TEST_ASSERT_NULL(balloc(&balloc_test));
}

TEST (static_malloc, bfree_set_busy_block_status_as_free) {
	Block_box_create(bfree_test, uint32_t, TEST_BLOCK_QUANTITY);

	uint32_t * balloced = balloc(&bfree_test);

	bfree(&bfree_test, balloced);
	TEST_ASSERT_TRUE(bfree_test.block_status[0]);
}

TEST (static_malloc, bfree_random_block_when_not_enough_blocks_and_ballock_it_again) {
	Block_box_create(bfree_test, uint32_t, TEST_BLOCK_QUANTITY);
	uint32_t * allocked_blocks [TEST_BLOCK_QUANTITY] = {NULL};
	bsize_t random_block_number = TEST_BLOCK_QUANTITY / 7;

	for (bsize_t block = 0; block < TEST_BLOCK_QUANTITY; block++) {
		TEST_ASSERT_TRUE(bfree_test.block_status[block]);
		allocked_blocks[block] = balloc(&bfree_test);
		TEST_ASSERT_FALSE(bfree_test.block_status[block]);
		TEST_ASSERT_NOT_NULL(allocked_blocks[block]);
	}

	TEST_ASSERT_FALSE(bfree_test.block_status[random_block_number]);
	bfree(&bfree_test, allocked_blocks[random_block_number]);
	TEST_ASSERT_TRUE(bfree_test.block_status[random_block_number]);

	allocked_blocks[random_block_number] = balloc(&bfree_test);
	TEST_ASSERT_NOT_NULL(allocked_blocks[random_block_number]);
	TEST_ASSERT_FALSE(bfree_test.block_status[random_block_number]);
}

TEST (static_malloc, coorrect_free_when_box_deleted) {
	Block_box_create(bfree_test, uint32_t, TEST_BLOCK_QUANTITY);
	Block_box_delete(&bfree_test);

	void * ptr = balloc(&bfree_test);
	TEST_ASSERT_NULL(ptr);
	bfree(&bfree_test, ptr);
	//no segmentation_fault here
}

TEST (static_malloc, create_memory_for_uint8_t_array) {
	#define DEFAULT_BUF_SIZE 200
	typedef struct buffer {
		uint8_t buf [DEFAULT_BUF_SIZE];
	} buf_t;
	TEST_ASSERT_EQUAL(DEFAULT_BUF_SIZE, sizeof(buf_t));

	Block_box_create(buffers, buf_t, 2);

	buf_t * new_buffer = balloc(&buffers);

	TEST_ASSERT_NOT_NULL(new_buffer);
	TEST_ASSERT_EQUAL_PTR(&buffers_box[0], new_buffer);

	buf_t * new_buffer_2 = balloc(&buffers);

	TEST_ASSERT_NOT_NULL(new_buffer_2);
	TEST_ASSERT_EQUAL_PTR(&buffers_box[1], new_buffer_2);

	buf_t * null_pointer = balloc(&buffers);

	TEST_ASSERT_NULL(null_pointer);

	bfree(&buffers, new_buffer);
	bfree(&buffers, new_buffer_2);
}
