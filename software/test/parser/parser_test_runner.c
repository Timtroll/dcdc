/*
 * Copyright © 2019-2020 Feodor A. Alexandrov (feodor.alexandrov@yandex.ru)
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3. See the file LICENSE in the top level
 * directory for more details.
 */

#include "unity_fixture.h"

TEST_GROUP_RUNNER (parser) {
	RUN_TEST_CASE (parser,
		create_store_command_dbase_correctly);
	RUN_TEST_CASE (parser,
		create_store_max_pattern_len_correctly);
	RUN_TEST_CASE (parser,
		delete_clear_command_dbase);
	RUN_TEST_CASE (parser,
		delete_clear_pettern_max_len_correctly);
    RUN_TEST_CASE (parser,
    	_parser_return_stub_response_if_cmd_dbase_empty);
    RUN_TEST_CASE (parser,
    	_parser_return_stub_action_if_cmd_dbase_empty);

    RUN_TEST_CASE (parser,
    	parse_install_correct_RESPONSE_if_cmd_found);
    RUN_TEST_CASE (parser,
    	parse_install_correct_ACTION_if_cmd_found);
    RUN_TEST_CASE (parser,
    	parse_install_stub_RESPONSE_if_cmd_found_with_empty_response);
    RUN_TEST_CASE (parser,
    	parse_install_stub_ACTION_if_cmd_found_with_empty_action);

    RUN_TEST_CASE (parser,
    	parse_install_stub_RESPONSE_if_cmd_NOT_found);
    RUN_TEST_CASE (parser,
    	parse_install_stub_ACTION_if_cmd_NOT_found);
}
