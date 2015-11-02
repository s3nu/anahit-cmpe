//============================================================================
// Name        : class5-1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main() {
	ifstream in_stream;
	ofstream out_stream;
	double array[10];
	char name[32];
	in_stream.open("input.txt");
	if (in_stream.fail()) {
		cout<<"open failed\n"<<endl;
		exit (1);
	}

		in_stream>>name;
		cout.setf(ios::left);
		cout<<setw(10)<<name;

		for (int i=0;i<10; i++) {
			in_stream>>array[i];
			cout<<setw(6)<<array[i];
			out_stream.open("output.txt");
		}


	return 0;
}
