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

char * sys_info_get_voltage_cut(void);
char * sys_info_get_charging_type(void);
char * sys_info_get_charge_threshold_Pb_lower(void);
char * sys_info_get_charge_threshold_Pb_upper(void);
char * sys_info_get_charge_threshold_others(void);
char * sys_info_get_discharge_threshold(void);
char * sys_info_get_quantity_cans(void);
char * sys_info_get_capacity(void);
char * sys_info_get_max_allowable_capacity(void);
char * sys_info_get_internal_voltage_default(void);
char * sys_info_get_type_battery(void);

#endif//_SYSTEM_INFO_H_

