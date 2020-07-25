#include "menu_internal.h"

/* здесь создается список экранов
1. Создается голова
2. Создается ячейка : главный экран, с использованием функций из screen.h
	данные для заполнения берутся из блока system_info
	они заносятся в двумерный массив из char.
	Слева название параметра, справа значение, которое ему соответсвтует
	Размер [QUANTITY_STRING_MAIN_SCREEN][2]
	После создания экрана, массив обнуляется
	
	Далее ячейка вставляется в начало списка

3. Создается ячейка : побочный экран
	Для этого заполняется одномерный массив размером [QUANTITY_STRING_SIDE_SCREEN], 
	скорее всего он равен 3
	Первая строка название экрана, вторая строка значенение из SYY_INFO ему соответствующее
	и третья это справка

	Далее ячейка вставляется за главным экраном
	и все остальные экраны встают друг за другом

Под данные(экран) выделяется malloc'ом, а потом уже указатель начинает указывть на значение ф-ии конструктора экранов


*/

void create_menu(void){

	Create_list(list);

}



uint8_t menu_get_actual_screen(void){
	
	cell_t * screen_current = NULL;
	actual_cell(&screen_current, RETURN);

	if (screen_current == get_main_screen())
	{
		return MAIN_SCREEN;
	}
	else if (screen_current != get_main_screen())
	{
		return SIDE_SCREEN;
	}
}


void menu_swipe_right(void){

	cell_t * screen_current = NULL;
	actual_cell(&screen_current, RETURN);
	printf("1:%x\n\n\n", screen_current);
	printf("2:%x\n\n\n", screen_current->front);
	printf("3:%x\n\n\n", screen_current->behind);
	actual_cell(screen_current->behind, SAVE);
	//printf("\n\n\n\n%p\n\n\n", screen_current->behind);

	
}


void menu_swipe_left(void){

	cell_t * screen_current = NULL;
	actual_cell(&screen_current, RETURN);
	/*printf("1:%x\n\n\n", screen_current);
	printf("2:%x\n\n\n", screen_current->front);
	printf("3:%x\n\n\n", screen_current->behind);*/
	actual_cell(screen_current->front, SAVE);

	
}

