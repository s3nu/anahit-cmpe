//============================================================================
// Name        : lecture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cctype>
#include <string.h>
using namespace std;

int main() {
	char array[100];
	int count = 0;
	char check;
	int lol = 0;
	int word = 0;

	cout << "enter line of text" << endl;
	cin.getline(array, 100);
	count = strlen(array);

	for (int i = 0; i < count; i++) {
		if (isalpha(array[i])) {

			lol++;
			tolower(array[i]);
		} else {
			if (array[i] == ' ' || array[i] == '\n') {
				word++;
			}
		}
	}
	int ck2[100];

	for (int w = 0; w < count; w++) {
		check = array[w];
		int stunt = 0;
		for (int z = 0; z < count; z++) {
			if (check == array[z]) {

				++stunt;
				ck2[w] = stunt;

			} else if (check == ' ') {
				ck2[w] = '\n';
			}
		}
	}
	for (int s = 0; s < count; s++) {
		if (array[s] == ' ') {

		} else {
			cout << array[s] <<" "<<ck2[s] << endl;
		}
	}

	cout << "number of letters:" << lol << endl;
	cout << "number of words:" << word + 1 << endl;

	return 0;
}

/*enter line of text
nadim
n 1
a 1
d 1
i 1
m 1
number of letters:5
number of words:1
 *
 */
