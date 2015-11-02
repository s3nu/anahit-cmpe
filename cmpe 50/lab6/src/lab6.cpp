//============================================================================
// Name        : lab6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class res {
public:
	res();
	res(int d);
	int ret1(int a);
	int ret2(int b);
	int val1(int a);
	int val2(int b);
	void output(ostream &out_stream);
	friend bool check(res &a, res &b);
private:
	int status;
	int to;

};
int main() {
	int choice = 0;
	int a, b = 0;
	res rest, rest1;
	do {

		cout << "1-change value of first object" << endl;
		cout << "2-change value of second object" << endl;
		cout << "3-display status member" << endl;
		cout << "4-check status" << endl;
		cout << "5-display each member" << endl;
		cout << "6-quit" << endl;
		cin>>choice;
		if (choice == 1) {
			cout<<"0 or 1"<<endl;
			cin>>a;
			rest.val1(a);
		}
		if (choice == 2) {
			cout<<"0 or 1"<<endl;
			cin>>b;
			rest1.val1(b);
		}
		if (choice == 3) {
			rest.output(cout);

		}
		if (choice == 4) {
			check(rest, rest1);
		}
		if (choice == 5) {
			rest.ret1(a);
			cout<<"member 1-"<<a<<endl;
			rest1.ret2(b);
			cout<<"member 2-"<<b<<endl;

		}


	} while (choice != 6);

	return 0;
}
res::res() {
	status = 0;
	to = 0;
}
res::res(int a) {
	to = a;
	status=0;
}
int res::ret1(int a) {
	status=a;
	return status;
}
int res::ret2(int b) {
	to=b;
	return to;
}

int res::val1(int a) {
	status=a;
	return status;
}

int res::val2(int b) {
	to=b;
	return to;
}
void res::output(ostream &out_stream) {
	out_stream<<status<<endl;


}
bool check(res &a, res &b){
	if (a.status==1&&b.status==1) {
		cout<<"resource available"<<endl;
		return true;
	}
	else {
		cout<<"resource unavailable"<<endl;
		return false;
	}

}
/*
 * 1-change value of first object
2-change value of second object
3-display status member
4-check status
5-display each member
6-quit
1
0 or 1
1
1-change value of first object
2-change value of second object
3-display status member
4-check status
5-display each member
6-quit
2
0 or 1
1
1-change value of first object
2-change value of second object
3-display status member
4-check status
5-display each member
6-quit
3
1
1-change value of first object
2-change value of second object
3-display status member
4-check status
5-display each member
6-quit
4
resource available
1-change value of first object
2-change value of second object
3-display status member
4-check status
5-display each member
6-quit
5
member 1-1
member 2-1
1-change value of first object
2-change value of second object
3-display status member
4-check status
5-display each member
6-quit
6
 *
 */
