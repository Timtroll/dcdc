#ifndef _STATIC_MALLOC_INTERNAL_H_
#define _STATIC_MALLOC_INTERNAL_H_

#include "static_malloc.h"

static inline bool block_free (block_box_t * box, bsize_t block_num) {
	return box->block_status[block_num];
}

static inline void make_busy (block_box_t * box, bsize_t block_num) {
	box->block_status[block_num] = false;
}

static inline void make_free (block_box_t * box, bsize_t block_num) {
	box->block_status[block_num] = true;
}

static inline void go_to_the_next_one (block_box_t * box, uint8_t ** current_block) {
	// char * block = *current_block;
	// block += box->block_size;
	// gcc can compile with void pointer, iar can not
	*current_block += box->block_size;
}

#define FOR_EACH(item, in_set) \
		for (bsize_t item = 0; item < in_set; item++)

#endif//_STATIC_MALLOC_INTERNAL_H_
