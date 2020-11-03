#include "charger_core.h"

#ifndef DEBUG_SOFTWARE

#include "measurements_core.h"
#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "hrtim.h"
#include "tim.h"
#include <stdbool.h>

#define RIGHT_DWN_IN HRTIM_OUTPUT_TB2
#define LEFT_DWN_IN  HRTIM_OUTPUT_TB1
#define RIGHT_UP1_IN HRTIM_OUTPUT_TA2
#define LEFT_UP1_IN  HRTIM_OUTPUT_TA1
#define RIGHT_UP2_IN HRTIM_OUTPUT_TC2
#define LEFT_UP2_IN  HRTIM_OUTPUT_TC1
#define RIGHT_UP3_IN HRTIM_OUTPUT_TD2
#define LEFT_UP3_IN  HRTIM_OUTPUT_TD1

#define RIGHT_REC HRTIM_OUTPUT_TE2
#define LEFT_REC  HRTIM_OUTPUT_TE1

#define TIMERS_PERIOD 640
#define MIN_VALUE_WIDHT_OUTPUT_PULSE 6

#define CHARGER_CHANNELS_AKK1 (RIGHT_DWN_IN | LEFT_UP1_IN | LEFT_DWN_IN | RIGHT_UP1_IN)
#define CHARGER_CHANNELS_AKK2 (RIGHT_DWN_IN | LEFT_UP2_IN | LEFT_DWN_IN | RIGHT_UP2_IN)
#define CHARGER_CHANNELS_GEN  (RIGHT_DWN_IN | LEFT_UP3_IN | LEFT_DWN_IN | RIGHT_UP3_IN)

#define HRTIM_ALL_TIMERS_ID (HRTIM_TIMERID_MASTER | HRTIM_TIMERID_TIMER_A | HRTIM_TIMERID_TIMER_B | HRTIM_TIMERID_TIMER_C | HRTIM_TIMERID_TIMER_D | HRTIM_TIMERID_TIMER_E)

#define GPIO_CHARGE_AKK1(charge_state) (HAL_GPIO_WritePin(GPIOA, Ch_Akk1_Pin, charge_state))
#define GPIO_CHARGE_AKK2(charge_state) (HAL_GPIO_WritePin(GPIOA, Ch_Akk2_Pin, charge_state))
#define GPIO_DISCHARGE_AKK1(discharge_state) (HAL_GPIO_WritePin(GPIOA, DisCh_Akk1_Pin, discharge_state))
#define GPIO_DISCHARGE_AKK2(discharge_state) (HAL_GPIO_WritePin(GPIOA, DisCh_Akk2_Pin, discharge_state))

#define ACTIVE   1
#define INACTIVE 0

#define OCCURED_ERROR 1


void hrtim_set_value_pwm_on_outputs (void);
void hrtim_outputs_start (void);
void hrtim_start_timer (void);
void hrtim_all_outputs_stop (void);
void hrtim_set_level_inactive_on_all_outputs (void);
void hrtim_stop_timer (void) ;
void hrtim_reset_timer (void);


void gpio_charge_akk (uint8_t charging_akk, _Bool state);
void gpio_discharge_akk (uint8_t charging_akk, _Bool state);


HRTIM_CompareCfgTypeDef channel_compare_cfg = {
	.AutoDelayedMode = HRTIM_AUTODELAYEDMODE_REGULAR,
	.AutoDelayedTimeout = 0x0000
};
extern osThreadId charging_akkHandle;

void charger_init (void) {
	charger_handle = (ts_charger_handle) {
		.charger_mode = CHARGER_MODE_NONE,
		.output_mode = OUTPUT_MODE_NONE,
		.output_pulse_widht = MIN_VALUE_WIDHT_OUTPUT_PULSE,
		.charger_output_state = STATE_OFF,
		.charging_akk = CHARGING_AKK_NONE,
		.charging_akk_mode = CHARGING_AKK_MODE_DEFAULT,
		.need_disch_pulse = false
	};
}

