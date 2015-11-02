/*
 * admin.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: senu
 */
#include "admin.h"
#include <iostream>
#include <iomanip>
using namespace std;

admin::admin() {
	salary1 =0;
	admin1 = name;
}
void admin::setname() {
	cout << "enter name of the BOSS" << endl;
	cin >> admin1;
	set_name(admin1);
}
void admin::read() {
	int choice = 0;
	do {
		cout << "1-enter salary" << endl;
		cout << "2-enter admin second in command" << endl;
		cout << "3-enter company area of interest" << endl;
		cout << "4-exit" << endl;
		cin>>choice;
		if (choice == 1) {
			int a = 0;
			cout << "1-would u like use old salary" << endl;
			cout << "2-enter a new salary" << endl;
			cin >> a;
			if (a == 1) {
				cout << "Old defined salary used" << endl;
				if (salary == 0) {
					cout
							<< "the old defined salary is lost or was not entered-error-returning"
							<< endl;
					continue;
				}
			}
			if (a == 2) {
				cout << "enter new salary" << endl;
				cin >> salary1;
				set_salary(salary1);
				salary1=get_salary();

			}
		}
		if (choice == 2) {
			cout << "enter second in command name" << endl;
			cin >> admin2;
		}
		if (choice == 3) {
			cout << "enter companies interest" << endl;
			cin >> type;
		}
	} while (choice != 4);
}
void admin::printer(const admin &ad) {
	cout<<"BOSS name: "<<ad.admin1<<endl;
	cout<<"second in command(the scrub): "<<ad.admin2<<endl;
	cout<<"field of interest: "<<ad.type<<endl;
	cout<<"salary: "<<std::fixed<<setprecision(2)<<ad.salary1<<endl;
	cout<<"---YEEEEEYEEEEE DEM BARS ON IHERITANCE---"<<endl;
	cout<<""<<endl;
}
void admin::print_check() {
	cout<<""<<endl;
		cout << "\n__________________________________________________\n";
		cout << "Pay to the order of " << admin1<< endl;
		cout << "The sum of " <<std::fixed<<setprecision(2)<< salary1 << " Dollars\n";
		cout << "_________________________________________________\n";
		cout << "Check Stub NOT NEGOTIABLE \n";

}

