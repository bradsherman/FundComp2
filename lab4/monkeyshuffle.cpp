// Brad Sherman
// Fundamentals of Computing 2
// Lab 4
// Monkey Shuffle
//

#include<iostream>
using namespace std;
#include<string>
#include"carddeck.h"
#include<stdlib.h>
#include<time.h>
#include<deque>

void shuffleDeck( CardDeck, int *, int);

int main() {
	// Randomize seed
	srand(time(NULL));

	// Initialize 9 card decks
	CardDeck cd71(7);
	CardDeck cd72(7);
	CardDeck cd73(7);
	CardDeck cd81(8);
	CardDeck cd82(8);
	CardDeck cd83(8);
	CardDeck cd91(9);
	CardDeck cd92(9);
	CardDeck cd93(9);

	// Array that contains number of shuffles for each deck
	int orders[9];

	// Shuffle each deck until in order, and record number of
	// shuffles in orders array
	shuffleDeck(cd71, orders, 0);
	shuffleDeck(cd72, orders, 1);
	shuffleDeck(cd73, orders, 2);
	shuffleDeck(cd81, orders, 3);
	shuffleDeck(cd82, orders, 4);
	shuffleDeck(cd83, orders, 5);
	shuffleDeck(cd91, orders, 6);
	shuffleDeck(cd92, orders, 7);
	shuffleDeck(cd93, orders, 8);

	// Display number of shuffles
	int j = 0;
	int numCards = 7;
	for (j = 0; j < 9; j++) {
		if( j == 3 ) numCards = 8;
		if( j == 6 ) numCards = 9;
		cout << "It took " << orders[j] << " shuffles to sort " << numCards << " cards." << endl;
	}
}


void shuffleDeck( CardDeck cd, int *orders, int i) {
	// Shuffle a deck until it is shuffled into order
	int shuffles = 0;
	while(1) {
		cd.shuffle();
		shuffles++;
		if(cd.inOrder()) {
			orders[i] = shuffles;
			break;
		}
	}
}
