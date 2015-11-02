/*
 * class.cpp
 *
 *  Created on: May 1, 2014
 *      Author: nsarras
 */
#include <iostream>
#include "class.h"
using namespace std;

void Figure::erase(){
	cout<<"Figure: erase"<<endl;
}

void Figure::draw(){
	cout<<"Figure: draw"<<endl;
}

void Figure::center(){
	cout<<"Figure: center"<<endl;
}
void Circle::erase(){
	cout<<"circle: erase"<<endl;
}

void Circle::draw(){
	cout<<"circle: draw"<<endl;
}
void Circle::center(){
	cout<<"circle: center"<<endl;
}

void Triangle::erase(){
	cout<<"triangle: erase"<<endl;
}

void Triangle::draw(){
	cout<<"triangle: draw"<<endl;
}

void Triangle::center(){
	cout<<"triangle: center"<<endl;
}

