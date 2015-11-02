/*
 * complex
 *
 *  Created on: Mar 18, 2014
 *      Author: senu
 */

#ifndef COMPLEX_
#define COMPLEX_
#include <iostream>
using namespace std;

class complex {
public:
	complex();
	complex(double a, double b);
	friend complex operator+(complex& one, complex& two );
	friend complex operator-(complex& one, complex& two );
	friend complex operator*(complex& one, complex& two );

private:
	double real;
	double imag;
};


#endif /* COMPLEX_ */
