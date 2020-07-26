#include "dl_list_internal.h"

#define Data(dl_list) ((list_cell_t *)(dl_list->data))

void cell_set_data (list_cell_t * cell, void * data) {
	Data(cell)->data = data;
}

void * cell_data (list_cell_t * cell) {
	return Data(cell)->data;
}

void cell_set_next (list_cell_t * cell, list_cell_t * next) {
	Data(cell)->next = next;
}

list_cell_t * cell_next (list_cell_t * cell) {
	return Data(cell)->next;
}

void cell_set_prev (list_cell_t * cell, list_cell_t * prev) {
	Data(cell)->prev = prev;
}

list_cell_t * cell_prev (list_cell_t * cell) {
	return Data(cell)->prev;
}

void data_set_head (dl_list_data_t * dl_list_data, list_cell_t * head) {
	dl_list_data->head = head;
}

list_cell_t * data_head (dl_list_data_t * data) {
	return data->head;
}

void data_set_tail (dl_list_data_t * dl_list_data, list_cell_t * tail) {
	dl_list_data->tail = tail;
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
