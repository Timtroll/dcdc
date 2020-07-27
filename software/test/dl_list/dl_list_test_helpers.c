#include "dl_list_test_helpers.h"

void create_with_assert (size_t cell_size) {
	dl_list_group_create();
	test_list = dl_list_create(cell_size);
}

void delete_with_assert (void) {
	// dl_list_delete(test_list);
	// dl_list_group_delete();
}