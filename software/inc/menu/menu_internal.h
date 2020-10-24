#ifndef _MENU_INTERNAL_H_
#define _MENU_INTERNAL_H_

#include "menu.h"
#include "../system_info/system_info.h"
#include "../dl_list/dl_list.h"

#include <stdlib.h>

#define MAIN_QUANTITY_ELEMENT 26
#define SIDE_QUANTITY_ELEMENT 4
#define DIVISION_CELLS "\n\n"



#define MAIN_SCREEN_POSITION 0 
#define SIDE_SCREEN_START_POSITION 1
#define QUANTITY_SCREEN 12

#define SIZEOF_DIV_CELLS 4
#define SIZEOF_END_SYMBOL 2


#define Raw_data(screen) \
	return get_sys_info[screen](); \

#define Set_raw_data(list_func, name_func)\
	list_func[name_func] = sys_info_get_ ## name_func;\

dl_list_t * menu;
static list_cell_t * actual_screen = NULL;

char * (* get_sys_info [QUANTITY_SCREEN]) (void);

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
void init_function(void);
void fill_with_data(void);

char * get_raw_data(uint8_t name_screen);

list_cell_t * get_actual_screen (void);
void set_actual_screen (list_cell_t * new_screen);

char ** get_screen_name_list(void);
char ** get_promt_list(void);
char ** get_raw_data_list(void);

#endif//_MENU_INTERNAL_H_

