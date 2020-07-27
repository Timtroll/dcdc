#ifndef _STATIC_MALLOC_H_
#define _STATIC_MALLOC_H_

#include <stdint.h>
#include <stdbool.h>
typedef uint16_t bsize_t;
typedef struct block_box {
	bsize_t
		block_size,
		block_quantity;
	bool * block_status;
	void * block_box;
} block_box_t;

// #define Block_box_create_generic(filescope, name, block_data_type, items_quantity) 
// 	filescope bool name ## _box_block_status [items_quantity]; 
// 	filescope block_data_type name ## _box   [items_quantity]; 
// 	filescope block_box_t name = { 
// 		.block_size = sizeof(block_data_type), 
// 		.block_quantity = items_quantity, 
// 		.block_status = name ## _box_block_status, 
// 		.block_box = name ## _box 
// 	}

#define Block_box_declare(name, block_data_type, items_quantity) \
	static bool name ## _box_block_status [items_quantity]; \
	static block_data_type name ## _box   [items_quantity]; \
	static block_box_t name = { \
		.block_size = sizeof(block_data_type), \
		.block_quantity = items_quantity, \
		.block_status = name ## _box_block_status, \
		.block_box = name ## _box \
	}
#define Block_box_create(name, block_data_type, items_quantity) \
	Block_box_declare(name, block_data_type, items_quantity); \
	___must_be_in_macro____block_box_init(&name)

#define Block_box_declare_global_internal(name, block_data_type, items_quantity) \
	bool name ## _box_block_status [items_quantity]; \
	block_data_type name ## _box   [items_quantity]; \
	block_box_t name = { \
		.block_size = sizeof(block_data_type), \
		.block_quantity = items_quantity, \
		.block_status = name ## _box_block_status, \
		.block_box = name ## _box \
	}
#define Block_box_declare_global(name, block_data_type, items_quantity) \
	extern bool name ## _box_block_status [items_quantity]; \
	extern block_data_type name ## _box   [items_quantity]; \
	extern block_box_t name;

#define Block_box_create_global(box_ptr) \
	___must_be_in_macro____block_box_init(box_ptr)

#define Block_box_delete(box_ptr) \
	___must_be_in_macro____block_box_deinit(box_ptr)

void ___must_be_in_macro____block_box_init (block_box_t * box);
void ___must_be_in_macro____block_box_deinit (block_box_t * box);

void * balloc (block_box_t * box);
void bfree (block_box_t * box, void * block);

#endif//_STATIC_MALLOC_H_
