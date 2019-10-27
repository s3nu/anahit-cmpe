#include <iostream>
#include <fstream>
#include "studentRosterType.h"
using namespace std;

int main() {
	ofstream fout;
	fout.open("exam1__5583.txt");						//Replace #### with last four digits of ID
	fout << "My name is Anahit Sarao.\n";						//Replace ---- with your first/last name
	fout << "The last 4 digits of my ID are 5583.\n";	//Replace #### with last four digits of ID

	fout << "\n***Objective 1***\n";
	studentRosterType studentRoster;
	studentRoster.load("studentData.txt");
	fout << "The class average is " << studentRoster.average() << endl;
	fout << "Names of students that are above average: " << endl;
	studentRoster.printNamesAbove(studentRoster.average(), fout);

	fout << "\n***Objective 2***\n";
	fout << "Removing Frank from the roster.\n";
	fout << "His ID is " << studentRoster.removeAndGetID("Frank") << endl;
	fout << "The new class average is " << studentRoster.average() << endl;
	fout << "ID's of students that are below the new average: " << endl;
	studentRoster.printIDsBelow(studentRoster.average(), fout);

	fout << "\n***Objective 3***\n";
	fout << "The new class median is " << studentRoster.median() << endl;
	fout << "Information of student(s) with that score: " << endl;
	studentRoster.printInfoFor(studentRoster.median(), fout);
    return 0;
}
