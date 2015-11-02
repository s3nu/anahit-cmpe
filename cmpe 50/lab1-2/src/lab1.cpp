//============================================================================
// Name        : lab1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

int main() {
	int var1 = 0;
	bool prime=true;
	cout << "what integer above 2??\n" << endl;
	cin >> var1;
		for (int i = 3; i < var1; i++) {
			prime=true;
			for (int i2 = 2; i2 < i; i2++) {
				if (i % i2 == 0) {
					prime=false;
					break;
				}

			}

			if (prime==true) {
				cout<<i<<"your number is prime\n";
		}

	}

	return 0;
}

/*output
 * what integer above 2??
 *
11
3 your number is prime
5 your number is prime
7 your number is prime
 *
 *
*/
