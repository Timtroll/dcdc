#ifndef _CHARGER_CORE_H_
#define _CHARGER_CORE_H_

// #define DEBUG_SOFTWARE

#include <stdint.h>
#include <stdbool.h>

#define CHARGER_MODE_NONE 0
#define CHARGER_MODE_AKK  1
#define CHARGER_MODE_GEN  2

#define OUTPUT_MODE_NONE 0
#define OUTPUT_MODE_AKK1 1
#define OUTPUT_MODE_AKK2 2
#define OUTPUT_MODE_GEN  3

#define CHARGER_OUTPUT_AKK_NONE 0
#define CHARGER_OUTPUT_AKK_1    1
#define CHARGER_OUTPUT_AKK_2    2

#define CHARGING_AKK_NONE 0
#define CHARGING_AKK_1    1
#define CHARGING_AKK_2    2

#define CHARGING_AKK_MODE_DEFAULT   0
#define CHARGING_AKK_MODE_ONE_AKK   1
#define CHARGING_AKK_MODE_DISCHARGE 2
#define CHARGING_AKK_MODE_ERROR     3

#define STATE_OFF 0
#define STATE_ON  1


typedef struct _charger_handle {
	// CHARGER
	uint8_t
		charger_mode,// AKK / GEN / none
		output_mode, // AKK1 / AKK2 / GEN / none
		output_pulse_widht_percent,
		output_pulse_widht
		;
	_Bool
		charger_output_state; // ON / OFF


	//CHARGING
	uint8_t
		charging_akk, // AKK1 / AKK2 / NONE
		charging_akk_mode, // default / one_akk / disch_akk
		charging_timing_state // 0 / 1 / 2 / 3 OR 0-9
		;
	uint16_t
		charging_period,
		charging_timing_positive_pulse,
		charging_timing_negative_pulse
		;
	_Bool
		charging_akk_state, // ON / OFF
		need_disch_pulse, // TRUE / FALSE
		need_switch_akk
		;
} ts_charger_handle;

typedef enum {
	STATUS_OK               = 0,
	STATUS_ERROR_INIT       = 1,
	STATUS_AKK_ALREADY_USED = 2,
	STATUS_MULTIPLE_START   = 3,
	STATUS_NEED_TURN_OFF    = 4
}CHARGER_STATUS;

ts_charger_handle charger_handle;



void charger_init (void);

CHARGER_STATUS charger_start (void);
void charger_stop (void);
CHARGER_STATUS charger_set_mode (uint8_t mode);
CHARGER_STATUS charger_set_akk (uint8_t akk);
CHARGER_STATUS charger_set_pulse_widght (uint16_t percent_widght);
uint8_t charger_get_mode (void);
uint8_t charger_get_output_akk (void);
uint8_t charger_get_output_pw (void);


CHARGER_STATUS charging_set_period (uint16_t time);
CHARGER_STATUS charging_set_mode (uint8_t mode);
CHARGER_STATUS charging_set_akk (uint8_t akk);
CHARGER_STATUS charging_start_akk (void);
void charging_stop_akk (void);
uint8_t charging_get_akk (void);
uint8_t charging_get_akk_mode (void);
uint16_t charging_get_period (void);

void charging_akk_switch (void);

//for test
uint16_t charging_get_timing_positive_pulse (void);
uint16_t charging_get_timing_negative_pulse (void);
_Bool charging_get_need_disch_pulse (void);

//root set
void charging_set_timing_positive_pulse (uint16_t time);
void charging_set_timing_negative_pulse (uint16_t time);
void charging_set_need_disch_pulse (_Bool value);

#endif//_CHARGER_CORE_H_
