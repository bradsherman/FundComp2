// Brad Sherman
// Fundamentals Of Computing 2
// Lab3 
// Overnight Package Class Interface
//

#ifndef OVERNIGHT_H
#define OVERNIGHT_H
#include<iostream>
using namespace std;
#include"package.h"
#include<string>

class Overnight : public Package{
	
	public:
		Overnight();
		virtual double CalculateCost();
	
	private:
		double exFeePerOz;	

};
#endif
