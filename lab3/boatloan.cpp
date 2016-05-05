// Brad Sherman
// Fundamentals of Computing 2
// Lab 3
// Boat Loan Implementation
//

#include<iostream>
using namespace std;
#include"boatloan.h"
#include"bankaccount.h"
#include<string>

BoatLoan::BoatLoan() {
	monthlyPayment = 500;
	maxSpeed = 20; // knots
}

void BoatLoan::print() {
	// Print monthly payment and max speed of the boat
	cout << endl << acct.getOwner() << ", your monthly payment is: $" << monthlyPayment << "!" << endl << endl;
	cout << "Congratulations! The max speed of your boat is: " << maxSpeed << " knots." << endl << endl;
}

void BoatLoan::setOwner(string n) {
	acct.setName(n);
}
