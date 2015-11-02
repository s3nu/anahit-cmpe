//============================================================================
// Name        : lecture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
string month1[12] = { "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug",
		"sep", "oct", "nov", "dec" };
class month {
public:
	month();
	month(string a);
	void months(int a);
	void input(istream&);
	void output(ostream&);
	void nextmonth(int a);
private:
	int mon;

};
int main() {
	int lol = 0;
	string mystr;
	int choice;
	do {
		month mn;
		cout << "1-char" << endl;
		cout << "2-number" << endl;
		cout << "3-exit" << endl;
		cin>>lol;
		if (lol==1) {
		cout << "enter three characters" << endl;
		cin >> mystr;
		month mn(mystr);
		}
		if (lol==2) {
		cout << "enter one number" << endl;
		cin >> choice;
		mn.months(choice);
		mn.nextmonth(choice);
		}
	} while (lol != 3);

	return 0;
}
month::month() {
	mon = 0;
}
month::month(string a) {
	int value;
	for (int i = 0; i < 12; i++) {
		if (a == month1[i]) {
			value = i + 1;
		}
	}
	cout <<"month as a number: "<< value << endl;
	cout<< "next month as a number: "<<value+1<<endl;
}
void month::months(int a) {
	a--;
	cout << month1[a] << endl;
}
void month::nextmonth(int a) {
	cout << "next month char: " << month1[a + 1] << endl;
	cout << "next month number: " << a << endl;
}
/*output
 * 1-char
2-number
3-exit
1
enter three characters
jan
month as a number: 1
next month as a number: 2
1-char
2-number
3-exit
2
enter one number
2
feb
next month char: apr
next month number: 2
1-char
2-number
3-exit
3
 *
 */

