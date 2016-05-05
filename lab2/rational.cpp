// Brad Sherman
// Fundamentals of Computing 2
// Lab 2
// Rational Class Implementation
//

#include<iostream>
using namespace std;
#include"rational.h"
#include<math.h>

Rational::~Rational() {
	num = 1;
	denom = 1;
}

Rational::Rational( int numerator, int denominator ) {
	// Check for valid input
	while( denominator == 0 ) {
		cout << "Error, cannot have 0 in the denominator." << endl;
		cout << "Please enter a new denominator: " << endl;
		cin >> denominator;
	}
	int greatest;
	if( numerator > denominator ) greatest = numerator;
	else if( denominator > numerator ) greatest = denominator;
	int gcd;
	// Simplify fraction
	gcd = findGCD( numerator, denominator );
	num = numerator/gcd;
	denom = denominator/gcd;
}	

int Rational::findGCD( int numerator, int denominator  ) {
	int i;
	// Use Euclid's algorithm to simplify fraction
	while( denominator != 0 ) {
		i = denominator;
		denominator = numerator % denominator;
		numerator = i;
	}
	return numerator;
	
}	
ostream &operator<<(ostream &output, Rational &rational ) {
	// Overload output operator
	if( rational.denom == 1 ) output << rational.num;
	else output << rational.num << "/" << rational.denom;
	return output;
}

Rational Rational::operator+(Rational &rational) {
	int newNum, newDenom;
	// Overloaded + operator
	newNum = (num*rational.denom) + (rational.num*denom);
	newDenom = denom * rational.denom;

	Rational temp(newNum, newDenom);
	return(temp);
}	

Rational Rational::operator-(Rational &rational) {
	int newNum, newDenom;
	// Overloaded - operator
	newNum = (num*rational.denom) - (rational.num*denom);	
	newDenom = denom*rational.denom;
	
	Rational temp(newNum, newDenom);
	return(temp);
}

Rational Rational::operator*(Rational &rational) {
	int newNum, newDenom;
	// Overloaded * operator
	newNum = (num*rational.num);
	newDenom = (denom*rational.denom);
	
	Rational temp(newNum, newDenom);
	return(temp);
}

Rational Rational::operator/( Rational &rational) {
	int newNum, newDenom;
	// Overloaded / operator
	newNum = num*rational.denom;
	newDenom = denom*rational.num;

	Rational temp(newNum, newDenom);
	return(temp);
}
Rational Rational::operator^( int exp ) {
	int newNum, newDenom;
	// Overloaded exponent operator	
	if( exp > 0 ) {
		newNum = pow(num, exp);
		newDenom = pow(denom, exp);
	} else if( exp == 0 ) {
		newNum = 1;
		newDenom = 1;
	} else if( exp < 0 ) {
		newNum = pow(denom, -1*exp);
		newDenom = pow(num, -1*exp);
	}
	Rational temp(newNum, newDenom);
	return(temp);
}
Rational & Rational::operator=( Rational &rational ) {
	// Overloaded = operator
	num = rational.num;
	denom = rational.denom;
	return(*this);
}
