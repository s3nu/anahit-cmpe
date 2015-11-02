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
	double temp3[degr + 1];
	double temp2[degr + 1];
	for (int i = 0; i <= degr; i++) {
		temp4[i] = pol.get_coeff(i);
		temp3[i] = pol.get_coeff(i);
		temp2[i] = pol.get_coeff(i);
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
	double cont = 0;
	cout << "enter constant" << endl;
	cin >> cont;
	int choice = 0;
	do {
		cout << "using polynomial one for all constant algebra:" << endl;
		cout << "1.polynomial + polynomial\n"
				"2.constant + polynomial\n"
				"3.polynomial + constant\n"
				"4.polynomial - polynomial\n"
				"5.constant - polynomial\n"
				"6.polynomial - constant\n"
				"7.polynomial * polynomial\n"
				"8.constant * polynomial\n"
				"9.polynomial * constant\n"
				"10.exit\n";
		cin >> choice;

		if (choice == 1) {
			Polynomial sum1;
			sum1 = pol + pol1;
			cout << sum1 << endl;
		}
		if (choice == 2) {
			int b = 0;
			Polynomial sum2;
			sum2 = pol;
			b = cont + temp4[0];
			sum2.set_coeff(0, b);
			cout << sum2 << endl;
		}
		if (choice == 3) {
			int b = 0;
			Polynomial sum3;
			sum3 = pol;
			b = cont + temp4[0];
			sum3.set_coeff(0, b);
			cout << sum3 << endl;
		}
		if (choice == 4) {
			Polynomial sub;
			sub = pol - pol1;
			cout << sub << endl;
		}
		if (choice == 5) {
			Polynomial sub2;
			sub2 = pol;
			int b = 0;
			b = temp4[0] - cont;
			sub2.set_coeff(0, b);
			cout << sub2 << endl;
		}
		if (choice == 6) {
			int b = 0;
			Polynomial sub3;
			sub3 = pol;
			b = temp4[0] - cont;
			sub3.set_coeff(0, b);
			cout << sub3 << endl;
		}
		if (choice == 7) {
			Polynomial multi;
			multi = pol * pol1;
			cout<<multi<<endl;
		}
		if (choice == 8) {
			Polynomial multi2;
			multi2 = pol;
			for (int i = 0; i <= degr; i++) {
				temp2[i] = temp2[i] * cont;

				multi2.set_coeff(i, temp2[i]);
			}
			cout << multi2 << endl;
		}
		if (choice == 9) {
			Polynomial multi1;
			multi1 = pol;
			for (int i = 0; i <= degr; i++) {
				temp3[i] = temp3[i] * cont;
				multi1.set_coeff(i, temp3[i]);
			}
			cout << multi1 << endl;
		}

	} while (choice != 10);

	return 0;
}
/*
 *
 * Enter the degree
1
enter coefficient
2
enter coefficient
4
4*x^1 + 2*x^0

Enter the degree
1
enter coefficient
6
enter coefficient
8
8*x^1 + 6*x^0

enter constant
2
using polynomial one for all constant algebra:
1.polynomial + polynomial
2.constant + polynomial
3.polynomial + constant
4.polynomial - polynomial
5.constant - polynomial
6.polynomial - constant
7.polynomial * polynomial
8.constant * polynomial
9.polynomial * constant
10.exit
1
12*x^1 + 8*x^0

using polynomial one for all constant algebra:
1.polynomial + polynomial
2.constant + polynomial
3.polynomial + constant
4.polynomial - polynomial
5.constant - polynomial
6.polynomial - constant
7.polynomial * polynomial
8.constant * polynomial
9.polynomial * constant
10.exit
2
4*x^1 + 4*x^0

using polynomial one for all constant algebra:
1.polynomial + polynomial
2.constant + polynomial
3.polynomial + constant
4.polynomial - polynomial
5.constant - polynomial
6.polynomial - constant
7.polynomial * polynomial
8.constant * polynomial
9.polynomial * constant
10.exit
3
4*x^1 + 4*x^0

using polynomial one for all constant algebra:
1.polynomial + polynomial
2.constant + polynomial
3.polynomial + constant
4.polynomial - polynomial
5.constant - polynomial
6.polynomial - constant
7.polynomial * polynomial
8.constant * polynomial
9.polynomial * constant
10.exit
4
-4*x^1 + -4*x^0

using polynomial one for all constant algebra:
1.polynomial + polynomial
2.constant + polynomial
3.polynomial + constant
4.polynomial - polynomial
5.constant - polynomial
6.polynomial - constant
7.polynomial * polynomial
8.constant * polynomial
9.polynomial * constant
10.exit
5
4*x^1 + 0*x^0

using polynomial one for all constant algebra:
1.polynomial + polynomial
2.constant + polynomial
3.polynomial + constant
4.polynomial - polynomial
5.constant - polynomial
6.polynomial - constant
7.polynomial * polynomial
8.constant * polynomial
9.polynomial * constant
10.exit
6
4*x^1 + 0*x^0

using polynomial one for all constant algebra:
1.polynomial + polynomial
2.constant + polynomial
3.polynomial + constant
4.polynomial - polynomial
5.constant - polynomial
6.polynomial - constant
7.polynomial * polynomial
8.constant * polynomial
9.polynomial * constant
10.exit
7
32*x^1 + 12*x^0

using polynomial one for all constant algebra:
1.polynomial + polynomial
2.constant + polynomial
3.polynomial + constant
4.polynomial - polynomial
5.constant - polynomial
6.polynomial - constant
7.polynomial * polynomial
8.constant * polynomial
9.polynomial * constant
10.exit
8
8*x^1 + 4*x^0

using polynomial one for all constant algebra:
1.polynomial + polynomial
2.constant + polynomial
3.polynomial + constant
4.polynomial - polynomial
5.constant - polynomial
6.polynomial - constant
7.polynomial * polynomial
8.constant * polynomial
9.polynomial * constant
10.exit
9
8*x^1 + 4*x^0

using polynomial one for all constant algebra:
1.polynomial + polynomial
2.constant + polynomial
3.polynomial + constant
4.polynomial - polynomial
5.constant - polynomial
6.polynomial - constant
7.polynomial * polynomial
8.constant * polynomial
9.polynomial * constant
10.exit
10
 *
 *
 */
