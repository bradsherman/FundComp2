// Brad Sherman
// Fundamentals of Computing 2
// Lab 4
// Card Deck Main Program
//

#include<iostream>
using namespace std;
#include"carddeck.h"
//#include"ndvector.h"
#include<string>
#include<time.h>
#include<stdlib.h>

int main() {
	srand(time(NULL));

	CardDeck Deck(52);

	int order;
	// Ensure Deck is in order
	order = Deck.inOrder();
	if(order) cout << "The Deck is in order." << endl;
	else cout << "The Deck is not in order." << endl;
	cout << endl << endl;
	// Print before shuffle
	cout << "This is the deck in order: " << endl;
	cout << Deck;
	cout << endl << endl;
	

	// Print in Reverse order
	cout << "This is the deck in reverse order: " << endl;
	Deck.printReverse();
	Deck.shuffle();
	cout << endl << endl;
	// Print after shuffle
	cout << "This is the deck after a shuffle " << endl;
	cout << Deck;
	order = Deck.inOrder();
	if(order) cout << "The Deck is in order." << endl;
	else cout << "The Deck is not in order." << endl;
	
}