CHARGER_STATUS charger_start (void) {
	if ((charger_handle.charger_mode == CHARGER_MODE_NONE) ||
			(charger_handle.output_mode == OUTPUT_MODE_NONE))
		return STATUS_ERROR_INIT;

	if (charger_handle.charger_output_state == STATE_ON)
		return STATUS_MULTIPLE_START;

	if (charger_handle.charging_akk_state == STATE_ON)
			if (charger_handle.charging_akk == charger_handle.output_mode)
				return STATUS_AKK_ALREADY_USED;

	hrtim_set_value_pwm_on_outputs();
	hrtim_outputs_start();
	hrtim_start_timer();

	charger_handle.charger_output_state = STATE_ON;
	return STATUS_OK;
}

void charger_stop (void) {
	hrtim_all_outputs_stop();
	hrtim_stop_timer();
	hrtim_set_level_inactive_on_all_outputs();
	hrtim_reset_timer();

	charger_handle.charger_output_state = STATE_OFF;
}

CHARGER_STATUS set_charger_mode (uint8_t mode) {
	if (charger_handle.charger_output_state == STATE_ON)
		return STATUS_NEED_TURN_OFF;

	if (mode == CHARGER_MODE_AKK){
		charger_handle.charger_mode = CHARGER_MODE_AKK;
		charger_handle.output_mode = OUTPUT_MODE_NONE;
	}
	else if (mode == CHARGER_MODE_GEN){
		charger_handle.charger_mode = CHARGER_MODE_GEN;
		charger_handle.output_mode = OUTPUT_MODE_GEN;
	}
	else{
		charger_handle.charger_mode = CHARGER_MODE_NONE;
		return STATUS_ERROR_INIT;
	}

	return STATUS_OK;
}

CHARGER_STATUS set_charger_akk (uint8_t akk) {
	if (charger_handle.charger_output_state == STATE_ON)
			return STATUS_NEED_TURN_OFF;

	if (charger_handle.charger_mode != CHARGER_MODE_AKK)
		return STATUS_ERROR_INIT;

	if (akk == CHARGER_OUTPUT_AKK_1)
		charger_handle.output_mode = OUTPUT_MODE_AKK1;
	else if (akk == CHARGER_OUTPUT_AKK_2)
		charger_handle.output_mode = OUTPUT_MODE_AKK2;
	else {
		charger_handle.output_mode = OUTPUT_MODE_NONE;
		return STATUS_ERROR_INIT;
	}
	return STATUS_OK;
}

CHARGER_STATUS set_charger_pulse_widght (uint16_t percent_widght) {
	hrtim_all_outputs_stop();

	if ((percent_widght > 1) && (percent_widght < 50)) {
		charger_handle.output_pulse_widht = (TIMERS_PERIOD / 2) * percent_widght / 100;
		charger_handle.output_pulse_widht_percent = percent_widght;
	}
	else{
		return STATUS_ERROR_INIT;
	}

	hrtim_set_value_pwm_on_outputs();
	hrtim_set_level_inactive_on_all_outputs();

	if(charger_handle.charger_output_state == STATE_ON)
		hrtim_outputs_start();

	return STATUS_OK;
}

void hrtim_set_value_pwm_on_outputs (void) {
	channel_compare_cfg.CompareValue = TIMERS_PERIOD / 4 + charger_handle.output_pulse_widht;
	HAL_HRTIM_WaveformCompareConfig(&hhrtim1, HRTIM_TIMERINDEX_MASTER, HRTIM_COMPAREUNIT_2, &channel_compare_cfg);

	channel_compare_cfg.CompareValue = TIMERS_PERIOD / 4 * 3 + charger_handle.output_pulse_widht;
	HAL_HRTIM_WaveformCompareConfig(&hhrtim1, HRTIM_TIMERINDEX_MASTER, HRTIM_COMPAREUNIT_4, &channel_compare_cfg);
}

void hrtim_outputs_start (void) {
	if(charger_handle.charger_mode == CHARGER_MODE_GEN) {
		HAL_HRTIM_WaveformOutputStart(&hhrtim1, CHARGER_CHANNELS_GEN);
	}
	else if (charger_handle.charger_mode == CHARGER_MODE_AKK) {
		if (charger_handle.output_mode == OUTPUT_MODE_AKK1) {
			HAL_HRTIM_WaveformOutputStart(&hhrtim1, CHARGER_CHANNELS_AKK1);
		}
		else if (charger_handle.output_mode == OUTPUT_MODE_AKK1) {
			HAL_HRTIM_WaveformOutputStart(&hhrtim1, CHARGER_CHANNELS_AKK2);
		}
	}
}

