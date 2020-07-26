#ifndef _DL_LIST_INTERNAL_H_
#define _DL_LIST_INTERNAL_H_

#include "dl_list.h"
#include "static_malloc.h"

typedef struct list_cell {
	void * data;

	struct list_cell
		* next,
		* prev;
} list_cell_t;

typedef struct dl_list_data {
	list_cell_t
		* head,
		* tail;

	size_t
		cell_size,
		cell_amount;
} dl_list_data_t;

Block_box_declare_global(dl_list_gruop_data, dl_list_data_t, LIST_AMOUNT);
Block_box_declare_global(dl_list_grpup_object, dl_list_t, LIST_AMOUNT);

void cell_set_data (list_cell_t * cell, void * data);
void * cell_data (list_cell_t * cell);

void cell_set_next (list_cell_t * cell, list_cell_t * next);
list_cell_t * cell_next (list_cell_t * cell);

void cell_set_prev (list_cell_t * cell, list_cell_t * prev);
list_cell_t * cell_prev (list_cell_t * cell);

void data_set_head (dl_list_data_t * dl_list_data, list_cell_t * head);
list_cell_t * data_head (dl_list_data_t * data);

void data_set_tail (dl_list_data_t * dl_list_data, list_cell_t * tail);
list_cell_t * data_tail (dl_list_data_t * data);

void data_set_cell_size (dl_list_data_t * data, size_t size);
size_t data_cell_size (dl_list_data_t * data);

void data_set_cell_amount (dl_list_data_t * data, size_t amount);
size_t data_cell_amount (dl_list_data_t * data);

#endif//_DL_LIST_INTERNAL_H_

