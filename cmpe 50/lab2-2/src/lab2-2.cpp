//============================================================================
// Name        : lab2-2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int count=0;
	char array[10];
	int i=0;
	while (1) {
	char a;
	cout<<"please enter 10 letters??\n"<<endl;
	cin>>a;
	if (a != '.') {
		array[i]=a;
		i++;
	}
	else if (a=='.') {
		break;
	}
	}
	array[i]='\0';
	count=strlen(array);
	for (int i=count-1; i>=0; i--) {
		cout<<array[i]<<endl;
	}

	return 0;
}
/*solution
 * please enter 10 letters??
a
please enter 10 letters??

b
please enter 10 letters??

d
please enter 10 letters??

f
please enter 10 letters??

.

f
d
b
a
 */
