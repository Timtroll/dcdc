#include "user_actions_internal.h"

char * _clear_data(char * parameter){
	static char cleared_string [MAX_LEN] = " ";	
	uint16_t counter = 0;
	uint16_t internal_counter = 0;

	while(counter < strlen(parameter))
	{
		if ((parameter[counter] == ' ') && (cleared_string[0] != " " )){
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
		}else if (cleared_string[0] != " ")
			return NULL;	
	}
	return cleared_string;
}

uint8_t check_parameter(uint8_t type_parameter, char * parameter){

	char * compute_parameter = _clear_data(parameter);
	if (compute_parameter == NULL || compute_parameter[0] == ' '){
		return INCORRECT_PARAMETER_INPUT;
	}

	switch (type_parameter){
		case MODE_PARAMETER:
			return 7;
		break;

		case PULSE_WIDGHT_PARAMETER:
			return 8;
		break;

		case TIME_PARAMETER:
			return 9;
		break;

		default:
			return UNKNOWN_TYPE; 
	}	
	
}
