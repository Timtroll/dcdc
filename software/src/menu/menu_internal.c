#include "menu_internal.h"

char * _get_raw_data(uint8_t name_screen){
	Raw_data(name_screen);
}

void menu_create(void){
	dl_list_group_create();
	menu = dl_list_create(sizeof(MAIN_SCREEN));
}

void fill_with_data(void){
	char * string_with_raw_data = _get_raw_data(main_scr);
}



char * main_screen_all(void){
	return "all";
}
/*
enum screen_name
{
	MAIN,
	VOLTAGE_CUT,
	CHARGING_TYPE,
	CHARGE_THRESHOLD_PB_LOWER,
	CHARGE_THRESHOLD_PB_UPPER,
	CHARGE_THRESHOLD_OTHERS,
	DISCHARGE_THRESHOLD,
	QUANTITY_CANS,
	CAPACITY,
	MAX_ALLOWABLE_CATACITY,
	INTERNAL_VOLTAGE_DEFAULT,
	TYPE_BATTERY
};
*/	