//============================================================================
// Name        : lecture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

template<class T>
int search(T *array, int size, T num) {
	bool test=false;
	for (int i = 0; i < size; i++) {
		if (num == array[i]) {
			cout << "number has been found--position is " << i << endl;
			cout << "number is--" << array[i] << endl;
			test = true;
			break;
		}
		else if (test==true) {
			cout << "returning -1" << endl;
			return -1;
		}

	}
}
int main() {

	int size = 0;
	int num1 = 0;
	cout << "enter size of array" << endl;
	cin >> size;
	int *array;
	array = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "enter array" << endl;
		cin >> array[i];
	}
	cout << "enter type of array" << endl;
	cin >> num1;
	search(array, size, num1);
}
/*
 *enter size of array
5
enter array
2
enter array
3
enter array
4
enter array
6
enter array
7
enter type of array
5
 *
 *
 *enter size of array
5
enter array
1
enter array
2
enter array
3
enter array
4
enter array
5
enter type of array
2
number has been found--position is 1
number is--2
 *
 *
 *
 */
//working for integer will work for char and string
