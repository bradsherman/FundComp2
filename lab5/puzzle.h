// Brad Sherman
// Fundamentals of Computing 2
// Lab 5
// Puzzle Class
//

#ifndef PUZZLE_H
#define PUZZLE_H
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<fstream>

template <typename T>
class Puzzle {
	
	public:
		Puzzle();
		void print();
		void addEntry( T, int, int );
		int checkSolved();

	private:
		int checkMiniGrids( T, int, int );
		int boardSize;
		vector< vector<T> > Board;
};
#endif

template <typename T>
Puzzle<T>::Puzzle() {
	boardSize = 9;
	int i,j;
	
	// make 2D vector
	vector<T> v(boardSize);
	vector<vector<T> > board(boardSize,v);

	cout << endl << "Please enter the name of the file to get the board from:" << endl;
	string file;
	cin >> file;
       	ifstream myfile (file.c_str());
	T tmp;
	// Read in each value of the file and place it in the 2D vector
	for (i = 0; i < boardSize; i++) {
		for (j = 0; j < boardSize; j++) {
			myfile >> tmp;
			board[i][j] = tmp;
		}
	}
	// Set the Board we declared earlier to be equal to the newly created 2D vector
	Board = board;
}

template <typename T>
void Puzzle<T>::print() {
	int i,j;
	
	// Header for column numbers
	cout << "   1 2 3   4 5 6   7 8 9" << endl;

	for (i = 0; i < boardSize; i++) {
		// Label for each row number
		cout << i+1 << " ";
		for (j = 0; j < boardSize; j++) {
			// Print out each member of Board
			cout << " " << Board[i][j];	
			// Separate every three lines
			if( j == 2 || j == 5 ) cout << " |";
		}
		// Separate every three lines
		if( i == 2 || i == 5 ) cout << endl << "   ---------------------";
		cout << endl;
	}
}

template <typename T>
void Puzzle<T>::addEntry( T entry, int row, int col ) {
	int i,j;
	int valid = 1;
	// Make sure row and column are on the board
	if( row < 0 || row >= boardSize ) {
		cout << "Invalid row choice." << endl;
		valid = 0;
	}if( col < 0 || col >= boardSize ) {
		cout << "Invlaid column choice." << endl;
		valid = 0;
	}
	// Make sure the position has not already been played
	if( Board[row][col] != 0 ) valid = 0;
	// Check each box for matching entry
	valid = checkMiniGrids( entry, row, col);
	// Make sure the entry is between 1 and 9
	if( entry < 1 || entry > 9 ) valid = 0;
	else if( valid ) {
		// Check the column for matching entry
		for( i = 0; i < boardSize; i++ ) {
			if( Board[i][col] == entry ){
				valid = 0;
				break;
			}
		}
		// Check the row for matching entry
		for( j = 0; j < boardSize; j++ ) {
			if( Board[row][j] == entry  ) {
				valid = 0;
				break;
			}
		}
		
	}
	if( valid ) Board[row][col] = entry;
	if( !valid ) cout << "That is not a valid entry" << endl;
}

template <typename T>
int Puzzle<T>::checkMiniGrids( T entry, int row, int col ){
	int i, j;
	// There are 9 "minigrids" that the desired position could belong to
	// Below is a series of if statements to figure out where it is at, and
	// then check the corresponding minigrid for a matching entry
	if( row < 3 ) {
		if( col < 3 ) {
			for( i = 0; i < 3; i++ ){
				for( j = 0; j < 3; j++ ){
					if( Board[i][j] == entry ) return 0;
				}
			}
		}	
		else if( col < 6 ) {
			for( i = 0; i < 3; i++ ){
				for( j = 3; j < 6; j++ ){
					if( Board[i][j] == entry ) return 0;
				}
			}

		}
		else {
			for( i = 0; i < 3; i++ ){
				for( j = 6; j < 9; j++ ){
					if( Board[i][j] == entry ) return 0;
				}
			}

		}
	}
	else if( row < 6 ) {
		if( col < 3 ) {
			for( i = 3; i < 6; i++ ){
				for( j = 0; j < 3; j++ ){
					if( Board[i][j] == entry ) return 0;
				}
			}

		}	
		else if( col < 6 ) {
			for( i = 3; i < 6; i++ ){
				for( j = 3; j < 6; j++ ){
					if( Board[i][j] == entry ) return 0;
				}
			}

		}
		else {
			for( i = 3; i < 6; i++ ){
				for( j = 6; j < 9; j++ ){
					if( Board[i][j] == entry ) return 0;
				}
			}

		}
	}
	else {
		if( col < 3 ) {
			for( i = 6; i < 9; i++ ){
				for( j = 0; j < 3; j++ ){
					if( Board[i][j] == entry ) return 0;
				}
			}

		}	
		else if( col < 6 ) {
			for( i = 6; i < 9; i++ ){
				for( j = 3; j < 6; j++ ){
					if( Board[i][j] == entry ) return 0;
				}
			}

		}
		else {
			for( i = 6; i < 9; i++ ){
				for( j = 6; j < 9; j++ ){
					if( Board[i][j] == entry ) return 0;
				}
			}

		}
	}
	return 1;
}

template <typename T>
int Puzzle<T>::checkSolved() {
	int i, j, sum;
	// Check to make sure the sum of all rows equals 45
	for (i = 0; i < boardSize; i++) {
		sum = 0;
		for (j = 0; j < boardSize; j++) {
			sum = sum + Board[i][j];	
		}
		if( sum != 45 ) return 0;
	}
	// Check to make sure the sum of all columns equals 45
	for (j = 0; j < boardSize; j++) {
		sum = 0;
		for (i = 0; i < boardSize; i++) {
			sum = sum + Board[i][j];	
		}
		if( sum != 45 ) return 0;
	}
	return 1;
}




