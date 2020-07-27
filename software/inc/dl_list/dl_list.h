#ifndef _DL_LIST_H_
#define _DL_LIST_H_

#include <stdlib.h>
#include <stdint.h>

#define LIST_AMOUNT (1)
#define CELL_AMOUNT (2)

typedef struct dl_list {
	void * data;

	void (* push) (struct dl_list * list, void * elt);
	void (* pop)  (struct dl_list * list, void * elt);
	void * (* head) (struct dl_list * list);
	void * (* tail) (struct dl_list * list);

	int (* size) (struct dl_list * list);
} dl_list_t;

void dl_list_group_create (void);
void dl_list_group_delete (void);

dl_list_t * dl_list_create (size_t elt_size);
void dl_list_delete (dl_list_t * list);

#define Dl_list_push(list, elt) list->push(list, elt)
#define Dl_list_pop(list, elt)  list->pop(list, elt)
#define Dl_list_head(list)      list->head(list)
#define Dl_list_tail(list)      list->tail(list)

#define Dl_list_size(list)      list->size(list)	


#endif//_DL_LIST_H_

