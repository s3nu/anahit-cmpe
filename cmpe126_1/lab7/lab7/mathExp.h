/*
 * mathExp.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Luther
 */

#ifndef MATHEXP_H_
#define MATHEXP_H_

#include <iostream>
#include <stack>
#include <string>

using namespace std;

void dispInstruct();

// Main function to convert Infix expression to Postfix
string convertToPfx(string expression);

// Function to verify that an operator has higher precedence over others
//int precedence(char op1, char op2);

//Checks if character is operator
bool isOperator(char C);

//Checks if character is alpha-numeric character
bool isAlphaNum(char C);

//Used in the precedence function; assigns int value to operators for comparison
int precedence(char op);
//evaluate expression
int eval(string exprission);


#endif /* MATHEXP_H_ */
