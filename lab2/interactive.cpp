// Brad Sherman 
// Fundamentals of Computing 2
// Lab 2
// Rational Class Driver function
//

#include<iostream>
using namespace std;
#include"rational.h"

Rational func1( Rational, Rational );
Rational func2( Rational, Rational );
Rational func3( Rational, Rational );
Rational func4( Rational, Rational );

int main( void ) {

	int num, denom;
	
	// Ask the user to choose two rational numbers

	cout << "Please choose the numerator for your first rational number (x): " << endl;
	cin >> num;
	cout << "Please choose the denominator for your first rational number (x): " << endl;
	cin >> denom;
	Rational x(num, denom);

	cout << "Please choose the numerator for your second rational number (y): " << endl;
	cin >> num;
	cout << "Please choose the denominator for your second rational number (y): " << endl;
	cin >> denom;
	Rational y( num, denom );
	
	cout << endl << endl;

	cout << "Now your rational numbers will be used as input for four functions" << endl;
	
	cout << "------------------------------------------------------------------" << endl;

	// Use rationals in four different functions
	
	Rational rat1 = func1(x, y);

	cout << "1. Result of f(x) = x^2 + y^2    --> " << rat1 << endl << endl;

	Rational rat2 = func2(x, y);
	
	cout << "2. Result of f(x) = x^3 - y^3    --> " << rat2 << endl << endl;

	Rational rat3 = func3(x, y);

	cout << "3. Result of f(x) = (x^4)/(xy)   --> " << rat3 << endl << endl;

	Rational rat4 = func4(x, y);
	
	cout << "4. Result of f(x) = xy/(x+y)     --> " << rat4 << endl << endl;

}	

Rational func1( Rational x, Rational y ) {
	// f(x) = x^2 + y^2
	
	Rational temp1 = y^2;
	Rational temp2 = x^2;
	Rational temp3 = temp1+temp2;
	return(temp3);
}

Rational func2( Rational x, Rational y ) {
	// f(x) = x^3 - y^3

	Rational temp1 = x^3;
	Rational temp2 = y^3;
	Rational temp3 = temp1-temp2;
	return(temp3);
}

Rational func3( Rational x, Rational y ) {
	// f(x) = (x^4)/(xy)
	
	Rational temp1 = x^4;
	Rational temp2 = x*y;
	Rational temp3 = temp1/temp2;
	return(temp3);
}

Rational func4( Rational x, Rational y ) {
	// f(x) = xy/(x+y)
	
	Rational temp1 = x*y;
	Rational temp2 = x+y;
	Rational temp3 = temp1/temp2;
	return(temp3);
}
