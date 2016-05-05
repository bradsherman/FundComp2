CC =          g++
CFLAGS =      -lm
TARGETS =     main

all: $(TARGETS)

main: main.o puzzle.h
	$(CC) $^ -o $@
main.o: main.cpp puzzle.h
	$(CC) -c $< -o $@
clean:
	rm -f *.o  $(TARGETS)
