// Brad Sherman
// Fundamentals Of Computing 2
// Lab 3
// Credit Card Account Class
//

#ifndef CREDITCARD_H
#define CREDITCARD_H
#include<iostream>
using namespace std;
#include<string>
#include"bankaccount.h"

class CreditCard : public BankAccount {
	
	public:
		CreditCard();
		CreditCard(double,double,int,double,string,double);
		void print();

	private:
		double maxCredit;
		double lateFee;
		int cardNum;			

};
#endif
