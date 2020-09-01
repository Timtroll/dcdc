#include "screen_internal.h"

int check_number_lines(char * data, char * delimiter_character) {
    char
		* cell_start,
		* cell_end;
	int number_lines = 0;
	int dlm_length = strlen(delimiter_character);
    if(!data) return 0;
    cell_start = data;
    while(cell_end = strstr(cell_start, delimiter_character)) {
        cell_start = cell_end + dlm_length;
        ++number_lines;
    }
    return ++number_lines;
}
