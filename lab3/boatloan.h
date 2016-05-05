// Brad Sherman
// Fundamentals of Computing 2
// Lab 3
// Boat Loan Class
//

#ifndef BOATLOAN_H
#define BOATLOAN_H
#include<iostream>
using namespace std;
#include"bankaccount.h"
#include<string>

class BoatLoan {
	
	public:
		BoatLoan();
		void setOwner(string);
		void print();

	private:
		double monthlyPayment;
		double maxSpeed;
		BankAccount acct;
};
#endif
