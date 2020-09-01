#include "unity_fixture.h"

#include "screen_internal.h"

TEST_GROUP (screen);

TEST_SETUP (screen) {

}

TEST_TEAR_DOWN (screen) {

}

TEST (screen, check_number_lines) {
	char * data = "11____222____3____4444____555";
	int num_lines = check_number_lines(data, "____");
	TEST_ASSERT_EQUAL_INT(5, num_lines);
}

// char ** create_empty_screen_obj (void) {
//     char * empty_screen[MAX_LINES_NUM];
// 	
//     for(int i = 0; i < MAX_LINES_NUM; i++) {
// 		empty_screen[i] = malloc(MAX_LINE_SIZE);
//        *empty_screen[i] = '\0';
//     }
//     return empty_screen;
// }
// 
// char ** scr_obj; // void * тоже не работает

TEST (screen, scr_constructor_screen_main) {
// 	scr_obj = create_empty_screen_obj();
//---------!!! REPEATED_CODE_START---------------
    char * scr_obj[MAX_LINES_NUM];
	
    for(int i = 0; i < MAX_LINES_NUM; i++) {
		scr_obj[i] = malloc(MAX_LINE_SIZE);
       *scr_obj[i] = '\0';
    }
//---------!!! REPEATED_CODE_END---------------
    char scr_data_main[] =
		"main\n\n4\n\nA\n\na\n\nB\n\nb\n\nC\n\nc\n\nD\n\nd";
    TEST_ASSERT_TRUE(0 == scr_constructor_screen(scr_data_main, scr_obj));
    TEST_ASSERT_EQUAL_STRING("main", scr_obj[0]);
	TEST_ASSERT_EQUAL_STRING("4", scr_obj[1]);
	TEST_ASSERT_EQUAL_STRING("A", scr_obj[2]);
	TEST_ASSERT_EQUAL_STRING("d", scr_obj[9]);
}

TEST (screen, scr_change_info_main) {
//==============================================
    //---------!!! REPEATED_CODE_START---------------
    char * scr_obj[MAX_LINES_NUM];
	
    for(int i = 0; i < MAX_LINES_NUM; i++) {
		scr_obj[i] = malloc(MAX_LINE_SIZE);
       *scr_obj[i] = '\0';
    }
//---------!!! REPEATED_CODE_END---------------
    char scr_data_main[] =
		"main\n\n4\n\nA\n\na\n\nB\n\nb\n\nC\n\nc\n\nD\n\nd";
    TEST_ASSERT_TRUE(0 == scr_constructor_screen(scr_data_main, scr_obj));
    TEST_ASSERT_EQUAL_STRING("main", scr_obj[0]);
	TEST_ASSERT_EQUAL_STRING("4", scr_obj[1]);
	TEST_ASSERT_EQUAL_STRING("A", scr_obj[2]);
	TEST_ASSERT_EQUAL_STRING("d", scr_obj[9]);
//==============================================
    
    scr_change_info(0, 0, "changed", scr_obj);
   	TEST_ASSERT_EQUAL_STRING("changed", scr_obj[2]);
	TEST_ASSERT_EQUAL_STRING("d", scr_obj[9]);
}

TEST (screen, scr_constructor_screen_side) {
//---------!!! REPEATED_CODE_START---------------
    char * scr_obj[MAX_LINES_NUM];
	
    for(int i = 0; i < MAX_LINES_NUM; i++) {
		scr_obj[i] = malloc(MAX_LINE_SIZE);
       *scr_obj[i] = '\0';
    }
//---------!!! REPEATED_CODE_END---------------
	char scr_data_side [] =
			"side\n\nheader\n\ninfo\n\nadvice";

    TEST_ASSERT_TRUE(0 == scr_constructor_screen(scr_data_side, scr_obj));
    TEST_ASSERT_EQUAL_STRING("side", scr_obj[0]);
	TEST_ASSERT_EQUAL_STRING("header", scr_obj[1]);
	TEST_ASSERT_EQUAL_STRING("info", scr_obj[2]);
	TEST_ASSERT_EQUAL_STRING("advice", scr_obj[3]);
}

TEST (screen, scr_change_info_side) {
//=============================================
//---------!!! REPEATED_CODE_START---------------
    char * scr_obj[MAX_LINES_NUM];
	
    for(int i = 0; i < MAX_LINES_NUM; i++) {
		scr_obj[i] = malloc(MAX_LINE_SIZE);
       *scr_obj[i] = '\0';
    }
//---------!!! REPEATED_CODE_END---------------
	char scr_data_side [] =
			"side\n\nheader\n\ninfo\n\nadvice";

    TEST_ASSERT_TRUE(0 == scr_constructor_screen(scr_data_side, scr_obj));
    TEST_ASSERT_EQUAL_STRING("side", scr_obj[0]);
	TEST_ASSERT_EQUAL_STRING("header", scr_obj[1]);
	TEST_ASSERT_EQUAL_STRING("info", scr_obj[2]);
	TEST_ASSERT_EQUAL_STRING("advice", scr_obj[3]);
//======================================================
    
    scr_change_info(0, 0, "new_info", scr_obj);
    TEST_ASSERT_EQUAL_STRING("side", scr_obj[0]);
	TEST_ASSERT_EQUAL_STRING("header", scr_obj[1]);
	TEST_ASSERT_EQUAL_STRING("new_info", scr_obj[2]);
	TEST_ASSERT_EQUAL_STRING("advice", scr_obj[3]);
}

TEST (screen, scr_destructor_screen) {
//---------!!! REPEATED_CODE_START---------------
    char * scr_obj[MAX_LINES_NUM];
	
    for(int i = 0; i < MAX_LINES_NUM; i++) {
		scr_obj[i] = malloc(MAX_LINE_SIZE);
       *scr_obj[i] = '\0';
    }
//---------!!! REPEATED_CODE_END---------------
    char scr_data_main[] =
		"main\n\n4\n\nA\n\na\n\nB\n\nb\n\nC\n\nc\n\nD\n\nd";
    TEST_ASSERT_TRUE(0 == scr_constructor_screen(scr_data_main, scr_obj));
    TEST_ASSERT_EQUAL_STRING("main", scr_obj[0]);
	TEST_ASSERT_EQUAL_STRING("4", scr_obj[1]);
	TEST_ASSERT_EQUAL_STRING("A", scr_obj[2]);
	TEST_ASSERT_EQUAL_STRING("d", scr_obj[9]);
//==============================================
    scr_destructor_screen(scr_obj);
//    print_table(scr_obj, 10, 2);
}
