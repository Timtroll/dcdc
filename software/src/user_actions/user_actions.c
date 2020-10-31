#include "user_actions_internal.h"

char user_response [URESP_MAX_LEN];

void prepare_response (char *sent_string){
	if (strlen(sent_string) > URESP_MAX_LEN) 
		return 0x0;
	memset(user_response, ' ', URESP_MAX_LEN);
	strncpy(user_response, sent_string, URESP_MAX_LEN);	
}

char * get_user_response(void){
	return user_response;
}

void analysis_error_type(uint8_t error_type){
	//if/else use, becouse switch/case does not allow use inline func
	if (error_type == INCORRECT_PARAMETER_INPUT) 
		prepare_response("Your error: Invalid parameter");
	else if (error_type == UNEXISTING_CHARGER) 
		prepare_response("Your error: Non-existent charger");
	else if (error_type == INCORRECT_PULSE_WIDTH) 
		prepare_response("Your error: Incorrect pulse width");
	else if (error_type == LESS_POSSIBLE) 
		prepare_response("Your error: The entered value is less than acceptable");
	else if (error_type == MORE_POSSIBLE) 
		prepare_response("Your error: The entered value is more than acceptable");
	else if (error_type == UNNECESSARY_PARAMETERS) 
		prepare_response("Your error: Unnecessary entered parameters");
	else if (error_type == UNKNOWN_TYPE) 
		prepare_response("Your error: UNKNOWN_TYPE");
}

void set_charger_mode(void) {
	if (check_parameter(MODE_PARAMETER, parser_parameter()) == SUCCESSFUL)
	{
		//hardware_func();
		//prepare_response(/*text*/);
	} else
		analysis_error_type(check_parameter(MODE_PARAMETER, parser_parameter()));
}

void set_charger_start(void){
	if (check_parameter(MODE_PARAMETER, parser_parameter()) == SUCCESSFUL)
	{
		//hardware_func();
		//prepare_response(/*text*/);
	} else
		analysis_error_type(check_parameter(MODE_PARAMETER, parser_parameter()));
}
void set_charger_stop(void){
	if (check_parameter(MODE_PARAMETER, parser_parameter()) == SUCCESSFUL)
	{
		//hardware_func();
		//prepare_response(/*text*/);
	} else
		analysis_error_type(check_parameter(MODE_PARAMETER, parser_parameter()));
}
void set_charger_pulse_width(void){
	if (check_parameter(PULSE_WIDTH_PARAMETER, parser_parameter()) == SUCCESSFUL)
	{
		//hardware_func();
		//prepare_response(/*text*/);
	} else
		analysis_error_type(check_parameter(PULSE_WIDTH_PARAMETER, parser_parameter()));
}



void set_charging_time(void){
if (check_parameter(TIME_PARAMETER, parser_parameter()) == SUCCESSFUL)
	{
		//hardware_func();
		//prepare_response(/*text*/);
	} else
		analysis_error_type(check_parameter(TIME_PARAMETER, parser_parameter()));
}
void set_charging_start_akk_1(void){
	// set_for_charging_start_akk_1();
}
void set_charging_start_akk_2(void){
	// set_for_charging_start_akk_2();
}
void set_charging_stop(void){
	// set_for_charging_stop();
}






void get_voltage_generator(void){
	// get_for_voltage_scheme_generator();
}
void get_voltage_scheme(void){
	// get_for_voltage_scheme_generator();
}
void get_voltage_output(void){
	// get_for_voltage_output();
}
void get_voltage_first_battery(void){
	// get_for_voltage_first_battery();
}
void get_voltage_second_battery(void){
	// get_for_voltage_second_battery();
}