void hrtim_start_timer (void) {
	HAL_HRTIM_WaveformCountStart(&hhrtim1, HRTIM_ALL_TIMERS_ID);
}

void hrtim_all_outputs_stop (void) {
	HAL_HRTIM_WaveformOutputStop(&hhrtim1, CHARGER_CHANNELS_AKK1 | CHARGER_CHANNELS_AKK2 | CHARGER_CHANNELS_GEN);
}

void hrtim_set_level_inactive_on_all_outputs (void) {
	HAL_HRTIM_WaveformSetOutputLevel(&hhrtim1, HRTIM_TIMERINDEX_TIMER_A, HRTIM_OUTPUT_TA1, HRTIM_OUTPUTLEVEL_INACTIVE);
	HAL_HRTIM_WaveformSetOutputLevel(&hhrtim1, HRTIM_TIMERINDEX_TIMER_A, HRTIM_OUTPUT_TA2, HRTIM_OUTPUTLEVEL_INACTIVE);
	HAL_HRTIM_WaveformSetOutputLevel(&hhrtim1, HRTIM_TIMERINDEX_TIMER_B, HRTIM_OUTPUT_TB1, HRTIM_OUTPUTLEVEL_INACTIVE);
	HAL_HRTIM_WaveformSetOutputLevel(&hhrtim1, HRTIM_TIMERINDEX_TIMER_B, HRTIM_OUTPUT_TB2, HRTIM_OUTPUTLEVEL_INACTIVE);
	HAL_HRTIM_WaveformSetOutputLevel(&hhrtim1, HRTIM_TIMERINDEX_TIMER_C, HRTIM_OUTPUT_TC1, HRTIM_OUTPUTLEVEL_INACTIVE);
	HAL_HRTIM_WaveformSetOutputLevel(&hhrtim1, HRTIM_TIMERINDEX_TIMER_C, HRTIM_OUTPUT_TC2, HRTIM_OUTPUTLEVEL_INACTIVE);
	HAL_HRTIM_WaveformSetOutputLevel(&hhrtim1, HRTIM_TIMERINDEX_TIMER_D, HRTIM_OUTPUT_TD1, HRTIM_OUTPUTLEVEL_INACTIVE);
	HAL_HRTIM_WaveformSetOutputLevel(&hhrtim1, HRTIM_TIMERINDEX_TIMER_D, HRTIM_OUTPUT_TD2, HRTIM_OUTPUTLEVEL_INACTIVE);
//	HAL_HRTIM_WaveformSetOutputLevel(&hhrtim1, HRTIM_TIMERINDEX_TIMER_E, HRTIM_OUTPUT_TE1, HRTIM_OUTPUTLEVEL_INACTIVE);
//	HAL_HRTIM_WaveformSetOutputLevel(&hhrtim1, HRTIM_TIMERINDEX_TIMER_E, HRTIM_OUTPUT_TE2, HRTIM_OUTPUTLEVEL_INACTIVE);
}

void hrtim_stop_timer (void) {
	HAL_HRTIM_WaveformCountStop(&hhrtim1, HRTIM_ALL_TIMERS_ID);
}

void hrtim_reset_timer (void) {
	HAL_HRTIM_SoftwareReset(&hhrtim1, HRTIM_TIMERRESET_MASTER);
}

uint8_t get_charger_mode (void) {
	return charger_handle.charger_mode;
}

uint8_t get_charger_output_akk (void) {
	if (charger_handle.charger_mode == CHARGER_MODE_AKK) {
		if (charger_handle.charger_output_state == OUTPUT_MODE_AKK1)
			return CHARGER_OUTPUT_AKK_1;
		else if (charger_handle.charger_output_state == OUTPUT_MODE_AKK1)
			return CHARGER_OUTPUT_AKK_2;
	}
	return CHARGER_OUTPUT_AKK_NONE;
}





uint8_t get_charging_akk (void) {
	return charger_handle.charging_akk;
}

