#include "system_info_internal.h"

void save_to_queue(parser_memory struct_to_save){
	//here will be code, when adress of queue is known
}

char * sys_info_get_voltage_cut(void){
	return "voltage_cut";
}
char * sys_info_get_charging_type(void){
	return "charging_type";
}
char * sys_info_get_charge_threshold_Pb_lower(void){
	return "charge_threshold_Pb_lower";
}
char * sys_info_get_charge_threshold_Pb_upper(void){
	return "charge_threshold_Pb_upper";
}
char * sys_info_get_charge_threshold_others(void){
	return "charge_threshold_others";
}
char * sys_info_get_discharge_threshold(void){
	return "discharge_threshold";
}
char * sys_info_get_quantity_cans(void){
	return "quantity_cans";
}
char * sys_info_get_capacity(void){
	return "capacity";
}
char * sys_info_get_max_allowable_capacity(void){
	return "max_allowable_capacity";
}
char * sys_info_get_internal_voltage_default(void){
	return "internal_voltage_default";
}
char * sys_info_get_type_battery(void){
	return "type_battery";
} 