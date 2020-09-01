#include "screen_internal.h"

#define GET_CELL(data_start) cell_start = data_start;                     \
                             cell_end = strstr(cell_start, DLM_CH); \
                             *cell_end = '\0'; 
enum {ALL_RIGHT, ERROR};

int scr_constructor_screen (char * input_data, char ** screen_obj)
{
    char data[MAX_LINE_SIZE] = {0};
    strcpy(data, input_data);
    
	char 
		* cell_start,
		* cell_end,
		* tmp;
	int number_lines;
    
	GET_CELL(data)
	if(!strcmp(data, "main")) {
		strcpy(screen_obj[0], data);
        
		GET_CELL(cell_end + 2)
		number_lines = atoi(cell_start);
        if(number_lines*2 + 2 != check_number_lines(input_data, DLM_CH)){
            return ERROR;
        }
		strcpy(screen_obj[1], cell_start);
        
		int i;
		for(i = 2; i < 2*number_lines + 1; i++) {
			GET_CELL(cell_end + 2)
			strcpy(screen_obj[i], cell_start);
		}
		cell_start = cell_end + 2;
		strcpy(screen_obj[i], cell_start);
        
	} else if(!strcmp(data, "side")) {
        if(check_number_lines(input_data, DLM_CH) != 4)
            return ERROR;
        strcpy(screen_obj[0], data);
        int i;
		for(i = 1; i < 3; i++) {
			GET_CELL(cell_end + 2)
			strcpy(screen_obj[i], cell_start);
		}
		cell_start = cell_end + 2;
		strcpy(screen_obj[i], cell_start);
        
	} else {return ERROR;}

	return ALL_RIGHT;
}

#define ROWS_NUM 2
void scr_change_info (int line, int row, char * data, char ** screen_obj) {
    if(strcmp(screen_obj[0], "main") == 0) {
    strcpy(
        screen_obj[line*ROWS_NUM + 2 + row],
        data);        
    }
    else if(strcmp(screen_obj[0], "side") == 0) {
        strcpy(screen_obj[2], data); 
    }
    else {
//         SCREEN_ERROR
        puts("ERROOOR");
    }
}

void scr_destructor_screen(char ** screen_obj) {
    for(int i = 0; i < MAX_LINES_NUM; i++) {
        *screen_obj[i] = '\0';
    }
}

//=========================================================
#include <stdio.h>

void print_spaces (int num)
{
	for(int i = 0; i < num; i++)
		printf(" ");
	printf(" ");
}

void print_table (char ** arr, int num_lines, int num_rows) 
{
	int 
		length	= 0,
		max_len = 4, // NULL, '\0'
		size = num_lines * num_rows;
	
	for(int i = 0; i < size; i++) {
		if(arr[i]) {
			length = strlen(arr[i]);
			if(length > max_len)
				max_len = length;
		}
	}
	for(int i = 0; i < size; i++) {
		if(arr[i]) {
			length = strlen(arr[i]);
			if(length) {
				printf("%s", arr[i]);
				print_spaces(max_len-length + 1);
			}
			else {
				printf("\'\\0\'");
				print_spaces(max_len-4 + 1);
			}
		}
		else {
			printf("NULL");
			print_spaces(max_len-4 + 1);
		}
		if( !((i+1) % num_rows) )
			printf("\n");
	}
}
