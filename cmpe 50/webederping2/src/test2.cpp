//============================================================================
// Name        : test2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include "test.h"
using namespace std;

int main() {//main
	void swap(char one[]);
	int choice = 0;
	do {
		cout << "1-ex2" << endl;
		cout << "2-ex3" << endl;
		cout << "3-end" << endl;
		cin >> choice;
		if (choice == 1) {//ex1
			char two[100];
			cout << "enter your a c-string" << endl;
			cin >> two;
			swap (two);
		}
		if (choice == 2) {//ex2
			stack stk1();
			stack stk2;
			bool hi;
			hi=stk2.isempty();



		}
	} while (choice != 3);

	return 0;
}

void swap(char one[]) {//swap front to back
	int size = 0;
	char *front, *rear;
	size = strlen(one);
	front=one;
	rear=&(one[size-1]);
	for (int i = 0; i < ((size-1)/2); i++) {
		char place=*front;
		*front=*rear;
		*rear=place;
		front++;
		rear--;
	}
	cout << "string reversed:" << endl;
	for (int m = 0; m < size; m++) {
		cout << one[m];
	}
	cout << endl;

}
/*1-ex2
2-ex3
3-end
1
enter your a c-string
hello
string reversed:
olleh
1-ex2
2-ex3
3-end
 * */

