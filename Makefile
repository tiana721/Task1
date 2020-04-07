CC=g++

CFLAGS=-c -Wall

all: pro

pro: main.o Vector.o VectorVert.o VectorHor.o test.o
	$(CC) main.o Vector.o VectorVert.o VectorHor.o test.o -o pro

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Vector.o: Vector.cpp
	$(CC) $(CFLAGS) Vector.cpp
	
VectorVert.o: VectorVert.cpp
	$(CC) $(CFLAGS) VectorVert.cpp
	
VectorHor.o: VectorHor.cpp
	$(CC) $(CFLAGS) VectorHor.cpp

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp
clean:
	rm -rf *.o pro