uint8_t get_charging_akk_mode (void) {
	return charger_handle.charging_akk_mode;
}

uint16_t get_charging_period (void) {
	return charger_handle.charging_period;
}

uint16_t get_charging_timing_positive_pulse (void) {
	return charger_handle.charging_timing_positive_pulse;
}

void set_charging_timing_positive_pulse (uint16_t time) {
	if (time > 100)
		charger_handle.charging_timing_positive_pulse = time;
}

uint16_t get_charging_timing_negative_pulse (void) {
	return charger_handle.charging_timing_negative_pulse;
}

void set_charging_timing_negative_pulse (uint16_t time) {
	if (time > 100)
		charger_handle.charging_timing_negative_pulse = time;
}

_Bool get_charging_need_disch_pulse (void) {
	return charger_handle.need_disch_pulse;
}

void set_charging_need_disch_pulse (_Bool value) {
	charger_handle.need_disch_pulse = value;
}

CHARGER_STATUS set_charging_period (uint16_t time) {
	if ((time > 500) && (time < 32000))
		return STATUS_ERROR_INIT;

	charger_handle.charging_period = time;
	return STATUS_OK;
}

CHARGER_STATUS set_charging_mode (uint8_t mode) {
	if (charger_handle.charging_akk_state == STATE_ON)
		return STATUS_NEED_TURN_OFF;

	if (mode == CHARGING_AKK_MODE_DEFAULT) {
		charger_handle.charging_akk_mode = CHARGING_AKK_MODE_DEFAULT;
	}
	else if (mode == CHARGING_AKK_MODE_ONE_AKK) {
		charger_handle.charging_akk_mode = CHARGING_AKK_MODE_ONE_AKK;
	}
	else if (mode == CHARGING_AKK_MODE_DISCHARGE) {
		charger_handle.charging_akk_mode = CHARGING_AKK_MODE_DISCHARGE;
	}
	else {
		charger_handle.charging_akk_mode = CHARGING_AKK_MODE_ERROR;
		return STATUS_ERROR_INIT;
	}

	return STATUS_OK;
}


void gpio_charge_akk (uint8_t charging_akk, _Bool state) {
	if (charging_akk == CHARGING_AKK_1) {
		GPIO_CHARGE_AKK1(state);
	}
	else if (charging_akk == CHARGING_AKK_2) {
		GPIO_CHARGE_AKK2(state);
	}
}

void gpio_discharge_akk (uint8_t charging_akk, _Bool state) {
	if (charging_akk == CHARGING_AKK_1) {
		GPIO_DISCHARGE_AKK1(state);
	}
	else if (charging_akk == CHARGING_AKK_2) {
		GPIO_DISCHARGE_AKK2(state);
	}
}

void set_state_on_all_charging_gpio_inactive (void) {
	GPIO_CHARGE_AKK1(INACTIVE);
	GPIO_CHARGE_AKK2(INACTIVE);
	GPIO_DISCHARGE_AKK1(INACTIVE);
	GPIO_DISCHARGE_AKK2(INACTIVE);
}

CHARGER_STATUS set_charging_akk (uint8_t akk) {
	if (charger_handle.charging_akk_state == STATE_ON)
		return STATUS_NEED_TURN_OFF;

	if (akk == CHARGING_AKK_1)
		charger_handle.charging_akk = CHARGING_AKK_1;
	else if (akk == CHARGING_AKK_2)
		charger_handle.charging_akk = CHARGING_AKK_2;
	else {
		charger_handle.charging_akk = CHARGING_AKK_NONE;
		return STATUS_ERROR_INIT;
	}

	return STATUS_OK;
}

CHARGER_STATUS start_charging_akk (void) {
	if (charger_handle.charging_akk_state == STATE_ON)
		return STATUS_MULTIPLE_START;

	if ((charger_handle.charging_period == 0) ||
			(charger_handle.charging_timing_positive_pulse == 0) ||
			(charger_handle.charging_timing_negative_pulse == 0))
		return STATUS_ERROR_INIT;

	if (charger_handle.charger_output_state == STATE_ON)
		if (charger_handle.output_mode == charger_handle.charging_akk)
			return STATUS_AKK_ALREADY_USED;

	charger_handle.charging_akk_state = STATE_ON;
	vTaskResume((TaskHandle_t)charging_akkHandle);
	return 0;
}

