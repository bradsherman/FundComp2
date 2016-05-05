// Brad Sherman
// Fundamentals of Computing 2
// Mortgage Class implementation
//

#include<iostream>
#include<stdio.h>
#include"mortgage.h"
using namespace std;
#include<math.h>
#include<iomanip>

Mortgage::Mortgage() {
	Principal = 30000;
	Rate = 5;
	Payment = 200;
}

Mortgage::Mortgage( double principal, double rate, double payment ) {
	while( principal <= 0 ) {
		cout << "Please enter a valid loan amout." << endl;
		cin >> principal;
	}Principal = principal;

	while( rate < 0 ) {
		cout << "Please enter a valid loan amount." << endl;
		cin >> rate;
	}Rate = rate;

	while( payment <=0 || (( Principal*(Rate/1200)) > payment )) {
		cout << "You either entered a negative monthly payment, or one" << endl;
		cout << "that is too small. Please enter a valid payment." << endl;	
		cin >> payment;
	}Payment = payment;
}

void Mortgage::credit( double value ) {
	Principal = Principal + value;
}

double Mortgage::getPrincipal( void ) {
	return Principal;
}

void Mortgage::amortize( void ) {
	
	int month = 0;
	double interest = 0;
	double total = Principal;	

	cout << "Month     Payment     Interest       Balance   " << endl;

	while( Principal > 0 ) {
		// Keep track of total months, interest paid, and total paid.
		month += 1;
		interest = Principal*(Rate/1200);
		total += interest;
		// Make sure last payment is calculated properly
		if( Principal + interest < Payment ) Payment = Principal+interest;
		Principal = Principal + interest - Payment;
		if( Principal < 0 ) Principal = 0;

		printf( "%-7d  ", month );
		printf( "$%8.2lf    ", Payment );
		printf( "$%8.2lf    ", interest );
		printf( "$%10.2lf\n", Principal );
	}
	int years, months;
	years = month/12;
	months = month%12;
	printf( "You paid a total of $%.2lf over %d years and %d months.\n", total, years, months );
}	
