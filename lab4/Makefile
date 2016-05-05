CC =          g++
CFLAGS =      -lm
TARGETS =     main monkeyshuffle blackjack

all: $(TARGETS)

main: main.o carddeck.o
	$(CC) $^ -o $@
monkeyshuffle: monkeyshuffle.o carddeck.o
	$(CC) $^ -o $@
blackjack: blackjack.o carddeck.o
	$(CC) $^ -o $@	
%.o: %.cpp
	$(CC) -c $< -o $@
clean:
	rm -f *.o  $(TARGETS)
