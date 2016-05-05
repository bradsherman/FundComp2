// Main file showcasing multiplication
//

#include<iostream>
using namespace std;
#include"tokenmult.h"
#include"interpretermult.h"
#include<string>

int main() {
	int multiply = 1;
	string input;
	while(multiply) {
		cout << "enter an expression to be multiplied" << endl;
		cin >> input;
		InterpreterMult interpreter(input);
		int result = interpreter.eval();
		cout << result << endl;
		cout << "Continue? (1/0)" << endl;
		cin >> multiply;
	}
}
