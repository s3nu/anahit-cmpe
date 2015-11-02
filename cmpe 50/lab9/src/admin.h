/*
 * admin.h
 *
 *  Created on: Apr 30, 2014
 *      Author: senu
 */

#ifndef ADMIN_H_
#define ADMIN_H_
#include "Salariedemployee.h"
#include <iostream>
using namespace std;
class admin: public SalariedEmployee {
public:
	admin();
	void setname();
	void read();
	void printer(const admin &ad);
	void print_check( );
private:
string admin1;//title of admin
string type;//type of work
string admin2;//second in command
double salary1;// salary from other file
};
#endif /* ADMIN_H_ */
