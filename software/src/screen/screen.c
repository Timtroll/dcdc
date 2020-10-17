#include "screen_internal.h"
#include <stdlib.h>

void scr_constructor_screen (
    int screen_type, 
    int number_lines, 
    char ** field_name,
    char ** value,
    char ** hint, 
    void * empty_screen_obj
) {
    char ** screen_obj = (char **)empty_screen_obj;
	if(screen_type == e_main/*screen_type == 0*/) {
		strcpy(screen_obj[0], "main");
		num_to_str(number_lines, screen_obj[1]);
        
		for(int i = 0; i < number_lines; i++) {
            strcpy(screen_obj[2*i+2], field_name[i]);
            strcpy(screen_obj[2*i+3], value[i]);
		}
	} else/*screen_type == 1...N*/{ 
        strcpy(screen_obj[0], "side");
        strcpy(screen_obj[1], field_name[screen_type-1]);
        strcpy(screen_obj[2], value[screen_type-1]);
		strcpy(screen_obj[3], hint[screen_type-1]);
	}
}

#define ROWS_NUM 2
void scr_change_info (int line, int row, char * data, void * screen_obj) {
    if(strcmp(( (char **)screen_obj )[0], "main") == 0) {
    strcpy(
        ( (char **)screen_obj )[line*ROWS_NUM + 2 + row],
        data);        
    }
    else if(strcmp(( (char **)screen_obj )[0], "side") == 0) {
        strcpy(( (char **)screen_obj )[2], data); 
    }
}

void scr_destructor_screen(void * screen_obj) {
    for(int i = 0; i < MAX_CELLS_NUM; i++) {
        *( (char **)screen_obj )[i] = '\0';
    }
}
