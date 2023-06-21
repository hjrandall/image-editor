SRC_ROOT_DIR := $(shell dirname $(shell pwd))
REPO_DIR_NAME := $(shell basename $(shell dirname $(shell pwd)))
UNIT_TEST_DIR_NAME := $(shell dirname $(shell dirname $(shell pwd)))/dsu-cs-3005-unit-tests-2022-20

all:

unit-test-%:
	SRC_ROOT_DIR=$(SRC_ROOT_DIR) UNIT_TEST_WORKING_DIR=$(REPO_DIR_NAME)/$* make -C $(UNIT_TEST_DIR_NAME) $@

clean-test-%:
	SRC_ROOT_DIR=$(SRC_ROOT_DIR) UNIT_TEST_WORKING_DIR=$(REPO_DIR_NAME)/$* make -C $(UNIT_TEST_DIR_NAME) spotless
