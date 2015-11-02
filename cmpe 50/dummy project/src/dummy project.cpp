//============================================================================
// Name        : dummy.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


double hat(int weight, int height);
double jacket(int weight, int height,int age);
double waist(int weight, int age);
int main() {
	while (1) {
	int weight;
	int height;
	int age;
	double hsize;
	double jsize;
	double waistsize;
	cout << "what is your weight?" << endl;
	cin >> weight;
	cout << "what is your height?" << endl;
	cin >> height;
	cout << "what is your age?" << endl;
	cin >> age;
	hsize=hat(weight,height);
	jsize=jacket(height,weight,age);
	waistsize=waist(weight, age);
	cout<<"your hat size\n"<<hsize<<endl;
	cout<<"your jacket size\n"<<jsize<<endl;
	cout<<"your waist size\n"<<waistsize<<endl;



	}

	return 0;

}
double hat(int weight, int height) {
	double sizehat;
	sizehat=(weight/height)*2.9;
	return sizehat;
}
double jacket(int height, int weight, int age) {
	double sizejacket;
	sizejacket=(height*weight)/288+(1/8)*(age-30)/10;
	return sizejacket;
}
double waist(int weight, int age){
	double waistsize;
	waistsize= weight/5.7+ (1/10)*(age-28)/2;
	return waistsize;
}
