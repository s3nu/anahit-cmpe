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
	string str, str2;
	cout << "enter your first name" << endl;
	cin >> str;
	cout << "enter your last name" << endl;
	cin >> str2;
	int len = 0;
	int lent = 0;
	char c;
	char b;
	len = str.length();
	lent = str2.length();
	for (int i = 0; i < len; i++) {
		tolower(str[i]);
	}
	for (int i2 = 0; i2 < len; i2++) {
		tolower(str2[i2]);
	}
	c = str[0];
	b = str2[0];
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		cout << str << "way";
	} else {
		str = str.substr(1, len);
		str = str + c;
		cout << str << "ay";
	}
	if (b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u') {

		cout << str << "way";
	} else {
		str2 = str2.substr(1, lent);
		str2 = str2 + b;
		cout << str2 << "ay";
	}
	return 0;
}

/*
 * enter your first name
anahit
enter your last name
sarao
anahitwayaraosay
 */
