/*
 * complex.cpp
 *
 *  Created on: Sep 8, 2014
 *      Author: nsarras
 */

#include "complex.h"
#include <iostream>
#include <fstream>
#include <math.h>



complex::complex(){
	real=0;
	imaginary=0;
	total=0;
	note=' ';
	sign=' ';

}
ostream& operator<<(ostream& outs, const complex& obj){

	if(obj.sign==' '){
		outs<<obj.real<<endl;
		return outs;
	}
	if(obj.sign==' '&& obj.imaginary==0){
		outs<<obj.real<<obj.note<<endl;
		return outs;
	}
	if(obj.note==' ' && obj.imaginary==0){
		outs<<obj.real<<obj.sign<<endl;
		return outs;
	}
	else{
		outs<<obj.real<<obj.sign<<obj.imaginary<<"i"<<endl;
		return outs;
	}



}
istream& operator>>(istream& in, complex& obj){
    double temp=0;


	in>>obj.real;
//    if (in.peek()=='.') {
//        
//    }
	if(in.peek()==' '||in.peek()=='\n'){
		return in;
	}
	in>>obj.sign;
	if(in.peek()==' '||in.peek()=='\n'){
		return in;
	}
	in>>obj.imaginary;
	if(in.peek()==' '||in.peek()=='\n'){
		return in;
	}
	in>>obj.note;
        
	cout<<endl;
	return in;


}

double complex::mag(){
	double r=0;
	double i=0;
	double m=0;
	double t=0;

	r=real*real;
	i=imaginary*imaginary;
	m=r+i;
	t=sqrt(m);
	return t;

}
void complex::convert(double magnitude){
	ofstream out;
	double r=0;

	r=2*sqrt(magnitude);

	//cout<<r<<"+"<<r<<"i"<<endl;
	out<<r<<"+"<<r<<"i"<<endl;


}


