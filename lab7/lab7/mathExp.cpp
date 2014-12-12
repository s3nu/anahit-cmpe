/*
 * mathExp.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: Luther
 */

#include <iostream>
#include <stack>
#include <string>
#include <cctype> 
#include <cstdlib>
#include "mathExp.h"

using namespace std;

void dispInstruct(){
	cout << "This program is able to handle the following: " << endl
			<< "- negative numbers denoted by '~' " << endl
			<< "- basic operators: +,-,*,/ " << endl
			<< "- program uses STL stack implementation" << endl << endl;
}

string convertToPfx(string expression){
	stack<char> cStck;
	string pfx = "";//initialize empty pfx string

	//loop through the whole string until the end of string
	for(int i = 0; i < (int)expression.length(); i++){
		//numbers, alphabets, negative and decimals append to pfx
		if( isAlphaNum(expression[i]) ){
			pfx += expression[i];
		}
		//ignore and continue for white spaces
		else if( isspace(expression[i]) ){
			continue;
		}
		//if next char is operator check precedence
		//compare top of stack with current char
		else if( isOperator(expression[i]) ){
			pfx += " "; //spacing for readibility
			while( ( !cStck.empty() ) && (precedence( cStck.top() ) >= precedence( expression[i] )) ){
				pfx += cStck.top();
				cStck.pop();
			}
			cStck.push( expression[i] );
		}
		//push open parenthesis to stack
		else if( expression[i] == '(' ){
			cStck.push( expression[i] );
		}
		//pop current operators from stack and process
		else if(  expression[i] == ')' ){
			while( (!cStck.empty()) && (cStck.top() != '(') ){
				pfx += cStck.top();
				cStck.pop();
			}
			if( !cStck.empty() ){
				cStck.pop();
			}
			else{
				cout << "Mismatch Error" << endl;
				exit(1);
			}
		}
		else{
			cout << "Invalid Infix Expression" << endl;
			exit(1);
		}
	}//end for loop

	//pop the rest of the stack until its empty
	while( !cStck.empty() ){
		pfx += cStck.top();
		cStck.pop();
	}

	return pfx;
} //end convertToPfx(string expression)

//Helper functions

bool isOperator(char C){

	switch (C){
	case '+': case '-': case '*': case '/':
	case '%': case '^':
		return true;
		break;

	default:
		return false;
		break;
	}

	return false; // last case scenario
}//end isOperator()

bool isAlphaNum(char C){

	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	//negative and decimal handling
	if(C == '.' || C == '~') return true;

	return false;
}//end isAlphaNum()

int precedence(char op){

	if (op == '^')
		return 4;
	if (op == '*' || op == '/' || op == '%')
		return 3;
	if (op == '-' || op == '+')
		return 2;

	//null case return -1 least weight
	return -1;
}

int eval(string exprission){
    stack<char> stk;
    int bind=0;
    char find=NULL;
    int holder=0;
    int holder1=0;
    int size=0;
    size=exprission.length();
    for (int i=0; i<size; i++) {
        if (isdigit(exprission[i])) {
            stk.push(exprission[i]);
        }
        else if( isspace(exprission[i]) ){
            continue;
        }
        if (isOperator((exprission[i]))){
            holder=stk.top()-48;
             stk.pop();
             holder1=stk.top()-48;
             stk.pop();
            find=exprission[i];
            if (find=='+'){
                bind=holder+holder1;
            }
            if (find=='-') {
                bind=holder1-holder;
               
            }
            if (find=='*') {
                bind=holder*holder1;
                
            }
            if (find=='/') {
                bind=holder/holder1;
            }
            stk.push((bind+48));
        }
    }
    int final=stk.top();
    return bind;
    
    
    
    
    

    
}
