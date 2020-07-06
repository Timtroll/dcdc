// #include "static_malloc_internal.h"
#include "static_malloc_internal.h"

#include <string.h>
void ___must_be_in_macro____block_box_init (block_box_t * box) {
	memset(box->block_status, true, box->block_quantity);
	// memset(box->block_box, 0, box->block_size * box->block_quantity);
}

void ___must_be_in_macro____block_box_deinit (block_box_t * box) {
	box->block_size = 0;
	box->block_quantity = 0;
	box->block_status = NULL;
	box->block_box = NULL;
}

void * balloc (block_box_t * box) {
	uint8_t * user_block = box->block_box;
	bsize_t in_block_set = box->block_quantity;

	FOR_EACH (block, in_block_set) {
		if (block_free(box, block)) {
			make_busy(box, block);
			return user_block;
		}
		go_to_the_next_one(box, &user_block);
	}
	return NULL;
}

void bfree (block_box_t * box, void * desired_block) {
	if (desired_block == NULL) return;
	uint8_t * one_of_blocks = box->block_box;
	bsize_t in_block_set = box->block_quantity;

	FOR_EACH (block, in_block_set) {
		if (one_of_blocks == desired_block) {
			make_free(box, block);
		}
		go_to_the_next_one(box, &one_of_blocks);
	}
}
