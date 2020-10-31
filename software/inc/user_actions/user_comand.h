#ifndef _USER_COMAND_H_
#define _USER_COMAND_H_



//maybe this part will be moved to separated block
#define RESP_INVALID_PARAMETER  "invalid (must be 0 - 255)"

#define CHARGER_START_RESPONSE 			"Status: Start"
#define CHARGER_STOP_RESPONSE 			"Status: Stop"
#define CHARGER_MODE_RESPONSE 			"You set the mode:"
#define CHARGER_PULSE_WIDTH_RESPONSE 	"You set the pulse width:"

#define CHARGING_TIME_RESPONSE 			"You set the time:"
#define CHARGING_START_AKK_1_RESPONSE 	"Charging: AKK 1"
#define CHARGING_START_AKK_2_RESPONSE 	"Charging: AKK 2"
#define CHARGING_STOP_RESPONSE 			"Charging: Stop"

#define VOLTAGE_SCHEME_RESPONSE			 "Voltage scheme:"
#define VOLTAGE_GENERATOR_RESPONSE 		 "Voltage generator:"
#define VOLTAGE_OUTPUT_RESPONSE 		 "Voltage output:"
#define VOLTAGE_FIRST_BATTERY_RESPONSE	 "Voltage first_battery:"
#define VOLTAGE_SECOND_BATTERY_RESPONSE  "Voltage second_battery:"

#define MAX_CMD_LEN      100//change this
//	


//!!ONLY DEFINITION FUNCTIONS!!
//All realization is in user_action.c  
void set_charger_start(void);
void set_charger_stop(void);
void set_charger_mode(void);
void set_charger_pulse_width(void);

#define START 				0
#define STOP_CHARGER 		1
#define MODE 				2
#define PULSE_WIDTH 		3

#define CHARGER_CMD_NUM 4


START_CMD_GROUP (charger_subcomands, CHARGER_CMD_NUM) {
	[START] = {
		.command = "start",
		.response = CHARGER_START_RESPONSE,
		.action = set_charger_start
		
	},
	[STOP_CHARGER] = {
		.command = "stop",
		.response =  CHARGER_STOP_RESPONSE,
		.action = set_charger_stop
	},
	[MODE] = {
		.command = "mode",
		.response =  CHARGER_MODE_RESPONSE,
		.action = set_charger_mode
	},
	[PULSE_WIDTH] = {
		.command = "pulse_width",
		.response =  CHARGER_PULSE_WIDTH_RESPONSE,
		.action = set_charger_pulse_width
	}

	END_CMD_GROUP_WITH_RESPONSE(
		CHARGER_CMD_NUM,
		RESP_INVALID_PARAMETER)
};


void set_charging_time(void);
void set_charging_start_akk_1(void);
void set_charging_start_akk_2(void);
void set_charging_stop(void);

#define TIME 				0
#define START_AKK_1 		1
#define START_AKK_2 		2
#define STOP_CHARGING 		3

#define CHARGING_CMD_NUM 4

START_CMD_GROUP (charging_subcomands, CHARGING_CMD_NUM) {
	[TIME] = {
		.command = "time",
		.response = CHARGING_TIME_RESPONSE,
		.action = set_charging_time
		
	},
	[START_AKK_1] = {
		.command = "start_akk_1",
		.response =  CHARGING_START_AKK_1_RESPONSE,
		.action = set_charging_start_akk_1
	},
	[START_AKK_2] = {
		.command = "start_akk_2",
		.response =  CHARGING_START_AKK_2_RESPONSE,
		.action = set_charging_start_akk_2
	},
	[STOP_CHARGING] = {
		.command = "stop",
		.response =  CHARGING_STOP_RESPONSE,
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


void get_voltage_generator(void);
void get_voltage_scheme(void);
void get_voltage_output(void);
void get_voltage_first_battery(void);
void get_voltage_second_battery(void);


#define SCHEME 			 0
#define GENERATOR 		 1
#define OUTPUT			 2
#define FIRST_BATTERY	 3
#define SECOND_BATTERY	 4

#define VOLTAGE_CMD_NUM 5

START_CMD_GROUP (voltage_subcomands, VOLTAGE_CMD_NUM) {
	[SCHEME] = {
		.command = "scheme",
		.response = VOLTAGE_SCHEME_RESPONSE,
		.action = get_voltage_scheme
	},
	[GENERATOR] = {
		.command = "generator",
		.response = VOLTAGE_GENERATOR_RESPONSE,
		.action = get_voltage_generator
	},
	[OUTPUT] = {
		.command = "output",
		.response =  VOLTAGE_OUTPUT_RESPONSE,
		.action = get_voltage_output
	},
	[FIRST_BATTERY] = {
		.command = "first_battery",
		.response =  VOLTAGE_FIRST_BATTERY_RESPONSE,
		.action = get_voltage_first_battery
	},
	[SECOND_BATTERY] = {
		.command = "second_battery",
		.response =  VOLTAGE_SECOND_BATTERY_RESPONSE,
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
	}
	END_CMD_GROUP(GET_COMANDS_NUM)
};

#define SET_CMD_NUM 	1
#define GET_CMD_NUM  	0

#define ALL_COMANDS_NUM  	2

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