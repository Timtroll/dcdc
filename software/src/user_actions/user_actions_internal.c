#include "user_actions_internal.h"

#define PHRASE_START 0
#define WORD_START 1
#define WORD_END 2
#define PHRASE_END 3

#define Str_comparate(parameter, const_string) ((strncmp(parameter, const_string, strlen(const_string)) == 0) && (strlen(parameter) == strlen(const_string)))  

static inline uint8_t extra_letters(char *string, uint8_t cntr){
	if (strlen(string) > MAX_LEN)
		return  INCORRECT_PARAMETER_INPUT;
	for (; cntr < strlen(string); cntr++)
	{
		if (string[cntr] >= 'a' && string[cntr] <= 'z' ) 
			return INCORRECT_PARAMETER_INPUT; 
	}
	return SUCCESSFUL;
}	

char *_clear_data(char *parameter){
	if (strlen(parameter) > MAX_LEN)
		return NULL;

	static char cleared_string [MAX_LEN] = " ";
	char cmp_string [MAX_LEN];
	uint16_t 
			counter = 0,
		 	internal_counter = 0;
	uint8_t 
			whole_word = PHRASE_START,
			return_value = 0;

	if (strncmp(cleared_string, " ", MAX_LEN) != 0) 
		memset(cleared_string, 0, MAX_LEN);
	
	for (; counter < MAX_LEN; counter++)
		if (cleared_string[counter] != ' ') internal_counter++;

	strncpy(cmp_string, cleared_string, internal_counter);
	counter = 0;
	internal_counter = 0;

	while(counter < strlen(parameter))
	{
		if (((parameter[counter] == ' ') || (parameter[counter] == '\t'))  && (cleared_string != " " )){
			if (whole_word == PHRASE_START) 
				whole_word = WORD_START;
			else if (whole_word == WORD_END)
				whole_word = PHRASE_END;
			counter++;
			continue;
		}
		else if ((counter != 0) &&
		 		(('0' <= parameter[counter] && '9' >= parameter[counter]) || 
		 		('a' <= parameter[counter] && 'z' >= parameter[counter])))
		{
			if (whole_word == WORD_START) whole_word = WORD_END;
			else if (whole_word == PHRASE_END) 
				return NULL;
			cleared_string[internal_counter] = parameter [counter];
			counter++;
			internal_counter++;
			continue;
		}
		else return NULL;
	}
	if (strncmp(cleared_string, cmp_string, MAX_LEN) ==  0){
		return NULL;
	}
	return cleared_string;
}

uint8_t check_parameter(uint8_t type_parameter, char *parameter){
	if (type_parameter == OTHERS)
		return SUCCESSFUL;

	char *compute_parameter = _clear_data(parameter);
	uint8_t symbol_ctnr = 0;
	if (compute_parameter == NULL) 
		return INCORRECT_PARAMETER_INPUT;
	
	char compared_strings [MAX_LEN] = " ";
	memset(compared_strings, 0, MAX_LEN);
	strncpy(compared_strings, compute_parameter, strlen(compute_parameter));

	switch (type_parameter){
		case MODE_CHARGER_PARAMETER:
			if (Str_comparate(compared_strings, "akk") || 
			 	Str_comparate(compared_strings, "gen")){
				return SUCCESSFUL;
				}
			else return UNEXISTING_CHARGER;	
		break;

		case AKK_CHARGER_PARAMETER:
			return 0;
		break;

		case PULSE_WIDTH_PARAMETER:
			if (SUCCESSFUL != extra_letters(compared_strings, symbol_ctnr))
				return INCORRECT_PARAMETER_INPUT;

			if (atoi(compared_strings) >= LOWER_WIDTH && atoi(compared_strings) <= TOP_WIDTH)
				return SUCCESSFUL;
			return INCORRECT_PULSE_WIDTH;
		break;

		case PERIOD_PARAMETER:
			if (SUCCESSFUL != extra_letters(compared_strings, symbol_ctnr))
				return INCORRECT_PARAMETER_INPUT;

			if (atoi(compared_strings) < LOWER_LIMIT_TIME)
				return LESS_POSSIBLE;
			else if (atoi(compared_strings) > UPPER_LIMIT_TIME)
				return MORE_POSSIBLE;
			else return SUCCESSFUL;
			return INCORRECT_PARAMETER_INPUT;
		break;

		case MODE_CHARGING_PARAMETER:
			if ( Str_comparate(compared_strings, "default") || 
			 	 Str_comparate(compared_strings, "one_akk") ||
			 	 Str_comparate(compared_strings, "full_discharge")){
				return SUCCESSFUL;
				}
			else return INCORRECT_PARAMETER_INPUT;	
		break;

		case AKK_CHARGING_PARAMETER:
			if ( Str_comparate(compared_strings, "akk1") || 
			 	 Str_comparate(compared_strings, "akk2") ){
				return SUCCESSFUL;
				}
			else return INCORRECT_PARAMETER_INPUT;	
		break;

		case OTHERS:
			return UNNECESSARY_PARAMETERS;
		break;


		#ifdef DEBUG_COMAND
			
		
		case T_POSITIVE_PULSE_PARAMETER:
			if (atoi(compared_strings) >= 10 && atoi(compared_strings) <= 32000)
				return SUCCESSFUL;
			return INCORRECT_PARAMETER_INPUT;
		break;

		case T_NEGATIVE_PULSE_PARAMETER:
			if (atoi(compared_strings) >= 10 && atoi(compared_strings) <= 32000)
				return SUCCESSFUL;
			return INCORRECT_PARAMETER_INPUT;
		break;

		case NEED_DISCH_PULSE_PARAMETER:
			if ( Str_comparate(compared_strings, "true") || 
			 	 Str_comparate(compared_strings, "false")){
				return SUCCESSFUL;
				}
			else return INCORRECT_PARAMETER_INPUT;	
		break;

		#endif


		default:
			return UNKNOWN_TYPE; 
	}	
	
}

