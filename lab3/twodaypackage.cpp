// Brad Sherman
// Fundamentals Of Computing 2
// Lab 3
// Two Day Package Class Implementation
//

#include<iostream>
using namespace std;
#include<string.h>
#include"package.h"
#include"twodaypackage.h"

TwoDayPackage::TwoDayPackage() {
	setName("empty");
	setZipCode(0);
	setWeight(0);
	setcpOz(5.0);
	expDeliveryCharge = 10.00;
}

double TwoDayPackage::CalculateCost() {
	return (expDeliveryCharge+getWeight()*getcpOz());
}
