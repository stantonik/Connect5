######################################################################
# @author      : stantenik (stantenik@stantenik-G1S)
# @file        : Makefile
# @created     : dimanche mai 19, 2024 15:25:16 CEST
######################################################################

run:
	g++ src/*.cpp src/gui/*.cpp -o bin/Connect5 -Iinclude -Isrc/gui -Isrc -lncurses -std=c++17
