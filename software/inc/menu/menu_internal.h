#ifndef _MENU_INTERNAL_H_
#define _MENU_INTERNAL_H_

#include "menu.h"
#include "../system_info/system_info.h"
#include "../dl_list/dl_list.h"

#include <stdlib.h>

#define MAIN_QUANTITY_ELEMENT 20
#define SIDE_QUANTITY_ELEMENT 4
#define MAIN_SCREEN "char * main_screen [MAIN_QUANTITY_ELEMENT]"
#define SIDE_SCREEN "char * main_screen [SIDE_QUANTITY_ELEMENT]"
#define DIVISION_CELLS "\n\n"

#define QUANTITY_SCREEN 12
#define MAIN_SCREEN_POSITION 0
#define SIDE_SCREEN_START_POSITION 1

#define SYS_INFO_START_PHRASE "sys_info_get_"

dl_list_t * menu;

enum screen_name
{
	main_scr,
	voltage_cut,
	charging_type,
	charge_threshold_Pb_lower,
	charge_threshold_Pb_upper,
	charge_threshold_others,
	discharge_threshold,
	quantity_cans,
	capacity,
	max_allowable_capacity,
	internal_voltage_default,
	type_battery
};


void menu_create(void);
void fill_with_data(void);

char * main_screen_all(void);

#define Raw_data(screen) \
	if(screen == main_scr) \
		return main_screen_all(); \
	return NULL;\
	//return get_sys_info[screen_index](); \


#endif//_MENU_INTERNAL_H_

