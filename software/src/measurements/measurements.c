#include "measurements_internal.h"
#include "measurements_core.h"
#include "charger_core.h"

// char * get_for_voltage_cut_off (void) {
// 	//return some_voltage_pointer
// }

// char * get_for_charge_current (void) {
// 	//return some_current_pointer
// }

//=============================================
#define MEAS_CHARGE_RESET                0
#define MEAS_CHARGE_POSITIVE_PULSE_START 1
#define MEAS_CHARGE_POSITIVE_PULSE_END   2

#define SIZE_CHARGE_ARRAYS 200

uint8_t meas_charge_state = MEAS_CHARGE_RESET;
float charge_positiv_pulse_array [SIZE_CHARGE_ARRAYS] = {},
	  charge_neutral_pulse_array [SIZE_CHARGE_ARRAYS] = {};

uint16_t count_meas_charge_positive_pulse = 0,
		 count_meas_charge_neutral_pulse = 0;

void meas_charge_positive_pulse_start (void) {
	meas_charge_state = MEAS_CHARGE_POSITIVE_PULSE_START;
	count_meas_charge_positive_pulse = 0;
}

void meas_charge_positive_pulse_stop (void) {
	meas_charge_state = MEAS_CHARGE_POSITIVE_PULSE_END;
	count_meas_charge_neutral_pulse = 0;
}

void meas_charge_period_end (void) {
	meas_charge_state = MEAS_CHARGE_RESET;
}

void meas_charge_reset (void) {
	meas_charge_state = MEAS_CHARGE_RESET;
}


void meas_charge_voltage_akk_save (void) {
	if (meas_charge_state == MEAS_CHARGE_RESET)
		return;

	uint8_t akk = charging_get_akk();

	if (meas_charge_state == MEAS_CHARGE_POSITIVE_PULSE_START) {
		if (akk == CHARGING_AKK_1) {
			charge_positiv_pulse_array[count_meas_charge_positive_pulse] =
					meas_get_voltage_akk1();
			count_meas_charge_positive_pulse++;
		}
		else if (akk == CHARGING_AKK_2) {
			charge_positiv_pulse_array[count_meas_charge_positive_pulse] =
					meas_get_voltage_akk2();
			count_meas_charge_positive_pulse++;
		}
	}
	else if (meas_charge_state == MEAS_CHARGE_POSITIVE_PULSE_END) {
		if (akk == CHARGING_AKK_1) {
			charge_neutral_pulse_array[count_meas_charge_neutral_pulse] =
					meas_get_voltage_akk1();
			count_meas_charge_neutral_pulse++;
		}
		else if (akk == CHARGING_AKK_2) {
			charge_neutral_pulse_array[count_meas_charge_neutral_pulse] =
					meas_get_voltage_akk2();
			count_meas_charge_neutral_pulse++;
		}
	}

}



float meas_calc_charge (float voltage[], int size) {
	float charge = 0;

	for(int i = 0; i < size; i++) {
		charge += voltage[i]; 
	}
	
	charge *= SAMPLE_TIME;

	return charge;
}

int meas_calc_discharge_time (float charge) {
	int time = 0;

	time = charge / (10 * DISCHARGE_VOLTAGE);
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
