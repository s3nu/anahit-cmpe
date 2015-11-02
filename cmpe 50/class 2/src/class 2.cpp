//============================================================================
// Name        : class.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	char coin;
	double total = 0;
	while (total < 3.50) {
		cout << "insert coin\n" << endl;
		cin >> coin;
		switch (coin) {
		case 'd':
			total = total + 1;
			break;
		case 'q':
			total = total + .25;
			break;
		case 'm':
			total = total + .10;
			break;
		case 'n':
			total = total + .5;
			break;
		default:
			break;
		}
		cout << total << endl;
	}
	if (total==3.50) {
		cout<<"enjoy your deep fired twinkie\n"<<endl;
	}
	if (total>3.50) {
		double tt=0;
		tt=total-3.50;
		cout<<"here is you change\n"<<tt<<endl;
	}
	return 0;
}
/*insert coin

d
1
insert coin

d
2
insert coin

d
3
insert coin

d
4
here is you change
0.5
*/
