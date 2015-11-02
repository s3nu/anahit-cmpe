/*
 * Polynomial.h
 *
 *  Created on: Oct 24, 2013
 *      Author: cltarng
 */

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
using namespace std;

// Class to implement polynomial operations
class Polynomial
{
public:
	Polynomial();
	Polynomial(int degr);
	// Initialize the object with degree of degr
	Polynomial(const Polynomial &poly);
	// Copy constructor
	Polynomial(double cf[], int degr);
	// Parameterized constructor. The input is an array of double values and
	// the degree. The array of double should have already been populated with
	// the coefficients of the polynomial.
	~Polynomial();
	int get_degree() const;
	// Return the private member degree.
	double get_coeff(int index) const;
	// Return the coefficient of a index.
	void set_coeff(int index, double val);
	// Mutator to alter a coefficient
	void operator = (const Polynomial &poly);
	// Assignment operator
	friend Polynomial operator+(const Polynomial &polya, const Polynomial &polyb);
	friend Polynomial operator-(const Polynomial &polya, const Polynomial &polyb);
	friend Polynomial operator*(const Polynomial &polya, const Polynomial &polyb);
	friend ostream& operator << (ostream& ost, const Polynomial &pol);
	double evaluate(double val);
	// Evaluate the polynomial
private:
	double *coeff;
	int degree;
};



#endif /* POLYNOMIAL_H_ */
