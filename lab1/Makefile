all: main

main: main.o c4col.o c4board.o
	g++ main.o c4col.o c4board.o -o main
main.o: main.cpp
	g++ -c main.cpp
c4col.o: c4col.cpp
	g++ -c c4col.cpp
c4board.o: c4board.cpp
	g++ -c c4board.cpp
clean:
	rm -f *.o main
