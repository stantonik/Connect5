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

.PHONY: all clean run

run: $(TARGET)
	$(TARGET)

$(TARGET): $(DBIN)
	$(CC) -o $@ $(SRCS) $(CFLAGS) $(INC) $(LIBS) 

$(DBIN):
	mkdir -p $(DBIN)

clean:
	rm $(TARGET)
