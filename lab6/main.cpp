// Brad Sherman
// Fundamentals of Computing 2
// Lab6 
// Sudoku
//

#include<iostream>
using namespace std;
#include"puzzle.h"
#include<string>

int main() {
	Puzzle<int> SudokuBoard;

	cout << "Here is your Sudoku board." << endl;
	SudokuBoard.print();

	SudokuBoard.solve();	
	cout << "Solved board:" << endl;
	SudokuBoard.print();
}
