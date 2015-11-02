//============================================================================
// Name        : lab2-1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

double add(double a, double a1);
int add(int b,int b1);
char add(char arr[],char arr1[]);

int main() {
	while (1) {
	int choice=0;
	cout<<"Do you want to add a:\n"
			"1-char\n"
			"2-int\n"
			"3-double\n"<<endl;
	cin>>choice;
	if (choice==1) {
		char array[100];
		char array1[100];
		cout<<"enter array 1 to fill array?\n"<<endl;
		cin>>array;
		cout<<"enter array 2 to fill array?\n"<<endl;
		cin>>array1;
		add(array,array1);

	}
	else if(choice==2) {
		int num1=0;
		int num2=0;
		cout<<"enter int1?\n"<<endl;
		cin>>num1;
		cout<<"enter int2?\n"<<endl;
		cin>>num2;
		int sum=0;
		sum=add(num1,num2);
		cout<<"The integer added:\n"<<sum<<endl;
	}
	else if (choice==3) {
		double i2=0;
		double i=0;
		double sum1=0;
		cout<<"enter double1?\n"<<endl;
		cin>>i2;
		cout<<"enter double2?\n"<<endl;
		cin>>i;
		sum1=add(i2,i);
		cout<<"Doubles added:\n"<<sum1<<endl;


	}
	}
	return 0;
}
double add(double a, double a1) {
	double sum2=0;
	sum2=a+a1;
	return sum2;


}
int add(int b,int b1){
	int summer=0;
	summer=b+b1;
	return summer;
}
char add(char arr[],char arr1[]){
	cout<<"array output-1:\n"<<arr<<endl;
	cout<<"array output-2:\n"<<arr1<<endl;

}


/*solution
 * Do you want to add a:
1-char
2-int
3-double

1
enter array 1 to fill array?

abbre
enter array 2 to fill array?

sdfs
array output-1:
abbre
array output-2:
sdfs
Do you want to add a:
1-char
2-int
3-double

2
enter int1?

2
enter int2?

2
The integer added:
4
Do you want to add a:
1-char
2-int
3-double

3
enter int1?

45
enter int2?

45
Doubles added:
90
 */


