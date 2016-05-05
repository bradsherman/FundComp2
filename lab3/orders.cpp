// Brad Sherman
// Fundamentals of Computing 2
// Lab 3
// Day's Orders Processing Program
//

#include<iostream>
using namespace std;
#include<string>
#include"package.h"
#include"twodaypackage.h"
#include"overnight.h"
#include<stdlib.h>
#include<time.h>

int main() {

	// Set random seed
	srand(time(NULL));

	// Initialize Package pointers
	Package * ptr1;
	Package * ptr2;
	Package * ptr3;
	Package * ptr4;
	Package * ptr5;
	Package * ptr6;

	// Instantiate objects
	TwoDayPackage t1;
	TwoDayPackage t2;
	TwoDayPackage t3;
	Overnight o1;
	Overnight o2;
	Overnight o3;

	// Assign pointers
	ptr1 = &t1;
	ptr2 = &t2;
	ptr3 = &t3;
	ptr4 = &o1;
	ptr5 = &o2;
	ptr6 = &o3;

	// Create array and set names
	Package* array[6] = {ptr1,ptr2,ptr3,ptr4,ptr5,ptr6};
	array[0]->setName("Brad");
	array[1]->setName("Steve");
	array[2]->setName("John");
	array[3]->setName("Reed");
	array[4]->setName("Matt");
	array[5]->setName("Travis");


	int i;
	double weight;
	double sum = 0;

	// Assign each package a random weight and then calculate the shipping
	// cost based on whether the pointer points to a Two Day Package or an
	// overnight Package
	for (i = 0; i < 6; i++) {
		weight = rand() % 15 + 1;
		array[i]->setWeight(weight);
		sum = sum + array[i]->CalculateCost();
		cout << endl << array[i]->getName() << ", your package weighs " << array[i]->getWeight() << " ounces" << endl;
		cout << " and costs $" << array[i]->CalculateCost() << " to ship." << endl;
	}
	cout << endl << "The total cost of shipping these packages is:   $" << sum << endl << endl;
}
