#include "dl_list_internal.h"

void _dl_list_push (struct dl_list * list, void * elt);
void _dl_list_pop (struct dl_list * list, void * elt);
void _dl_list_head (struct dl_list * list, void * head);
void _dl_list_tail (struct dl_list * list, void * tail);
int _dl_list_size (struct dl_list * list);
int _dl_list_active_size (struct dl_list * list);

Block_box_declare_global_internal(dl_list_group_data, dl_list_data_t, LIST_AMOUNT);
Block_box_declare_global_internal(dl_list_group_object, dl_list_t, LIST_AMOUNT);

void dl_list_group_create (void) {
	Block_box_create_global(&dl_list_group_data);
	// assign defaults for list data group here

	Block_box_create_global(&dl_list_group_object);
	// assign defaults for list objects group here
}

void dl_list_group_delete (void) {
	Block_box_delete(&dl_list_group_data);
	Block_box_delete(&dl_list_group_object);
}

dl_list_t * dl_list_create (void * elt_memory, size_t elt_size) {
	dl_list_t * list = balloc(&dl_list_group_object);
	if (list == NULL) return NULL;

	list->data = balloc(&dl_list_group_data);
	if (list->data == NULL) {
		bfree(&dl_list_group_object, list);
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
	list->active_size = _dl_list_active_size;

	return list;
}

void dl_list_delete (dl_list_t * list) {

}


void _dl_list_push (struct dl_list * list, void * elt) {

}

void _dl_list_pop (struct dl_list * list, void * elt) {

}

void _dl_list_head (struct dl_list * list, void * head) {

}

void _dl_list_tail (struct dl_list * list, void * tail) {

}

int _dl_list_size (struct dl_list * list) {
	return 0;
}

int _dl_list_active_size (struct dl_list * list) {
	return 0;
}
