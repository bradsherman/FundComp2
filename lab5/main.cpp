// Brad Sherman
// Fundamentals of Computing 2
// Lab5 
// Sudoku
//

#include<iostream>
using namespace std;
#include"puzzle.h"
#include<string>

int main() {
	cout << "Welcome to the puzzle solver. Try to solve your puzzle!" << endl;
	cout << endl << "First, get your Sudoku board.";	
	Puzzle<int> SudokuBoard;

	cout << endl << "Now, get your Wordoku board.";
	Puzzle<char> WordokuBoard;

	cout << endl << "Here is you Wordoku board!" << endl;
	WordokuBoard.print();

	cout << endl << "For now, we are going to play Sudoku." << endl;
	cout << "Make your choices wisely, if you mess up you have to start over." << endl << endl;
	cout << "Here is your Sudoku board." << endl;
	SudokuBoard.print();
	
	int num,row,col;
	int solved = 0;
	 
	while ( !solved ) {
		cout << "What character/number do you wish to input?" << endl;
		cin >> num;

		cout << "Which row would you like to place it at?" << endl;
		cin >> row;
		row = row - 1;   // re-index to match board

		cout << "Which column would you like to place it at?" << endl;
		cin >> col;
		col = col -1;   // re-index to match board

		SudokuBoard.addEntry(num, row, col);

		SudokuBoard.print();
		solved = SudokuBoard.checkSolved();
	}

	cout << endl << "Congratulations you solved the puzzle!" << endl;

}
