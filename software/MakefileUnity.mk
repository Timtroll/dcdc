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
	$(PROJECT_HOME_DIR)/src/find \
	$(PROJECT_HOME_DIR)/src/parser \

TEST_SRC_DIRS = \
	$(PROJECT_TEST_DIR) \
	$(PROJECT_TEST_DIR)/find \
	$(PROJECT_TEST_DIR)/parser \
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
	$(PROJECT_HOME_DIR)/inc/find \
	$(PROJECT_HOME_DIR)/inc/parser \

include $(UNITY_BUILD_HOME)/MakefileWorker.mk
