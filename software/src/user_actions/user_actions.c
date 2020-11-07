#include "user_actions_internal.h"

char user_response [URESP_MAX_LEN];

void _prepare_response (char *sent_string){
	if (strlen(sent_string) > URESP_MAX_LEN){ 
		memset(user_response, 0, URESP_MAX_LEN);
		return 0x0;
	}
	memset(user_response, ' ', URESP_MAX_LEN);
	strncpy(user_response, sent_string, URESP_MAX_LEN);	
}

char * get_user_response(void){
	return user_response;
}

void _write_response(char *answer){
	char internal_response [URESP_MAX_LEN];
	memset(internal_response, ' ', URESP_MAX_LEN);
	strncpy(internal_response, parser_response(), URESP_MAX_LEN);
	strncat(internal_response, answer, URESP_MAX_LEN); 
	_prepare_response(internal_response);
}

void analysis_error_type(uint8_t error_type){
	switch (error_type){
		case INCORRECT_PARAMETER_INPUT:
			_prepare_response("Your error: Invalid parameter");
		break;

		case UNEXISTING_CHARGER:
			_prepare_response("Your error: Non-existent charger");
		break;

		case INCORRECT_PULSE_WIDTH:
			_prepare_response("Your error: Incorrect pulse width");
		break;

		case LESS_POSSIBLE:
			_prepare_response("Your error: The entered value is less than acceptable");
		break;

		case MORE_POSSIBLE:
			_prepare_response("Your error: The entered value is more than acceptable");
		break;

		case UNNECESSARY_PARAMETERS:
			_prepare_response("Your error: Unnecessary entered parameters");
		break;

		case UNKNOWN_TYPE:
			_prepare_response("Your error: UNKNOWN_TYPE");
		break;

		default:
			_prepare_response("Unknown error!");
		break;
	}
}


inline static void _do_action (
							uint8_t type,
							void  *(* hardware_function),
							char *text_response
							)
{
	if (check_parameter(type, parser_parameter()) == SUCCESSFUL)
	{	
		//hardware_func();
		_write_response(text_response);
	} else
		analysis_error_type(check_parameter(type, parser_parameter()));
}
void set_charger_start(void){
	_do_action(OTHERS, analysis_error_type, "");
}

void set_charger_stop(void){
	_do_action(OTHERS, analysis_error_type, "");
}

void set_charger_mode(void) {
	_do_action(MODE_CHARGER_PARAMETER, analysis_error_type, parser_parameter());
}

void set_charger_akk(void) {
	_do_action(AKK_CHARGER_PARAMETER, analysis_error_type, parser_parameter());
}

void set_charger_pulse_width(void){
	_do_action(PULSE_WIDTH_PARAMETER, analysis_error_type, parser_parameter());
}





void set_charging_period(void){
	_do_action(PERIOD_PARAMETER, analysis_error_type, parser_parameter());
}

void set_charging_mode(void){
	_do_action(MODE_CHARGING_PARAMETER, analysis_error_type, parser_parameter());
}

void set_charging_akk(void){
	_do_action(AKK_CHARGING_PARAMETER, analysis_error_type, parser_parameter());
}

void set_charging_start(void){
	_do_action(OTHERS, analysis_error_type, "");
}

void set_charging_stop(void){
	_do_action(OTHERS, analysis_error_type, "");
}

#ifdef DEBUG_COMAND
void set_charging_t_positive_pulse(void){
	_do_action(T_POSITIVE_PULSE_PARAMETER, analysis_error_type, parser_parameter());
}
void set_charging_t_negative_pulse(void){
	_do_action(T_NEGATIVE_PULSE_PARAMETER, analysis_error_type, parser_parameter());
}
void set_charging_need_disch_pulse(void){
	_do_action(NEED_DISCH_PULSE_PARAMETER, analysis_error_type, parser_parameter());
}
#endif




void get_voltage_generator(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		//sent_string = get_hardware_func();
		//_write_response((char *)sent_string);
		_write_response("1");//будет записано значение, полученное из функции. Нужно привести из double к string
	}
	else
		analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_voltage_scheme(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){	
		//sent_string = get_hardware_func();
		//_write_response((char *)sent_string);
		_write_response("2");//будет записано значение, полученное из функции. Нужно привести из double к string
	}
	else
		analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_voltage_output(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		//sent_string = get_hardware_func();
		//_write_response((char *)sent_string);
		_write_response("3");//будет записано значение, полученное из функции. Нужно привести из double к string
	}
	else
		analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_voltage_first_battery(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){	
		//sent_string = get_hardware_func();
		//_write_response((char *)sent_string);
		_write_response("4");//будет записано значение, полученное из функции. Нужно привести из double к string
	}else
		analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_voltage_second_battery(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){	
		//sent_string = get_hardware_func();
		//_write_response((char *)sent_string);
		_write_response("5");//будет записано значение, полученное из функции. Нужно привести из double к string
	}else
		analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}

