#ifndef _SYSTEM_INFO_H_
#define _SYSTEM_INFO_H_

#include "stddef.h"
#include "stdio.h"
#include "string.h"

#include "../parser/d_base.h"
#include "../parser/parser.h"

typedef struct {
	char
		* parameter,
		* response;
	action_t action;
} parser_memory;

#endif//_SYSTEM_INFO_H_

