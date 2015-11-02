//============================================================================
// Name        : class.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
using namespace std;

int main() {
	double number[100];
	double sum=0;
	double average=0;
	ifstream in_stream;
	ofstream out_stream;
	in_stream.open("input.txt");
	int counter =0;

	if (in_stream.fail()) {
		cout<<"open failed\n"<<endl;
		exit (1);
	}



	for (int i=0;i<10; i++) {
		in_stream>>number[i];
		counter++;
	}
	for (int i=0; i<10; i++) {
		sum+=number[i];
	}
	average=sum/counter;
	cout<<average<<endl;
	return 0;
}
/*input file
 * 1 2 3 4 5 6 7 8 9 10
 *
 * solution
 *
 * 5.5
 */
