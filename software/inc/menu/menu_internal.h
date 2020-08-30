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

#define MAIN_SCREEN_POSITION 0
#define SIDE_SCREEN_START_POSITION 1
#define QUANTITY_SCREEN 12

dl_list_t * menu;
char * (* get_sys_info [QUANTITY_SCREEN]) (void);

#define Raw_data(screen) \
	return get_sys_info[screen](); \

#define Fill_get_func(list_func, name_func)\
	list_func[name_func] = sys_info_get_ ## name_func;\

enum screen_name{
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

void init_get_sys_info_func(void);





char * sys_info_get_main_scr(void);
char * get_raw_data(uint8_t name_screen);

#endif//_MENU_INTERNAL_H_

