/*
 * Copyright © 2019-2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#ifndef _FIND_H_
#define _FIND_H_

#include <stdint.h>
#include <string.h>

#include "../inc/parser/parser_internal.h"
#include "../inc/parser/d_base.h"

dbase_record_t * find_cmd (const char * message);

#endif//_FIND_H_

