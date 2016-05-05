// Brad Sherman
// Fundamentals of Computing 2
// Connect 4 Board Class Implementation
//

#include<iostream>
#include"c4col.h"
#include"c4board.h"
#include<stdlib.h>
using namespace std;

C4Board::C4Board() {
	numCols = 7;
}


	
ostream &operator<<( ostream &output, C4Board &board ) {
	// Header for the board labeling columns
	output << "  1   2   3   4   5   6   7" << endl;
 	int i,j;
	int rows = board.Board[0].getMaxDiscs();
	// Print out board with "|" on either side
	for( i = rows-1; i >= 0; i-- ) {
		for( j = 0; j < board.numCols; j++ ) {
			output << "| " << board.Board[j].getDisc(i) << " ";
		}
		output << "|" << endl;
	}
	return output;
}

void C4Board::play() {
	int win = 0;
	int full = 0;
	int player = 0;
	int column;
	system("clear");
	// Play until a winner is decided
	while( !win ) {
		// Show board
		cout << *this << endl;
		// Take player one's choice
		cout << "Player one choose which column to play (or enter -1 to end game): " << endl;
		cin >> column;
		if( column == -1 ) break;
		column -=  1; // 0-index
		// Check to make sure the column is on the board
		while( column < 0 || column >= numCols ) {
			cout << "That is not on the board." << endl;
			cout << "Player one choose which column to play (or enter -1 to end game): " << endl;
			cin >> column;
			if( column == -1 ) break;
			column -= 1;
		// Add the disc to the column
		}

		if( column == -1 ) break;
		Board[column]+='X';
		win = checkWin();
		// if win is true the game is over
		if( win  ) {
			player = 1;
			continue;
		}full = checkFull();
		if( full ) break;
		// The next few lines are the same as above, except for player 2
		cout << *this << endl;
		cout << "Player two choose which column to play (or enter -1 to end game): " << endl;
		cin >> column;
		if( column == -1 ) break;
		column -= 1;
		while( column < 0 || column >= numCols ) {
			cout << "That is not on the board." << endl;
			cout << "Player two choose which column to play (or enter -1 to end game): " << endl;
			cin >> column;
			if( column == -1 ) break;
			column -= 1;
		}
		if( column == -1 ) break;
		Board[column]+='O';
		win = checkWin();
		if( win ) player = 2;
		full = checkFull();
		if( full ) break;
	}
	// display board and winner
	if( column != -1 ) {
		cout << *this << endl;
		cout << endl << endl;
	}if( win ) cout << "Congratulations! Player " << player << " won!" << endl;
	if( full ) cout << "Game over, the board is full" << endl;
}

int C4Board::checkFull() {
	int i,j;
	int rows = Board[0].getMaxDiscs();
	for( i = rows; i >= 0; i-- ) {
		for( j = 0; j < numCols; j++ ) {
			if( Board[j].getDisc(i) == ' ') return 0;
		}
	}
	return 1;
}
int C4Board::checkWin() {
	// Function to check if there is a winner
	int k[8][2] = {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
	int i,j,m,x,y,count = 0;
	int s = 1; // magnifying factor 
	int rows = Board[0].getMaxDiscs(); // get number of rows
	for( i = rows; i >=0; i-- ) {
		for( j = 0; j < numCols; j++ ) {
			// Checks for a match for player 1's character
			if( Board[j].getDisc(i) == 'X' ) {
				for( m = 0; m < 8; m++ ) {
					s = 1;
					count = 0;
					x = k[m][0];
					y = k[m][1];
					// check to make sure coordinate is on the board
					if( (j+s*x) < 0 || (j+s*x) >= numCols || (i+s*y) < 0 || (i+s*y) > rows ) continue;
					while( Board[j+s*x].getDisc(i+s*y) == 'X') {
						// if the adjacent coordinate is a match
						// increment count and the magnifying
						// factor
						count++;
						if( count == 3) return 1;
						s++;
						// Check to make sure the new coordinate
						// is on the board
						if( (j+s*x) < 0 || (j+s*x) >= numCols || (i+s*y) < 0 || (i+s*y) > rows ) break;
					}
				
				}
			}
			// This else if statement is the same as the above 
			// if statement except for player 2's character
			else if( Board[j].getDisc(i) == 'O' ) {
				for( m = 0; m < 8; m++ ) {
					s = 1;
					count = 0;
					x = k[m][0];
					y = k[m][1];
					if( (j+s*x) < 0 || (j+s*x) >= numCols || (i+s*y) < 0 || (i+s*y) > rows ) continue;
					while( Board[j+s*x].getDisc(i+s*y) == 'O') {
						count++;
						if( count == 3) return 1;
						s++;
						if( (j+s*x) < 0 || (j+s*x) >= numCols || (i+s*y) < 0 || (i+s*y) > rows ) break;
					}
				
				}
			}
		}
	}
	return 0;
}		
	
C4Board::~C4Board() {}	
