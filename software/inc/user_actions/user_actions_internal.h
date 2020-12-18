#ifndef _USER_ACTIONS_INTERNAL_H_
#define _USER_ACTIONS_INTERNAL_H_

#include "user_actions.h"
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 50
#define UPPER_LIMIT_TIME 32000
#define LOWER_LIMIT_TIME 500
#define LOWER_WIDTH 2
#define TOP_WIDTH 99
#define MODE_CHARGER_LENGTH 3


typedef enum error_type
{
	SUCCESSFUL = 1,
	INCORRECT_PARAMETER_INPUT,
	UNEXISTING_CHARGER,
	INCORRECT_PULSE_WIDTH,
	LESS_POSSIBLE,
	MORE_POSSIBLE,
	UNNECESSARY_PARAMETERS,
	UNKNOWN_TYPE
} status;

typedef enum settable_parameter{
	MODE_CHARGER_PARAMETER,
	AKK_CHARGER_PARAMETER,
	PULSE_WIDTH_PARAMETER,
	PERIOD_PARAMETER,
	MODE_CHARGING_PARAMETER,
	AKK_CHARGING_PARAMETER,
	T_POSITIVE_PULSE_PARAMETER,
	T_NEGATIVE_PULSE_PARAMETER,
	NEED_DISCH_PULSE_PARAMETER,
	OTHERS
} settable;

status check_parameter(uint8_t type_parameter, char * parameter);
char *clear_data(char *parameter);

static inline bool str_compare (char *parameter, char *const_string){
	if ((strncmp(parameter, const_string, strlen(const_string)) == 0 ) && strlen(const_string) == strlen(parameter))
		return true;
	else {
		return false;
	}
}


#endif//_USER_ACTIONS_INTERNAL_H_

