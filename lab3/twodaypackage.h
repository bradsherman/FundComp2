// Brad Sherman
// Fundamentals Of Computing 2
// Lab 3
// Two Day Package Class Inteface
//

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include<iostream>
using namespace std;
#include<string>
#include"package.h"

class TwoDayPackage : public Package {

	public:
		TwoDayPackage();
		virtual double CalculateCost();

	private:
		double expDeliveryCharge;

};
#endif
