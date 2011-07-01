# Bloom Filter in C++

A simple Bloom filter implementation in C++. Tested using Google Test.

## Usage

Dependencies:

 * POSIX system with `/usr/share/dict/words`
 * C++ compiler (see Makefile if other than g++)
 * Google Test (see Makefile vars `DIR_GTEST` and `LINK_LIBS` to set up
   proper paths for your system (on OS X with Homebrew, simply run
   `brew install gtest`))

Clone the repository and run `make` to compile and run the tests.
Refer to the tests `src/*Test.cpp` for examples on how to use the filter.

## Time

 * June 16, 30 mins, setting up gtest and compiling a simple file
 * June 29, 2-3 hours, first version, seems to work (need to add tests,
   fix Makefile, refactor, ...)
 * June 29 again, 30 min, Makefile and refactor
 * July 1, 30 min, started looking at gtest, added print function
 * July 1 again, 2 hours, learning gtest and writing tests
