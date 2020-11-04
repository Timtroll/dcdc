#include "unity_fixture.h"

TEST_GROUP_RUNNER (measurements) {
	RUN_TEST_CASE (measurements, calc_charge);
	RUN_TEST_CASE (measurements, calc_discharge_time);
}

