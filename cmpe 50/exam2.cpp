//============================================================================
// Name        : exam2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstdlib>
#include <cctype>
#include <fstream>

using namespace std;
int rates[5] = { 0 };
class book {
public:
	book();
	void rating(int a);
	int getavg(int* a, int b, int c);
	void nm(string a);
	void ct(string b);
private:
	string name;
	string cat;
	int rate;
};

int main() {
	int choice = 0;
	do {
		cout << "1-ex2" << endl;
		cout << "2-ex3" << endl;
		cout << "3-quit" << endl;
		cin >> choice;
		if (choice == 1) { //ex2
			ifstream in;
			ofstream out;
			string a, b;
			int p1, p2, p3, p4, p5 = 0; //position values
			in.open("input.txt");
			if (in.fail()) { //fail safe
				cout << "open failed" << endl;
				exit(1);
			}
			getline(in, a); //read first line
			getline(in, b); //read second line
			cout << a << endl;
			cout << b << endl;
			if (a.find('4')) { //checks for number
				p1 = a.find('4'); //gives position value
				a.replace(p1, 1, "four");
			}
			if (a.find('2')) {
				p2 = a.find('2');
				a.replace(p2, 1, "two");
			}
			if (a.find('6')) {
				p3 = a.find('6');
				a.replace(p3, 1, "six");
			}
			if (b.find('3')) {
				p4 = b.find('3');
				b.replace(p4, 1, "three");
			}
			if (b.find('8')) {
				p5 = b.find('8');
				b.replace(p5, 1, "eight");
			}
			cout << "--converted output:--" << endl;
			cout << a << endl;
			cout << b << endl;
			out.open("ouput.txt"); //output to file
			out << a << endl;
			out << b << endl;
		} //close ex2
		if (choice == 2) { //ex3
			book bk; //start of class objective
			string a, b;
			int rate;
			cout << "Enter book name" << endl;
			cin >> a;
			cout << "Enter Category" << endl;
			cin >> b;
			bk.nm(a);
			bk.ct(b);
			while (1) {
				cout
						<< "Enter a Rating:1 to 5, (Entering more or less than 5 will stop rating)"
						<< endl;
				cin >> rate;
				if (rate <= 5 || rate >= 0) {
					bk.rating(rate);
				} else {
					cout << "more than 5 entered: exiting" << endl;
					break;
				}
			}

		}
	} while (choice != 3); //quit while
} //end main

book::book() { //default
	name;
	cat;
	rate = 0;
}
void book::rating(int a) { //calculate ratings
	rate = a;
	double ppl = 0;
	if (rate == 1) {
		rates[0] = rates[0] + 1;
		ppl++;
	}
	if (rate == 2) {
		rates[1] = rates[1] + 1;
		ppl++;
	}
	if (rate == 3) {
		rates[2] = rates[2] + 1;
		ppl++;
	}
	if (rate == 4) {
		rates[3] = rates[3] + 1;
		ppl++;
	}
	if (rate == 5) {
		rates[4] = rates[4] + 1;
		ppl++;
	}
	cout << "The Number of People That Rated This Book as 1:" << rates[0]
			<< endl;
	cout << "The Number of People That Rated This Book as 2:" << rates[1]
			<< endl;
	cout << "The Number of People That Rated This Book as 3:" << rates[2]
			<< endl;
	cout << "The Number of People That Rated This Book as 4:" << rates[3]
			<< endl;
	cout << "The Number of People That Rated This Book as 5:" << rates[4]
			<< endl;
	getavg(rates, 5, ppl); //calls average

}
int book::getavg(int* a, int b, int c) { //calculates average
	int avg1 = 0;
	int avg2 = 0;
	avg1 = (a[0] * 1) + (a[1] * 2) + (a[2] * 3) + (a[3] * 3) + (a[4] * 4)
			+ (a[5] * 5);
	avg2 = (avg1 / c);
	cout << "The review average is:" << avg2 << endl;
}

void book::nm(string a) { //book name
	name = a;
	cout << "The book name:" << name << endl;
}
void book::ct(string b) { //book type
	cat = b;
	cout << "category of book:" << b << endl;
}

/*output for program--
 * 1-ex2
 2-ex3
 3-quit
 1
 The price of the cup is 4 dollars. But it's on sale today at 2 for 6 dollars.
 If you buy more, you can get 3 for 8 dollars.
 --converted output:--
 The price of the cup is four dollars. But it's on sale today at two for six dollars.
 If you buy more, you can get three for eight dollars.
 1-ex2
 2-ex3
 3-quit
 2
 Enter book name
 title1
 Enter Category
 fiction
 The book name:title1
 category of book:fiction
 Enter a Rating:1 to 5, (Entering more or less than 5 will stop rating)
 1
 The Number of People That Rated This Book as 1:1
 The Number of People That Rated This Book as 2:0
 The Number of People That Rated This Book as 3:0
 The Number of People That Rated This Book as 4:0
 The Number of People That Rated This Book as 5:0
 The review average is:1
 Enter a Rating:1 to 5, (Entering more or less than 5 will stop rating)
 2
 The Number of People That Rated This Book as 1:1
 The Number of People That Rated This Book as 2:1
 The Number of People That Rated This Book as 3:0
 The Number of People That Rated This Book as 4:0
 The Number of People That Rated This Book as 5:0
 The review average is:3
 Enter a Rating:1 to 5, (Entering more or less than 5 will stop rating)
 3
 The Number of People That Rated This Book as 1:1
 The Number of People That Rated This Book as 2:1
 The Number of People That Rated This Book as 3:1
 The Number of People That Rated This Book as 4:0
 The Number of People That Rated This Book as 5:0
 The review average is:6
 Enter a Rating:1 to 5, (Entering more or less than 5 will stop rating)
 4
 The Number of People That Rated This Book as 1:1
 The Number of People That Rated This Book as 2:1
 The Number of People That Rated This Book as 3:1
 The Number of People That Rated This Book as 4:1
 The Number of People That Rated This Book as 5:0
 The review average is:9
 Enter a Rating:1 to 5, (Entering more or less than 5 will stop rating)
 5
 The Number of People That Rated This Book as 1:1
 The Number of People That Rated This Book as 2:1
 The Number of People That Rated This Book as 3:1
 The Number of People That Rated This Book as 4:1
 The Number of People That Rated This Book as 5:1
 The review average is:13
 Enter a Rating:1 to 5, (Entering more or less than 5 will stop rating)
 4
 The Number of People That Rated This Book as 1:1
 The Number of People That Rated This Book as 2:1
 The Number of People That Rated This Book as 3:1
 The Number of People That Rated This Book as 4:2
 The Number of People That Rated This Book as 5:1
 The review average is:16
 Enter a Rating:1 to 5, (Entering more or less than 5 will stop rating)
 3
 The Number of People That Rated This Book as 1:1
 The Number of People That Rated This Book as 2:1
 The Number of People That Rated This Book as 3:2
 The Number of People That Rated This Book as 4:2
 The Number of People That Rated This Book as 5:1
 The review average is:19
 Enter a Rating:1 to 5, (Entering more or less than 5 will stop rating)
 6
 *
 */

