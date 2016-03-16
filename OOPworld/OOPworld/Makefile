# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -std=c++11 -g -Wall

# the build target executable:
TARGET = main.sh

# file
FILE = board2.cpp driver2.cpp herbivora.cpp karnivora.cpp list.cpp makhluk.cpp pathtree.cpp Point.cpp singa.cpp zebra.cpp board.cpp

# check for newer version
CEKVER = board2.cpp board2.h driver2.cpp herbivora.cpp karnivora.cpp list.cpp list.h makhluk.cpp makhluk.h pathtree.cpp pathtree.h Point.cpp Point.h singa.cpp singa.h zebra.cpp zebra.h board.cpp board.h

$(TARGET): $(CEKVER)
	$(CC) $(CFLAGS) -o $(TARGET) $(FILE)

clean:
	$(RM) $(TARGET)
