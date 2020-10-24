#include "dl_list_internal.h"

#define List_data(list) ((dl_list_data_t *)((list)->data))

void cell_set_data (list_cell_t * cell, void * data) {
	cell->data = data;
}

void * cell_data (list_cell_t * cell) {
	return cell->data;
}

void cell_set_next (list_cell_t * cell, list_cell_t * next) {
	cell->next = next;
}

list_cell_t * cell_next (list_cell_t * cell) {
	return cell->next;
}

void cell_set_prev (list_cell_t * cell, list_cell_t * prev) {
	cell->prev = prev;
}

list_cell_t * cell_prev (list_cell_t * cell) {
	return cell->prev;
}

void data_set_head (dl_list_data_t * data, list_cell_t * head) {
	data->head = head;
}

list_cell_t * data_head (dl_list_data_t * data) {
	return data->head;
}

void data_set_tail (dl_list_data_t * data, list_cell_t * tail) {
	data->tail = tail;
}

list_cell_t * data_tail (dl_list_data_t * data) {
	return data->tail;
}

void data_set_cell_size (dl_list_data_t * data, size_t size) {
	data->cell_size = size;
}

size_t data_cell_size (dl_list_data_t * data) {
	return data->cell_size;
}

void data_set_cell_amount (dl_list_data_t * data, size_t amount) {
	data->cell_amount = amount;
}

size_t data_cell_amount (dl_list_data_t * data) {
	return data->cell_amount;
}

list_cell_t ** _dl_list_head_ptr (struct dl_list * list) {
	return &List_data(list)->head;
}

list_cell_t ** _dl_list_tail_ptr (struct dl_list * list) {
	return NULL;
}