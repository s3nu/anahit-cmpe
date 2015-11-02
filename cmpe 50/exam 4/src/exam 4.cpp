//============================================================================
// Name        : test4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
//-------------------------------------------exercise 1----------------------------------------------------
vector <int> organise (vector<int> &array, int size){//vector STL
	int *counter;
	counter= new int[size];
	for (int a=0; a<size;a++){//recurences
		int count=0;
		int up=0;
		for (int i=0;i<size;i++){
			if (array[a]==array[count]){
				counter[a]=up+1;
				up++;
			}
			count++;
		}
	}
	sort(array.begin(),array.begin()+size);//sorting
	int max=size-1;
	for (int b=0; b<size; b++){
		cout<<array[max]<<"            "<< counter[b]<<endl;
		max--;
	}
	return array;
}
//-------------------------------------------exercise 1----------------------------------------------------END

//-------------------------------------------exercise 2----------------------------------------------------
class cust{//base class
public:
	cust();//deafult
	virtual ~cust();//destructor
	void getinfo();//get information
	virtual void  print();//printer
protected:
	string name;
	int age;
	int time;
	int *price;
};
class vip: public cust{//vip class
public:
	vip();//deafult
	void getinfo2();//get information
	virtual ~vip();//destructor
	virtual void print();//printer
private:
	string title;
	int crebate;
	int *rebate;
};
void printrecord(cust &obj);//function for exercise 2
//-------------------------------------------exercise 2----------------------------------------------------END



//--------------------------------------MAIN----------------------------------------------
int main() {
	int choice=0;
	do {
		cout<<"1-Program 1"<<endl;
		cout<<"2-program 2"<<endl;
		cout<<"3-exit"<<endl;
		cin>>choice;

		if(choice==1){//exercise 1
			vector<int> arr;
			int num=0;
			while(num != 999){
				cout<<"enter your number please"<<endl;
				cin>>num;
				arr.push_back(num);
			}
			int sz=0;
			arr.pop_back();//deletes last item--999
			sz=arr.size();
			organise(arr, sz);//send vector to vector STL
		}
		if(choice==2){//exercise 2
			int ch=0;
			cout<<"1-regular customer--2-vip customer"<<endl;
			cin>>ch;
			if (ch==1){
				cust cp;
				cp.getinfo();
				printrecord(cp);

			}
			if (ch==2){
				vip vp;
				vp.getinfo();
				vp.getinfo2();
				printrecord(vp);

			}

		}
	}while(choice != 3);//end choice loop
	return 0;
}
//--------------------------------------MAIN----------------------------------------------END
void printrecord(cust &obj){//function for exercise 2
	obj.print();

}

//-------------------------------------------Definition for EX 2----------------------------------------------------
cust::cust(){
	age=0;
	time=0;
	price=new int;

}
cust:: ~cust(){
	delete []price;
}
void cust::getinfo(){
	cout<<"enter name"<<endl;
	cin>>name;
	cout<<"enter age"<<endl;
	cin>>age;
	cout<<"enter time of purchase"<<endl;
	cin>>time;
	int price1=0;
	price=new int[time];
	for (int i=0;i<time;i++){
		cout<<"enter amount at time of purchase"<<endl;
		cin>>price1;
		price[i]=price1;
	}
}
void cust::print(){
	cout<<"Name: "<< name<<endl;
	cout<<"Age: "<< age<<endl;
	for (int i=0;i<time;i++){
		cout<<"Purchases:"<<price[i]<<endl;
	}
}

vip::vip(){
	title=title+name;
	crebate=0;
	rebate=new int;
}
void vip::getinfo2(){
	cout<<"enter title"<<endl;
	cin>>title;
	cout<<"enter number of rebate"<<endl;
	cin>>crebate;
	int rebate1=0;
	rebate=new int[crebate];
	for (int i=0; i<crebate;i++){
		cout<<"enter rebate"<<endl;
		cin>>rebate1;
		rebate[i]=rebate1;
	}
}
vip::~vip(){
	delete []rebate;
}
void vip::print(){
	cout<<"Name: "<< name<<endl;
	cout<<"Title"<< title<<endl;
	cout<<"Age: "<< age<<endl;
	for (int i=0;i<time;i++){
		cout<<"Purchases:"<<price[i]<<endl;
	}
	for (int i=0;i<crebate;i++){
		cout<<"Amount of Rebates: "<< rebate[i]<<endl;
	}

}
//-------------------------------------------Definition for EX 2----------------------------------------------------END
/*
 * 1-Program 1
2-program 2
3-exit
1
enter your number please
3
enter your number please
8
enter your number please
3
enter your number please
4
enter your number please
5
enter your number please
6
enter your number please
999
8            2
6            1
5            2
4            1
3            1
3            1
1-Program 1
2-program 2
3-exit
 *
 */
/*1-Program 1
2-program 2
3-exit
2
1-regular customer--2-vip customer
1
enter name
anahit
enter age
19
enter time of purchase
2
enter amount at time of purchase
100
enter amount at time of purchase
100
Name: anahit
Age: 19
Purchases:100
Purchases:100
1-Program 1
2-program 2
3-exit
2
1-regular customer--2-vip customer
2
enter name
anahit
enter age
19
enter time of purchase
2
enter amount at time of purchase
90
enter amount at time of purchase
90
enter title
Dr
enter number of rebate
2
enter rebate
100
enter rebate
90
Name: anahit
TitleDr
Age: 19
Purchases:90
Purchases:90
Amount of Rebates: 100
Amount of Rebates: 90
1-Program 1
2-program 2
3-exit
 */


