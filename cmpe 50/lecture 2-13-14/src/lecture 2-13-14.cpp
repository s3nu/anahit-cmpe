//============================================================================
// Name        : lecture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	char array[100];
	ifstream in;
	ofstream out;
	ifstream ifs;
	in.open("input.txt");
	out.open("output.txt");
	char uno=0;
	int linenum=1;
	int i =0;
	while(uno!='\n') {
		in.get(uno);
		array[i]=uno;
		i++;
	}
	array[i]=0;
	cout<<array<<endl;
	cout<<uno;
	out<<setfill('0')<<setw(3)<<linenum<<":";
	out<<array<<endl;

	return 0;
}
/*
 * 001:line one
 */
