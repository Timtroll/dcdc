#ifndef _SYSTEM_INFO_INTERNAL_H_
#define _SYSTEM_INFO_INTERNAL_H_

#include "system_info.h"

parser_memory memory;

void save_to_queue(parser_memory struct_to_save);

void save_data_from_set (void);
void save_data_from_get (char * parameter);
#endif//_SYSTEM_INFO_INTERNAL_H_

