#include "unity_fixture.h"
#include "screen_internal.h"

TEST_GROUP (screen);

TEST_SETUP (screen) {
    
}

TEST_TEAR_DOWN (screen) {
    
}

#define CREATE_EMPTY_SCREEN_OBJECT \
    char ** scr_obj; \
    scr_obj = create_empty_screen_obj();

TEST (screen, scr_constructor_screen_main) {
    CREATE_EMPTY_SCREEN_OBJECT

    char scr_data_main[] =
		"A\n\na\n\nB\n\nb\n\nC\n\nc\n\nD\n\nd";
    
    scr_constructor_screen(e_main, 4, scr_data_main, scr_obj);
    
    TEST_ASSERT_EQUAL_STRING("main", scr_obj[0]);
	TEST_ASSERT_EQUAL_STRING("4", scr_obj[1]);
	TEST_ASSERT_EQUAL_STRING("A", scr_obj[2]);
	TEST_ASSERT_EQUAL_STRING("d", scr_obj[9]);
    
    free_screen_obj(scr_obj);
}

TEST (screen, scr_change_info_main) {
    CREATE_EMPTY_SCREEN_OBJECT

    char scr_data_main[] =
		"A\n\na\n\nB\n\nb\n\nC\n\nc\n\nD\n\nd";
    scr_constructor_screen(e_main, 4, scr_data_main, scr_obj);
    
    scr_change_info(0, 0, "changed", scr_obj);
    scr_change_info(1, 1, "changed", scr_obj);
    scr_change_info(3, 1, "changed", scr_obj);

    TEST_ASSERT_EQUAL_STRING("main", scr_obj[0]);
    TEST_ASSERT_EQUAL_STRING("4", scr_obj[1]);
    TEST_ASSERT_EQUAL_STRING("changed", scr_obj[2]);
    TEST_ASSERT_EQUAL_STRING("a", scr_obj[3]);
    TEST_ASSERT_EQUAL_STRING("B", scr_obj[4]);
    TEST_ASSERT_EQUAL_STRING("changed", scr_obj[5]);
    TEST_ASSERT_EQUAL_STRING("C", scr_obj[6]);
    TEST_ASSERT_EQUAL_STRING("c", scr_obj[7]);
    TEST_ASSERT_EQUAL_STRING("D", scr_obj[8]);
    TEST_ASSERT_EQUAL_STRING("changed", scr_obj[9]);
}

TEST (screen, scr_constructor_screen_side) {
    CREATE_EMPTY_SCREEN_OBJECT

	char scr_data_side[] =
			"header\n\ninfo\n\nadvice";

    scr_constructor_screen(e_side, 0, scr_data_side, scr_obj);
    
    TEST_ASSERT_EQUAL_STRING("side", scr_obj[0]);
	TEST_ASSERT_EQUAL_STRING("header", scr_obj[1]);
	TEST_ASSERT_EQUAL_STRING("info", scr_obj[2]);
	TEST_ASSERT_EQUAL_STRING("advice", scr_obj[3]);
}

TEST (screen, scr_change_info_side) {
    CREATE_EMPTY_SCREEN_OBJECT
	char scr_data_side[] =
			"header\n\ninfo\n\nadvice";

    scr_constructor_screen(e_side, 0, scr_data_side, scr_obj);

    scr_change_info(0, 2, "new_info", scr_obj);

    TEST_ASSERT_EQUAL_STRING("side", scr_obj[0]);
	TEST_ASSERT_EQUAL_STRING("header", scr_obj[1]);
	TEST_ASSERT_EQUAL_STRING("new_info", scr_obj[2]);
	TEST_ASSERT_EQUAL_STRING("advice", scr_obj[3]);
}

TEST (screen, scr_destructor_screen) {
    CREATE_EMPTY_SCREEN_OBJECT
    char scr_data_main[] =
		"A\n\na\n\nB\n\nb\n\nC\n\nc\n\nD\n\nd";
    scr_constructor_screen(e_main, 4, scr_data_main, scr_obj);

    scr_destructor_screen(scr_obj);

    TEST_ASSERT_EQUAL_STRING("", scr_obj[0]);
    TEST_ASSERT_EQUAL_STRING("", scr_obj[1]);
    TEST_ASSERT_EQUAL_STRING("", scr_obj[2]);
    TEST_ASSERT_EQUAL_STRING("", scr_obj[9]);
}
