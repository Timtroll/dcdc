#ifndef _MENU_INTERNAL_H_
#define _MENU_INTERNAL_H_

#include "menu.h"
#include <stdint.h>
/*#include "../screen/screen.h" 
uncomment when block screen is created
From this block, a function will be obtained to
 create information for the "data" field
*/

#define MAIN_SCREEN 0
#define SIDE_SCREEN 1

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
	cell_t name = { \
		.front = NULL, \
		.behind = NULL, \
		.data = NULL \
	}

#define Constructor_header(name) \
	header_t name = { \
		.head = NULL, \
		.tail = NULL, \
		.node_quantity = 0 \
	}

void insert_cell(header_t * header, cell_t * cell);
void add_data_in_cell(cell_t * cell, void * data, uint16_t type_screen);



#endif//_MENU_INTERNAL_H_

