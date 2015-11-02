//============================================================================
// Name        : lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int choice = 0;
	do {
		cout << "1-start from console" << endl;
		cout << "2-start from file" << endl;
		cout << "3-stop" << endl;
		cin >> choice;
		if (choice == 1) {
			int size=0;
			char **seats;
			cout << "how many rows" << endl;
			cin >> size;
			seats = new char*[size];
			for (int i = 0; i < size; i++) {
				seats[i] = new char[4];
			}

			for (int i = 0; i < size; i++) {
				seats[i][0] = 'A';
			}
			for (int i = 0; i < size; i++) {
				seats[i][1] = 'B';
			}
			for (int i = 0; i < size; i++) {
				seats[i][2] = 'C';
			}
			for (int i = 0; i < size; i++) {
				seats[i][3] = 'D';
			}
			cout << "Tickets available for sale:" << endl;
			for (int i = 0; i < size; i++) {
				cout << seats[i][0];
				for (int b = 1; b < 4; b++) {
					cout << seats[i][b];
				}
				cout << "" << endl;
			}
			int num = 0;
			int num1 = 0;
			cout << "what would like to order??" << endl;
			cin >> num;
			cin >> num1;
			for (int i = 0; i < 1; i++) {
				if (seats[num][num1] != 'x') {
					cout << "seat found" << endl;
					seats[num][num1] = 'x';
					break;
				} else {
					cout << "seat is taken" << endl;
				}
			}
			cout << "current seat layout-x means taken" << endl;
			for (int i = 0; i < size; i++) {
				cout << seats[i][0];
				for (int b = 1; b < 4; b++) {
					cout << seats[i][b];
				}
				cout << "" << endl;
			}
			while (1) {
				char chose;
				cout << "would like to order more tickets(y-yes...n-no)?" << endl;
				cin >> chose;
				if (chose == 'y') {
					cout << "what would like to order??" << endl;
					cin >> num;
					cin >> num1;
					for (int i = 0; i < 1; i++) {
						if (seats[num][num1] != 'x') {
							cout << "seat found" << endl;
							seats[num][num1] = 'x';
							break;
						} else {
							cout << "seat is taken" << endl;
						}
					}
					cout << "current seat layout-x means taken" << endl;
					for (int i = 0; i < size; i++) {
						cout << seats[i][0];
						for (int b = 1; b < 4; b++) {
							cout << seats[i][b];
						}
						cout << "" << endl;
					}

				}
				if (chose == 'n') {
					break;
				}
			}
		} //if 1
		if(choice==2){
			ifstream in;
			ofstream out;
			in.open("input.txt");
			int size=0;
			char **seats;
			in >> size;
			seats = new char*[size];
			for (int i = 0; i < size; i++) {
				seats[i] = new char[4];
			}

			for (int i = 0; i < size; i++) {
				seats[i][0] = 'A';
			}
			for (int i = 0; i < size; i++) {
				seats[i][1] = 'B';
			}
			for (int i = 0; i < size; i++) {
				seats[i][2] = 'C';
			}
			for (int i = 0; i < size; i++) {
				seats[i][3] = 'D';
			}
			cout << "Tickets available for sale:" << endl;
			for (int i = 0; i < size; i++) {
				cout << seats[i][0];
				for (int b = 1; b < 4; b++) {
					cout << seats[i][b];
				}
				cout << "" << endl;
			}
			while(!in.eof()){
			int num = 0;
			int num1 = 0;
			in >> num;
			in >> num1;
			for (int i = 0; i < 1; i++) {
				if (seats[num][num1] != 'x') {
					cout << "seat found" << endl;
					seats[num][num1] = 'x';
					break;
				} else {
					cout << "seat is taken" << endl;
				}
			}
			cout << "current seat layout-x means taken" << endl;
			for (int i = 0; i < size; i++) {
				cout << seats[i][0];
				for (int b = 1; b < 4; b++) {
					cout << seats[i][b];
				}
				cout << "" << endl;
			}
			}
	}
	} while (choice != 3);
	return 0;
}
/*
 * 1-start from console
2-start from file
3-stop
1
how many rows
4
Tickets available for sale:
ABCD
ABCD
ABCD
ABCD
what would like to order??
1
3
seat found
current seat layout-x means taken
ABCD
ABCx
ABCD
ABCD
would like to order more tickets(y-yes...n-no)?
y
what would like to order??
2
3
seat found
current seat layout-x means taken
ABCD
ABCx
ABCx
ABCD
would like to order more tickets(y-yes...n-no)?
n
1-start from console
2-start from file
3-stop
3
*/

