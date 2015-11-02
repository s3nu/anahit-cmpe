//============================================================================
// Name        : lab6-1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class rat {
public:
	rat();
	rat(int a, int b);
	void intput(istream& in);
	void output(ostream& out);
	friend rat add(rat &one, rat&two);
	friend rat sub(rat &one, rat&two);
	friend rat mult(rat &one, rat&two);
	friend rat dev(rat &one, rat&two);
	friend bool equal(rat &one, rat&two);
	friend bool lessthan(rat &one, rat&two);
private:
	int dem;
	int num;
};
int main() {
	rat rt, rt1, rt3;
	int choice = 0;
	bool a;
	do {
		cout << "1-enter first fraction" << endl;
		cout << "2- second fraction" << endl;
		cout << "3-add" << endl;
		cout << "4-subb" << endl;
		cout << "5-multiply" << endl;
		cout << "6-divide" << endl;
		cout << "7-equal" << endl;
		cout << "8-less than" << endl;
		cout << "9-quit" << endl;
		cout << "" << endl;
		cin >> choice;
		if (choice == 1) {
			rt.intput(cin);
		}
		if (choice == 2) {
			rt1.intput(cin);
		}
		if (choice == 3) {
			rt3 = add(rt, rt1);
			rt3.output(cout);
		}
		if (choice == 4) {
			rt3 = sub(rt, rt1);
			rt3.output(cout);
		}
		if (choice == 5) {
			rt3 = mult(rt, rt1);
			rt3.output(cout);
		}
		if (choice == 6) {
			rt3 = dev(rt, rt1);
			rt3.output(cout);
		}
		if (choice == 7) {
			equal(rt, rt1);
		}
		if (choice == 8) {
			a=lessthan(rt,rt1);
		}

	} while (choice != 9);

	return 0;
}
rat::rat() {
	dem = 0;
	num = 0;
}
void rat::intput(istream& in) {
	cout << "enter in num" << endl;
	in >> num;
	cout << "enter in dem" << endl;
	in >> dem;
}
void rat::output(ostream& out) {
	out << "Output:" << num << "/" << dem << flush << endl;
}
rat::rat(int a, int b) {
	dem = a;
	num = b;
}
rat add(rat &one, rat&two) {
	rat temp;
	temp.num = (one.dem * two.num) + (one.num * two.dem);
	temp.dem = (one.dem * two.dem);
	return temp;
}
rat sub(rat &one, rat&two) {
	rat temp1;
	temp1.num = (one.num * two.dem) - (one.dem * two.num);
	temp1.dem = (one.dem * two.dem);
	return temp1;

}
rat mult(rat &one, rat&two) {
	rat temp2;
	temp2.num = (one.num * two.num);
	temp2.dem = (one.dem * two.dem);
	return temp2;

}
rat dev(rat &one, rat&two) {
	rat temp3;
	temp3.num = (one.num * two.dem);
	temp3.dem = (one.dem * two.num);
	return temp3;

}
bool equal(rat &one, rat&two) {
	double val = 0;
	double val1 = 0;
	val = one.dem / one.num;
	val1 = two.dem / two.num;
	cout<<"checking for equality"<<endl;
	if (val == val1) {
		cout << "true" << endl;
		return true;
	}
	else {
		cout<<"false"<<endl;
		return false;
	}
}
bool lessthan(rat &one, rat&two) {
	double val1 = 0;
	double val2 = 0;
	val1 = one.dem / one.num;
	val2 = two.dem / two.num;
	cout<<"checking if first fraction is less than second"<<endl;
	if (val1<val2) {
		cout << "true" << endl;
		return true;
	}
	else {
		cout<<"false"<<endl;
		return false;
	}
}
/*
 * 1-enter first fraction
2- second fraction
3-add
4-subb
5-multiply
6-divide
7-equal
8-less than
9-quit

1
enter in num
1
enter in dem
2
1-enter first fraction
2- second fraction
3-add
4-subb
5-multiply
6-divide
7-equal
8-less than
9-quit

2
enter in num
1
enter in dem
2
1-enter first fraction
2- second fraction
3-add
4-subb
5-multiply
6-divide
7-equal
8-less than
9-quit

3
Output:4/4
1-enter first fraction
2- second fraction
3-add
4-subb
5-multiply
6-divide
7-equal
8-less than
9-quit

4
Output:0/4
1-enter first fraction
2- second fraction
3-add
4-subb
5-multiply
6-divide
7-equal
8-less than
9-quit

5
Output:1/4
1-enter first fraction
2- second fraction
3-add
4-subb
5-multiply
6-divide
7-equal
8-less than
9-quit

5
Output:1/4
1-enter first fraction
2- second fraction
3-add
4-subb
5-multiply
6-divide
7-equal
8-less than
9-quit

6
Output:2/2
1-enter first fraction
2- second fraction
3-add
4-subb
5-multiply
6-divide
7-equal
8-less than
9-quit

7
checking for equality
true
1-enter first fraction
2- second fraction
3-add
4-subb
5-multiply
6-divide
7-equal
8-less than
9-quit

8
checking if first fraction is less than second
false
1-enter first fraction
2- second fraction
3-add
4-subb
5-multiply
6-divide
7-equal
8-less than
9-quit
 */
