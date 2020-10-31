#ifndef _USER_ACTIONS_H_
#define _USER_ACTIONS_H_

#include <stdio.h>
#include <stdint.h>
#include "../parser/d_base.h"
#include "parser.h"
#include "user_comand.h"

#define URESP_MAX_LEN 100



/* !!May be realization user comand function may be moved in user_action.c
and the funcs bellow droped

void set_for_charger_start(void);
void set_for_charger_stop(void);
void set_for_charger_mode(void);
void set_for_charger_pulse_width(uint8_t pulse_width);

void set_for_charging_time(uint16_t time);
void set_for_charging_start_akk_1(void);
void set_for_charging_start_akk_2(void);
void set_for_charging_stop(void);

double get_for_voltage_scheme_generator(void);
double get_for_voltage_output(void);
double get_for_voltage_first_battery(void);
double get_for_voltage_second_battery(void);
*/

char * get_user_response(void);

#endif//_USER_ACTIONS_H_

