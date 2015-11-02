#include <iostream>
#include "salariedemployee.h"
#include "employee.h"

class manag: public SalariedEmployee {
public:
	manag();
	manag(const manag &man);
	void operator =(manag &man);
	~manag();
	void addreport(SalariedEmployee *one);
	friend ostream& operator <<(ostream& ost, manag &man);
private:
	SalariedEmployee *reports;
	int noReport;

};

int main() {
	manag man1;
	SalariedEmployee s1;
	Employee em;
	string name;
	string ssn;
	double salary;
	cout << "Enter name of person" << endl;
	cin >> name;
	em.set_name(name);
	cout << "Enter ssn" << endl;
	cin >> ssn;
	em.set_ssn(ssn);
	cout << "Enter salary" << endl;
	cin >> salary;
	em.set_net_pay(salary);
	man1.addreport(&s1);

}
manag::manag() {
	noReport = 0;
}
manag::manag(const manag &man) {


	reports = new SalariedEmployee[noReport + 1];
}
void manag::operator =(manag &man) {

}
manag::~manag() {
	delete[] reports;
}
void manag::addreport(SalariedEmployee *one) {


}
ostream& operator <<(ostream& ost, manag &man) {
	cout << man << endl;
	return ost;

}

