// Brad Sherman
// Fundamentals of Computing 2
// Connect 4 Column Class Implementation
//

#include<iostream>
#include"c4col.h"
using namespace std;
#include<ctype.h>
#include<string.h>

C4Col::C4Col() {
	numDiscs = 0;
	maxDiscs = 6;
	int i;
	discs = new char[maxDiscs];
	// Initialize discs
	for( i = 0; i < maxDiscs; i++ ) discs[i]= ' ';
}

int C4Col::isFull() {
	if( numDiscs == maxDiscs) return 1;
	else return 0;
}

char C4Col::getDisc( int x ) {
	// Make sure the request is in bounds
	if( x > maxDiscs || x < 0 ) {
		cout << "Invalid input" << endl;
		return 0;
	}else return discs[x];
}

int C4Col::getMaxDiscs() {
	return maxDiscs;
}

void C4Col::addDisc( char newDisc ) {
	// See if column is full, if not add a disc
	if( !isFull() ){
		discs[numDiscs] = newDisc;
		numDiscs++;
	}else cout << "That column is full" << endl;
}
C4Col::~C4Col () {
	delete [] discs;
}	
