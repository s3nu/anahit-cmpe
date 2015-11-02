#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <cctype>

using namespace std;


class cdaccount{
public:
	cdaccount();
	cdaccount(double intial,
			double interest,
			int term);
	double get_initial();
	double get_initial_maturity(double initial1, double interest1, int term1);
private:
	double initial1;
	double interest1;
	double maturity1;
	int term1;
};

int main() {

	cdaccount CD1;

	double first;
	double rt;
	int trm;

	cout<<"balance"<<endl;
	cin>>first;

	cout<<"interest"<<endl;
	cin>>rt;

	cout<<"term"<<endl;
	cin>>trm;



	cdaccount CD2(first,rt,trm);
	double after;

	first=CD2.get_initial();
	cout<<first<<endl;
	after=CD2.get_initial_maturity(first,rt,trm);
	cout<<after<<endl;

	return 0;
}
cdaccount::cdaccount(){
	initial1=0;
	interest1=0;
	term1=0;

}
cdaccount::cdaccount(double intial, double interest,int term){
	initial1=intial;
	interest1=interest;
	term1=term;
}
double cdaccount::get_initial_maturity(double initial1, double interest1, int term1){
	double number=0;
	number=initial1+((initial1*(interest1/100))*term1);
	return number;
}
double cdaccount::get_initial(){
	return initial1;
}

/*output
 * balance
100
interest
10
term
2
100
120*/


