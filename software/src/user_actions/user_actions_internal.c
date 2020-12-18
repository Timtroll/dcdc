#include "user_actions_internal.h"

#define NO_PHRASE 0
#define PHRASE_START 1
#define PHRASE_LASTS 2
#define WORD_START 3
#define WORD_END 4
#define PHRASE_END 5


bool extra_spaces(char *compute_string){
	uint16_t counter = 0;
	uint8_t phrase_status = NO_PHRASE;

	while (!(counter == strlen(compute_string))){
		if ((compute_string[counter] == ' ') && (phrase_status == NO_PHRASE))
		{
			counter++;
			continue;
		} else if ((compute_string[counter] != ' ') && ((phrase_status == NO_PHRASE) || (phrase_status == PHRASE_LASTS)))
		{
			phrase_status = PHRASE_LASTS;
			counter++;
			continue;		
		} else if ((compute_string[counter] == ' ') && ((phrase_status == PHRASE_LASTS) || (phrase_status == PHRASE_END)))
		{
			phrase_status = PHRASE_END;
			counter++;
			continue;
		} else if ((compute_string[counter] == '\n') && (phrase_status == PHRASE_END))
			return true;
		else {
			return false;
		}
	}
	return true;
}

status extra_letters(char *string){
	if (strlen(string) > MAX_LEN)
		return  INCORRECT_PARAMETER_INPUT;
	for (uint16_t cntr = 0; cntr < strlen(string); cntr++)
	{
		if (string[cntr] >= 'a' && string[cntr] <= 'z' ) 
			return INCORRECT_PARAMETER_INPUT; 
	}
	return SUCCESSFUL;
}	


status check_correctness(settable type, char *clear_parameter){
	switch(type){
			case MODE_CHARGER_PARAMETER:
			if (str_compare(clear_parameter, "akk") || 
			 	str_compare(clear_parameter, "gen")){
				return SUCCESSFUL;
				}
			else return UNEXISTING_CHARGER;	
		break;

		case AKK_CHARGER_PARAMETER:
				if ( str_compare(clear_parameter, "akk1") || 
			 	 	 str_compare(clear_parameter, "akk2") ){
				return SUCCESSFUL;
				}
			else return INCORRECT_PARAMETER_INPUT;	
		break;

		case PULSE_WIDTH_PARAMETER:
			if (SUCCESSFUL != extra_letters(clear_parameter))
				return INCORRECT_PARAMETER_INPUT;
			if (atoi(clear_parameter) >= LOWER_WIDTH && atoi(clear_parameter) <= TOP_WIDTH)
				return SUCCESSFUL;
			return INCORRECT_PULSE_WIDTH;
		break;

		case PERIOD_PARAMETER:

			if (SUCCESSFUL != extra_letters(clear_parameter))
				return INCORRECT_PARAMETER_INPUT;

			if (atoi(clear_parameter) < LOWER_LIMIT_TIME)
				return LESS_POSSIBLE;
			else if (atoi(clear_parameter) > UPPER_LIMIT_TIME)
				return MORE_POSSIBLE;
			else return SUCCESSFUL;
			return INCORRECT_PARAMETER_INPUT;
		break;

		case MODE_CHARGING_PARAMETER:
			if ( str_compare(clear_parameter, "default") || 
			 	 str_compare(clear_parameter, "one_akk") ||
			 	 str_compare(clear_parameter, "full_discharge")){
				return SUCCESSFUL;
				}
			else return INCORRECT_PARAMETER_INPUT;	
		break;

		case AKK_CHARGING_PARAMETER:
			if ( str_compare(clear_parameter, "akk1") || 
			 	 str_compare(clear_parameter, "akk2") ){
				return SUCCESSFUL;
				}
			else return INCORRECT_PARAMETER_INPUT;	
		break;

		case OTHERS:
			return UNNECESSARY_PARAMETERS;
		break;


		#ifdef DEBUG_COMAND
			
		
		case T_POSITIVE_PULSE_PARAMETER:
			if (atoi(clear_parameter) >= 10 && atoi(clear_parameter) <= 32000)
				return SUCCESSFUL;
			return INCORRECT_PARAMETER_INPUT;
		break;

		case T_NEGATIVE_PULSE_PARAMETER:
			if (atoi(clear_parameter) >= 10 && atoi(clear_parameter) <= 32000)
				return SUCCESSFUL;
			return INCORRECT_PARAMETER_INPUT;
		break;

		case NEED_DISCH_PULSE_PARAMETER:
			if ( str_compare(clear_parameter, "true") || 
			 	 str_compare(clear_parameter, "false")){
				return SUCCESSFUL;
				}
			else return INCORRECT_PARAMETER_INPUT;	
		break;

		#endif


		default:
			return UNKNOWN_TYPE; 
	}
}



char *clear_data(char *parameter){

	if (strlen(parameter) > MAX_LEN)
		return NULL;

	bool extra_spaces = false;
	static char cleared_string [MAX_LEN] = " ";
	uint16_t 
			counter = 0,
		 	internal_counter = 0;

	if (strncmp(cleared_string, " ", MAX_LEN) != 0) 
		memset(cleared_string, 0, MAX_LEN);

	while(counter < strlen(parameter))
	{
		if (((parameter[counter] == ' ') || (parameter[counter] == '\t'))  && (cleared_string != " " )){
			if (extra_spaces == true)
			{
				return cleared_string;
			}
			counter++;
			continue;
		} else if (
			(('0' <= parameter[counter] && '9' >= parameter[counter]) ||
		 	('a' <= parameter[counter] && 'z' >= parameter[counter])) || (parameter[counter] == '_' || (parameter[counter] == '.' ))
			)
		{
			extra_spaces = true;
			cleared_string[internal_counter] = parameter [counter];
			counter++;
			internal_counter++;
			continue;
		} else if (parameter[counter] == '\0' || parameter[counter] == '\n' || parameter[counter] == ' ' ){
			return cleared_string;
		}else {
			return NULL;
		}
	}
	return cleared_string;
}

status check_parameter(uint8_t type_parameter, char *parameter){
	
	if (type_parameter == OTHERS)
		return SUCCESSFUL;
	if (extra_spaces(parameter) == false)
		return INCORRECT_PARAMETER_INPUT;

	char *compute_parameter = clear_data(parameter);
	if (compute_parameter == NULL) 
		return INCORRECT_PARAMETER_INPUT;

	uint8_t symbol_ctnr = 0;
		
	char clear_parameter [MAX_LEN] = " ";
	memset(clear_parameter, 0, MAX_LEN);
	strncpy(clear_parameter, compute_parameter, strlen(compute_parameter));

	status parameter_classification = check_correctness(type_parameter, compute_parameter);
	return parameter_classification;	
	
}

