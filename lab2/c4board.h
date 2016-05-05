// Brad Sherman
// Fundamentals of Computing 2
// Connect 4 Board Class Interface
//

#ifndef C4BOARD_H
#define C4BOARD_H
#include<iostream>
#include"c4col.h"

class C4Board {
	
	friend std::ostream &operator<<( std::ostream &, C4Board & );
	
	public:
		C4Board();
		void display();
		void play();
		~C4Board();
	private:
		int numCols;
		C4Col Board[7];
		int checkFull();
		int checkWin();
};
#endif
