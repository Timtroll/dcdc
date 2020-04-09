#ifndef _SYSTEM_CONFIG_INTERNAL_H_
#define _SYSTEM_CONFIG_INTERNAL_H_

#include "system_config.h"


void set_for_voltage_cut_off (void);
void set_for_charge_current (void);

void set_for_battery_type (void);
char * get_for_battery_type (void);

#endif//_SYSTEM_CONFIG_INTERNAL_H_

