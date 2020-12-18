#include "user_actions_internal.h"

#include <stdio.h>

#define PLUG -1
#define START_FUNC 0
#define STOP_FUNC 1
#define DIFFERENT_FUNC 2
#define SET 0
#define GET 1

#define BOOL_OR_UINT8_T 1
#define UINT16_T 2 
#define FLOAT_ 4

#define MAX_LEN_STRING 150
#define MAX_LEN_RESPONSE 50

typedef struct response
{
	uint8_t 
		set_get_func,
		type,
		stop_start_func;
	void *(* hardware_function)();
	char text_response[MAX_LEN_RESPONSE];
	bool 
		accept_parameters, 
		defined_num;
} response_t;

response_t response;
static char user_response [URESP_MAX_LEN];
static char string_num [MAX_LEN_STRING] ;
static bool valid_sintax = false; 

static inline void constructor (
		uint8_t function_type,
		uint8_t	parameter_type,
		uint8_t function_mode,
		void *(*function_hardware),
		bool receiving,
		bool defined)
{
			memset(&response, 0, sizeof(response));
			response.set_get_func = function_type;
			response.type = parameter_type;
			response.stop_start_func = function_mode;
			response.hardware_function = function_hardware;
			if (response.stop_start_func == DIFFERENT_FUNC){
				strcpy(response.text_response, parser_parameter());
			}
			response.accept_parameters = receiving;
			response.defined_num = defined;
}




void _prepare_response (char *sent_string){
	if (strlen(sent_string) > URESP_MAX_LEN){ 
		memset(user_response, 0, URESP_MAX_LEN);
		return 0x0;
	}
	memset(user_response, 0, URESP_MAX_LEN);
	strncpy(user_response, sent_string, URESP_MAX_LEN);
}

char * get_user_response(void){
	static char check_invalid_string [URESP_MAX_LEN] = " ";
	if ((str_compare(check_invalid_string, user_response)) && (valid_sintax == false) )
		return "Incorrect syntax\n\r";
	else{
		valid_sintax = false;
		strncpy(check_invalid_string, user_response, URESP_MAX_LEN);

		return user_response;
	}
}

void _write_response(char *answer){
	char internal_response [URESP_MAX_LEN];
	memset(internal_response, 0, URESP_MAX_LEN);
	strncpy(internal_response, parser_response(), URESP_MAX_LEN);
	strncat(internal_response, answer, URESP_MAX_LEN);
	strncat(internal_response, "\n\r", URESP_MAX_LEN);
	_prepare_response(internal_response);
}



void _analysis_error_type(uint8_t error_type){
	switch (error_type){
		case INCORRECT_PARAMETER_INPUT:
			_prepare_response("Your error: Invalid parameter\n\r");
		break;

		case UNEXISTING_CHARGER:
			_prepare_response("Your error: Non-existent charger\n\r");
		break;

		case INCORRECT_PULSE_WIDTH:
			_prepare_response("Your error: Incorrect pulse width\n\r");
		break;

		case LESS_POSSIBLE:
			_prepare_response("Your error: The entered value is less than acceptable\n\r");
		break;

		case MORE_POSSIBLE:
			_prepare_response("Your error: The entered value is more than acceptable\n\r");
		break;

		case UNNECESSARY_PARAMETERS:
			_prepare_response("Your error: Unnecessary entered parameters\n\r");
		break;

		case UNKNOWN_TYPE:
			_prepare_response("Your error: UNKNOWN_TYPE\n\r");
		break;

		default:
			_prepare_response("Unknown error!\n\r");
		break;
	}
}

void _analysis_hardware_status(CHARGER_STATUS hardware_status, char *response){
	switch (hardware_status){
		case STATUS_OK:
			_write_response(clear_data(response));
		break;
		case STATUS_ERROR_INIT:
			_prepare_response("STATUS_ERROR_INIT\n\r");
		break;
		case STATUS_AKK_ALREADY_USED:
			_prepare_response("STATUS_AKK_ALREADY_USED\n\r");
		break;
		case STATUS_MULTIPLE_START:
			_prepare_response("STATUS_MULTIPLE_START\n\r");
		break;
		case STATUS_NEED_TURN_OFF:
			_prepare_response("STATUS_NEED_TURN_OFF\n\r");
		break;
		default:
			_prepare_response("ERROR_\n\r");
		break;
	}
}


