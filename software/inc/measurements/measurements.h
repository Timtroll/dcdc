#ifndef _MEASUREMENTS_H_
#define _MEASUREMENTS_H_

#include "stddef.h"
#include "stdio.h"
#include "string.h"

#define SAMPLE_TIME 1.00
#define DISCHARGE_VOLTAGE 1.00

float calc_charge (float voltage[], int size);
int calc_discharge_time (float charge);

#endif//_MEASUREMENTS_H_

