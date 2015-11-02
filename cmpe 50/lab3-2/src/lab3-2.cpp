//============================================================================
// Name        : lab3-2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <cctype>
#include <iomanip>
using namespace std;

int main() {
	ifstream in;
	ofstream out;
	int array[50];
	char name[10];
	int check = 0;

	int t = 0;
	int i3 = 0;
	int array2[50];
	int choice = 0;
	do {
		cout << "1-file enter" << endl;
		cout << "2-console entry" << endl;
		cout << "3-exit" << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "file name please?" << endl;
			cin >> name;
			in.open("input.txt");
			if (in.fail()) {
				cout << "open failed" << endl;
				exit(1);
			}
			int s = 0;
			int number = 0;
			while (in >> number) {
				array[s] = number;
				s++;
			}
			out.open("output.txt");
			for (int i4 = 0; i4 < s; i4++) {
				int stunt = 0;
				check = array[i4];
				for (int w = 0; w < s; w++) {
					if (check == array[w]) {
						++stunt;
						array2[i4] = stunt;
					}
				}
			}
			for (int z = 0; z < s; z++) {
				out<<(array[z]);
				out<<(array2[z])<<endl;

			}
		}
		if (choice == 2) {

			cout << "enter integer list" << endl;
			while (t != 999) {
				cin >> t;
				array[i3] = t;
				i3++;
			}
			i3--;

			for (int i = 0; i < i3; i++) {
				int stunt = 0;
				check = array[i];
				for (int i2 = 0; i2 < i3; i2++) {
					if (check == array[i2]) {
						++stunt;
						array2[i] = stunt;
					}
				}
			}
			for (int z = 0; z < i3; z++) {
				cout << array[z];
				cout << array2[z] << endl;

			}

		} //if statement
	} while (choice != 3);

	return 0;
}
