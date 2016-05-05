// Brad Sherman
// Fundamentals of Computing 2
// Estimating Pi
//

#include<iostream>
#include<math.h>
using namespace std;

void calculatePi( int );

int main( void ) {
	
	// Get number of terms from user	
	cout << "Please enter the number of terms you would like to use to estimate pi" << endl;
	int terms;
	cin >> terms;
	// Ensure that number of terms is greater than 2
	while( terms <= 2 ) {
		cout << "Please enter a number larger than 2" << endl;	
		cin >> terms;
	}

	double pi;	
	calculatePi( terms );
	
}

void calculatePi( int terms ) {
	// Calculate pi and display after each term of the summation is added
	double i;
	double pi = 0;
	for( i = 0; i < terms; i++ ) {
		pi = pi + pow(-1,i)*(4/(1+(2*i)));	
		cout << "Estimate for pi after " << (i+1) << " terms(s): " << pi << endl;
	}
}	
