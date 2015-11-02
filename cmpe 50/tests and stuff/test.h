/*
 * test.h
 *
 *  Created on: Apr 24, 2014
 *      Author: test2
 */

#ifndef TEST_H_
#define TEST_H_
#include <iostream>
#include <fstream>
using namespace std;
class stack {//class-none derived
public:
	stack();//default constructor
	stack(double m);//constructor
	stack(const stack &s1);//copy constructor
	~stack();//destructor
	stack& operator=(const stack &p2);//overload
	void addlast (double a);//function
	double getlast(double b);//function
	void deletelast(double c);//function
	bool isempty();//function
	friend ostream operator <<(ostream &ost,const stack &p3);//overload
private:
	double *value;
	double size;
	double maxsize;

};




#endif /* TEST_H_ */
