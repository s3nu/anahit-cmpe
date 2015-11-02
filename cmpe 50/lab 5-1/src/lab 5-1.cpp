//============================================================================
// Name        : lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class study {
public:
	study();
	study(double q, double q2, double mt, double fl);
	void average(double a, double b, double c, double d);
private:
	double quiz;
	double quiz2;
	double mterm;
	double final;
};


int main() {
	study cd1();
	double quiz=0;
	double quiz2=0;
	double midterm=0;
	double final=0;
	cout<<"quiz one"<<endl;
	cin>>quiz;
	cout<<"quiz two "<<endl;
	cin>>quiz2;
	cout<<"midterm"<<endl;
	cin>>midterm;
	cout<<"final"<<endl;
	cin>>final;
	study cd2 (quiz,quiz2,midterm,final);
	cd2.average(quiz, quiz2, midterm,final);
}
study::study(){
	quiz=0;
	quiz2=0;
	mterm=0;
	final=0;

}
study::study(double a, double b, double c , double d) {
	quiz=a;
	quiz2=b;
	mterm=c;
	final=d;



}
void study::average(double a, double b, double c, double d) {
	double score=0;
	score=(((a+b)*.25)+(c*.25)+(d*.25));
	cout<<"you final grade is "<< score<<endl;
}

/*output
 * quiz one
90
quiz two
80
midterm
79
final
60
you final grade is 77.25
 *
 */
