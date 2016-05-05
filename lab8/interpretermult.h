// Python Interpreter for Multiplication
// Interpreter Class Interface
//

#include<iostream>
using namespace std;
#include<string>
#include<math.h>
#include"tokenmult.h"

#ifndef INTERPRETERMULT_H
#define INTERPRETERMULT_H
class InterpreterMult{

	public:
		InterpreterMult(string);
		TokenMult* getNextToken();
		void eat(string);
		int eval();

	private:
		int position;
		string text;
		TokenMult* current_token;
};
#endif
