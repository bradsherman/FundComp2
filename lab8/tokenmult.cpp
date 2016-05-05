// Python Interpreter for Multiplication
// Token Class Implementation
//

#include<iostream>
using namespace std;
#include<string>
#include<math.h>
#include"tokenmult.h"

TokenMult::TokenMult(string t, string tok){
	type = t;
	token = tok;
}

void TokenMult::print(){
	cout << "Token(" << type << "," << token << ")" << endl;
}

string TokenMult::getType(){
	return type;
}

string TokenMult::getToken() {
	return token;
}
