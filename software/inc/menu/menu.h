#ifndef _MENU_H_
#define _MENU_H_


#include <stdint.h>

/*тут функция создающая всё меню
свайпы
получения актуального экрана
изменение информации в экранах
*/

void create_menu(void);
uint8_t menu_get_actual_screen(void);
void menu_swipe_right(void);
void menu_swipe_left(void);

#endif//_MENU_H_

