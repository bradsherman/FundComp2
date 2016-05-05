// Brad Sherman
// Fundamentals of Computing 2
// Lab 4
// Card Deck Class Implementation
//

#include<iostream>
using namespace std;
#include<string>
#include<deque>
#include"carddeck.h"
#include<algorithm>
#include<stdlib.h>
#include<time.h>

CardDeck::CardDeck(int n) {
	// Non-default constructor
	int i;
	for (i = 0; i < n; i++) {
		Deck.push_back(i+1);
	}
}

int CardDeck::getSize() {
	return Deck.size();
}

void CardDeck::shuffle() {
	random_shuffle(Deck.begin(), Deck.end());
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
	deque<int>::const_iterator i;
	for (i = myDeck.Deck.begin(); i != myDeck.Deck.end(); ++i) {
		if( i == myDeck.Deck.end()-1 ) output << *i << endl;
		else output << *i << ", ";
	}
	return output;
}

void CardDeck::printReverse() {
	// Print the deck in reverse order
	deque<int>::reverse_iterator r;
	for (r = Deck.rbegin(); r != Deck.rend(); ++r) {
		if( r == Deck.rend()-1 ) cout << *r << endl;
		else cout << *r << ", ";
	}
}

int CardDeck::Deal() {
	// Return a card from the deck
	shuffle();
	int card = Deck.back();
	Deck.pop_back();
	return card;
}

int CardDeck::findScore() {
	// Calculate the score of a player deck in Blackjack
	int i;
	int sum = 0;
	int tmp;
	for (i = 0; i < Deck.size(); i++) {
		tmp = Deck[i] % 13;
		if( tmp <= 8 ) sum = sum + (tmp+2);              // 2-10
		else if( tmp > 8 && tmp <= 11 ) sum = sum + 10;  // Jack, Queen, and King
		else if( tmp == 12 ) sum = sum + 11;             // Ace

	}
	return sum;
}

void CardDeck::addCard(int x){
	Deck.push_back(x);
}
CardDeck::~CardDeck() {
	Deck.clear();	
}
