//============================================================================
// Name        : Lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <string>
using namespace std;


double convertToPostfix(string expression);
int precedence(char operator1, char operator2);
bool checkoperator(char C);
bool checkother(char C);
int order(char val);
int leftright(char val);
double eval(double num,double num2,char c);

int main() {
	//Test Cases
	//	A + B - C;
	//	(A + B ) * C;
	//	(A + B) * (C - D);
	//	A + ((B + C) * (E - F) - G) / (H - I);
	//	A + B * (C + D ) - E / F * G + H;


	string expression1="3 + 4 * 5 - 6 / 7 * 8";
	cout<<"The resultant of the equation is\n\n"<<convertToPostfix(expression1)<<endl;

	string expression2="(5+5)*2";
	cout<<"The resultant of the equation is\n\n"<<convertToPostfix(expression2)<<endl;

	string expression3="(2+4)*(2-7)";
	cout<<"The resultant of the equation is\n\n"<<convertToPostfix(expression3)<<endl;

	string expression4="9+((3+3)*(8-9)-1)/(5-1)";
	cout<<"The resultant of the equation is\n\n"<<convertToPostfix(expression4)<<endl;

	string expression5="1+4*(3+2)-7/4*1+9";
	cout<<"The resultant of the equation is\n\n"<<convertToPostfix(expression5)<<endl;




	return 0;
}

double eval(double num,double num2,char c){


	switch(c){


	case '+': return num+num2;
	case '-': return num2-num;
	case '/': return num/num2;
	case '*': return num*num2;
	case '>': return num++;
	case '<': return num--;



	default: return 0;
	}

}

double convertToPostfix(string expression){


	stack<char> S;
	stack<char> E;
	int size=expression.length();
	string postfix = "";
	int temp1=0;
	int temp2=0;
	double value=0;

	cout<<"Infix expression "<<expression<<endl;


	for(int i = 0;i<size;i++) {


		if(expression[i] == ' ' || expression[i] == ',') continue;

		else if(checkoperator(expression[i]))
		{
			while(!S.empty() && S.top() != '(' /*&& precedence(S.top(),expression[i])*/)
			{
				postfix+= S.top();
				S.pop();
			}
			S.push(expression[i]);
		}

		else if(checkother(expression[i]))
		{
			postfix +=expression[i];
		}

		else if (expression[i] == '(')
		{
			S.push(expression[i]);
		}

		else if(expression[i] == ')')
		{
			while(!S.empty() && S.top() !=  '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while(!S.empty()) {
		postfix += S.top();
		S.pop();
	}
	cout<<"Postfix Expression: "<<postfix<<endl;
	//----------------------------This is where the magic happens(where the postfix equation becomes evaluated)---------------



	for(int i=0;i<size;i++){

		if(isdigit(postfix[i])){
			E.push(postfix[i]);
		}
		else if(isspace(postfix[i])){
			continue;
		}
		if(checkoperator(postfix[i])){
			temp1=E.top()-48;
			E.pop();
			temp2=E.top()-48;
			E.pop();
			value=eval(temp1,temp2,postfix[i]);
			E.push(value+48);
		}


	}

	return value;

}

bool checkoperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$'||C==','||C=='>'||C=='<')
		return true;

	return false;
}
bool checkother(char C)
{
	if(C>='0' && C<='9') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}
int order(char val)
{
	int weight = -1;

	if(val=='+'||val=='-'){
		weight =1;
	}
	if(val=='*' || val=='/'){
		weight=2;
	}
	if(val=='$'){
		weight=3;
	}
	return weight;
}
int leftright(char val)
{
	if(val == '$') return true;
	return false;
}

int precedence(char p1, char p2)
{
	int c1 = order(p1);
	int c2 = order(p2);

	if(c1 == c2)
	{
		if(leftright(p1)) return false;
		else return true;
	}
	if(c1>c2){
		return true;
	}
	else{
		return false;
	}

}







