// Brad Sherman
// Fundamentals of Computing 2
// Lab 3
// Package Class Implementation
//

#include<iostream>
using namespace std;
#include<string>
#include"package.h"
#include<stdlib.h>

Package::Package() {
	name = "empty";	
	zipCode = 0;
	weight = 0;
	cpOZ = 5.0;
}

Package::Package(string Name, int zip, double Weight, double CPOZ ) {
	name = Name;
	if( zip < 0 ) zip = zip*-1;
	zipCode = zip;
	if( Weight < 0 ) Weight = Weight*-1;
	weight = Weight;
	if( CPOZ < 0 ) CPOZ = CPOZ*-1;
	cpOZ = CPOZ;
}

// Set and get functions

double Package::CalculateCost() {
	return cpOZ*weight;
}

double Package::getWeight() {
	return weight;
}

double Package::getcpOz() {
	return cpOZ;
}

int Package::getZipCode() {
	return zipCode;
}

string Package::getName() {
	return name;
}

void Package::setWeight(double w) {
	if( w<0 ) w = -1*w;
	weight = w;
}

void Package::setcpOz(double c) {
	if( c<0 ) c = -1*c;
	cpOZ = c;
}

void Package::setZipCode(int z) {
	if( z<0 ) z = -1*z;
	zipCode = z;
}

void Package::setName(string n) {
	name = n;
}
