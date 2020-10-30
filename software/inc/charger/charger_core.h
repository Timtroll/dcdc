#ifndef _CHARGER_CORE_H_
#define _CHARGER_CORE_H_

// //#define DEBUG_SOFTWARE

#include <stdint.h>
#include <stdbool.h>

#define CHARGER_MODE_AKK1 1
#define CHARGER_MODE_AKK2 2
#define CHARGER_MODE_GEN  3
#define CHARGER_MODE_ERR  4

#define CHARGING_AKK1 0
#define CHARGING_AKK2 1
#define AKK_NOT_CHARGING 2

void charger_start (void);
void charger_stop (void);
void charger_restart (void);
void charger_set_mode (uint8_t mode);
void charger_set_pulse_widght (uint16_t percent_widght);
uint8_t get_charger_mode (void);

void set_t_charging (uint16_t time);
void start_charge_akk1 (void);
void start_charge_akk2 (void);
void stop_charge_akk (void);
void charge_akk_interrupt (void);
uint8_t get_charging_akk (void);

#endif//_CHARGER_CORE_H_
