#include "dl_list_test_helpers.h"

dl_list_t * test_list = NULL;

void create_with_assert (size_t cell_size) {
	dl_list_group_create();
	test_list = dl_list_create(cell_size);
}

void delete_with_assert (void) {
	dl_list_delete(&test_list);
	// dl_list_group_delete();
}

test_cell_val_t
	test_val_1 = {
		.attr1 = 1
	},
	test_val_2 = {
		.attr2 = 2
	},
	test_val_3 = {
		.attr3 = 3
	};

void test_list_push_3_differ_cells (void) {
	Dl_list_push(test_list, &test_val_1);
	// TEST_ASSERT_EQUAL_INT(1, data_cell_amount(test_list->data));
	// TEST_ASSERT_NOT_NULL(data_head(test_list->data));
	// TEST_ASSERT_NOT_NULL(Dl_list_head(test_list));

	Dl_list_push(test_list, &test_val_2);
	// TEST_ASSERT_EQUAL_INT(2, data_cell_amount(test_list->data));
	// TEST_ASSERT_NOT_NULL(Dl_list_head(test_list));

	Dl_list_push(test_list, &test_val_3);
	// TEST_ASSERT_EQUAL_INT(3, data_cell_amount(test_list->data));
	// TEST_ASSERT_NOT_NULL(Dl_list_head(test_list));
}