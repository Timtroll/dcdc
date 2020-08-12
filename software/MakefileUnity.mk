#Set this to @ to keep the makefile quiet

SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = software_unity

#--- Inputs ----#
UNITY_HOME = ../tdd_creator/Unity
CPP_PLATFORM = Gcc
PROJECT_HOME_DIR = .
PROJECT_TEST_DIR = test
UNITY_BUILD_HOME = ../tdd_creator

UNITY_CFLAGS += -Wno-missing-prototypes
UNITY_WARNINGFLAGS = -Wall
UNITY_WARNINGFLAGS = -Werror
UNITY_WARNINGFLAGS = -Wswitch-default
#UNITY_WARNINGFLAGS += -Wshadow
SRC_DIRS = \
	$(PROJECT_HOME_DIR)/src/ \
	$(PROJECT_HOME_DIR)/src/display \
	$(PROJECT_HOME_DIR)/src/json_parser \
	$(PROJECT_HOME_DIR)/src/uart_data_transfer \
	$(PROJECT_HOME_DIR)/src/dl_list \
	$(PROJECT_HOME_DIR)/src/static_malloc \
	$(PROJECT_HOME_DIR)/src/menu \
	$(PROJECT_HOME_DIR)/src/system_info \
	$(PROJECT_HOME_DIR)/src/measurements \
	$(PROJECT_HOME_DIR)/src/system_config \
	$(PROJECT_HOME_DIR)/src/find \
	$(PROJECT_HOME_DIR)/src/parser \

TEST_SRC_DIRS = \
	$(PROJECT_TEST_DIR) \
	$(PROJECT_TEST_DIR)/display \
	$(PROJECT_TEST_DIR)/json_parser \
	$(PROJECT_TEST_DIR)/uart_data_transfer \
	$(PROJECT_TEST_DIR)/dl_list \
	$(PROJECT_TEST_DIR)/static_malloc \
	$(PROJECT_TEST_DIR)/menu \
	$(PROJECT_TEST_DIR)/system_info \
	$(PROJECT_TEST_DIR)/measurements \
	$(PROJECT_TEST_DIR)/system_config \
	$(PROJECT_TEST_DIR)/find \
	$(PROJECT_TEST_DIR)/parser \
	$(PROJECT_TEST_DIR)/smart_ups_dbase/ \
	$(UNITY_HOME)/unity \
	$(UNITY_HOME)/src \
	$(UNITY_HOME)/extras/memory/src/ \
	$(UNITY_HOME)/extras/fixture/src \
	$(UNITY_HOME)/extras/fixture/test \

INCLUDE_DIRS = \
	. \
	$(UNITY_HOME)/src \
	$(UNITY_HOME)/extras/memory/src/ \
	$(UNITY_HOME)/extras/fixture/src \
	$(UNITY_HOME)/extras/fixture/test \
	$(PROJECT_HOME_DIR)/inc/ \
	$(PROJECT_HOME_DIR)/inc/display \
	$(PROJECT_HOME_DIR)/inc/json_parser \
	$(PROJECT_HOME_DIR)/inc/uart_data_transfer \
	$(PROJECT_HOME_DIR)/inc/dl_list \
	$(PROJECT_HOME_DIR)/inc/static_malloc \
	$(PROJECT_HOME_DIR)/inc/menu \
	$(PROJECT_HOME_DIR)/inc/system_info \
	$(PROJECT_HOME_DIR)/inc/measurements \
	$(PROJECT_HOME_DIR)/inc/system_config \
	$(PROJECT_HOME_DIR)/inc/find \
	$(PROJECT_HOME_DIR)/inc/parser \

include $(UNITY_BUILD_HOME)/MakefileWorker.mk
