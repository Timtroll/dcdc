#include "menu_internal.h"

#define QUANTITY_STRING_MAIN_SCREEN 10 
#define QUANTITY_STRING_SIDE_SCREEN 3


//This function is inserted only at the end of the list
void insert_cell(header_t * header, cell_t * cell){
	if (header->head == NULL && 
		header->tail == NULL &&
		header->node_quantity == 0)
	{
		header->head = cell;
		header->tail = cell;
		header->node_quantity++;		
	}
	else
	{
		header->tail->behind = cell;
		cell->front = header->tail;
		header->tail = cell;
		header->node_quantity++;
	}

}


