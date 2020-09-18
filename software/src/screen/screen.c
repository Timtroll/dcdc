#include "screen_internal.h"
#include <stdlib.h>

#define GET_CELL(data_start) cell_start = data_start;               \
                             cell_end = strstr(cell_start, DLM_CH); \
                             *cell_end = '\0'; 

void scr_constructor_screen (int screen_type, int number_lines, char * input_data, void * empty_screen_obj)
{
    char data[MAX_CELL_SIZE] = {0};
    strcpy(data, input_data);
    
	char 
		* cell_start,
		* cell_end,
		* tmp;
    char ** screen_obj = (char **)empty_screen_obj;
	if(screen_type == e_main) {
		strcpy(screen_obj[0], "main");
		itoa(number_lines, screen_obj[1]);
        if(!number_lines) return;
	    else GET_CELL(data)
        int i;
        strcpy(screen_obj[2], cell_start);
		for(i = 3; i < 2*number_lines + 1; i++) {
            GET_CELL(cell_end + 2)
            strcpy(screen_obj[i], cell_start);
		}
		cell_start = cell_end + 2;
		strcpy(screen_obj[i], cell_start);
        
	} else if(screen_type == e_side) {
        strcpy(screen_obj[0], "side");
        GET_CELL(data)
        strcpy(screen_obj[1], cell_start);
        GET_CELL(cell_end + 2)
        strcpy(screen_obj[2], cell_start);
		cell_start = cell_end + 2;
		strcpy(screen_obj[3], cell_start);
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
