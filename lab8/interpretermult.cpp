// Python Interpreter for Multiplication
// Interpreter Class Implementation
//

#include<iostream>
using namespace std;
#include<string>
#include<math.h>
#include"tokenmult.h"
#include"interpretermult.h"
#include<cctype>
#include<cstdlib>

InterpreterMult::InterpreterMult( string expr){
	text = expr;
	position = 0;
	current_token = NULL; 
}

TokenMult* InterpreterMult::getNextToken(){
	if( position > text.length()-1 ) {
		return new TokenMult("EOF","NONE");
	}
	char current_char;
	current_char = text[position];

	if( isdigit(current_char) ){
		position++;
		return new TokenMult("INTEGER",string(1,current_char));
	}
	else if( string(1,current_char) == "*"){
		position++;
		return new TokenMult("MULTIPLICATION",string(1,current_char));
	}
}

void InterpreterMult::eat(string token_type){
	if( current_token->getType() == token_type ) {
		current_token = getNextToken();
	}else cout << "Couldn't get next token." << endl;
}

int InterpreterMult::eval(){
	current_token = getNextToken();
	TokenMult* left = current_token;
	eat("INTEGER");

	TokenMult* op = current_token;
	eat("MULTIPLICATION");

	TokenMult* right = current_token;
	eat("INTEGER");

	int result = atoi(left->getToken().c_str()) * atoi(right->getToken().c_str());
	delete left;
	delete right;
	delete op;
	return result;
}
