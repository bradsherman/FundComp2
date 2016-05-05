// Brad Sherman
// Fundamentals of Computing 2
// Lab 3
// Overnight Package Class Implementation
//

#include<iostream>
using namespace std;
#include"overnight.h"
#include<string>
#include"package.h"

Overnight::Overnight() {
	setName("empty");
	setZipCode(0);
	setWeight(0);
	setcpOz(5.0);
	exFeePerOz = 3.00;
}

double Overnight::CalculateCost() {
	return (getWeight()*(exFeePerOz+getcpOz()));
}
