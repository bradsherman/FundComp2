// Brad Sherman
// Fundamentals of Computing 2
// Mortgage Driver Program
//

#include<iostream>
#include"mortgage.h"
using namespace std;

int main( void ) {
	Mortgage first( -10000, -5.0, -500 );
	Mortgage second;

	second.credit( 10000 );
	cout << "Current balance after crediting second mortgage 10K: " << second.getPrincipal() << endl;
	cout << "Amortization schedule for first mortgage: " << endl;
	first.amortize();
}
