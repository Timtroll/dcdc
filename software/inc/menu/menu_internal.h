#ifndef _MENU_INTERNAL_H_
#define _MENU_INTERNAL_H_

#include "menu.h"
#include <stdint.h>
/*#include "../screen/screen.h" 
uncomment when block screen is created
From this block, a function will be obtained to
 create information for the "data" field
*/

typedef struct cell_node
{
	void 
		* ahead,
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
		.head = NULL, \
		.tail = NULL, \
		.node_quantity = 0 \
	}

#define Constructor_header(name) \
	header_t name = { \
		.head = NULL, \
		.tail = NULL, \
		.node_quantity = 0 \
	}



#endif//_MENU_INTERNAL_H_

