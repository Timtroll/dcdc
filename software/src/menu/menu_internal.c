#include "menu_internal.h"

#define QUANTITY_STRING_MAIN_SCREEN 10 
#define QUANTITY_STRING_SIDE_SCREEN 3


//This function is inserted only at the end of the list
void cell_insert (header_t * header, cell_t * cell){
	
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
		header->head->front = cell;
		cell->behind = header->head;
		header->tail = cell;
		header->node_quantity++;
	}

}

void cell_add_data (cell_t * cell, char * data, uint16_t type_screen){

	cell->data =(char)malloc(sizeof(data));
	cell->data = data;
	//проверка на размерность данных для разных главного экрана и остальных экранов
}


void actual_cell(cell_t ** cell, uint8_t mode){

	static cell_t * screen = NULL;
	
	switch(mode){
		case SAVE:
			screen = cell;
		break;

		case RETURN:
			*cell = screen;
		break;
	}

}

cell_t * main_screen_keeper = NULL;

void set_main_screen(cell_t * main_screen){
	main_screen_keeper = main_screen;
}

cell_t * get_main_screen(void){
	return main_screen_keeper;
}
