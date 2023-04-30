CC = g++
CFLAGS = -O3 -Wall -std=c++17

all: main.o mylib.o
	$(CC) $(CFLAGS) main.o mylib.o -o run

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
    
mylib.o: mylib.cpp mylib.h
	$(CC) $(CFLAGS) -c mylib.cpp

clean:
	del /f *.o run.exe