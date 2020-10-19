#ifndef _USER_COMAND_H_
#define _USER_COMAND_H_

#include "user_actions.h"

//maybe this part will be moved to separated block
#define RESP_INVALID_PARAMETER  "invalid (must be 0 - 255)"NEWLINE

#define MAX_CMD_LEN      100//change this
//	

#define START 		0
#define STOP 		1
#define MODE 		2
#define PULSE_WIDTH 3

#define CHARGER_CMD_NUM 4

START_CMD_GROUP (charger_subcomands, CHARGER_CMD_NUM) {
	[START] = {
		.command = "start",
		.response = "charger start was set",
		.action = set_charger_start
		
	},
	[STOP] = {
		.command = "stop",
		.response =  "charger stop was set",
		.action = set_charger_stop
	},
	[MODE] = {
		.command = "mode",
		.response =  "charger mode was set",
		.action = set_charger_mode
	},
	[PULSE_WIDTH] = {
		.command = "pulse_width",
		.response =  "charger pulse_width was set",
		.action = set_charger_pulse_width
	}

	END_CMD_GROUP_WITH_RESPONSE(
		CHARGER_CMD_NUM,
		RESP_INVALID_PARAMETER)
}

#define TIME 		0
#define START_AKK_1 1
#define START_AKK_2 2
#define STOP 		3

#define CHARGING_CMD_NUM 4

START_CMD_GROUP (charging_subcomands, CHARGING_CMD_NUM) {
	[TIME] = {
		.command = "time",
		.response = "charging time was set",
		.action = set_charging_time
		
	},
	[START_AKK_1] = {
		.command = "start_akk_1",
		.response =  "charging start_akk_1 was set",
		.action = set_charging_start_akk_1
	},
	[START_AKK_2] = {
		.command = "start_akk_2",
		.response =  "charging start_akk_2 was set",
		.action = set_charging_start_akk_2
	},
	[STOP] = {
		.command = "stop",
		.response =  "charging top was set",
		.action = set_charging_stop
	}

	END_CMD_GROUP_WITH_RESPONSE(
		CHARGING_CMD_NUM,
		RESP_INVALID_PARAMETER)
};


#define CHARGER 	0
#define CHARGING 	1

#define SET_COMANDS_NUM  	2

START_CMD_GROUP (set_parameter_subcomands, SET_COMANDS_NUM) {
	[CHARGER] = {
		.command = "charger",
		.subcommand = SUBCOMMAND(charger_subcomands)
	},
	[CHARGING] = {
		.command = "charging",
		.subcommand = SUBCOMMAND(charging_subcomands)
	}
	END_CMD_GROUP(SET_COMANDS_NUM)
};






#define SCHEME_GENERATOR 0
#define OUTPUT			 1
#define FIRST_BATTERY	 2
#define SECOND_BATTERY	 3

#define VOLTAGE_CMD_NUM 4

START_CMD_GROUP (voltage_subcomands, VOLTAGE_CMD_NUM) {
	[SCHEME_GENERATOR] = {
		.command = "scheme_generator",
		.response = "voltage scheme_generator was got",
		.action = get_voltage_scheme_generator
		
	},
	[OUTPUT] = {
		.command = "output",
		.response =  "voltage output was got",
		.action = get_voltage_output
	},
	[FIRST_BATTERY] = {
		.command = "first_battery",
		.response =  "voltage of first battery was got",
		.action = get_voltage_first_battery
	},
	[SECOND_BATTERY] = {
		.command = "second_battery",
		.response =  "voltage of second battery was got",
		.action = get_voltage_second_battery
	}

	END_CMD_GROUP_WITH_RESPONSE(
		VOLTAGE_CMD_NUM,
		RESP_INVALID_PARAMETER)
};


#define VOLTAGE 0

#define GET_COMANDS_NUM  	1

START_CMD_GROUP (get_parameter_subcomands, GET_COMANDS_NUM) {
	[VOLTAGE] = {
		.command = "voltage",
		.subcommand = SUBCOMMAND(voltage_subcomands)
	},

	END_CMD_GROUP(GET_COMANDS_NUM)
};








#define ALL_COMANDS_NUM  	2
#define SET_CMD_NUM 	1
#define GET_CMD_NUM  	0

START_CMD_GROUP (groups_of_commands, ALL_COMANDS_NUM) {
	[SET_CMD_NUM] = {
		.command = "get",
		.subcommand = SUBCOMMAND(get_parameter_subcomands)
	},
	[GET_CMD_NUM] = {
		.command = "set",
		.subcommand = SUBCOMMAND(set_parameter_subcomands)
	}
	END_CMD_GROUP(ALL_COMANDS_NUM)
};



#endif//_USER_COMAND_H_