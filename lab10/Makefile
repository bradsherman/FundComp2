CC       =     g++
CFLAGS   =     -lm
TARGETS  =     main docprocess
VERSION  =     -std=c++11

all: $(TARGETS)

main: main.o puzzle.h
	$(CC) $(VERSION) $^ -o $@
main.o: main.cpp puzzle.h
	$(CC) -c $(VERSION) $< -o $@
docprocess: docprocess.cpp
	$(CC) $^ -o $@
clean:
	rm -f *.o  $(TARGETS)
