//============================================================================
// Name        : lecture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class pet {
public:
	pet();
	void petset(string nm, int ag,string dt[]);
	pet(const pet &p1);
	virtual ~pet();
	void setsize(int sz);
	virtual void print(const pet &p3);
	pet& operator=(const pet &p2);
private:
	string name;
	int age;
	string* date;
	int size;
};
class dog: public pet {
public:
	dog();
	dog(string bd, string sh, int size);
	dog(const dog &d1);
	virtual ~dog();
	virtual void print2(const dog &d3);
	dog operator=(const dog &d1);

private:
	string breed;
	string* shot;
};

int main() {

	return 0;
}
pet::pet() {
	name="NULL";
	age=0;
	date=new string;
	size=0;
}
void pet::petset(string nm, int ag,string dt[]) {
	name=nm;
	age=ag;
	date=new string[size];
	for (int i=0;i<size;i++ ) {
		date[i]=dt[i];
	}
}
pet::pet(const pet &p1) {
	date=new string[size];
	for (int i=0;i<size;i++ ) {
		date[i]=p1.date[i];
	}
}
pet::~pet() {
	delete [] date;
}
void pet::print(const pet &p3) {
	for (int i=0; i<size; i++){

		cout<<"Age"<<p3.age<<endl;
		cout<<"Name"<<p3.name<<endl;
		cout<<"dates"<<p3.date<<endl;
	}
}
pet& pet::operator=(const pet &p2) {
	age=p2.age;
	name=p2.name;
	if (this==&p2){
		return *this;
	}
	else {
		for (int i=0; i<size; i++){
			p2.date[i]=date[i];
		}
	}
	return *this;
}

void pet::setsize(int sz){
	cout<<"how many pets"<<endl;
	cin>>sz;
	size=sz;
}
