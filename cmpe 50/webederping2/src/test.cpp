/*
 * test.cpp
 *
 *  Created on: Apr 24, 2014
 *      Author: test2
 */
#include "test.h"
#include <iostream>
#include <fstream>
using namespace std;

stack::stack(){ //default constructor
	maxsize=10;
	value = new double[10];
	size = 0;
}
stack::stack(double m) { //constructor
	maxsize = m;
	size = maxsize;
	value = new double[10];
}

stack::stack(const stack &s1) { // copy constructor
	size = s1.size;
	maxsize = s1.maxsize;
	value = new double[10];
	for (int i = 0; i < maxsize; i++) {
		s1.value[i] = value[i];
	}
}
stack::~stack() { //destructor
	delete[] value;
}
//stack& stack::operator =(const stack &p2) { //overloaded
//	maxsize = p2.maxsize;
//	size = p2.size;
//	value = new double[10];
//	if (this == &p2) {
//		return *this;
//	} else {
//		for (int i = 0; i < maxsize; i++) {
//			value[i]=p2.value[i];
//			delete[] value;
//
//		}
//	}
//}
void stack::addlast (double a) { //function
	if (size<maxsize) {
		value=new double[20];
		maxsize=20;
		cout<<"increased size"<<endl;
	}
	else if(size>maxsize){
		value[10]=a;
	}
}
double stack::getlast(double b) { //function
	int ld=0;
	int size2=0;
	size2=size;
	ld=value[size2];
	return ld;
}
void stack::deletelast(double c) {//function
	int size2=0;
	size2=size;
	value[size2]=0;
}
//bool stack::isempty() { //function
//	for (int i=0; i<maxsize;i++){
//	if(isdigit(value[i])){
//		cout<<"the list is not empty"<<endl;
//		return false;
//		break;
//	}
//	else {return true;
//	}
//
//	}
//}
ostream operator <<(ostream &ost, const stack &p3) { //overload

	return ost;
}

