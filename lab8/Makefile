CC =          g++
CFLAGS =      -lm
TARGETS =     main

all: $(TARGETS)

main: main.o tokenmult.o interpretermult.o
	$(CC) $^ -o $@
main.o: main.cpp
	$(CC) -c main.cpp
interpretermult.o: interpretermult.cpp interpretermult.h
	$(CC) -c interpretermult.cpp
tokenmult.o: tokenmult.h tokenmult.cpp
	$(CC) -c tokenmult.cpp
clean:
	rm -f *.o  $(TARGETS)
