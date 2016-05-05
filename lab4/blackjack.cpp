// Brad Sherman
// Fundamentals Of Computing 2
// Lab 4
// Black Jack
//

#include<iostream>
using namespace std;
#include<string>
#include"carddeck.h"
#include<deque>
#include<stdlib.h>
#include<time.h>
#include<cctype>

void reset( int &play, int &playerScore, int &dealerScore, int &pChoice, int &dChoice, int &bust, CardDeck * pDeck, CardDeck * dDeck, int &begin );
void start( int &pCard, int &dCard, CardDeck * mDeck, CardDeck * pDeck, CardDeck * dDeck, int &playerScore, int &dealerScore, int &begin );

int main() {
	// Randomize seed
	srand(time(NULL));

	// Initialize Decks and other variables
	CardDeck *pDeck;
	CardDeck *dDeck;
	CardDeck *mDeck;

	pDeck = new CardDeck(0);
	dDeck = new CardDeck(0);
	mDeck = new CardDeck(52);

	int playerScore = 0;
	int dealerScore = 0;
	int play = 1;
	int pChoice = 1, dChoice = 1;
	int pCard, dCard;
	int bust = 0;
	int playerWins = 0, dealerWins = 0;
	int begin = 1;

	system("clear");
	cout << "Welcome to Black Jack! Feel free to try your" << endl;
	cout << "luck against the house!" << endl;
	cout << "============================================" << endl;

	while( play ) {

		// Start game, deal two cards to dealer and player as in normal Blackjack
		if( begin ) start( pCard, dCard, mDeck, pDeck, dDeck, playerScore, dealerScore, begin);
		// Check to see if either player was dealt 2 aces off the bat
		if( playerScore > 21 || dealerScore > 21 ) bust = 1;
	
		// Shuffle Cards before each turn
		mDeck->shuffle();

		// As long as the user wants another card, keep asking them
		if( pChoice && !bust ){
			cout << "Player score: " << playerScore << ". Hit(enter 1) or stand(enter 0)?" << endl;
			cin >> pChoice;
		}
		// As long as the user is getting more cards, keep track of their score
		if(pChoice && !bust) {
			pCard = mDeck->Deal();
			pDeck->addCard(pCard);
		}playerScore = pDeck->findScore();

		//  Check if the player busted
		if( playerScore > 21 ) {
			bust = 1;
			cout << "Player busted at " << playerScore << ". Dealer wins!" << endl;
			dealerWins++;
		// Dealer continues to get more cards as long as it hasn't busted or is still under a score of 17	
		}if(dChoice && !bust) {
			dCard = mDeck->Deal();
			dDeck->addCard(dCard);
		}

		dealerScore = dDeck->findScore();

		if(dealerScore < 17) dChoice = 1;
		else dChoice = 0;
		
		// Check to see if dealer busted
		if( dealerScore > 21 ) {
			cout << "The dealer busted at " << dealerScore << ". Player wins!" << endl;
			bust = 1;
			playerWins++;
		// If both players choose to stand where they are, this displays
		}if(dChoice == 0 && pChoice == 0 && !bust) {
			cout << "Player score: " << playerScore << "." << endl;
			cout << "Dealer score: " << dealerScore << "." << endl;
			if( playerScore > dealerScore ) {
				cout << "Player wins!" << endl;
				playerWins++;
			}else if( dealerScore > playerScore ) {
				cout << "Dealer wins!" << endl;
				dealerWins++;
			}else if( dealerScore == playerScore ) cout << "It's a push!" << endl;
		}
		// This runs everytime a game ends, no matter how it ends
		if( (dChoice == 0 && pChoice == 0) || bust ) reset( play, playerScore, dealerScore, pChoice, dChoice, bust, pDeck, dDeck, begin );
		
		// Make sure deck is large enough
		if( mDeck->getSize() < 15 ) {
			delete mDeck;
			mDeck = new CardDeck(52);
		}
	}	
	delete pDeck;
	delete dDeck;
	delete mDeck;
	cout << endl << "Total player wins: " << playerWins << endl;
	cout << "Total dealer wins: " << dealerWins << endl;	
}

void reset( int &play, int &playerScore, int &dealerScore, int &pChoice, int &dChoice, int &bust, CardDeck * pDeck, CardDeck * dDeck, int &begin ){
	// Reset variables for a new game
	cout << "Play again? (1 for yes, 0 for no) " << endl;
	cin >> play;
	playerScore = 0;
	dealerScore = 0;
	pChoice = 1;
	dChoice = 1;
	bust = 0;
	delete pDeck;
	delete dDeck;
	pDeck = new CardDeck(0);
	dDeck = new CardDeck(0);
	begin = 1;
}

void start( int &pCard, int &dCard, CardDeck * mDeck, CardDeck * pDeck, CardDeck * dDeck, int &playerScore, int &dealerScore, int &begin ){
	// Begin game by dealing two cards to the dealer and the player
	cout << endl;
	pCard = mDeck->Deal();
	pDeck->addCard(pCard);
	dCard = mDeck->Deal();
	dDeck->addCard(dCard);
	dealerScore = dDeck->findScore();
	mDeck->shuffle();
	pCard = mDeck->Deal();
	pDeck->addCard(pCard);
	dCard = mDeck->Deal();
	dDeck->addCard(dCard);
	playerScore = pDeck->findScore();

	cout << "Dealer score after one card: " << dealerScore << endl;
	cout << "Player score after the first two cards: " << playerScore << endl << endl;
	begin = 0;

}
