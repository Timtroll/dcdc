#include "measurements_core.h"

#ifndef DEBUG_SOFTWARE

#include "adc.h"

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
	if(hadc->Instance == ADC1) {

	}
	else if(hadc->Instance == ADC2) {

	}
}

double meas_voltage_gen (void) {
	//convert 12 bit in voltage
	return 0;
}

double meas_current_charger (void) {
	//convert 12 bit in current
	return 0;
}

#else

double meas_voltage_gen (void) {
	return 0;
}

double meas_current_charger (void) {
	return 0;
}

#endif
