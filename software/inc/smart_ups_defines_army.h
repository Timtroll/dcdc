#ifndef _RESPONSE_DEFINES_ARMY_SMART_CHARGER_H_
#define _RESPONSE_DEFINES_ARMY_SMART_CHARGER_H_

#define MAX_CMD_LEN      30//100

#define MAX_CMD_LEN      30//100

#define NEWLINE "\r"
#define NO_RESPONSE ""


#define RESP_INVALID_PARAMETER  "invalid (must be 0 - 255)"NEWLINE
#define VOLTAGE_CUT_OFF "voltage_cut_off"
#define CHARGE_CURRNENT "charge_current"
#define BATTERY_TYPE "battery_type"

#define CMD_SET                      "set"
	#define SET_PARAMETER "set_parameter"

#define CMD_GET                       "get"
		#define SET_PARAMETER "set_parameter"

#endif//_RESPONSE_DEFINES_ARMY_SMART_CHARGER_H_