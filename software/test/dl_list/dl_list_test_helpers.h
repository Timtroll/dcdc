#ifndef _DL_LIST_TEST_HELPERS_
#define _DL_LIST_TEST_HELPERS_

#include "dl_list_internal.h"
#include "unity_fixture.h"

typedef struct test_cell_val {
	uint8_t
		attr1,
		attr2,
		attr3;
} test_cell_val_t;

dl_list_t * test_list;

test_cell_val_t
	test_val_1,
	test_val_2,
	test_val_3;

void create_with_assert (size_t cell_size);
void delete_with_assert (void);

void test_list_push_3_differ_cells (void);

#define TODO()  TEST_FAIL_MESSAGE("          TODO: WRITE THIS TEST...")

#endif//_DL_LIST_TEST_HELPERS_