#include "menu_internal.h"

char * str_screen_name[QUANTITY_SCREEN] = {
	"main_scr",
	"voltage_cut",
	"charging_type",
	"charge_threshold_Pb_lower",
	"charge_threshold_Pb_upper",
	"charge_threshold_others",
	"discharge_threshold",
	"quantity_cans",
	"capacity",
	"max_allowable_capacity",
	"internal_voltage_default",
	"type_battery"
};

char * promt_list[QUANTITY_SCREEN-1] = {
	"test_promt_voltage_cut",
	"test_promt_charging_type",
	"test_promt_charge_threshold_Pb_lower",
	"test_promt_charge_threshold_Pb_upper",
	"test_promt_charge_threshold_others",
	"test_promt_discharge_threshold",
	"test_promt_quantity_cans",
	"test_promt_capacity",
	"test_promt_max_allowable_capacity",
	"test_promt_internal_voltage_default",
	"test_promt_type_battery"
};//in work!!!

void init_function(void){
	Set_raw_data(get_sys_info, voltage_cut);
	Set_raw_data(get_sys_info, charging_type);
	Set_raw_data(get_sys_info, charge_threshold_Pb_lower);
	Set_raw_data(get_sys_info, charge_threshold_Pb_upper);
	Set_raw_data(get_sys_info, charge_threshold_others);
	Set_raw_data(get_sys_info, discharge_threshold);
	Set_raw_data(get_sys_info, quantity_cans);
	Set_raw_data(get_sys_info, capacity);
	Set_raw_data(get_sys_info, max_allowable_capacity);
	Set_raw_data(get_sys_info, internal_voltage_default);
	Set_raw_data(get_sys_info, type_battery);
	Set_raw_data(get_sys_info, main_scr);
}

char * get_raw_data(uint8_t name_screen){
	static uint8_t init_flag = 0;
	if (init_flag == 0)
	{
	 	init_function();
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
	
	for (int screen_counter = main_scr;screen_counter <= type_battery; screen_counter++){
		string_with_raw_data = get_raw_data(screen_counter);
		//function for creat screen

		//function for push data in dl_list 
	}
}

char ** sys_info_get_main_scr(void){
	static char ** main_raw_string[QUANTITY_SCREEN - 1];
	
	for(int num = 0; num < (QUANTITY_SCREEN-1); num++){
		main_raw_string[num] = get_raw_data(num+1);
	}

	return main_raw_string;
}


char * _get_screen_name(uint8_t number_screen){
	return str_screen_name[number_screen];
}

char * _get_promt(uint8_t number_screen){
	return promt_list[number_screen];
}

