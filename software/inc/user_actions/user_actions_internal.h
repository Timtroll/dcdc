#ifndef _USER_ACTIONS_INTERNAL_H_
#define _USER_ACTIONS_INTERNAL_H_

#include "user_actions.h"
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 50
#define UPPER_LIMIT_TIME 32000
#define LOWER_LIMIT_TIME 100
#define LOWER_WIDTH 2
#define TOP_WIDTH 49


enum settable_parameter{
	MODE_PARAMETER,
	PULSE_WIDTH_PARAMETER,
	TIME_PARAMETER,
	OTHERS
};

enum error_type
{
	SUCCESSFUL = 1,
	INCORRECT_PARAMETER_INPUT,
	UNEXISTING_CHARGER,
	INCORRECT_PULSE_WIDTH,
	LESS_POSSIBLE,
	MORE_POSSIBLE,
	UNNECESSARY_PARAMETERS,
	UNKNOWN_TYPE
};

uint8_t check_parameter(uint8_t type_parameter, char * parameter);



#endif//_USER_ACTIONS_INTERNAL_H_

