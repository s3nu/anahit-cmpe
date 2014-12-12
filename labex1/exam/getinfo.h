#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "stdlib.h"


#ifndef GETINFO_H_
#define GETINFO_H_

using namespace std;


class Student
{
public:
    Student(string n="",double score=0,int idnumber = 0);
    void print() const;
    friend ostream& operator<<(ostream& os, const Student& studentInformation);
    double getScore() const;
    string getName() const;
    int getId() const;
private:
    double scores;
    string name;
    int id;

};

#endif /* GETINFO_H_ */
