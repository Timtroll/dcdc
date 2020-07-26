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
    RUN_TEST_GROUP(charger);
    RUN_TEST_GROUP(static_malloc);
    RUN_TEST_GROUP(navigation);
    RUN_TEST_GROUP(linked_list);
    RUN_TEST_GROUP(dl_list);
}

int main(int argc, const char * argv [])
{
    return UnityMain(argc, argv, run_all_tests);
}
