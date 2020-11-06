#include "measurements_core.h"

#ifndef DEBUG_SOFTWARE

#include "adc.h"
#include "tim.h"

#define ADC1_SIZE_MEASUREMENTS 4
#define ADC2_SIZE_MEASUREMENTS 3

uint16_t adc1_measurements [ADC1_SIZE_MEASUREMENTS] = {0},
		 adc2_measurements [ADC2_SIZE_MEASUREMENTS] = {0};


uint16_t akk1_voltage = 0,
		 akk2_voltage = 0,
		 output_voltage = 0,
//		 adc1_in12
		 generator_voltage = 0,
		 scheme_voltage = 0;
//		 adc2_in12


void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
	if(hadc->Instance == ADC1) {
		akk1_voltage = adc1_measurements[0];
		akk2_voltage = adc1_measurements[1];
		output_voltage = adc1_measurements[2];
//		adc1_in12
	}
	else if(hadc->Instance == ADC2) {
		generator_voltage = adc2_measurements[0];
		scheme_voltage = adc2_measurements[1];
//		adc2_in12
	}
}



void start_measurements (void) {
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc1_measurements, ADC1_SIZE_MEASUREMENTS);
	HAL_ADC_Start_DMA(&hadc2, (uint32_t *)adc2_measurements, ADC2_SIZE_MEASUREMENTS);
	HAL_TIM_Base_Start(&htim15);
}


float meas_get_voltage_akk1 (void) {
	return akk1_voltage * 16.8 / 4096;
}

float meas_get_voltage_akk2 (void) {
	return akk1_voltage * 16.8 / 4096;
}

float meas_get_voltage_charger_output (void) {
	return akk1_voltage * 16.8 / 4096;
}

float meas_get_voltage_generator (void) {
	return akk1_voltage * 16.8 / 4096;
}

float meas_get_voltage_scheme (void) {
	return akk1_voltage * 16.8 / 4096;
}

#else

float meas_get_voltage_akk1 (void) {
	return 3.3;
}

float meas_get_voltage_akk2 (void) {
	return 3.3;
}

float meas_get_voltage_charger_output (void) {
	return 3.3;
}

float meas_get_voltage_generator (void) {
	return 3.3;
}

float meas_get_voltage_scheme (void) {
	return 3.3;
}

#endif
