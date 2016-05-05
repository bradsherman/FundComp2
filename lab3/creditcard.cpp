// Brad Sherman
// Fundamentals Of Computing 2
// Lab 3
// Credit Card Implementation
//

#include<iostream>
using namespace std;
#include"creditcard.h"
#include"bankaccount.h"
#include<string>

CreditCard::CreditCard () : BankAccount() {
	maxCredit = 200;
	lateFee = 70;
	cardNum = 0;
}

CreditCard::CreditCard ( double mc, double lf, int n, double p, string name, double r ) : BankAccount ( p, name, r ) {
	maxCredit = mc;
	lateFee = lf;
	cardNum = n;
}

void CreditCard::print() {
	// print late fee,, card number, and card owner
	cout << getOwner() << ", don't be late on your payment unless you want to pay $" << lateFee << "!" << endl << endl;
	cout << "The card number: "<< cardNum << " belongs to " << getOwner() << endl << endl;
}
