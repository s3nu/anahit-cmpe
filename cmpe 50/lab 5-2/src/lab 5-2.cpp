//============================================================================
// Name        : lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class type {
public:
	type();
	type(double a);
	double in(double b);
	double dec(double c);
	double dis(double d);
	void show(double e);
private:
	double count;
};
int main() {
	type st();
	double count = 0;
	int choice = 0;
	cout << "what is the starting count" << endl;
	cin >> count;
	do {
		cout << "1-add to counter" << endl;
		cout << "2-lower counter" << endl;
		cout << "3-show count" << endl;
		cout << "4-reset count" << endl;
		cout << "5-quiz" << endl;
		cin >> choice;

		type st(count);
		if (choice == 1) {
			count = st.in(count);
		}
		if (choice == 2) {
			count = st.dec(count);
		}
		if (choice == 3) {
			st.show(count);
		}
		if (choice == 4) {
			count = st.dis(count);
		}
		if (choice == 5) {
			exit(1);
		}

	} while (choice != 5);

}
type::type() {
	count = 0;
}
type::type(double a) {
	count = a;
}
double type::in(double b) {
	b++;
	return b;

}
double type::dec(double c) {
	c--;
	return c;
}
double type::dis(double d) {
	d = 0;
	return d;
}
void type::show(double e) {
	if (e>0) {
		cout << "your print out is: "<<e<< endl;

	}
	else {
		cout<<"you print out is:0"<<endl;
	}

}
/* output
 * what is the starting count
30
1-add to counter
2-lower counter
3-show count
4-reset count
5-quiz
1
1-add to counter
2-lower counter
3-show count
4-reset count
5-quiz
1
1-add to counter
2-lower counter
3-show count
4-reset count
5-quiz
3
your print out is: 32
1-add to counter
2-lower counter
3-show count
4-reset count
5-quiz
4
1-add to counter
2-lower counter
3-show count
4-reset count
5-quiz
3
you print out is:0
1-add to counter
2-lower counter
3-show count
4-reset count
5-quiz
5
 *
 */
