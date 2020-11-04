#include "measurements_internal.h"

// char * get_for_voltage_cut_off (void) {
// 	//return some_voltage_pointer
// }

// char * get_for_charge_current (void) {
// 	//return some_current_pointer
// }

//=============================================
float calc_charge (float voltage[], int size) {
	float charge = 0;

	for(int i = 0; i < size; i++) {
		charge += voltage[i]; 
	}
	
	charge *= sample_time;

	return charge;
}

int calc_discharge_time (float charge) {
	int time = 0;

	time = charge / (10 * discharge_voltage);
	return time;
}

//------------------------------------------------
// #define POW2(x) x*x

// float calc_energy (float voltage[], int size) {
// 	float energy = 0;

// 	for(int i = 0; i < size; i++) {
// 		energy += POW2(voltage[i]); 
// 	}
	
// 	energy *= sample_time;

// 	return energy;
// }

// int calc_discharge_time (float energy) {
// 	int time = 0;

// 	time = energy / (10 * POW2(discharge_voltage));
// 	return time;
// }

//-------------------------------------------