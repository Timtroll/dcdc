#include "screen_internal.h"

/* K&R's itoa */
 void reverse(char s[])
 {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }

 void itoa(int n, char s[])
 {
     int i, sign;
 
     if ((sign = n) < 0)
         n = -n;
     i = 0;
     do {  
         s[i++] = n % 10 + '0'; 
     } while ((n /= 10) > 0);
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }

//==================_FOR_TESTS_=======================

char ** create_empty_screen_obj(void) {
    char ** scr_obj;
    scr_obj = malloc(MAX_CELLS_NUM * sizeof(char **));
    
    for(int i = 0; i < MAX_CELLS_NUM; i++) {
        scr_obj[i] = malloc(MAX_CELL_SIZE);
       *scr_obj[i] = '\0';
    }
    return scr_obj;
}

void free_screen_obj(void * scr_obj) {
    for(int i = 0; i < MAX_CELLS_NUM; i++) {
        free(((char **)scr_obj)[i]);
    }
    free(scr_obj);
} 