void _do_action (response_t sending_string)
{
	valid_sintax = true;

	if (check_parameter(sending_string.type, sending_string.text_response) == SUCCESSFUL)
	{	
		if (sending_string.set_get_func == GET)
		{	
			_write_response(string_num);
		}

		if (sending_string.stop_start_func == START_FUNC){
			_analysis_hardware_status((CHARGER_STATUS)sending_string.hardware_function(), " ");
			return;
		}
		else if(sending_string.stop_start_func == STOP_FUNC){
			sending_string.hardware_function();
			_write_response("");
			return;
		}

		if (sending_string.accept_parameters == true && sending_string.defined_num == true)
		{
			sprintf(string_num, " %d", atoi(sending_string.text_response));
			_analysis_hardware_status((CHARGER_STATUS)sending_string.hardware_function(atoi(sending_string.text_response)), sending_string.text_response);
			return ;
		} 
		else if (sending_string.accept_parameters == true && sending_string.defined_num == false)
		{
			_analysis_hardware_status((CHARGER_STATUS)sending_string.hardware_function(transform_parameter(clear_data(sending_string.text_response))), sending_string.text_response);
			return ;
		} 
		else _prepare_response("_ERROR");
		

	} else{
		_analysis_error_type(check_parameter(sending_string.type, sending_string.text_response));
	}
}

void set_charger_start(void){
	constructor(SET, OTHERS, START_FUNC, charger_start, false, false);
	_do_action(response);
}

void set_charger_stop(void){
	constructor(SET, OTHERS, STOP_FUNC, charger_stop, false, false);
	_do_action(response);
}

void set_charger_mode(void) {
	constructor(SET, MODE_CHARGER_PARAMETER, DIFFERENT_FUNC, charger_set_mode, true, false);
	_do_action(response);
}

void set_charger_akk(void) {
	constructor(SET, AKK_CHARGER_PARAMETER, DIFFERENT_FUNC, charger_set_akk, true, false);
	_do_action(response);
}

void set_charger_pulse_width(void){//////////FIX NAMED IN MARKDOWN
	constructor(SET, PULSE_WIDTH_PARAMETER, DIFFERENT_FUNC, charger_set_pulse_widght, true, true);
	_do_action(response);
}


void set_charging_period(void){
	constructor(SET, PERIOD_PARAMETER, DIFFERENT_FUNC, charging_set_period, true, true);
	_do_action(response);
}

void set_charging_mode(void){
	constructor(SET, MODE_CHARGING_PARAMETER, DIFFERENT_FUNC, charging_set_mode, true, false);
	_do_action(response);
}

void set_charging_akk(void){
	constructor(SET, AKK_CHARGING_PARAMETER, DIFFERENT_FUNC, charging_set_akk, true, false);
	_do_action(response);
}

void set_charging_start(void){
	constructor(SET, OTHERS, START_FUNC, charging_start_akk, false, false);
	_do_action(response);
}

void set_charging_stop(void){
	constructor(SET, OTHERS, STOP_FUNC, charging_stop_akk, false, false);
	_do_action(response);
}

#ifdef DEBUG_COMAND
void set_charging_t_positive_pulse(void){
	valid_sintax = true;
	if (check_parameter(T_POSITIVE_PULSE_PARAMETER, parser_parameter()) == SUCCESSFUL){
		charging_set_timing_positive_pulse(atoi(parser_parameter()));
		_write_response(clear_data(parser_parameter()));
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}

void set_charging_t_negative_pulse(void){
	valid_sintax = true;
	if (check_parameter(T_NEGATIVE_PULSE_PARAMETER, parser_parameter()) == SUCCESSFUL){
		charging_set_timing_negative_pulse(atoi(parser_parameter()));
		_write_response(clear_data(parser_parameter()));
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}

void set_charging_need_disch_pulse(void){
	valid_sintax = true;
	if (SUCCESSFUL == check_parameter(NEED_DISCH_PULSE_PARAMETER, parser_parameter())){
		_write_response(clear_data(parser_parameter()));
		if (str_compare(clear_data(parser_parameter()), "true"))
			charging_set_need_disch_pulse(true);
		else
			charging_set_need_disch_pulse(false);

	}else
		_analysis_error_type(check_parameter(NEED_DISCH_PULSE_PARAMETER, parser_parameter()));
}


void get_charging_t_positive_pulse(void){
	// constructor(GET, OTHERS, PLUG, charging_get_timing_positive_pulse, PLUG, PLUG);
	// //printf("%d\n", charging_get_timing_positive_pulse());
	// sprintf(string_num, " %d", charging_get_timing_positive_pulse());
	// _do_action(response);
	valid_sintax = true;
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		sprintf(string_num, " %d", charging_get_timing_positive_pulse());
		_write_response(string_num);
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));

}
void get_charging_t_negative_pulse(void){
	valid_sintax = true;
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		valid_sintax = true;
		sprintf(string_num, " %d", charging_get_timing_negative_pulse());
		_write_response(string_num);
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_charging_need_disch_pulse(void){
	valid_sintax = true;
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		if (charging_get_need_disch_pulse() == true)
			_write_response(" true");
		else
			_write_response(" false");
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_charging_pulse_power(void){
	//returned float !!
	valid_sintax = true;
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		sprintf(string_num, " %.3f", charging_pulse_power());
		_write_response(string_num);
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));

}
void get_charging_fall_pulse(void){
	valid_sintax = true;
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		sprintf(string_num, " %.3f", charging_fall_pulse());
		_write_response(string_num);
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}