void stop_charging_akk (void) {
	charger_handle.charging_akk_state = STATE_OFF;
	charger_handle.charging_timing_state = 0;
	set_state_on_all_charging_gpio_inactive();
}



uint16_t charge_akk (void) {
	if (charger_handle.charging_timing_state == 0) {
		gpio_charge_akk(charger_handle.charging_akk, ACTIVE);
		charger_handle.charging_timing_state++;

		return charger_handle.charging_timing_positive_pulse;
	}
	else if (charger_handle.charging_timing_state == 1) {
		gpio_charge_akk(charger_handle.charging_akk, INACTIVE);
		charger_handle.charging_timing_state++;

		return charger_handle.charging_period -
				charger_handle.charging_timing_positive_pulse;
	}
	else if (charger_handle.charging_timing_state == 2) {
		gpio_discharge_akk(charger_handle.charging_akk, ACTIVE);
		charger_handle.charging_timing_state++;

		return charger_handle.charging_timing_negative_pulse;
	}
	else {
		gpio_discharge_akk(charger_handle.charging_akk, INACTIVE);
		charger_handle.charging_timing_state = 0;

		return charger_handle.charging_period -
				charger_handle.charging_timing_negative_pulse;
	}
}


void charging_akk_mode_default (void) {
	// temp
	//
	charging_akk_mode_one_akk();

	//change akk logic

	// correct time work
	// changing charging akk
}

void charging_akk_mode_one_akk (void) {
	// negative pulse neen? calc
	if (charger_handle.charging_timing_state == 2) {
		//charger_handle.need_disch_pulse = calc negative pulse need?
		//charger_handle.charging_timing_negative_pulse = calc negative pulse width
		//charger_handle.charging_timing_positive_pulse = calc next positive pulse

		if (charger_handle.need_disch_pulse == 0)
			charger_handle.charging_timing_state = 0;
	}

	osDelay(charge_akk());
}

void charging_akk_mode_discharge (void) {
	if (charger_handle.charging_timing_state % 2 == 0)
		gpio_discharge_akk(charger_handle.charging_akk, ACTIVE);
	else
		gpio_discharge_akk(charger_handle.charging_akk, INACTIVE);

	if (charger_handle.charging_timing_state < 9){
		charger_handle.charging_timing_state++;
		osDelay(charger_handle.charging_period / 10);
	}
	else {
		charger_handle.charging_timing_state = 0;

		if (charger_handle.charging_akk == CHARGING_AKK_1) {
			if (meas_get_voltage_akk1() <= 10.5)
				charger_handle.charging_akk_state = STATE_OFF;
		}
		else if (charger_handle.charging_akk == CHARGING_AKK_2) {
			if (meas_get_voltage_akk2() <= 10.5)
				charger_handle.charging_akk_state = STATE_OFF;
		}
		osDelay(charger_handle.charging_period);
	}
}

void charging_akk_task(void const * argument) {
	for (;;) {
		if (charger_handle.charging_akk_state == STATE_OFF) {
			vTaskSuspend((TaskHandle_t)charging_akkHandle);
		}
		else {
			if (charger_handle.charging_akk_mode == CHARGING_AKK_MODE_DEFAULT)
				charging_akk_mode_default();
			else if (charger_handle.charging_akk_mode == CHARGING_AKK_MODE_ONE_AKK)
				charging_akk_mode_one_akk();
			else if (charger_handle.charging_akk_mode == CHARGING_AKK_MODE_DISCHARGE)
				charging_akk_mode_discharge();
		}
	}
}

#else


void charger_start (void) {

}

void charger_stop (void) {

}

void charger_restart (void) {

}

void charger_set_mode (uint8_t mode) {

}

void charger_set_pulse_widght (uint16_t percent_widght) {

}


void start_charge_akk1 (void) {

}

void start_charge_akk2 (void) {

}

void stop_charge_akk (void) {

}

void charge_akk_interrupt (void) {

}

void set_t_charging (uint16_t time) {

}

#endif
