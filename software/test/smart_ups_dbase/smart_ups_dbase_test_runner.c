
#include "unity_fixture.h"

TEST_GROUP_RUNNER(charger){
	RUN_TEST_CASE(charger, 
		right_extract_of_set_command);
	RUN_TEST_CASE(charger, 
		right_extract_of_get_command);
	RUN_TEST_CASE(charger, 
		right_work_with_structure);
	RUN_TEST_CASE(charger,
		right_getting);
}