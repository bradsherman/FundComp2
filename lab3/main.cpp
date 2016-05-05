// Brad Sherman
// Fundamentals of Computing 2
// Lab 3
// Driver Program
//

#include<iostream>
using namespace std;
#include"bankaccount.h"
#include"boatloan.h"
#include"creditcard.h"
#include<string>

int main() {

	// Welcome statement
	cout << "Welcome to Blackbeard's bank!" << endl;
	cout << "I heard you want to loan a boat, " << endl;
	cout << "and take out a credit card. " << endl << endl;

	// Initialize variables
	double principal;
	string name;
	double intRate;
	double maxCredit;
	double lateFee;
	int cardNum;
	double monthlyPayment;
	double maxSpeed;

	// Get name
	cout << "What is your name?" << endl;
	cin >> name;

	// Get other information for the loan
	cout << "Okay, first we will take care of your boat loan. " << endl;
	cout << "How fast of a boat would you like? " << endl;
	cin >> maxSpeed;
	principal = 60000;
	intRate = .06;
	cout << "Okay, your interest rate is 6\% and your " << endl;
	cout << "boat will be 60000. What will" << endl;
	cout << "your monthly payment be?" << endl;
	cin >> monthlyPayment;
	
	// Make sure payment is large enough
	while( monthlyPayment <= 0 || (( principal*(intRate/1200)) > monthlyPayment )) {
		cout << "Please enter a higher monthly payment: " << endl;
		cin >> monthlyPayment;
	}
	// This was used when boat loan inherited BankAccount, but does not work
	// after we changed it to composition according to part 3
//	BoatLoan loan1( monthlyPayment, maxSpeed, principal, name, intRate );
	// Commented out because of part 3

	cout << endl << "Now we will set up your credit card." << endl << endl;

	// Get information for credit card
	cout << "What would you like to set as your maximum balance on the card per month?" << endl;
	cin >> maxCredit;
	
	cout << "What card number would you like (4 digits)?" << endl;
	cin >> cardNum;
	// Make sure card number is valid
	while( cardNum < 1000 || cardNum > 9999 ) {
		cout << "Please enter a valid card number." << endl;
		cin >> cardNum;
	}

	principal = 0;
	lateFee = 70;
	intRate = .11;

	cout << "Perfect! The late fee at Blackbeard's bank is " << endl;
	cout << "$70, and the interest rate is 11\%. " << endl;
	
	CreditCard card1( maxCredit, lateFee, cardNum, principal, name, intRate );

//	loan1.print(); // Commented out because of part 3
	card1.print();	


}	
