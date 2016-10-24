/*
 * studenRosterType.h
 *
 *  Created on: Sep 23, 2014
 *      Author: senu
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "getinfo.h"
using namespace std;


#ifndef STUDENROSTERTYPE_H_
#define STUDENROSTERTYPE_H_


class studentRosterType: public Student
{
public:
	studentRosterType();
	studentRosterType(string name,int score);
	void load(string filename);
	int removeAndGetID(const string name);
	double average();
	int median();
	void print() const ;
	void printNamesAbove(double average,ofstream &fout);
	void printIDsBelow(double avg,ofstream &fout);
	void printInfoFor(int median,ofstream &fout);
	int returnVectorSize();
private:
	double classAverage;
	int classMedian;
	string inputFileName;
	vector<Student> info;
};
#endif /* STUDENROSTERTYPE_H_ */
