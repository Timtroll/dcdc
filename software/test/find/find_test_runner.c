#include "unity_fixture.h"

TEST_GROUP_RUNNER (find_cmd) {
	RUN_TEST_CASE (find_cmd,
		extract_pattern_return_empty_string_if_len_owerflows);
	RUN_TEST_CASE (find_cmd,
		extract_pattern_return_null_if_cmd_len_bigger_than_msg_len);
	// RUN_TEST_CASE (find_cmd,
	// 	extract_pattern_return_empty_string_if_extracting_BEFORE_msg);
	RUN_TEST_CASE (find_cmd,
		extract_pattern_return_empty_string_if_extracting_AFTER_msg);

	RUN_TEST_CASE (find_cmd,
		extract_pattern_return_pattern_if_len_valid);
	RUN_TEST_CASE (find_cmd,
		recursive_handling_model);
	RUN_TEST_CASE (find_cmd,
		dbase_table_find_return_null_if_not_found);
	RUN_TEST_CASE (find_cmd,
		dbase_table_find_return_correct_record_in_not_nested_table);

	RUN_TEST_CASE (find_cmd,
		free_spaces_handle_str_started_with_space_and_tabs);
	RUN_TEST_CASE (find_cmd,
		free_spaces_handle_str_started_with_no_space_no_tabs);

	RUN_TEST_CASE (find_cmd,
		dbase_table_find_return_null_command_if_command_not_full);
	RUN_TEST_CASE (find_cmd,
		dbase_table_find_return_null_if_incorrect_command);
	RUN_TEST_CASE (find_cmd,
		dbase_table_find_return_correct_record_in_two_tables);
	RUN_TEST_CASE (find_cmd,
		dbase_table_find_return_correct_record_in_nested_tables);
	RUN_TEST_CASE (find_cmd,
		set_parameter_if_message_continue_without_subcommand);
}