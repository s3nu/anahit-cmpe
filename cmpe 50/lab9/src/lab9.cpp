//============================================================================
// Name        : lab9.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <string>
#include <iostream>
#include "admin.h"

int main() {
	admin ad1;
	ad1.setname();
	ad1.read();
	ad1.printer(ad1);
	ad1.print_check();
	return 0;
}
