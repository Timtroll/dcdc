#ifndef _DL_LIST_TEST_HELPERS_
#define _DL_LIST_TEST_HELPERS_

#include "dl_list.h"

typedef struct test_cell_val {
	uint8_t
		attr1,
		attr2,
		attr3;
} test_cell_val_t;

extern dl_list_t * test_list;

void create_with_assert (size_t cell_size);
void delete_with_assert (void);

#endif//_DL_LIST_TEST_HELPERS_