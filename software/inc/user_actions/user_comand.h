#ifndef _USER_COMAND_H_
#define _USER_COMAND_H_

#define DEBUG_COMAND 


//maybe this part will be moved to separated block
#define RESP_INVALID_PARAMETER  "invalid (must be 0 - 255)"

#define CHARGER_START_RESPONSE 			 "Status: Start"
#define CHARGER_STOP_RESPONSE 			 "Status: Stop"
#define CHARGER_MODE_RESPONSE 			 "You set the mode:"
#define CHARGER_AKK_RESPONSE 			 "You set the akk:"
#define CHARGER_PULSE_WIDTH_RESPONSE 	 "You set the pulse width:"

#define CHARGING_PERIOD_RESPONSE 		 "You set the period:"
#define CHARGING_MODE_RESPONSE  		 "You set the charging mode:"
#define CHARGING_AKK_RESPONSE   		 "Now charging:"
#define CHARGING_START_RESPONSE 		 "Charging: Start"
#define CHARGING_STOP_RESPONSE  		 "Charging: Stop"

#define VOLTAGE_SCHEME_RESPONSE			 "Voltage scheme: "
#define VOLTAGE_GENERATOR_RESPONSE 		 "Voltage generator: "
#define VOLTAGE_OUTPUT_RESPONSE 		 "Voltage output: "
#define VOLTAGE_FIRST_BATTERY_RESPONSE	 "Voltage first_battery: "
#define VOLTAGE_SECOND_BATTERY_RESPONSE  "Voltage second_battery: "

#define MAX_CMD_LEN      150//change this
//	


//!!ONLY DEFINITION FUNCTIONS!!
//All realization is in user_action.c  
void set_charger_start(void);
void set_charger_stop(void);
void set_charger_mode(void);
void set_charger_akk(void);
void set_charger_pulse_width(void);

#define START_CHARGER 		0
#define STOP_CHARGER 		1
#define MODE_CHARGER 		2
#define AKK_CHARGER         3
#define PULSE_WIDTH 		4

#define CHARGER_CMD_NUM 5


