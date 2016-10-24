/*
 * complex.h
 *
 *  Created on: Sep 8, 2014
 *      Author: nsarras
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

class complex{

public:
	complex();
	double mag();
	void convert(double magnitude);
	friend ostream& operator<<(ostream& outs, const complex& obj);
    friend istream& operator >>(istream& in, complex& obj);



private:
	int real;
	char sign;
	int imaginary;
	char note;
	double total;
    double im;


};






#endif /* COMPLEX_H_ */
