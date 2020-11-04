#include "unity_fixture.h"

#include "measurements_internal.h"

TEST_GROUP (measurements);

TEST_SETUP (measurements) {

}

TEST_TEAR_DOWN (measurements) {

}

TEST (measurements, calc_charge) {
	float input[] = {1, 2, 3, 4, 5};

	TEST_ASSERT_TRUE(calc_charge(input, 5) == 15);

}


TEST (measurements, calc_discharge_time) {
	float input[] = {1, 2, 3, 4, 5};

	int time;
	time = calc_charge(input, 5);

	TEST_ASSERT_TRUE(time == 15/10);
	
}