#include "menu_internal.h"

char * (* get_sys_info [QUANTITY_SCREEN]) (void) ={NULL};

void _init_get_sys_info_func(void){
	
}
/*
const char * sys_info_end_phrase [QUANTITY_SCREEN] = {
	"main_scr",
	"sys_info_get_voltage_cut()",
	"sys_info_get_charging_type()",
	"sys_info_get_charge_threshold_Pb_lower()",
	"sys_info_get_charge_threshold_Pb_upper()",
	"sys_info_get_charge_threshold_others()",
	"sys_info_get_discharge_threshold()",
	"sys_info_get_quantity_cans()",
	"sys_info_get_capacity()",
	"sys_info_get_max_allowable_capacity()",
	"sys_info_get_internal_voltage_default()",
	"sys_info_get_type_battery()"
};*/


char * _get_raw_data(uint8_t name_screen){
	Raw_data(name_screen);
}

void menu_create(void){
	dl_list_group_create();
	menu = dl_list_create(sizeof(MAIN_SCREEN));
}

void fill_with_data(void){
	for (int screen_counter = MAIN_SCREEN_POSITION;
		screen_counter < 2; 
		screen_counter++)
	{
		char * string_with_raw_data = NULL;
		string_with_raw_data = _get_raw_data(screen_counter);
		//printf("%s\n", string_with_raw_data);
	}
}



char * main_screen_all(void){
	return "all";
}