START_CMD_GROUP (charger_subcomands, CHARGER_CMD_NUM) {
	[START_CHARGER] = {
		.command = "start",
		.response = CHARGER_START_RESPONSE,
		.action = set_charger_start
		
	},
	[STOP_CHARGER] = {
		.command = "stop",
		.response =  CHARGER_STOP_RESPONSE,
		.action = set_charger_stop
	},
	[MODE_CHARGER] = {
		.command = "mode",
		.response =  CHARGER_MODE_RESPONSE,
		.action = set_charger_mode
	},
	[AKK_CHARGER] = {
		.command = "akk",
		.response =  CHARGER_AKK_RESPONSE,
		.action = set_charger_akk
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


#ifdef DEBUG_COMAND

#define CHARGING_T_POSITIVE_PULSE_RESPONSE 		 "Duration + pulse:"
#define CHARGING_T_NEGATIVE_PULSE_RESPONSE 		 "Duration - pulse:"
#define CHARGING_NEED_DISCH_PULSE_RESPONSE 		 "The need for negative pulse:"

void set_charging_period(void);
void set_charging_mode(void);
void set_charging_akk(void);
void set_charging_start(void);
void set_charging_stop(void);
void set_charging_t_positive_pulse(void);
void set_charging_t_negative_pulse(void);
void set_charging_need_disch_pulse(void);

#define PERIOD 				0
#define MODE_CHARGING       1
#define AKK_CHARGING		2
#define START_CHARGING		3
#define STOP_CHARGING 		4
#define T_POSITIVE_PULSE 	5
#define T_NEGATIVE_PULSE 	6
#define NEED_DISCH_PULSE 	7

#define CHARGING_CMD_NUM 8

START_CMD_GROUP (charging_subcomands, CHARGING_CMD_NUM) {
	[PERIOD] = {
		.command = "period",
		.response = CHARGING_PERIOD_RESPONSE,
		.action = set_charging_period
		
	},
	[MODE_CHARGING] = {
		.command = "mode",
		.response =  CHARGING_MODE_RESPONSE,
		.action = set_charging_mode
	},
	[AKK_CHARGING] = {
		.command = "akk",
		.response =  CHARGING_AKK_RESPONSE,
		.action = set_charging_akk
	},
	[START_CHARGING] = {
		.command = "start",
		.response =  CHARGING_START_RESPONSE,
		.action = set_charging_start
	},
	[STOP_CHARGING] = {
		.command = "stop",
		.response =  CHARGING_STOP_RESPONSE,
		.action = set_charging_stop
	},
	[T_POSITIVE_PULSE] = {
		.command = "t_positive_pulse",
		.response =  CHARGING_T_POSITIVE_PULSE_RESPONSE,
		.action = set_charging_t_positive_pulse
	},
	[T_NEGATIVE_PULSE] = {
		.command = "t_negative_pulse",
		.response =  CHARGING_T_NEGATIVE_PULSE_RESPONSE,
		.action = set_charging_t_negative_pulse
	},
	[NEED_DISCH_PULSE] = {
		.command = "need_disch_pulse",
		.response = CHARGING_NEED_DISCH_PULSE_RESPONSE ,
		.action = set_charging_need_disch_pulse
	}


	END_CMD_GROUP_WITH_RESPONSE(
		CHARGING_CMD_NUM,
		RESP_INVALID_PARAMETER)
};
#else

void set_charging_period(void);
void set_charging_mode(void);
void set_charging_akk(void);
void set_charging_start(void);
void set_charging_stop(void);


#define PERIOD 				0
#define MODE_CHARGING       1
#define AKK_CHARGING		2
#define START_CHARGING		3
#define STOP_CHARGING 		4

#define CHARGING_CMD_NUM 5

START_CMD_GROUP (charging_subcomands, CHARGING_CMD_NUM) {
	[PERIOD] = {
		.command = "period",
		.response = CHARGING_PERIOD_RESPONSE,
		.action = set_charging_period
		
	},
	[MODE_CHARGING] = {
		.command = "mode",
		.response =  CHARGING_MODE_RESPONSE,
		.action = set_charging_mode
	},
	[AKK_CHARGING] = {
		.command = "akk",
		.response =  CHARGING_AKK_RESPONSE,
		.action = set_charging_akk
	},
	[START_CHARGING] = {
		.command = "start",
		.response =  CHARGING_START_RESPONSE,
		.action = set_charging_start
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


#endif


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


#ifdef DEBUG_COMAND

#define G_CHARGING_T_POSITIVE_PULSE_RESPONSE				"The positive pulse is now:" 
#define G_CHARGING_T_NEGATIVE_PULSE_RESPONSE				"The negative pulse is now:"
#define G_CHARGING_NEED_DISCH_PULSE_RESPONSE				"The need for negative pulse:"
#define G_CHARGING_PULSE_POWER_RESPONSE 					"The amount of charge transferred:"
#define G_CHARGING_FALL_PULSE_RESPONSE 						"Voltage drop ratio:"
#define G_CHARGING_AKK_RESPONSE 							"The battery is charging now:"
#define G_CHARGING_AKK_MODE_RESPONSE						"Set charging mode:"
#define G_CHARGING_PERIOD_RESPONSE							"Charging period:"


void get_charging_t_positive_pulse(void);
void get_charging_t_negative_pulse(void);
void get_charging_need_disch_pulse(void);
void get_charging_pulse_power(void);
void get_charging_fall_pulse(void);
void get_charging_akk(void);
void get_charging_akk_mode(void);
void get_charging_period(void);

#define G_CHARGING_T_POSITIVE_PULSE 			0
#define G_CHARGING_T_NEGATIVE_PULSE 			1
#define G_CHARGING_NEED_DISCH_PULSE 			2
#define G_CHARGING_PULSE_POWER 					3
#define G_CHARGING_FALL_PULSE 					4
#define G_CHARGING_AKK 							5
#define G_CHARGING_AKK_MODE 					6
#define G_CHARGING_PERIOD 						7

#define G_CHARGING_CMD_NUM 8


START_CMD_GROUP (g_charging_subcomands, G_CHARGING_CMD_NUM) {
	[G_CHARGING_T_POSITIVE_PULSE] = {
		.command = "t_positive_pulse",
		.response = G_CHARGING_T_POSITIVE_PULSE_RESPONSE,
		.action = get_charging_t_positive_pulse
	},
	[G_CHARGING_T_NEGATIVE_PULSE] = {
		.command = "t_negative_pulse",
		.response = G_CHARGING_T_NEGATIVE_PULSE_RESPONSE,
		.action = get_charging_t_negative_pulse
	},
	[G_CHARGING_NEED_DISCH_PULSE] = {
		.command = "need_disch_pulse",
		.response =  G_CHARGING_NEED_DISCH_PULSE_RESPONSE,
		.action = get_charging_need_disch_pulse
	},
	[G_CHARGING_PULSE_POWER] = {
		.command = "pulse_power",
		.response =  G_CHARGING_PULSE_POWER_RESPONSE,
		.action = get_charging_pulse_power
	},
	[G_CHARGING_FALL_PULSE] = {
		.command = "fall_pulse",
		.response =  G_CHARGING_FALL_PULSE_RESPONSE,
		.action = get_charging_fall_pulse
	},
	[G_CHARGING_AKK] = {
		.command = "akk",
		.response = G_CHARGING_AKK_RESPONSE, 
		.action = get_charging_akk
	},
	[G_CHARGING_AKK_MODE] = {
		.command = "akk_mode",
		.response = G_CHARGING_AKK_MODE_RESPONSE, 
		.action = get_charging_akk_mode
	},
	[G_CHARGING_PERIOD] = {
		.command = "period",
		.response = G_CHARGING_PERIOD_RESPONSE, 
		.action = get_charging_period
	}
	

	END_CMD_GROUP_WITH_RESPONSE(
		G_CHARGING_CMD_NUM,
		RESP_INVALID_PARAMETER)
};


#define G_CHARGER_MODE_RESPONSE 								"Operating mode:"
#define G_GHARGER_OUTPUT_AKK_RESPONSE							"The battery is discharging:"
#define G_CHARGER_OUTPUT_PW_RESPONSE	 						"Output pulse width:"

void get_charger_mode(void);
void get_charger_output_akk(void);
void get_charger_output_pw(void);

#define G_CHARGER_MODE 									0
#define G_GHARGER_OUTPUT_AKK 							1
#define G_CHARGER_OUTPUT_PW 							2


#define G_CHARHER_CMD_NUM 								3

START_CMD_GROUP (g_charger_subcomands, G_CHARHER_CMD_NUM) {
	[G_CHARGER_MODE] = {
		.command = "mode",
		.response = G_CHARGER_MODE_RESPONSE,
		.action = get_charger_mode
	},
	[G_GHARGER_OUTPUT_AKK] = {
		.command = "output_akk",
		.response = G_GHARGER_OUTPUT_AKK_RESPONSE,
		.action = get_charger_output_akk
	},
	[G_CHARGER_OUTPUT_PW] = {
		.command = "output_pw",
		.response =  G_CHARGER_OUTPUT_PW_RESPONSE,
		.action = get_charger_output_pw
	}
	

	END_CMD_GROUP_WITH_RESPONSE(
		G_CHARHER_CMD_NUM,
		RESP_INVALID_PARAMETER)
};




#define VOLTAGE 										0
#define G_CHARGING 										1
#define G_CHARGER 										2	

#define GET_COMANDS_NUM  	3

START_CMD_GROUP (get_parameter_subcomands, GET_COMANDS_NUM) {
	[VOLTAGE] = {
		.command = "voltage",
		.subcommand = SUBCOMMAND(voltage_subcomands)
	},
	[G_CHARGING] = {
		.command = "charging",
		.subcommand = SUBCOMMAND(g_charging_subcomands)
	},
	[G_CHARGER] = {
		.command = "charger",
		.subcommand = SUBCOMMAND(g_charger_subcomands)
	}
	END_CMD_GROUP(GET_COMANDS_NUM)
};

#else
#define VOLTAGE 0

#define GET_COMANDS_NUM  	1

START_CMD_GROUP (get_parameter_subcomands, GET_COMANDS_NUM) {
	[VOLTAGE] = {
		.command = "voltage",
		.subcommand = SUBCOMMAND(voltage_subcomands)
	}
	END_CMD_GROUP(GET_COMANDS_NUM)
};
#endif


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