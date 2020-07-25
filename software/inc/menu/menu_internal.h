#ifndef _MENU_INTERNAL_H_
#define _MENU_INTERNAL_H_

#include "menu.h"
#include <stdint.h>
/*#include "../screen/screen.h" 
	uncomment when block screen is created
	From this block, a function will be obtained to
 	create information for the "data" field
*/


//this block will be a source for obtaining information
#include "../system_info/system_info.h"




#define MAIN_SCREEN 0
#define SIDE_SCREEN 1

#define SAVE 0
#define RETURN 1

#define QUANTITY_SIDE_SCREEN 9

typedef struct cell_node
{
	void 
		* front,
		* behind,
		* data;

	//screen_t * data;

} cell_t;

typedef struct header_node
{
	cell_t 
		* head,
		* tail;
	uint8_t node_quantity;

} header_t;


#define Constructor_cell(name) \
	static cell_t name = { \
		.front = NULL, \
		.behind = NULL, \
		.data = NULL \
	}

#define Constructor_header(name) \
	static header_t name = { \
		.head = NULL, \
		.tail = NULL, \
		.node_quantity = 0 \
	}

void cell_insert (header_t * header, cell_t * cell);
void cell_add_data (cell_t * cell, char * data, uint16_t type_screen);
void actual_cell(cell_t ** cell, uint8_t mode);

void set_main_screen(cell_t * main_screen);
cell_t * get_main_screen(void);

#define Create_list(name_list) \
	Constructor_header(name_list); \
	Constructor_cell(main_screen); \
	cell_insert(&name_list, &main_screen); \
	for (int counter = 0; counter < QUANTITY_SIDE_SCREEN; counter++) \
	{	\
		Constructor_cell(counter); \
		cell_insert(&name_list, &counter); \
	} \
	actual_cell(&main_screen, SAVE); \
	set_main_screen(&main_screen); \

#endif//_MENU_INTERNAL_H_

