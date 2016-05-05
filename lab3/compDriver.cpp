// Brad Sherman
// Fundamentals Of Computing 2
// Lab 3
// Driver Program for Composition with Boat Loan
//

#include<iostream>
using namespace std;
#include"boatloan.h"
#include"bankaccount.h"
#include<string>

int main() {

	//Instantiate loan
	BoatLoan loan;
	
	string n;
	cout << "What is your name?" << endl;
	cin >> n;
	//Set loan owner's name
	loan.setOwner(n);
	loan.print();
}
