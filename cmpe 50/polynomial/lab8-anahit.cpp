//============================================================================
// Name        : lab8-anahit.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "polynomial.h"
using namespace std;

int main() {
	int degr;
	cout << "Enter the degree" << endl;
	cin >> degr;
	Polynomial pol(degr);
	for (int i = 0; i <= degr; i++) {
		double temp = 0;
		cout << "enter coefficient" << endl;
		cin >> temp;
		pol.set_coeff(i, temp);
	}
	cout << pol << endl;
	double temp4[degr + 1];
	for (int i = 0; i <= degr; i++) {
		temp4[i] = pol.get_coeff(i);
	}
	int degr2;
	cout << "Enter the degree" << endl;
	cin >> degr2;
	Polynomial pol1(degr2);
	for (int i = 0; i <= degr2; i++) {
		double temp2 = 0;
		cout << "enter coefficient" << endl;
		cin >> temp2;
		pol1.set_coeff(i, temp2);
	}
	cout << pol1 << endl;
	double temp5[degr2 + 1];
	for (int i = 0; i <= degr2; i++) {
		temp5[i] = pol1.get_coeff(i);
	}
	double cont=0;
	cout<<"enter constant"<<endl;
	cin>>cont;
	int choice = 0;
	do {
		cout << "1.polynomial + polynomial\n"
				"2.constant + polynomial\n"
				"3.polynomial + constant\n"
				"4.polynomial – polynomial\n"
				"5.constant – polynomial\n"
				"6.polynomial – constant\n"
				"7.polynomial * polynomial\n"
				"8.constant * polynomial\n"
				"9.polynomial * constant\n"
				"10.exit\n";
		cin >> choice;
		if (choice == 1) {
			Polynomial sum;
			sum=pol+pol1;
			cout<<sum<<endl;
		}
		if (choice == 2) {
			int b;
			Polynomial sum;
			b=cont+temp4[0];
			pol.set_coeff(0,b);
			cout<<pol<<endl;
		}
		if (choice == 3) {
			Polynomial sum;
		}
		if (choice == 4) {
			Polynomial sub;
		}
		if (choice == 5) {
			Polynomial sub;
		}
		if (choice == 6) {
			Polynomial sub;
		}
		if (choice == 7) {
			Polynomial multi;
		}
		if (choice == 8) {
			Polynomial multi;
		}
		if (choice == 9) {
			Polynomial multi;
		}

	} while (choice != 10);

	return 0;

}
