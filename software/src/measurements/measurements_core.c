#include "measurements_core.h"

#ifndef DEBUG_SOFTWARE

#include "adc.h"

#define ADC1_SIZE_MEASUREMENTS 4
#define ADC2_SIZE_MEASUREMENTS 3

uint16_t adc1_measurements [ADC1_SIZE_MEASUREMENTS] = {0},
		 adc2_measurements [ADC2_SIZE_MEASUREMENTS] = {0};


uint16_t first_battery_voltage = 0,
		 second_battery_voltage = 0,
		 output_voltage = 0,
//		 adc1_in12
		 generator_voltage = 0,
		 scheme_power_voltage = 0;
//		 adc2_in12


void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
	if(hadc->Instance == ADC1) {
		first_battery_voltage = adc1_measurements[0];
		second_battery_voltage = adc1_measurements[1];
		output_voltage = adc1_measurements[2];
//		adc1_in12
	}
	else if(hadc->Instance == ADC2) {
		generator_voltage = adc2_measurements[0];
		scheme_power_voltage = adc2_measurements[1];
//		adc2_in12
	}
}



void start_measurements (void) {
	HAL_ADC_Start_DMA(&hadc1, adc1_measurements, ADC1_SIZE_MEASUREMENTS);
	HAL_ADC_Start_DMA(&hadc2, adc2_measurements, ADC2_SIZE_MEASUREMENTS);
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
