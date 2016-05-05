// Brad Sherman
// Fundamentals of Computing 2
// Lab 4
// Card Deck Class Interface
//

#ifndef CARDDECK_H
#define CARDDECK_H
#include<iostream>
using namespace std;
#include<string>
#include<deque>

class CardDeck {

	friend ostream &operator<<(ostream &, CardDeck &);

	public:
		CardDeck(int=52); // fall-back value of 52
		int getSize();
		void shuffle();   // uses srand() to ensure better randomness
		int inOrder();
		void printReverse();
		int Deal();
		int findScore();
		void addCard(int);
		~CardDeck();

	private:
		deque<int> Deck;

};
#endif
