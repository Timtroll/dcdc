#include "menu_internal.h"

void init_get_sys_info_func(void){
	Fill_get_func(get_sys_info, main_scr);
	Fill_get_func(get_sys_info, voltage_cut);
	Fill_get_func(get_sys_info, charging_type);
	Fill_get_func(get_sys_info, charge_threshold_Pb_lower);
	Fill_get_func(get_sys_info, charge_threshold_Pb_upper);
	Fill_get_func(get_sys_info, charge_threshold_others);
	Fill_get_func(get_sys_info, discharge_threshold);
	Fill_get_func(get_sys_info, quantity_cans);
	Fill_get_func(get_sys_info, capacity);
	Fill_get_func(get_sys_info, max_allowable_capacity);
	Fill_get_func(get_sys_info, internal_voltage_default);
	Fill_get_func(get_sys_info, type_battery);
}

char * get_raw_data(uint8_t name_screen){
	static uint8_t init_flag = 0;
	if (init_flag == 0)
	{
	 	init_get_sys_info_func();
	 	init_flag = 1;
	} 

	if (name_screen >= main_scr && name_screen <= type_battery)
		Raw_data(name_screen);
	
}

void menu_create(void){
	dl_list_group_create();
	menu = dl_list_create(sizeof(MAIN_SCREEN));
}

void fill_with_data(void){
	char * string_with_raw_data = NULL;
	
	for (int screen_counter = main_scr;screen_counter < type_battery; screen_counter++){
		string_with_raw_data = get_raw_data(screen_counter);
		
		//function for creat screen

		//function for push data in dl_list 
	}
}

char ** sys_info_get_main_scr(void){
	char * main_raw_string[QUANTITY_SCREEN - 1];

	return "all";
}
