// Brad Sherman
// Fundamentals of Computing 2
// Mortgage Class interface
//

#include<iostream>

class Mortgage {
	
	public:
		Mortgage();                         // default constructor
		Mortgage( double, double, double ); // normal constructor
		void credit( double );              // deducts value from principal
		double getPrincipal( void );        // returns current principal
		void amortize( void );              // displays amortization table
		
	private:
		double Principal;                   // principal remaining
		double Rate;                        // interest rate
		double Payment;                     // monthly payment
};
