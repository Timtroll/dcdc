#include "charger_core.h"

#ifndef DEBUG_SOFTWARE

#include "hrtim.h"

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

#define CHARGER_MODE_AKK1 1
#define CHARGER_MODE_AKK2 2
#define CHARGER_MODE_GEN  3
#define CHARGER_MODE_ERR  4

#define CHARGER_CHANNELS_AKK1 (RIGHT_DWN_IN | LEFT_UP1_IN | LEFT_DWN_IN | RIGHT_UP1_IN)
#define CHARGER_CHANNELS_AKK2 (RIGHT_DWN_IN | LEFT_UP2_IN | LEFT_DWN_IN | RIGHT_UP2_IN)
#define CHARGER_CHANNELS_GEN  (RIGHT_DWN_IN | LEFT_UP3_IN | LEFT_DWN_IN | RIGHT_UP3_IN)

#define HRTIM_ALL_TIMERS_ID (HRTIM_TIMERID_MASTER | HRTIM_TIMERID_TIMER_A | HRTIM_TIMERID_TIMER_B | HRTIM_TIMERID_TIMER_C | HRTIM_TIMERID_TIMER_D | HRTIM_TIMERID_TIMER_E)

void hrtim_set_value_pwm_on_outputs (uint8_t mode, uint8_t pulse_widht);
void hrtim_outputs_start (uint8_t mode) ;
void hrtim_start_timer (void);
void hrtim_all_outputs_stop (void);
void hrtim_set_level_inactive_on_all_outputs (void);
void hrtim_stop_timer (void) ;
void hrtim_reset_timer (void);

void charger_start (void);
void charger_stop (void);
void charger_restart (void);
void charger_set_mode (uint8_t mode);
void charger_set_pulse_widght (uint16_t percent_widght);


HRTIM_CompareCfgTypeDef channel_compare_cfg = {
	.AutoDelayedMode = HRTIM_AUTODELAYEDMODE_REGULAR,
	.AutoDelayedTimeout = 0x0000
};

uint8_t charger_mode = CHARGER_MODE_ERR,
		hrtim_widht_output_pulse = MIN_VALUE_WIDHT_OUTPUT_PULSE;


void hrtim_set_value_pwm_on_outputs (uint8_t mode, uint8_t pulse_widht) {
	channel_compare_cfg.CompareValue = TIMERS_PERIOD / 4 + pulse_widht;
	HAL_HRTIM_WaveformCompareConfig(&hhrtim1, HRTIM_TIMERINDEX_MASTER, HRTIM_COMPAREUNIT_2, &channel_compare_cfg);

	channel_compare_cfg.CompareValue = TIMERS_PERIOD / 4 * 3 + pulse_widht;
	HAL_HRTIM_WaveformCompareConfig(&hhrtim1, HRTIM_TIMERINDEX_MASTER, HRTIM_COMPAREUNIT_4, &channel_compare_cfg);
}

