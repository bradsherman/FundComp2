// Brad Sherman
// Fundamentals of Computing 2
// Lab 4
// Card Deck Class Implementation
//

#include<iostream>
using namespace std;
#include<string>
#include"carddeck.h"
#include<algorithm>
#include<stdlib.h>
#include<time.h>

CardDeck::CardDeck(int n) {
	// Non-default constructor
	int i;
	for (i = 0; i < n; i++) {
		Deck.addtoBack(i+1);
	}
}

int CardDeck::getSize() {
	return Deck.getsize();
}

void CardDeck::shuffle() {
	int i,randnum;
	int tmp;
	for( i = 1; i < getSize(); i++ ){
		randnum = rand() % i;// + 1;
		tmp = Deck[i];
		Deck[i] = Deck[randnum];
		Deck[randnum] = tmp;
	}
}

int CardDeck::inOrder() {
	// Check to see if the deck is in order
	int i;
	for (i = 0; i < getSize()-1; i++) {
		if(Deck[i]>Deck[i+1]) return 0;
	}
	return 1;
}

ostream &operator<<( ostream &output, CardDeck &myDeck ){
	// Overload << operator
	int i; 
	for( i = 0; i < myDeck.Deck.getsize(); i++ ){
		if( i == myDeck.Deck.getsize()-1 ) output << myDeck.Deck[i];
		else output << myDeck.Deck[i] << ",";
	}
	output << endl;
	return output;
}

void CardDeck::printReverse() {
	// Print the deck in reverse order
	int i;
	for (i = getSize()-1; i >= 0; i--) {
		if( i == 0 ) cout << Deck[i];
		else cout << Deck[i] << ",";
	}
}

int CardDeck::Deal() {
	// Return a card from the deck
	shuffle();
	int card = Deck.getLast();
	Deck.removefromBack();
	return card;
}

int CardDeck::findScore() {
	// Calculate the score of a player deck in Blackjack
	int i;
	int sum = 0;
	int tmp;
	for (i = 0; i < Deck.getsize(); i++) {
		tmp = Deck[i] % 13;
		if( tmp <= 8 ) sum = sum + (tmp+2);              // 2-10
		else if( tmp > 8 && tmp <= 11 ) sum = sum + 10;  // Jack, Queen, and King
		else if( tmp == 12 ) sum = sum + 11;             // Ace

	}
	return sum;
}

void CardDeck::addCard(int x){
	Deck.addtoBack(x);
}
CardDeck::~CardDeck() {
	Deck.clear();	
}
