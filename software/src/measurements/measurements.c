#include "measurements_internal.h"
#include "measurements_core.h"
#include "charger_core.h"

#define MEAS_CHARGE_RESET                0
#define MEAS_CHARGE_POSITIVE_PULSE_START 1
#define MEAS_CHARGE_POSITIVE_PULSE_END   2

#define SIZE_CHARGE_ARRAYS 200

uint8_t meas_charge_state = MEAS_CHARGE_RESET;
float charge_positiv_pulse_array[SIZE_CHARGE_ARRAYS] = {},
	  charge_neutral_pulse_array[SIZE_CHARGE_ARRAYS] = {};

uint16_t num_meas_charge_positive_pulse = 0,
		 num_meas_charge_neutral_pulse = 0;

void meas_charge_positive_pulse_start (void) {
	meas_charge_state = MEAS_CHARGE_POSITIVE_PULSE_START;
	num_meas_charge_positive_pulse = 0;
}

void meas_charge_positive_pulse_stop (void) {
	meas_charge_state = MEAS_CHARGE_POSITIVE_PULSE_END;
	num_meas_charge_neutral_pulse = 0;
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
		if (num_meas_charge_positive_pulse == SIZE_CHARGE_ARRAYS)
			return;

		if (akk == CHARGING_AKK_1) {
			charge_positiv_pulse_array[num_meas_charge_positive_pulse] =
					meas_get_voltage_akk1();
			num_meas_charge_positive_pulse++;
		}
		else if (akk == CHARGING_AKK_2) {
			charge_positiv_pulse_array[num_meas_charge_positive_pulse] =
					meas_get_voltage_akk2();
			num_meas_charge_positive_pulse++;
		}
	}
	else if (meas_charge_state == MEAS_CHARGE_POSITIVE_PULSE_END) {
		if (num_meas_charge_neutral_pulse == SIZE_CHARGE_ARRAYS)
			return;

		if (akk == CHARGING_AKK_1) {
			charge_neutral_pulse_array[num_meas_charge_neutral_pulse] =
					meas_get_voltage_akk1();
			num_meas_charge_neutral_pulse++;
		}
		else if (akk == CHARGING_AKK_2) {
			charge_neutral_pulse_array[num_meas_charge_neutral_pulse] =
					meas_get_voltage_akk2();
			num_meas_charge_neutral_pulse++;
		}
	}

}



float meas_calc_charge (void) {
	float charge = 0;

	for(int i = 0; i < num_meas_charge_positive_pulse; i++) {
		charge += charge_positiv_pulse_array[i];
	}
	
	charge *= SAMPLE_TIME;

	return charge;
}

int meas_calc_discharge_time (float charge) {
	int time = 0;

	time = charge / (10 * DISCHARGE_VOLTAGE);
	return time;
}



float meas_calc_coef_fall_charging_voltage (void) {
	if (num_meas_charge_neutral_pulse < 3)
		return 0;

//	memset((void *)charge_neutral_pulse_derivative_array, 0, sizeof(float) * SIZE_CHARGE_ARRAYS - 1);

	float coef_fall = 0;
	uint16_t num_first_derivative_samples,
			num_second_derivative_samples;

	for (num_first_derivative_samples = 0; num_first_derivative_samples < num_meas_charge_neutral_pulse - 1; num_first_derivative_samples++) {
		charge_neutral_pulse_array[num_first_derivative_samples] =
				charge_neutral_pulse_array[num_first_derivative_samples] - charge_neutral_pulse_array[num_first_derivative_samples + 1];
	}

	charge_neutral_pulse_array[num_first_derivative_samples] = 0;

	for (num_second_derivative_samples = 0; num_second_derivative_samples < num_first_derivative_samples - 1; num_second_derivative_samples++) {
		charge_neutral_pulse_array[num_second_derivative_samples] =
				charge_neutral_pulse_array[num_second_derivative_samples] - charge_neutral_pulse_array[num_second_derivative_samples + 1];
	}

	charge_neutral_pulse_array[num_second_derivative_samples] =0;

	for (uint16_t num_sample = 0; num_sample < num_second_derivative_samples; num_sample++) {
		coef_fall += charge_neutral_pulse_array[num_sample];
	}

	memset((void *)charge_neutral_pulse_array, 0, sizeof(float) * SIZE_CHARGE_ARRAYS);

	return coef_fall / num_second_derivative_samples;
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
