//============================================================================
// Name        : lecture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
class duple
{
public:
	duple();
	duple(int fisrt, int second);
	friend istream& operater >>(istream& ins, duple& second);
	friend ostream& operater <<(ostream& outs, const duple& second);
	friend duple operater+(duple& second);
	friend duple operater-(duple& second);
private:
	int f;
	int s;
};




int main() {
	duple dup1,dup2,dup3;
	cin>>dup1;
	cin>>dup1;
	dup3=dup1+dup2;
	cout<<dup3<<endl;
	dup3=dup2-dup1;
	cout<<dup3;

	return 0;
}
duple::duple() {
	f=0;
	s=0;
}
istream& operater >>(istream& ins, duple& second) {
	return ins;

}
ostream& operater <<(ostream& outs, const duple& second) {
return outs;
}
