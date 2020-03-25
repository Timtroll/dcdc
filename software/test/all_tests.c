/*
 * Copyright © 2019-2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#include "unity_fixture.h"

static void run_all_tests (void) {
    RUN_TEST_GROUP(parser);
    RUN_TEST_GROUP(find_cmd);
}

int main(int argc, const char * argv [])
{
    return UnityMain(argc, argv, run_all_tests);
}
