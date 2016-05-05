// Brad Sherman
// Fundamentals of Computing 2
// Connect 4 Column Class Interface
//

#ifndef C4COL_H
#define C4COL_H
#include<iostream>

class C4Col {

	public:
		C4Col();
		int isFull();
		char getDisc(int);
		int getMaxDiscs();
		void addDisc(char);
		~C4Col();
	private:
		int numDiscs;
		int maxDiscs;
		char *discs;
};
#endif
