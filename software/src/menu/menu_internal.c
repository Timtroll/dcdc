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
	// Set_raw_data(get_sys_info, main_scr);
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

static char * _main_screen [MAIN_QUANTITY_ELEMENT];
static char
	* _voltage_cut [SIDE_QUANTITY_ELEMENT],
	* _charging_type [SIDE_QUANTITY_ELEMENT],
	* _charge_threshold_Pb_lower [SIDE_QUANTITY_ELEMENT],
	* _charge_threshold_Pb_upper [SIDE_QUANTITY_ELEMENT],
	* _charge_threshold_others [SIDE_QUANTITY_ELEMENT],
	* _discharge_threshold [SIDE_QUANTITY_ELEMENT],
	* _quantity_cans [SIDE_QUANTITY_ELEMENT],
	* _capacity [SIDE_QUANTITY_ELEMENT],
	* _max_allowable_capacity [SIDE_QUANTITY_ELEMENT],
	* _internal_voltage_default [SIDE_QUANTITY_ELEMENT],
	* _type_battery [SIDE_QUANTITY_ELEMENT];

void menu_create(void){
	dl_list_group_create();
	menu = dl_list_create(sizeof(char * [MAIN_QUANTITY_ELEMENT]));

	Dl_list_push(menu, _main_screen);
	Dl_list_push(menu, _voltage_cut);
	Dl_list_push(menu, _charging_type);
	Dl_list_push(menu, _charge_threshold_Pb_lower);
	Dl_list_push(menu, _charge_threshold_Pb_upper);
	Dl_list_push(menu, _charge_threshold_others);
	Dl_list_push(menu, _discharge_threshold);
	Dl_list_push(menu, _quantity_cans);
	Dl_list_push(menu, _capacity);
	Dl_list_push(menu, _max_allowable_capacity);
	Dl_list_push(menu, _internal_voltage_default);
	Dl_list_push(menu, _type_battery);

	list_cell_t 
		* head = Dl_list_head(menu),
		* tail = Dl_list_tail(menu);
	tail->prev = head;
	head->next = tail;

	set_actual_screen(head);

	printf("menu_create_addr: %p\n", menu);
}

void fill_with_data(void){
	char * string_with_raw_data = NULL;
	
	for (int screen_counter = main_scr;screen_counter <= type_battery; screen_counter++){
		//string_with_raw_data = get_raw_data(screen_counter);
		
		//function for push data in dl_list 
	}
}


list_cell_t * get_actual_screen (void){
	return actual_screen;
}
void set_actual_screen (list_cell_t * new_screen){
	actual_screen = new_screen;
}



char ** get_raw_data_list(void){
	static char * main_raw_string[QUANTITY_SCREEN - 1];

	for(int num = 0; num < (QUANTITY_SCREEN-1); num++){
		main_raw_string[num] = get_raw_data(num+1);
	}

	return main_raw_string;
}

char ** get_screen_name_list(void){
	return str_screen_name;
}

char ** get_promt_list(void){
	return promt_list;
}

