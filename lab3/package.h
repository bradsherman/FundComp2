// Brad Sherman
// Fundamentals of Computing 2
// Lab 3
// Package Class Interface
//

#ifndef PACKAGE_H
#define PACKAGE_H
#include<iostream>
using namespace std;
#include<string>

class Package {
	
	public:
		Package();
		Package(string,int,double,double);
		virtual double CalculateCost();
		double getWeight();
		double getcpOz();
		int getZipCode();
		string getName();
		void setWeight(double);
		void setcpOz(double);
		void setZipCode(int);
		void setName(string);

	private:
		string name;
		int zipCode;
		double weight;
		double cpOZ;

};
#endif

	

