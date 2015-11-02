//============================================================================
// Name        : lecture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int *array;
	int size = 0;
	int number = 0;
	int *f;
	int *r;
	cout << "size of array" << endl;
	cin >> size;
	array = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> number;
		array[i] = number;
	}
	int temp2 = 0;
	temp2 = size;
	f = new int[size];
	r = new int[size];
	int temp = 0;
	for (int i = 0; i < size; i++) {
		f[i] = array[i];
		r[i] = array[size];
		temp = array[i];
		array[i] = r[i];
		array[size] = temp;
		size--;
	}
	for (int a = 0; a < temp2; a++) {
		cout << array[a] << endl;
	}
	return 0;
}
/*
size of array
3
1
2
3
0
3
2
 */
