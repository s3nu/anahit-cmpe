/*
 * complex
 *
 *  Created on: Mar 18, 2014
 *      Author: senu
 */


#include<iostream>
#include "complex.h"

complex::complex() {
	real = 0;
	imag = 0;
}
complex::complex(double a, double b) {
	real = a;
	imag = b;
}
complex operator+(complex& one, complex& two) {
	complex temp;
	temp.real = one.real + two.real;
	temp.imag = one.imag + two.imag;
	return temp;
}
complex operator-(complex& one, complex& two) {
	complex temp1;
	temp1.real = one.real - two.real;
	temp1.imag = one.imag - two.imag;
	return temp1;
}
complex operator*(complex& one, complex& two) {
	complex temp2;
	temp2.real = one.real * two.real - one.imag * two.imag;
	temp2.imag = one.real * two.imag + one.imag * two.real;
	return temp2;
}
