#ifndef _DL_LIST_TEST_HELPERS_
#define _DL_LIST_TEST_HELPERS_

#include "dl_list.h"

typedef struct test_screen {
	uint8_t
		attr1,
		attr2,
		attr3;
} test_screen_t;

extern dl_list_t * test_list;

void create_with_assert (size_t cell_size);
void delete_with_assert (void);

#endif//_DL_LIST_TEST_HELPERS_