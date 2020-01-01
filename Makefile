#
# @Author: Jxtopher
# @License: *
# @Date: 2018-10
# @Version: 1
# @Description: Makefile
#

CC = g++
CFLAGS = -std=c++0x -Wall
OFLAGS = -Os # Optimization flags
GFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused # -Wshadow
OSX_GFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused # -Wshadow
DFLAGS = -DDEBUG
FLAGS = $(CFLAGS) $(OFLAGS) $(GFLAGS) $(DFLAGS)
OSX_FLAGS = $(CFLAGS) $(OFLAGS) $(OSX_GFLAGS) $(DFLAGS)
EXEC_NAME = mini-solver

#INCLUDES =
#LIBS =
#OBJ_FILES = fichier_1.o fichier_2.o
#INSTALL_DIR = /usr/bin
#SOURCES_DIR = ./sources/

#all : $(EXEC_NAME)

#$(EXEC_NAME): $(SOURCES_DIR)main.cpp
all : ./sources/main.cpp
	$(CC) $(FLAGS) $< -o $(EXEC_NAME)

build-osx : ./sources/main.cpp
	$(CC) $(OSX_FLAGS) $< -o $(EXEC_NAME)

run:
	./$(EXEC_NAME)

packages-debian:
	apt-get install g++ build-essential

unit-test: ./unitTesting/main.cpp
	$(CC) $(FLAGS) $< -o $(EXEC_NAME)_unitTest
	./$(EXEC_NAME)_unitTest

unit-test-osx: ./unitTesting/main.cpp
	$(CC) $(OSX_FLAGS) $< -o $(EXEC_NAME)_unitTest
	./$(EXEC_NAME)_unitTest

.PHONY: clean

clean:
	rm $(EXEC_NAME)

mrproper:
	rm $(EXEC_NAME) *.o
