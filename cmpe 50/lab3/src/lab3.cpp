//============================================================================
// Name        : lab3.cpp
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

using namespace std;

int main() {
	ifstream in;
	ofstream out;
	char single;
	int lent;
	char array[100]={0};
	char array2[100];
	char lower;
	char upper;
	in.open("input.txt");
	if (in.fail()) {
		cout << "open failed" << endl;
		exit(1);
	}

	int i = 0;
	while (in.get(single)) {
		//if (isalpha(single)) {
			array[i] = single;
			cout << array[i] << endl;
			i++;
		//}
	}

	out.open("output.txt");
	lent = strlen(array);
	array[i]='\n';
	for (int i2 = 0; i2 < lent; i2++) {
		upper = toupper(array[i2]);
		array2[i2] = upper;
		cout << array2[i2] << endl;
		out.put(array2[i2]);

	}



	return 0;
}
