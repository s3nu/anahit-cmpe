//============================================================================
// Name        : lecture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "complex.h"



using namespace std;

int main() {
	double c;
	double d;
	double num;
	complex cx;
	cout<<"enter a value"<<endl;
	cin>>c;
	cout<<"enter a value"<<endl;
	cin>>d;
	num=complex(c,d);//will not let me do this getting an error
	cout<<"your result"<<num<<endl;
	return 0;
}
