#ifndef _MEASUREMENTS_H_
#define _MEASUREMENTS_H_

#include "stddef.h"
#include "stdio.h"
#include "string.h"

#define SAMPLE_TIME 1.00
#define DISCHARGE_VOLTAGE 1.00

void meas_charge_positive_pulse_start (void);
void meas_charge_positive_pulse_stop (void);
void meas_charge_period_end (void);
void meas_charge_reset (void);

void meas_charge_voltage_akk_save (void);


float meas_calc_charge (float voltage[], int size);
int meas_calc_discharge_time (float charge);

#endif//_MEASUREMENTS_H_