#endif




void get_voltage_generator(void){
	// if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
	// 	switch(charging_get_akk()){

	// 	}

	// }else
	// 	_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_voltage_scheme(void){
// 	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
// 		sprintf(string_num, " %d", charging_get_timing_negative_pulse());
// 		_write_response(string_num);
// 	}else
// 		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_voltage_output(void){
	// if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
	// 	//sent_string = get_hardware_func();
	// 	//_write_response((char *)sent_string);
	// 	_write_response("3");//будет записано значение, полученное из функции. Нужно привести из double к string
	// }
	// else
	// 	analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_voltage_first_battery(void){
	// if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){	
	// 	//sent_string = get_hardware_func();
	// 	//_write_response((char *)sent_string);
	// 	_write_response("4");//будет записано значение, полученное из функции. Нужно привести из double к string
	// }else
	// 	analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_voltage_second_battery(void){
	// if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){	
	// 	//sent_string = get_hardware_func();
	// 	//_write_response((char *)sent_string);
	// 	_write_response("5");//будет записано значение, полученное из функции. Нужно привести из double к string
	// }else
	// 	analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}

void get_charging_akk(void){
	valid_sintax = true;
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		if (charging_get_akk() == 1 )
			_write_response(" AKK1");
		else if (charging_get_akk() == 2)
			_write_response(" AKK2");
		else 
			_write_response(" NONE");
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_charging_akk_mode(void){
	valid_sintax = true;
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		if (charging_get_akk_mode() == 0)
			_write_response(" default");
		else if (charging_get_akk_mode() == 1)
			_write_response(" one_akk");
		else if (charging_get_akk_mode() == 2)
			_write_response(" disch_akk");
		else 
			_write_response(" error");
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}

void get_charging_period(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		valid_sintax = true;
		sprintf(string_num, " %d", charging_get_period());
		_write_response(string_num);
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}


void get_charger_mode(void){
	valid_sintax = true;
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		if (charger_get_mode() == 0)
			_write_response(" AKK");
		else if (charger_get_mode() == 1)
			_write_response(" GEN");
		else 
			_write_response(" error");
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_charger_output_akk(void){
	valid_sintax = true;
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		if (charger_get_output_akk() == 0)
			_write_response(" AKK1");
		else if (charger_get_output_akk() == 1)
			_write_response(" AKK2");
		else 
			_write_response(" error");
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_charger_output_pw(void){
	valid_sintax = true;
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		sprintf(string_num, " %d", charger_get_output_pw());
		_write_response(string_num);
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}


char *crop_trash(char *raw_string){
	if (strlen(raw_string) > URESP_MAX_LEN)
		return NULL;
	static char clear_string [URESP_MAX_LEN] = " ";
	memset(clear_string, 0, URESP_MAX_LEN );
	uint16_t counter = 0;
	while (!(raw_string[counter] == '\n' || raw_string[counter] == '\r')){
		clear_string[counter] = raw_string [counter];
		counter++;
		if (strlen(raw_string) == counter)
			break;
	}
	clear_string[counter+1] = '\n';
	return clear_string;
}

int transform_parameter(char * text){
	if (str_compare(text, "akk"))
		return CHARGER_MODE_AKK;
	if (str_compare(text, "gen"))
		return CHARGER_MODE_GEN;
	if (str_compare(text, "akk1"))
		return CHARGER_OUTPUT_AKK_1;
	if (str_compare(text, "akk2"))
		return CHARGER_OUTPUT_AKK_2;
	if (str_compare(text, "default"))
		return CHARGING_AKK_MODE_DEFAULT;
	if (str_compare(text, "one_akk"))
		return CHARGING_AKK_MODE_ONE_AKK;
	if (str_compare(text, "full_discharge"))
		return CHARGING_AKK_MODE_DISCHARGE;
	else
		return CHARGER_MODE_NONE;
}
