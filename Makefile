######################################################################
# @author      : stantenik (stantenik@stantenik-G1S)
# @file        : Makefile
# @created     : dimanche mai 19, 2024 15:25:16 CEST
######################################################################

APP_NAME := Connect5
CC := g++

# DETECT PLATFORM
ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif


# VARIABLE PATH
DSRC := src
DBIN := bin
DOBJ := $(DBIN)/obj

INC := -Iinclude
LIBS := -lncurses

CFLAGS := -Wall -g -std=c++11

SRCS := $(shell find $(DSRC) -type f -name '*.cpp')

ifeq ($(detected_OS), Windows)
	INC += -IC:\MinGW\include\ncurses
	LIBS += -LC:\MinGW\lib
endif

.PHONY: all clean run

TARGET := $(DBIN)/$(APP_NAME)

run: $(TARGET)
	$(TARGET)

$(TARGET): $(DBIN)
	$(CC) -o $@ $(SRCS) $(CFLAGS) $(INC) $(LIBS) 

$(DBIN):
	mkdir -p $(DBIN)

clean:
	rm $(TARGET)
