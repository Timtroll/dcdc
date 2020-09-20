#include "menu_internal.h"

void menu_swipe_right(void){
	_menu_init();
}

void menu_swipe_left(void){
	_menu_init();
	set_actual_screen(get_actual_screen()->prev);
}

void * menu_get_actual_screen(void){
	_menu_init();
	return get_actual_screen()->data;
}

void menu_set_info(char * new_data){
	_menu_init();
	
}

void _menu_init(void){

	static uint8_t init_passed = 0;
	if ( init_passed == 0)
	{
		menu_create();
		init_function();
		fill_with_data();
		init_passed = 1;
	}
	//static list_cell_t * actual_screen = Dl_list_head(menu);
	//this func will monitor important
	// functions about init menu:
	// 1)dl_list create
	// 2) fill dl_list 

	//work with help static variable(flags)
	// which show status INIT/DEINIT 

}
