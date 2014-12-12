/*
 * getinfo.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: senu
 */

#include <iostream>
#include <fstream>
#include <string>
#include "getinfo.h"
using namespace std;

Student::Student(string n,double score,int idnumber)
{
    name = n;
    scores = score;
    id = idnumber;
}
ostream& operator<<(ostream& os, const Student& studentInformation)
{
    os << "Student Name: " << studentInformation.name << endl;
    os << "Test Score: " << studentInformation.scores << endl;
    os << "ID: " << studentInformation.id << endl;
    return os;
}
string Student::getName() const
{
    return name;
}
double Student::getScore() const
{
    return scores;
}
int Student::getId() const
{
    return id;
}
void Student::print() const
{
    cout << "Student Name: " << name << endl;
    cout << "Test Score: " << scores << endl;
    cout << "Student ID: " << id << endl;

}

