//============================================================================
// Name        : Lecture3-13-2014.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <istream>
using namespace std;

class Duple {
public:
	Duple();
	Duple(int first, int second);
	friend istream& operator >>(istream& ins, Duple& second);
	friend ostream& operator <<(ostream& outs, const Duple& second);
	friend Duple operator+(Duple& second);
	friend Duple operator-(Duple& second);
private:
	int f;
	int s;
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Duple dup1, dup2, dup3;
	cin >> dup1; //Enter 1, 3 from console
	cin >> dup2; //Enter 2, 4
	dup3 = dup1 + dup2;
	cout << dup3; // it should print out(3,7)
	dup3 = dup2 - dup1;
	cout << dup3; //(1,1)
	return 0;
}

Duple::Duple() {
	f = 0;
	s = 0;
}
Duple::Duple(int first, int second) {
	f = first;
	s = second;
}
operator+(Duple& second){
	Duple tdup;
	tdup=second.f+second.s;
	tdup=second.s+second.f;

}
operator-(Duple& second){
	Duple tdup;
	tdup=second.f-second.s;
	tdup=second.s-second.f;
}

istream& operator >>(istream& ins, Duple& second) {
	ins >> second.f >> second.s;
	return ins;
}

ostream& operator <<(ostream& outs, const Duple& second) {
	outs << "f: " << second.f << "s: " << second.s;
	return outs;
}
