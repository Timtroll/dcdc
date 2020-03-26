/*
 * Copyright © 2019-2020 Daniil D. Ryabinin (ryabiko1953@gmail.com)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#ifndef _SMART_CHARGER_DATA_BASE_H_
#define _SMART_CHARGER_DATA_BASE_H_

// #include "../../inc/parser/parser.h"
#include "smart_ups_defines_army.h"
#include "stddef.h"
#include "smart_ups_actions.h"

#include <string.h>

//at all points is given NO_RESPONSE, because the responce is unknown
void set_vol_cut_off (void) {
	save_data_from_set();
	set_for_voltage_cut_off();
}

void set_charge_current (void) {
	save_data_from_set();
	set_for_charge_current();
}

void set_battery_type (void) {
	save_data_from_set();
	set_for_battery_type();
}

#define VOLTAGE 0
#define CURRENT 1
#define TYPE 2

#define SET_PARAMETER_NUM 3
START_CMD_GROUP (set_parameter, SET_PARAMETER_NUM) {
	[VOLTAGE] = {
		.command = VOLTAGE_CUT_OFF,
		.response = NO_RESPONSE,
		.action = set_vol_cut_off
		
	},
	[CURRENT] = {
		.command = CHARGE_CURRNENT,
		.response =  NO_RESPONSE,
		.action = set_charge_current
	},
	[TYPE] = {
		.command = BATTERY_TYPE,
		.response =  NO_RESPONSE,
		.action = set_battery_type
	}

	END_CMD_GROUP_WITH_RESPONSE(
		SET_PARAMETER_NUM,
		RESP_INVALID_PARAMETER)
};
	

void get_vol_cut_off (void) {
	save_data_from_get(get_for_voltage_cut_off());
}

void get_charge_current (void) {
	save_data_from_get(get_for_charge_current());
}

void get_battery_type (void) {
	save_data_from_get(get_for_battery_type());
}

#define GET_PARAMETER_NUM 3
START_CMD_GROUP (get_parameter, GET_PARAMETER_NUM) {
	[VOLTAGE] = {
		.command = VOLTAGE_CUT_OFF,
		.response = NO_RESPONSE,
		.action = get_vol_cut_off
	},
	[CURRENT] = {
		.command = CHARGE_CURRNENT,
		.response =  NO_RESPONSE,
		.action = get_charge_current
	},
	[TYPE] = {
		.command = BATTERY_TYPE,
		.response =  NO_RESPONSE,
		.action = get_battery_type
	}

	END_CMD_GROUP_WITH_RESPONSE(
		SET_PARAMETER_NUM,
		RESP_INVALID_PARAMETER)
};


#define CHARGER_CMD_NUM  	2
#define charger_cmd_SET 	1
#define charger_cmd_GET  	0	
#define charger_cmd_NOT_FOUND (CHARGER_CMD_NUM - 1)

START_CMD_GROUP (smart_charger_commands, CHARGER_CMD_NUM) {
	[charger_cmd_GET] = {
		.command = CMD_GET,
		.subcommand = SUBCOMMAND(get_parameter)
	},
	[charger_cmd_SET] = {
		.command = CMD_SET,
		.subcommand = SUBCOMMAND(set_parameter)
	}
	END_CMD_GROUP(CHARGER_CMD_NUM)
};

#endif//_SMART_CHARGER_DATA_BASE_H_
