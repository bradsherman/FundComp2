CC =          g++
CFLAGS =      -lm
TARGETS =     main special ndvectortest

all: $(TARGETS)

main: main.o ndvector.h 
	$(CC) $^ -o $@
main.o: main.cpp ndvector.h
	$(CC) -c $< -o $@
special: special.o binarytree.h
	$(CC) $^ -o $@
special.o: special.cpp binarytree.h
	$(CC) -c $< -o $@
ndvectortest: ndvectortest.o ndvector.h carddeck.o
	$(CC) $^ -o $@
ndvectortest.o: ndvectortest.cpp ndvector.h
	$(CC) -c $< -o $@
carddeck.o: carddeck.cpp carddeck.h
	$(CC) -c $< -o $@
clean:
	rm -f *.o  $(TARGETS)
