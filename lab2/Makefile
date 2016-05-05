all: main interactive

main: main.o c4col.o c4board.o
	g++ main.o c4col.o c4board.o -o main
main.o: main.cpp
	g++ -c main.cpp
c4col.o: c4col.cpp
	g++ -c c4col.cpp
c4board.o: c4board.cpp
	g++ -c c4board.cpp
interactive: interactive.o rational.o
	g++ interactive.o rational.o -o interactive
interactive.o: interactive.cpp
	g++ -c interactive.cpp
rational.o: rational.cpp
	g++ -c rational.cpp
clean:
	rm -f *.o main interactive
