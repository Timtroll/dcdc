#ifndef _DL_LIST_H_
#define _DL_LIST_H_

#include <stdlib.h>
#include <stdint.h>

#define LIST_AMOUNT (1)

typedef struct dl_list {
	void * data;

	void (* push) (struct dl_list * list, void * elt);
	void (* pop)  (struct dl_list * list, void * elt);
	void (* head) (struct dl_list * list, void * head);
	void (* tail) (struct dl_list * list, void * tail);

	int (* size) (struct dl_list * list);
	int (* active_size) (struct dl_list * list);
} dl_list_t;

void dl_list_group_create (void);
void dl_list_group_delete (void);

dl_list_t * dl_list_create (void * elt_memory, size_t elt_size);
void dl_list_delete (dl_list_t * list);

#endif//_DL_LIST_H_

