// Brad Sherman
// Fundamentals of Computing 2
// Lab 3
// Bank Account Base Class
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include<iostream>
using namespace std;
#include <string>

class BankAccount {
	
	public:
		BankAccount();
		BankAccount(double, string, double);
		string getOwner();
		double getPrincipal();
		double getintRate();
		void setName(string);

	private:
		double principal;
		string owner;
		double intRate;
};
#endif
