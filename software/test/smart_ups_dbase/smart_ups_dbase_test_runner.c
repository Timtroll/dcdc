/*
 * Copyright © 2019-2020 Daniil D. Ryabinin (ryabiko1953@gmail.com)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

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