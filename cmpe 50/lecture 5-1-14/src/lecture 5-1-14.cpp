//============================================================================
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <vector>
#include <iostream>
#include<cctype>
using namespace std;
vector<string> split(string target, string delimiter);
int main() {
	string a, b;
	cout << "enter string" << endl;
	cin >> a;
	cout << "enter delimiter" << endl;
	cin >> b;
	split(a, b);

	return 0;
}
vector<string> split(string target, string delimiter) {
	string str, sstr, str2;
	str = target;
	sstr = delimiter;
	int index, index2, size = 0;
	size = str.size();
	index = str.find(sstr);
	index2 = sstr.size();
	while (index != string::npos) {
		str = str.erase(index);
		str = str.replace(index, 1, ",");
	}
	str = str + str2;
	cout << str << endl;
}
