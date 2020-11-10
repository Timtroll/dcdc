#include "user_actions_internal.h"


#define START_FUNC 0
#define STOP_FUNC 1
#define DIFFERENT_FUNC 2
#define SET 0
#define GET 1

#define BOOL_OR_UINT8_T 1
#define UINT16_T 2 
#define FLOAT_ 4

#define MAX_LEN_STRING 15

typedef struct response
{
	uint8_t 
		set_get_func,
		type,
		stop_start_func;
	void *(* hardware_function)();
	char *text_response;
	bool 
		accept_parameters, 
		defined_num;
} response_t;

response_t response; 

#define Constructor_response(function_type,parameter_type, function_mode, function_hardware, receiving, defined) \
		response.set_get_func = function_type; 			\
		response.type = parameter_type; 				\
		response.stop_start_func = function_mode; 		\
		response.hardware_function = function_hardware; \
		response.text_response = parser_parameter();	\
		response.accept_parameters = receiving;			\
		response.defined_num = defined; 				\



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

void _analysis_error_type(uint8_t error_type){
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

void _analysis_hardware_status(CHARGER_STATUS hardware_status, char *response){
	switch (hardware_status){
		case STATUS_OK:
			_write_response(response);
		break;
		case STATUS_ERROR_INIT:
			_prepare_response("STATUS_ERROR_INIT");
		break;
		case STATUS_AKK_ALREADY_USED:
			_prepare_response("STATUS_AKK_ALREADY_USED");
		break;
		case STATUS_MULTIPLE_START:
			_prepare_response("STATUS_MULTIPLE_START");
		break;
		case STATUS_NEED_TURN_OFF:
			_prepare_response("STATUS_MULTIPLE_START");
		break;
		default:
			_prepare_response("ERROR_");
		break;
	}
}


void _do_action (response_t sending_string)
{
	if (check_parameter(sending_string.type, sending_string.text_response) == SUCCESSFUL)
	{	
		// if (sending_string.set_get_func == GET)
		// {	

		// }

		if (sending_string.stop_start_func == START_FUNC){
			_analysis_hardware_status((CHARGER_STATUS)sending_string.hardware_function(), "");
			return ;
		}
		else if(sending_string.stop_start_func == STOP_FUNC){
			sending_string.hardware_function();
			_write_response("");
			return ;
		}

		if (sending_string.accept_parameters == true && sending_string.defined_num == true)
		{
			uint16_t value = atoi(sending_string.text_response);
			_analysis_hardware_status((CHARGER_STATUS)sending_string.hardware_function(value), sending_string.text_response);
			return ;
		} 
		else if (sending_string.accept_parameters == true && sending_string.defined_num == false)
		{
			if (Str_comparate(sending_string.text_response, " akk"))
				_analysis_hardware_status((CHARGER_STATUS)sending_string.hardware_function(CHARGER_MODE_AKK),sending_string.text_response);
			else if (Str_comparate(sending_string.text_response, " gen"))
				_analysis_hardware_status((CHARGER_STATUS)sending_string.hardware_function(CHARGER_MODE_GEN),sending_string.text_response);
			else if (Str_comparate(sending_string.text_response, " akk1"))
				_analysis_hardware_status((CHARGER_STATUS)sending_string.hardware_function(CHARGER_OUTPUT_AKK_1),sending_string.text_response);
			else if (Str_comparate(sending_string.text_response, " akk2"))
				_analysis_hardware_status((CHARGER_STATUS)sending_string.hardware_function(CHARGER_OUTPUT_AKK_2),sending_string.text_response);
			else if (Str_comparate(sending_string.text_response, " default"))
				_analysis_hardware_status((CHARGER_STATUS)sending_string.hardware_function(CHARGING_AKK_MODE_DEFAULT),sending_string.text_response);
			else if (Str_comparate(sending_string.text_response, " one_akk"))
				_analysis_hardware_status((CHARGER_STATUS)sending_string.hardware_function(CHARGING_AKK_MODE_ONE_AKK),sending_string.text_response);
			else if (Str_comparate(sending_string.text_response, " full_discharge"))
				_analysis_hardware_status((CHARGER_STATUS)sending_string.hardware_function(CHARGING_AKK_MODE_DISCHARGE),sending_string.text_response);
			return ;
		} 
		else _prepare_response("_ERROR");
		

	} else
		_analysis_error_type(check_parameter(sending_string.type, sending_string.text_response));
}

void set_charger_start(void){
	Constructor_response(SET, OTHERS, START_FUNC, charger_start, false, false);
	_do_action(response);
	memset(&response, 0, sizeof(response));
}

void set_charger_stop(void){
	Constructor_response(SET, OTHERS, STOP_FUNC, charger_stop, false, false);
	_do_action(response);

	memset(&response, 0, sizeof(response));}

void set_charger_mode(void) {
	Constructor_response(SET, MODE_CHARGER_PARAMETER, DIFFERENT_FUNC, charger_set_mode, true, false); 				
	_do_action(response);

	memset(&response, 0, sizeof(response));
}

void set_charger_akk(void) {
	Constructor_response(SET, AKK_CHARGER_PARAMETER, DIFFERENT_FUNC, charger_set_akk, true, false); 				
	_do_action(response);

	memset(&response, 0, sizeof(response));}

void set_charger_pulse_width(void){
	Constructor_response(SET, PULSE_WIDTH_PARAMETER, DIFFERENT_FUNC, charger_set_pulse_widght, true, true); 				
	_do_action(response);

	memset(&response, 0, sizeof(response));
}





void set_charging_period(void){

	Constructor_response(SET, PERIOD_PARAMETER, DIFFERENT_FUNC, charging_set_period, true, true); 				
	_do_action(response);

	memset(&response, 0, sizeof(response));


}

void set_charging_mode(void){
	Constructor_response(SET, MODE_CHARGING_PARAMETER, DIFFERENT_FUNC, charging_set_mode, true, true); 				
	_do_action(response);
	memset(&response, 0, sizeof(response));
}

void set_charging_akk(void){
	Constructor_response(SET, AKK_CHARGING_PARAMETER, DIFFERENT_FUNC, charging_set_mode, true, true); 				
	_do_action(response);
	memset(&response, 0, sizeof(response));
	//_do_action(AKK_CHARGING_PARAMETER, analysis_error_type, parser_parameter());
}

void set_charging_start(void){
	Constructor_response(SET, OTHERS, START_FUNC, charging_start_akk, false, false);
	_do_action(response);
	memset(&response, 0, sizeof(response));
}

void set_charging_stop(void){
	//!!!!!!!!!!! нет железной ф-ии
	//_do_action(OTHERS, analysis_error_type, "");
}

#ifdef DEBUG_COMAND
void set_charging_t_positive_pulse(void){
	if (check_parameter(T_POSITIVE_PULSE_PARAMETER, parser_parameter()) == SUCCESSFUL){
		charging_set_timing_positive_pulse(atoi(parser_parameter()));
		_write_response(parser_parameter());
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}

void set_charging_t_negative_pulse(void){
	if (check_parameter(T_NEGATIVE_PULSE_PARAMETER, parser_parameter()) == SUCCESSFUL){
		charging_set_timing_positive_pulse(atoi(parser_parameter()));
		_write_response(parser_parameter());
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}

void set_charging_need_disch_pulse(void){
	if (check_parameter(NEED_DISCH_PULSE_PARAMETER, parser_parameter()) == SUCCESSFUL){
		if (Str_comparate(parser_parameter(), " true"))
		{
			charging_set_need_disch_pulse(true);
			_write_response(parser_parameter());
		}
		else if (Str_comparate(parser_parameter(), " false")){
			charging_set_need_disch_pulse(false);
			_write_response(parser_parameter());
		} 
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));


}

char string_num [MAX_LEN_STRING] = " ";
void get_charging_t_positive_pulse(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		sprintf(string_num, " %d", charging_get_timing_positive_pulse());
		_write_response(string_num);
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_charging_t_negative_pulse(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		sprintf(string_num, " %d", charging_get_timing_negative_pulse());
		_write_response(string_num);
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_charging_need_disch_pulse(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		if (charging_get_need_disch_pulse() == true)
		{
			_write_response(" true");
		} else _write_response(" false");
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_charging_pulse_power(void){
	//returned float !!
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		sprintf(string_num, " %.3f", charging_pulse_power());
		_write_response(string_num);
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));

}
void get_charging_fall_pulse(void){

	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){
		sprintf(string_num, " %.3f", charging_fall_pulse());
		_write_response(string_num);
	}else
		_analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}

#endif




void get_voltage_generator(void){
	//Constructor_response(GET, OTHERS, DIFFERENT_FUNC, , true, false);
	//_do_action(response);
	//memset(&response, 0, sizeof(response));
	_write_response("");
}
void get_voltage_scheme(void){
	// if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL){	
	// 	//sent_string = get_hardware_func();
	// 	//_write_response((char *)sent_string);
	// 	_write_response("2");//будет записано значение, полученное из функции. Нужно привести из double к string
	// }
	// else
	// 	analysis_error_type(check_parameter(OTHERS, parser_parameter()));
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

