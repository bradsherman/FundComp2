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
		void solve();

	private:
		int checkMiniGrids( T, int, int );
		int checkValid(T,int,int);
		void checkRow( int, int );
		void checkCol(int, int );
		int boardSize;
		vector< vector<T> > Board;
		vector< vector< vector<T> > > Possibilities;
};
#endif

template <typename T>
Puzzle<T>::Puzzle() {
	boardSize = 9;
	int i,j,k;
	
	// make 2D vector
	vector<T> v(boardSize);
	vector<vector<T> > board(boardSize,v);

	cout << endl << "Please enter the name of the file to get the board from:" << endl;
	string file;
	cin >> file;
	ifstream myfile (file.c_str());
	T tmp;

	vector<T> v2(boardSize);
	vector<vector<T> > p(boardSize,v);
	vector<vector<vector<T> > > possibilities(9,p);

	// Read in each value of the file and place it in the 2D vector
	for (i = 0; i < boardSize; i++) {
		for (j = 0; j < boardSize; j++) {
				myfile >> tmp;
				board[i][j] = tmp;
			for( k = 0; k < 9; k++ ) {
				possibilities[i][j][k] = 1;
			}
		}
	}
	// Set the Board we declared earlier to be equal to the newly created 2D vector
	Board = board;
	Possibilities = possibilities;


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
void Puzzle<T>::solve() {
	int h,i,j,k,m,n,p;
	int entry;
	while( checkSolved() != 1 ) {
		// Go through board and find empty cells
		for( i = 0; i < boardSize; i++ ) {
			for( j = 0; j < boardSize; j++ ) {
				if( Board[i][j] == 0 ) {

					// go through mini grids
					for( h = 0; h < 9; h++ ) Possibilities[i][j][h] = checkMiniGrids( h+1, i, j );

					// Go through each cell in the same
					// column, and add possible values to 
					// the current cell
					checkCol(i,j);

					// Go through each cell in the same 
					// row, and add possible values to
					// the current cell
					checkRow(i, j);

					// At this point, each empty cell has a corresponding
					// array of 1's and 0's for the numbers 1-9. A 1 stands
					// for a valid option, and a 0 stands for an invalid 
					// option for that particular cell. Now we go through 
					// each array of possibilities, and if there is only one
					// valid option, we place the value in that cell. 	
					int num;
					int count = 0;
					for( h = 0; h < boardSize; h++ ) {
						if( Possibilities[i][j][h] == 1 ) {
							num = h+1;
							count++;
						}	
					}
					if( count == 1 ) {
						Board[i][j] = num;
						cout << "Added a " << num << " at (" << i << "," << j << ")." << endl;
					}								
				}
			}
		}
		// Singleton Method
		for( i = 0; i < 3; i++ ) {
			for( j = 0; j < 3; j++ ) {
				vector<int> counter(10);
				int x,y,row,col;
				for( x = 0; x < 3; x++ ) {
					for( y = 0; y < 3; y++ ) {
						row = (i*3)+x;
						col = (j*3)+y;
						if(Board[row][col] == 0 ) {
							//checkCol(row,col);
							//checkRow(row,col);

							for( k = 0; k < 9; k++ ) {
								//Possibilities[i][j][k] = checkMiniGrids( k+1, i, j );
								if( Possibilities[row][col][k] == 1 ) counter[k]++;
							}
						}			
					}
				}
				for( x = 0; x < 3; x++ ) {
					for( y = 0; y < 3; y++ ) {
						row = (i*3)+x;
						col = (j*3)+y;
						if(Board[row][col] == 0) {
							for( k = 0; k < 9; k++ ){
								if( Possibilities[row][col][k] == 1 && counter[k] == 1 ) {
									cout << "Added a " << k+1 << " at (" << row << "," << col << ")." << endl;
									Board[row][col] = k+1;
									print();	
								}		
							}
						}		
					}
				}
			counter.clear();	
			}
		}
		// Now check each row, column, and minigrid to see if there is only one spot left
		for( i = 0; i < boardSize; i++ ){
			int sumRow = 0,sumRow2 = 0;
			int sumCol = 0,sumCol2 = 0;
			for( j = 0; j < boardSize; j++ ) {
				if( Board[i][j] != 0 ) {
					checkCol(i,j);
					checkRow(i,j);
					for( h = 0; h < 9; h++ ) Possibilities[i][j][h] = checkMiniGrids( h+1, i, j );
					sumRow = sumRow + 1;
					sumRow2 = sumRow2 + Board[i][j];
				}if( Board[j][i] != 0 ) {
					checkCol(j,i);
					checkRow(j,i);
					for( h = 0; h < 9; h++ ) Possibilities[j][i][h] = checkMiniGrids( h+1, j, i );
					sumCol = sumCol + 1;
					sumCol2 = sumCol2 + Board[j][i];
				}
			}	
			if( sumRow == 8 ) {
				for( j = 0; j < boardSize; j++ ) {
					if( Board[i][j] == 0 && Possibilities[i][j][45-sumRow2-1] == 1 ) {
							Board[i][j] = 45-sumRow2;
							cout << "added an entry" << endl;
							print();
					}			
				}
			}
			if( sumCol == 8 ) {
				for( j = 0; j < boardSize; j++ ) {
					if( Board[j][i] == 0 && Possibilities[j][i][45-sumCol2-1] == 1 ) {
							Board[j][i] = 45-sumCol2;
							cout << "added an entry" << endl;
							print();
					}		
				}
			}
		}
	}
}	
template <typename T>
void Puzzle<T>::checkRow( int row, int col ) {
	int n, entry;
	for( n = 0; n < boardSize; n++ ) {
		if( Board[row][n] != 0 ) {
			entry = Board[row][n];
			Possibilities[row][col][entry-1] = 0;
		}
	}	
}
template <typename T>
void Puzzle<T>::checkCol( int row, int col ) {
	int n, entry;
	for( n = 0; n < boardSize; n++ ) {
		if( Board[n][col] != 0 ) {
			entry = Board[n][col];
			Possibilities[row][col][entry-1] = 0;
		}
	}	
}
template <typename T>
int Puzzle<T>::checkValid( T entry, int row, int col ) {
	int i,j;
	int valid = 1;
	// Make sure row and column are on the board
	if( row < 0 || row >= boardSize ) {
		cout << "Invalid row choice." << endl;
		return 0;
	}if( col < 0 || col >= boardSize ) {
		cout << "Invalid column choice." << endl;
		return 0;
	}
	// Make sure the position has not already been played
	if( Board[row][col] != 0 ) return 0;
	// Check each box for matching entry
	valid = checkMiniGrids( entry, row, col);

	// Make sure the entry is between 1 and 9
	if( entry < 1 || entry > 9 ) return 0;
	else {
		// Check the column for matching entry
		for( i = 0; i < boardSize; i++ ) {
			if( Board[i][col] == entry ){
				return 0;
			}
		}
		// Check the row for matching entry
		for( j = 0; j < boardSize; j++ ) {
			if( Board[row][j] == entry  ) {
				return 0;
			}
		}
		
	}
	return valid;
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
	else {
		// Check the column for matching entry
		for( i = 0; i < boardSize; i++ ) {
			if( i == row ) continue;
			if( Board[i][col] == entry ){
				valid = 0;
				break;
			}
		}
		// Check the row for matching entry
		for( j = 0; j < boardSize; j++ ) {
			if( j == col ) continue;
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




