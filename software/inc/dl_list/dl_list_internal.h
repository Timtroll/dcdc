#ifndef _DL_LIST_INTERNAL_H_
#define _DL_LIST_INTERNAL_H_

#include "dl_list.h"
#include "static_malloc.h"

#define DATA_AMOUNT LIST_AMOUNT

typedef struct dl_list_data {
	list_cell_t
		* head,
		* tail;

	size_t
		cell_size,
		cell_amount;
} dl_list_data_t;

Block_box_declare_global(dl_list_group_cells, list_cell_t, CELL_AMOUNT);
Block_box_declare_global(dl_list_group_data, dl_list_data_t, DATA_AMOUNT);
Block_box_declare_global(dl_list_group_lists, dl_list_t, LIST_AMOUNT);

void _dl_list_push (struct dl_list * list, void * elt);
void * _dl_list_pop (struct dl_list * list);

list_cell_t * _dl_list_head (struct dl_list * list);
list_cell_t * _dl_list_tail (struct dl_list * list);

list_cell_t ** _dl_list_head_ptr (struct dl_list * list);
list_cell_t ** _dl_list_tail_ptr (struct dl_list * list);

int _dl_list_size (struct dl_list * list);

void cell_set_data (list_cell_t * cell, void * data);
void * cell_data (list_cell_t * cell);

void cell_set_next (list_cell_t * cell, list_cell_t * next);
list_cell_t * cell_next (list_cell_t * cell);

void cell_set_prev (list_cell_t * cell, list_cell_t * prev);
list_cell_t * cell_prev (list_cell_t * cell);

void data_set_head (dl_list_data_t * data, list_cell_t * head);
list_cell_t * data_head (dl_list_data_t * data);

void data_set_tail (dl_list_data_t * data, list_cell_t * tail);
list_cell_t * data_tail (dl_list_data_t * data);

void data_set_cell_size (dl_list_data_t * data, size_t size);
size_t data_cell_size (dl_list_data_t * data);

void data_set_cell_amount (dl_list_data_t * data, size_t amount);
size_t data_cell_amount (dl_list_data_t * data);

#endif//_DL_LIST_INTERNAL_H_

