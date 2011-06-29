CC = g++
EXE = bloom
GTEST = -I/usr/local/Cellar/gtest/1.5.0/include/gtest
WARN = -Wall -Wextra -ansi -pedantic -Wnewline-eof
OPTIMIZE = -O3

BIN = bin
BUILD = build
SRC = src
INCLUDE = include

all:
	@ clear
	rm -f $(BIN)/$(EXE)
	$(CC) -o $(BIN)/$(EXE) $(SRC)/*.c* $(WARN) $(OPTIMIZE) $(GTEST) -I$(INCLUDE)
	@ echo "--- Running $(BIN)/$(EXE) ---"
	@ $(BIN)/$(EXE)
