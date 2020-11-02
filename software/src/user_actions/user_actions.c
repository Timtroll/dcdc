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

inline static void _write_response(char *answer){
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

// #define RESPONSE(type,hardware_function, text_response) \
// 	if (check_parameter(type, parser_parameter()) == SUCCESSFUL) \
// 	{ \
// 		hardware_function(); \
// 		_write_response(text_response);\
// 	}analysis_error_type(check_parameter(type, parser_parameter())); \

void set_charger_start(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL)
	{	
		//hardware_func();
		_write_response("");
	} else
		analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void set_charger_stop(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL)
	{
		//hardware_func();
		_write_response("");
	} else
		analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}

void set_charger_mode(void) {
	if (check_parameter(MODE_PARAMETER, parser_parameter()) == SUCCESSFUL)
	{
		//hardware_func();
		_write_response(parser_parameter());
	} else
		analysis_error_type(check_parameter(MODE_PARAMETER, parser_parameter()));
}

void set_charger_pulse_width(void){
	if (check_parameter(PULSE_WIDTH_PARAMETER, parser_parameter()) == SUCCESSFUL)
	{
		//hardware_func();
		_write_response(parser_parameter());
	} else
		analysis_error_type(check_parameter(PULSE_WIDTH_PARAMETER, parser_parameter()));
}



void set_charging_time(void){
	if (check_parameter(TIME_PARAMETER, parser_parameter()) == SUCCESSFUL)
	{
		//hardware_func();
		_write_response(parser_parameter());
	} else
		analysis_error_type(check_parameter(TIME_PARAMETER, parser_parameter()));
}
void set_charging_start_akk_1(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL)
	{
		//hardware_func();
		_write_response("");
	} else
		analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void set_charging_start_akk_2(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL)
	{
		//hardware_func();
		_write_response("");
	} else
		analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void set_charging_stop(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL)
	{
		//hardware_func();
		_write_response("");
	} else
		analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}






void get_voltage_generator(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL)
		_write_response("");
	else
		analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_voltage_scheme(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL)	
		_write_response("");
	 else
		analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_voltage_output(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL)
		_write_response("");
	else
		analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_voltage_first_battery(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL)	
		_write_response("");
	else
		analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}
void get_voltage_second_battery(void){
	if (check_parameter(OTHERS, parser_parameter()) == SUCCESSFUL)	
		_write_response("");
	else
		analysis_error_type(check_parameter(OTHERS, parser_parameter()));
}