void hrtim_outputs_start (uint8_t mode) {
	if (mode == CHARGER_MODE_AKK1) {
		HAL_HRTIM_WaveformOutputStart(&hhrtim1, CHARGER_CHANNELS_AKK1);
	}
	else if (mode == CHARGER_MODE_AKK2) {
		HAL_HRTIM_WaveformOutputStart(&hhrtim1, CHARGER_CHANNELS_AKK2);
	}
	else if (mode == CHARGER_MODE_GEN) {
		HAL_HRTIM_WaveformOutputStart(&hhrtim1, CHARGER_CHANNELS_GEN);
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


void charger_start (void) {
	hrtim_set_value_pwm_on_outputs(charger_mode, hrtim_widht_output_pulse);
	hrtim_outputs_start(charger_mode);
	hrtim_start_timer();
}

void charger_stop (void) {
	hrtim_all_outputs_stop();
	hrtim_stop_timer();
	hrtim_set_level_inactive_on_all_outputs();
	hrtim_reset_timer();
}

void charger_restart (void) {
	charger_stop();
	charger_start();
}

void charger_set_mode (uint8_t mode) {
	if (mode == CHARGER_MODE_AKK1) {
		charger_mode = CHARGER_MODE_AKK1;
	}
	else if (mode == CHARGER_MODE_AKK2) {
		charger_mode = CHARGER_MODE_AKK2;
	}
	else if (mode == CHARGER_MODE_GEN) {
		charger_mode = CHARGER_MODE_GEN;
	}
	else {
		charger_mode = CHARGER_MODE_ERR;
	}
}

void charger_set_pulse_widght (uint16_t percent_widght) {
	if ((percent_widght > 1) && (percent_widght < 50)) {
		hrtim_widht_output_pulse = (TIMERS_PERIOD / 2) * percent_widght / 100;
	}
	else{
		hrtim_widht_output_pulse = MIN_VALUE_WIDHT_OUTPUT_PULSE;
	}
}

// TEMP_FOR_TEST_NO_REF_CODE
#include "tim.h"
#include <stdbool.h>

#define GPIO_CHARGE_AKK1(charge_state) (HAL_GPIO_WritePin(GPIOA, Ch_Akk1_Pin, charge_state))
#define GPIO_CHARGE_AKK2(charge_state) (HAL_GPIO_WritePin(GPIOA, Ch_Akk2_Pin, charge_state))
#define GPIO_DISCHARGE_AKK1(discharge_state) (HAL_GPIO_WritePin(GPIOA, DisCh_Akk1_Pin, discharge_state))
#define GPIO_DISCHARGE_AKK2(discharge_state) (HAL_GPIO_WritePin(GPIOA, DisCh_Akk2_Pin, discharge_state))

#define CHARGE_SIGNAL_ARRAY_SIZE 26
#define CHARGING_AKK1 0
#define CHARGING_AKK2 1

#define ACTIVE   1
#define INACTIVE 0

int8_t charge_signal_array[CHARGE_SIGNAL_ARRAY_SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 1, 0, 1, 0, 1, 0};
int8_t * charge_signal = charge_signal_array;
uint16_t num_pos_charge = 0;

uint8_t charging_akk = 0;
_Bool discharge_akk_changed = false,
	  charger_mode_changed_from_gen = false;


void start_charge_akk1 (void);
void start_charge_akk2 (void);
void start_discharge_akk1 (void);
void start_discharge_akk2 (void);
void stop_discharge_akk1 (void);
void stop_discharge_akk2 (void);
void stop_charge_akk (void);
void charge_akk_interrupt (void);
void set_t_charging (uint16_t time);

void gpio_charge_akk (uint8_t charging_akk, _Bool state);
void gpio_discharge_akk (uint8_t charging_akk, _Bool state);



void set_t_charging (uint16_t time) {
	htim17.Init.Period = time;
	HAL_TIM_Base_Init(&htim17);
}

void start_charge_akk1 (void) {
	charging_akk = CHARGING_AKK1;
	HAL_TIM_Base_Start_IT(&htim17);
}

void start_charge_akk2 (void) {
	charging_akk = CHARGING_AKK2;
	HAL_TIM_Base_Start_IT(&htim17);
}

void start_discharge_akk1 (void) {
	GPIO_DISCHARGE_AKK1(ACTIVE);
}

void start_discharge_akk2 (void) {
	GPIO_DISCHARGE_AKK2(ACTIVE);
}


//state where state == -1 discharge will be active in 0
void stop_discharge_akk1 (void) {
	if (discharge_akk_changed == true) {
		discharge_akk_changed = false;
	}
	GPIO_DISCHARGE_AKK1(INACTIVE);
}

void stop_discharge_akk2 (void) {
	if (discharge_akk_changed == true) {
		discharge_akk_changed = false;
	}
	GPIO_DISCHARGE_AKK2(INACTIVE);

}

void gpio_charge_akk (uint8_t charging_akk, _Bool state) {
	if (charging_akk == CHARGING_AKK1) {
		GPIO_CHARGE_AKK1(state);
	}
	else if (charging_akk == CHARGING_AKK2) {
		GPIO_CHARGE_AKK2(state);
	}
}

void gpio_discharge_akk (uint8_t charging_akk, _Bool state) {
	if (charging_akk == CHARGING_AKK1) {
		GPIO_DISCHARGE_AKK1(state);
	}
	else if (charging_akk == CHARGING_AKK2) {
		GPIO_DISCHARGE_AKK1(state);
	}
}


void stop_charge_akk (void) {
	HAL_TIM_Base_Stop_IT(&htim17);

	gpio_charge_akk(charging_akk, INACTIVE);
	gpio_discharge_akk(charging_akk, INACTIVE);

	num_pos_charge = 0;

	if (discharge_akk_changed == true) {
		gpio_discharge_akk(charging_akk ==  CHARGING_AKK1 ? CHARGING_AKK2 : CHARGING_AKK1, ACTIVE);

		charger_set_mode(charging_akk ==  CHARGING_AKK1 ? CHARGER_MODE_AKK2 : CHARGER_MODE_AKK1);
		charger_start();

		discharge_akk_changed = false;
	}
	else if (charger_mode_changed_from_gen == true) {
		charger_set_mode(CHARGER_MODE_GEN);
		charger_restart();

		charger_mode_changed_from_gen = false;
	}
}


void charge_akk_interrupt (void) {
	if (charge_signal[num_pos_charge] == 1){
		gpio_charge_akk(charging_akk, ACTIVE);
	}
	else if (charge_signal[num_pos_charge] == 0) {
		gpio_charge_akk(charging_akk, INACTIVE);
		gpio_discharge_akk(charging_akk, INACTIVE);

		if (discharge_akk_changed == true) {
			charger_stop();

			gpio_discharge_akk(charging_akk ==  CHARGING_AKK1 ? CHARGING_AKK2 : CHARGING_AKK1, ACTIVE);//define ?

			charger_set_mode(charging_akk ==  CHARGING_AKK1 ? CHARGER_MODE_AKK2 : CHARGER_MODE_AKK1);
			charger_start();

			discharge_akk_changed = false;
		}else if (charger_mode_changed_from_gen == true) {
			charger_set_mode(CHARGER_MODE_GEN);
			charger_restart();

			charger_mode_changed_from_gen = false;
		}
	}
	else if (charge_signal[num_pos_charge] == -1) {
		if ((charger_mode == CHARGER_MODE_AKK1) || (charger_mode == CHARGER_MODE_AKK2)) {
			charger_stop();

			gpio_discharge_akk(charging_akk ==  CHARGING_AKK1 ? CHARGING_AKK2 : CHARGING_AKK1, INACTIVE);
			gpio_discharge_akk(charging_akk ==  CHARGING_AKK1 ? CHARGING_AKK1 : CHARGING_AKK2, ACTIVE);

			charger_set_mode(charging_akk ==  CHARGING_AKK1 ? CHARGER_MODE_AKK1 : CHARGER_MODE_AKK2);
			charger_start();

			discharge_akk_changed = true;
		}
		else if (charger_mode == CHARGER_MODE_GEN) {
			charger_stop();

			gpio_discharge_akk(charging_akk ==  CHARGING_AKK1 ? CHARGING_AKK1 : CHARGING_AKK2, ACTIVE);

			charger_set_mode(charging_akk ==  CHARGING_AKK1 ? CHARGER_MODE_AKK1 : CHARGER_MODE_AKK2);
			charger_start();

			charger_mode_changed_from_gen = true;
		}
	}

	if (num_pos_charge < 26)
		num_pos_charge++;
	else
		num_pos_charge = 0;
}

#else



#endif
