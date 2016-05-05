// Python Interpreter for Multiplication
// Token Class Interface
//

#include<iostream>
using namespace std;
#include<string>
#include<math.h>

#ifndef TOKENMULT_H
#define TOKENMULT_H
class TokenMult{
	
	public:
		TokenMult(string,string);
		void print();
		string getType();
		string getToken();

	private:
		string type;
		string token;

};
#endif
