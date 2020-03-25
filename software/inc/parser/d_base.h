/*
 * Copyright © 2019-2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */
#ifndef _D_BASE_H_
#define _D_BASE_H_

#define SUBCOMMAND(cell_list_ptr) ( \
	(dbase_record_t *)(cell_list_ptr) \
)

#define START_CMD_GROUP(name, items_quantity) \
static dbase_record_t \
name [items_quantity + 1] =

#define END_CMD_GROUP(items_quantity) \
	,[items_quantity] = {NULL}

#define END_CMD_GROUP_WITH_RESPONSE(items_quantity, resp) \
	,[items_quantity] = {.response = resp}


typedef struct parser_record {
	char
		* command,
		* response,
		* parameter;
	void (* action) (void);
	struct parser_record * subcommand;
} dbase_record_t;

typedef dbase_record_t dbase_table_t [];
typedef dbase_record_t (* command_dbase_t) [];
typedef void (* action_t) (void);

#endif//_D_BASE_H_