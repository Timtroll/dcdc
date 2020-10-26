#include "user_actions_internal.h"

#define PHRASE_START 0
#define WORD_START 1
#define WORD_END 2
#define PHRASE_END 3

#define Extra_letters(string, cntr) \
	for ( ; cntr < strlen(string); cntr++) \
	{ \
		if (string[cntr] >= 'a' && string[cntr] <= 'z' ) \
			return INCORRECT_PARAMETER_INPUT; \
	} \
	cntr = 0; \

char * _clear_data(char * parameter){
	if (strlen(parameter) > MAX_LEN)
			return NULL;

	static char cleared_string [MAX_LEN] = " ";	
	uint16_t counter = 0;
	uint16_t internal_counter = 0;
	uint8_t whole_word = PHRASE_START;

	if (strcmp(cleared_string, " ") != 0)
		memset(cleared_string, 0, MAX_LEN);
	char cmp_string [MAX_LEN];
	strcpy(cmp_string, cleared_string);
	
	while(counter < strlen(parameter))
	{
		if (((parameter[counter] == ' ') || (parameter[counter] == '\t'))  && (cleared_string != " " )){
			if (whole_word == PHRASE_START) whole_word = WORD_START;
			else if (whole_word == WORD_END) whole_word = PHRASE_END;
			counter++;
			continue;
		}
		else if ((counter != 0) &&
		 		(('0' <= parameter[counter] && '9' >= parameter[counter]) || 
		 		('a' <= parameter[counter] && 'z' >= parameter[counter])))
		{
			if (whole_word == WORD_START) whole_word = WORD_END;
			else if (whole_word == PHRASE_END) return NULL;

			cleared_string[internal_counter] = parameter [counter];
			counter++;
			internal_counter++;
			continue;
		}else if (cleared_string[0] !=  ' ' )
			return NULL;	
	}
	if (strcmp(cleared_string, cmp_string) ==  0)
		return NULL;
	return cleared_string;
}

uint8_t check_parameter(uint8_t type_parameter, char * parameter){
	char * compute_parameter = _clear_data(parameter);
	uint8_t symbol_ctnr = 0;
	if (compute_parameter == NULL)
		return INCORRECT_PARAMETER_INPUT;

	switch (type_parameter){
		case MODE_PARAMETER:
			if (strcmp(compute_parameter, "akk1") == 0 || 
				strcmp(compute_parameter, "akk2") == 0 ||
			 	strcmp(compute_parameter, "gen") == 0)
			{
				return SUCCESSFUL;
			} else return UNEXISTING_CHARGER;	
		break;

		case PULSE_WIDTH_PARAMETER:
			Extra_letters(compute_parameter, symbol_ctnr);
			if (atoi(compute_parameter) >= LOWER_WIDTH && atoi(compute_parameter) <= TOP_WIDTH)
				return SUCCESSFUL;
			
			return INCORRECT_PULSE_WIDTH;
		break;

		case TIME_PARAMETER:
			Extra_letters(compute_parameter, symbol_ctnr);

			if (atoi(compute_parameter) >= LOWER_LIMIT_TIME && atoi(compute_parameter) <= UPPER_LIMIT_TIME)
				return SUCCESSFUL;
			else if (atoi(compute_parameter) < LOWER_LIMIT_TIME)
				return LESS_POSSIBLE;
			else if (atoi(compute_parameter) > UPPER_LIMIT_TIME)
				return MORE_POSSIBLE;
	
			return INCORRECT_PARAMETER_INPUT;
		break;

		default:
			return UNKNOWN_TYPE; 
	}	
	
}
