// Brad Sherman
// Fundamentals of Computing 2
// Lab 3
// Package Driver Program 1
//

#include<iostream>
using namespace std;
#include"package.h"
#include"twodaypackage.h"
#include"overnight.h"
#include<string>

int main() {

	// Welcome statement
	cout << "Welcome to Amazon package delivery!" << endl;
	cout << "-----------------------------------" << endl;
	cout << "You will be sending one two day package" << endl;
	cout << "and one overnight package. Please enter" << endl;
	cout << "your information below and we will" << endl;
	cout << "calculate your cost." << endl << endl;

	// Instantiate objects
	TwoDayPackage t;
	Overnight o;

	// Set names
	cout << "What is your name?" << endl;
	string N;
	cin >> N;
	t.setName(N);
	o.setName(N);

	// Set weights
	cout << "What is the weight of your package?" << endl;
	double w;
	cin >> w;
	t.setWeight(w);
	o.setWeight(w);

	// Set zip codes
	cout << "What zip code are you shipping to?" << endl;
	int z;
	cin >> z;
	t.setZipCode(z);
	o.setZipCode(z);

	// Calculate shipping cost
	double tCost = t.CalculateCost();
	double oCost = o.CalculateCost();

	// Display neatly to user
	cout << "Thanks, " << N << "! Your Prices are listed below:" << endl;
	cout << "------------------------------------" << endl;
	cout << "Two Day Shipping to " << z << ":    " << tCost << endl;
	cout << "Overnight Shipping to " << z << ":  " << oCost << endl << endl;
	return 0;
}
