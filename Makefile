######################################################################
# @author      : stantenik (stantenik@stantenik-G1S)
# @file        : Makefile
# @created     : dimanche mai 19, 2024 15:25:16 CEST
######################################################################

APP_NAME := Connect5
CC := g++

# VARIABLE PATH
DSRC := src
DBIN := bin
DOBJ := $(DBIN)/obj

INC := -Iinclude
LIBS := -lncurses

CFLAGS := -Wall -g -std=c++11

# DETECT PLATFORM
ifeq ($(OS),Windows_NT)
	INC += -IC:\MinGW\include\ncurses
	LIBS += -LC:\MinGW\lib
	SRCS := $(shell where /r $(DSRC) *.cpp)
	TARGET := $(DBIN)\$(APP_NAME).exe
	DOBJ := $(DBIN)\obj
else
	SRCS := $(shell find $(DSRC) -type f -name '*.cpp')
	TARGET := $(DBIN)/$(APP_NAME)
endif

# Exclude main.cpp for the debug target
TEST_SRCS := $(filter-out $(DSRC)/main.cpp, $(SRCS))

# Criterion Library Flags
CRIT_INC := -I/usr/local/include
CRIT_LIB := -L/usr/local/lib -lcriterion

# Test sources
TSRC := $(shell find tests -type f -name '*.cpp')

.PHONY: all clean run debug

all: $(TARGET)

run: $(TARGET)
	$(TARGET)

$(TARGET): $(DBIN)
	$(CC) -o $@ $(SRCS) $(CFLAGS) $(INC) $(LIBS) 

$(DBIN):
	mkdir -p $(DBIN)

debug: $(DBIN)/$(APP_NAME)_test

$(DBIN)/$(APP_NAME)_test: $(DBIN)
	$(CC) -o $@ $(TEST_SRCS) $(TSRC) $(CFLAGS) $(INC) $(CRIT_INC) $(LIBS) $(CRIT_LIB)

clean:
	rm -f $(TARGET) $(DBIN)/$(APP_NAME)_test
