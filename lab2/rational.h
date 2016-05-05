// Brad Sherman
// Fundamentals of Computing 2
// Lab 2
// Rational Class Interface
//

#ifndef RATIONAL_H
#define RATIONAL_H

#include<iostream>
using namespace std;

class Rational {
	
	friend ostream &operator<<( ostream &, Rational & );

	public:
		~Rational();
		Rational( int, int );
		Rational operator+( Rational &);
		Rational operator-( Rational &);
		Rational operator*( Rational &);
		Rational operator/( Rational &);
		Rational& operator=( Rational &rational);
		Rational operator^( int );		

	private:
		int num;
		int denom;
		int findGCD( int, int );
};
#endif
