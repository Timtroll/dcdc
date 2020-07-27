#include "dl_list_internal.h"

Block_box_declare_global_internal(dl_list_group_cells, dl_list_data_t, CELL_AMOUNT);
Block_box_declare_global_internal(dl_list_group_lists, dl_list_t, LIST_AMOUNT);

void dl_list_group_create (void) {
	Block_box_create_global(&dl_list_group_cells);
	// assign defaults for list data group here

	Block_box_create_global(&dl_list_group_lists);
	// assign defaults for list objects group here
}

void dl_list_group_delete (void) {
	Block_box_delete(&dl_list_group_cells);
	Block_box_delete(&dl_list_group_lists);
}

dl_list_t * dl_list_create (size_t elt_size) {
	dl_list_t * list = balloc(&dl_list_group_lists);
	if (list == NULL) return NULL;

	list->data = balloc(&dl_list_group_cells);
	if (list->data == NULL) {
		bfree(&dl_list_group_lists, list);
		return NULL;
	}

	data_set_head(list->data, NULL);
	data_set_tail(list->data, NULL);
	data_set_cell_size(list->data, elt_size);
	data_set_cell_amount(list->data, 0);

	list->push = _dl_list_push;
	list->pop = _dl_list_pop;
	list->head = _dl_list_head;
	list->tail = _dl_list_tail;

	list->size = _dl_list_size;

	return list;
}

void dl_list_delete (dl_list_t * list) {

}


void _dl_list_push (dl_list_t * list, void * elt) {
	data_set_cell_amount(list->data, data_cell_amount(list->data) + 1);
}

void _dl_list_pop (struct dl_list * list, void * elt) {

}

void * _dl_list_head (struct dl_list * list) {
	return data_head(list->data);
}

void * _dl_list_tail (struct dl_list * list) {
	return data_tail(list->data);
}

int _dl_list_size (struct dl_list * list) {
	return 0;
}

