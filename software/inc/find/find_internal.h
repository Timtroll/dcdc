/*
 * Copyright © 2019-2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#ifndef _FIND_INTERNAL_H_
#define _FIND_INTERNAL_H_

#include "find.h"

char * extract_pattern (
	char * message,
	uint16_t from_here,
	uint16_t cmd_len
);

char * free_spaces (char * source);

dbase_record_t * dbase_table_find (
	dbase_table_t table,
	char * message
);



#endif//_FIND_INTERNAL_H_