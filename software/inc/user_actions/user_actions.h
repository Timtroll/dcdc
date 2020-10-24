#ifndef _USER_ACTIONS_H_
#define _USER_ACTIONS_H_

#include <stdio.h>
#include <stdint.h>
#include "../parser/d_base.h"

void set_for_charger_start(void);
void set_for_charger_stop(void);
void set_for_charger_mode(uint8_t mode);
void set_for_charger_pulse_width(uint8_t);

void set_for_charging_time(uint16_t time);
void set_for_charging_start_akk_1(void);
void set_for_charging_start_akk_2(void);
void set_for_charging_stop(void);

double get_for_voltage_scheme_generator(void);
double get_for_voltage_output(void);
double get_for_voltage_first_battery(void);
double get_for_voltage_second_battery(void);

#endif//_USER_ACTIONS_H_

