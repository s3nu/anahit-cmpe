//============================================================================
// Name        : Lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cctype>
#include <stack>
#include <queue>



using namespace std;

string lower(string name);
bool check(string name);
bool check2(string name);

int main() {
	int option =0;
	cout<<"Welcome to the palindrome checker...\n\n"<<endl;
	do{
		cout<<"Press 1 to continue or\nPress 2 to exit\n"<<endl;
		cin>>option;

		if(option==1){

			string name;
			cout<<"Which word would you like to check for palindrome?"<<endl;
			cin>>name;
			name=lower(name);

			if(check2(name)){
				cout<<"Your word is a Palindrome\n\n"<<endl;
			}

			else{
				cout<<"Your word is not a palindrome\n\n"<<endl;
			}
		}

		if(option==2){
			cout<<"Exiting Program"<<endl;
		}
	}while(option!=2);
	return 0;
}


string lower(string name){

	string lower_case;
	for(unsigned int i=0;i<name.size();i++){

		lower_case+=tolower(name[i]);

	}


	return lower_case;


}
bool check(string name){
	queue<char> Q;
	stack<char> S;
	int counter=0;
	unsigned int popper=0;
	for(unsigned int i=0;i<name.size();i++){

		Q.push(name[i]);
		S.push(name[i]);


	}

	while (popper<name.size())
	{
		if (Q.front() != S.top()){
			++counter;

			Q.pop();
			S.pop();
		}
		popper++;
	}


	if(counter==0){
		return true;
	}
	return false;


}

bool check2(string name){

	int size=0;
	size=name.size();

	int front=0;
	int back=size-1;
	int counter=0;

	for(int i=0;i<size;i++){

		if(name[front]==name[back]){
			if(front==back){
				counter--;
			}
			front++;
			back--;


		}
		else{
			counter++;
		}
		size=size-2;

	}

	if(counter==0){
		return true;
	}
	return false;

}

