#include "menu_internal.h"

char * str_screen_name[QUANTITY_SCREEN] = {
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
	//Set_raw_data(get_sys_info, main_scr);
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
	menu = dl_list_create(sizeof(char * [MAIN_QUANTITY_ELEMENT]));

	char * main_screen [MAIN_QUANTITY_ELEMENT];
	char * 
		voltage_cut [SIDE_QUANTITY_ELEMENT],
		charging_type [SIDE_QUANTITY_ELEMENT],
		charge_threshold_Pb_lower [SIDE_QUANTITY_ELEMENT],
		charge_threshold_Pb_upper [SIDE_QUANTITY_ELEMENT],
		charge_threshold_others [SIDE_QUANTITY_ELEMENT],
		discharge_threshold [SIDE_QUANTITY_ELEMENT],
		quantity_cans [SIDE_QUANTITY_ELEMENT],
		capacity [SIDE_QUANTITY_ELEMENT],
		max_allowable_capacity [SIDE_QUANTITY_ELEMENT],
		internal_voltage_default [SIDE_QUANTITY_ELEMENT],
		type_battery [SIDE_QUANTITY_ELEMENT];

	Dl_list_push(menu, &main_screen);
	Dl_list_push(menu, &voltage_cut);
	Dl_list_push(menu, &charging_type);
	Dl_list_push(menu, &charge_threshold_Pb_lower);
	Dl_list_push(menu, &charge_threshold_Pb_upper);
	Dl_list_push(menu, &charge_threshold_others);
	Dl_list_push(menu, &discharge_threshold);
	Dl_list_push(menu, &quantity_cans);
	Dl_list_push(menu, &capacity);
	//Dl_list_push(menu, &max_allowable_capacity);
	//Dl_list_push(menu, &internal_voltage_default);
	//Dl_list_push(menu, &type_battery);

	list_cell_t 
		* head = Dl_list_head(menu),
		* tail = Dl_list_tail(menu);
	tail->prev = head;
	head->next = tail;

	set_actual_screen(head);
	/*
	ATTENTION: нельзя больше 10 элементов добавить в список.
	*/
}

void fill_with_data(void){
	char * string_with_raw_data = NULL;
	
	for (int screen_counter = main_scr;screen_counter <= type_battery; screen_counter++){
		//string_with_raw_data = get_raw_data(screen_counter);
		
		//function for push data in dl_list 
	}
}

char ** sys_info_get_main_scr(void){
	static char * main_raw_string[QUANTITY_SCREEN - 1];

	for(int num = 0; num < (QUANTITY_SCREEN-1); num++){
		main_raw_string[num] = get_raw_data(num+1);
	}

	return main_raw_string;
}

char * _get_screen_name(uint8_t number_screen){
	return str_screen_name[number_screen-1];
}

char * _get_promt(uint8_t number_screen){
	return promt_list[number_screen-1];
}

char * side_screen_string_forming(uint8_t name_screen){

	static char screen_raw[sizeof(_get_screen_name(name_screen))];

	strcpy(screen_raw, _get_screen_name(name_screen));
	strncat(screen_raw, DIVISION_CELLS, SIZEOF_DIV_CELLS);
	strncat(screen_raw, get_raw_data(name_screen), strlen(get_raw_data(name_screen)));
	strncat(screen_raw, DIVISION_CELLS,SIZEOF_DIV_CELLS);
	strncat(screen_raw, _get_promt(name_screen), strlen(_get_promt(name_screen)));

	return screen_raw;
}
char * main_screen_string_forming(void){

	static char screen_raw[sizeof(_get_screen_name(voltage_cut))];

	strcpy(screen_raw, _get_screen_name(voltage_cut));
	strncat(screen_raw, DIVISION_CELLS, SIZEOF_DIV_CELLS);
	strncat(screen_raw, get_raw_data(voltage_cut), strlen(get_raw_data(voltage_cut)));

	for(int scr_num = 2;scr_num < QUANTITY_SCREEN; scr_num++){

		strncat(screen_raw, DIVISION_CELLS, SIZEOF_DIV_CELLS);
		strncat(screen_raw, _get_screen_name(scr_num), strlen(_get_screen_name(scr_num)));
		strncat(screen_raw, DIVISION_CELLS, SIZEOF_DIV_CELLS);
		strncat(screen_raw, get_raw_data(scr_num), strlen(get_raw_data(scr_num)));	
	}
	return screen_raw;
}

list_cell_t * get_actual_screen (void){
	return actual_screen;
}
void set_actual_screen (list_cell_t * new_screen){
	actual_screen = new_screen;
}
