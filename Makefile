DIR_BIN   = bin
DIR_BUILD = build
DIR_LIB   = lib
DIR_SRC   = src

DIR_GTEST         = /usr/local/Cellar/gtest/1.5.0
DIR_GTEST_INCLUDE = $(DIR_GTEST)/include/gtest
DIR_GTEST_LIB     = $(DIR_GTEST)/lib

EXE = $(DIR_BIN)/bloom

CC        = g++
LINK_LIBS = $(DIR_GTEST_LIB)/libgtest.dylib
WARN      = -Wall -Wextra -ansi -pedantic
OPTIMIZE  = -O3

# src/file1.c src/file2.c ...
SOURCES = $(wildcard $(DIR_SRC)/*.cpp)
# lib/file1.h lib/file2.h ...
HEADERS = $(wildcard $(DIR_LIB)/*.h)
# src/file1 src/file2 ...
BASENAMES = $(basename $(SOURCES))
# build/file1.o build/file2.o ...
OBJECTS = $(BASENAMES:$(DIR_SRC)/%=$(DIR_BUILD)/%.o)

all: build test

build: setup trim $(EXE)

setup:
	mkdir -p $(DIR_BIN)
	mkdir -p $(DIR_BUILD)

clean: trim
	rm -rf $(DIR_BIN)/* $(DIR_BUILD)/*

trim:
	@- trim $(DIR_SRC)/*.* $(DIR_LIB)/*.*
	clear

run:
	@- echo '--- Running $(EXE) ...'
	$(EXE)

test:
	@- echo '--- Testing $(EXE) ...'
	$(EXE) test

# Build object from source (depends on own def. and ALL .h files (easiest)).
$(DIR_BUILD)/%.o: $(DIR_SRC)/%.cpp $(HEADERS) Makefile
	@- echo '--- Compiling $< ...'
	$(CC) -o $@ -c $< $(WARN) $(OPTIMIZE) -I$(DIR_LIB) -I$(DIR_GTEST_INCLUDE)

# Build executable from all objects.
$(EXE): $(OBJECTS)
	@- echo '--- Linking $@ ...'
	$(CC) -o $@ $(OBJECTS) $(LINK_LIBS)
