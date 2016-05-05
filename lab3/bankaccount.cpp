// Brad Sherman
// Fundamentals of Computing 2
// Lab 3
// Bank Account Implementation
//

#include<iostream>
using namespace std;
#include"bankaccount.h"
#include<string>

BankAccount::BankAccount() {
	principal = 500;
	owner = "empty";
	intRate = .05;
}

BankAccount::BankAccount( double p, string name, double r ) {
	principal = p;
	owner = name;
	intRate = r;
}

string BankAccount::getOwner() {
	return owner;
}

double BankAccount::getPrincipal() {
	return principal;
}

double BankAccount::getintRate() {
	return intRate;
}

void BankAccount::setName(string n) {
	owner = n;
}
