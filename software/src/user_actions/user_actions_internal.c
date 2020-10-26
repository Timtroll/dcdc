#include "user_actions_internal.h"

char * _clear_data(char * parameter){
	static char cleared_string [MAX_LEN] = " ";	
	uint16_t counter = 0;
	uint16_t internal_counter = 0;

	if (strcmp(cleared_string, " ") != 0)
		memset(cleared_string, 0, MAX_LEN);
	char cmp_string [MAX_LEN];
	strcpy(cmp_string, cleared_string);

	while(counter < strlen(parameter))
	{
		if (((parameter[counter] == ' ') || (parameter[counter] == '\t'))  && (cleared_string[0] != " " )){
			counter++;
			continue;
		}
		else if ((counter != 0) &&
		 	(('0' <= parameter[counter] && '9' >= parameter[counter]) || 
		 	('a' <= parameter[counter] && 'z' >= parameter[counter])))
		{
			cleared_string[internal_counter] = parameter [counter];
			counter++;
			internal_counter++;
			continue;
		}else if (cleared_string[0] !=  ' ' || strcmp(cleared_string, 0) == 0 )
			return NULL;	
	}
	if (strcmp(cleared_string, cmp_string) ==  0)
		return NULL;
	return cleared_string;
}

uint8_t check_parameter(uint8_t type_parameter, char * parameter){

	char * compute_parameter = _clear_data(parameter);
	printf("|%s|\n", compute_parameter);
	if (compute_parameter == NULL){
		return INCORRECT_PARAMETER_INPUT;
	}

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
			return 8;
		break;

		case TIME_PARAMETER:
			return 9;
		break;

		default:
			return UNKNOWN_TYPE; 
	}	
	
}
