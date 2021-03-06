/*
 * Copyright © 2020 Daniil D. Ryabinin (ryabiko1953@gmail.com)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#ifndef _RESPONSE_DEFINES_ARMY_SMART_CHARGER_H_
#define _RESPONSE_DEFINES_ARMY_SMART_CHARGER_H_

#define MAX_CMD_LEN      30//100

#define NEWLINE "\r"
#define NO_RESPONSE ""

#define RESP_INVALID_PARAMETER  "invalid (must be 0 - 255)"NEWLINE
#define VOLTAGE_CUT_OFF         "voltage_cut_off"
#define CHARGE_CURRNENT         "charge_current"
#define BATTERY_TYPE            "battery_type"

#define CMD_SET                      "set"
	#define SET_PARAMETER            "set_parameter"
	#define VOLTAGE_CUT_OFF_SET_RESPONSE "voltage_cut_off is set"
	#define CHARGE_CURRENT_SET_RESPONSE "charge_current is set"
	#define BATTERY_TYPE_SET_RESPONSE	"battery_type is set"

#define CMD_GET                       "get"
		#define SET_PARAMETER         "set_parameter"
		#define VOLTAGE_CUT_OFF_GET_RESPONSE "voltage_cut_off was got"NEWLINE
		#define CHARGE_CURRENT_GET_RESPONSE "charge_current was got"NEWLINE
		#define BATTERY_TYPE_GET_RESPONSE	"battery_type was got"NEWLINE



#endif//_RESPONSE_DEFINES_ARMY_SMART_CHARGER_H_
