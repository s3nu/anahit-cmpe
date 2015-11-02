//============================================================================
// Name        : lab2-3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main() {
	double array[3][5];
	double hwmax = 0;
	double hwmin = 0;
	double testmin = 0;
	double testmax = 0;
	int i3 = 1;
	double adder = 0;
	double adder1 = 0;
	double average3 = 0;
	double average2 = 0;
	int i4 = 1;
	ifstream in;
	ofstream out;
	while (1) {
		for (int i = 0; i < 5; i++) {

			cout << "enter " << i3 << " hw grades?" << endl;
			cin >> array[0][i];
			i3++;

		}
		for (int i2 = 0; i2 < 5; i2++) {

			cout << "enter " << i4 << " test grades?" << endl;
			cin >> array[1][i2];
			i4++;

		}
		break;
	}
	hwmax = array[0][0];
	for (int i5 = 0; i5 < 5; i5++) {

		if (array[0][i5] > hwmax) {
			hwmax = array[0][i5];
		}
	}
	hwmin = array[0][0];
	for (int i6 = 1; i6 < 5; i6++) {

		if (array[0][i6] < hwmin) {
			hwmin = array[0][i6];
		}
	}
	testmax = array[1][0];
	for (int i7 = 0; i7 < 5; i7++) {

		if (array[1][i7] > testmax) {
			testmax = array[1][i7];
		}
	}
	testmin = array[1][0];
	for (int i8 = 1; i8 < 5; i8++) {

		if (array[1][i8] < testmin) {
			testmax = array[1][i8];
		}
	}
	for (int i11 = 0; i11 < 5; i11++) {

		adder += array[0][i11];
	}
	for (int i12 = 0; i12 < 5; i12++) {

		adder1 += array[1][i12];
	}

	for (int i9 = 0; i9 < 5; i9++) {
		double dummy1 = 0;
		double dummy2 = 0;
		dummy1 = array[0][i9];
		dummy2 = array[1][i9];
		double average = 0;
		average = (dummy1 + dummy2) / 2;
		array[3][i9] = average;
	}
	average2 = adder / 5;
	average3 = adder1 / 5;
	cout.setf(ios::right);
	cout.width(3);

	cout << "      1";
	cout << "    2";
	cout << "   3";
	cout << "   4";
	cout << "  5" << endl;

	cout << "    *********************" << endl;
	cout << "HW" << setw(2) << "  GR" << setw(3) << array[0][0] << setw(3)
			<< array[0][1] << setw(4) << array[0][2] << setw(4) << array[0][3]
			<< setw(4.8) << array[0][4] << setw(20) << "BEST HW:" << hwmax
			<< setw(15) << "WORST HW:" << hwmin << setw(10) << "AVG HW:"
			<< average2 << endl;
	cout << "Lab" << setw(2) << " GR" << setw(3) << array[1][0] << setw(3)
			<< array[1][1] << setw(4) << array[1][2] << setw(4) << array[1][3]
			<< setw(4.8) << array[1][4] << setw(21) << "BEST LAB:" << testmin
			<< setw(14.9) << "WORST LAB:" << testmax << setw(10.5) << "AVG LAB:"
			<< average3 << endl;
	cout << setw(1.9) << "AVG" << setw(6.5) << array[3][0] << setw(3.8)
			<< array[3][1] << setw(4) << array[3][2] << setw(4.4) << array[3][3]
			<< setw(4) << array[3][4] << endl;
	bool hai = 'true';
	if (average2 < 50) {
		cout
				<< "Im sorry to inform you that you failed the class, because your performance in HW was <50%. Try again next semester"
				<< endl;
		hai = false;
	}
	if (average3 < 50) {
		cout
				<< "Im sorry to inform you that you failed the class, because your performance in LAB was <50%. Try again next semester"
				<< endl;
		hai = false;
	}
	for (int a = 0; a < 5; a++) {
		if (array[3][a] < 50) {
			cout
					<< "Im sorry to inform you that you failed the class, because your performance in LAB/HW was <50%. Try again next semester"
					<< endl;
			hai = false;
			break;
		}
	}
	if (hai == true) {
		cout << "Congratulations! You passed the class!" << endl;
	}
	out.open("output.txt");

	out << "      1";
	out << "    2";
	out << "   3";
	out << "   4";
	out << "  5" << endl;

	out << "    *********************" << endl;
	out << "HW" << setw(2) << "  GR" << setw(3) << array[0][0] << setw(3)
			<< array[0][1] << setw(4) << array[0][2] << setw(4) << array[0][3]
			<< setw(4.8) << array[0][4] << setw(20) << "BEST HW:" << hwmax
			<< setw(15) << "WORST HW:" << hwmin << setw(10) << "AVG HW:"
			<< average2 << endl;
	out << "Lab" << setw(2) << " GR" << setw(3) << array[1][0] << setw(3)
			<< array[1][1] << setw(4) << array[1][2] << setw(4) << array[1][3]
			<< setw(4.8) << array[1][4] << setw(21) << "BEST LAB:" << testmax
			<< setw(14.9) << "WORST LAB:" << testmin << setw(10.5) << "AVG LAB:"
			<< average3 << endl;
	out << setw(1.9) << "AVG" << setw(6.5) << array[3][0] << setw(3.8)
			<< array[3][1] << setw(4) << array[3][2] << setw(4.4) << array[3][3]
			<< setw(4) << array[3][4] << endl;
	bool lol = 'true';
		if (average2 < 50) {
			out
					<< "Im sorry to inform you that you failed the class, because your performance in HW was <50%. Try again next semester"
					<< endl;
			lol = false;
		}
		if (average3 < 50) {
			out
					<< "Im sorry to inform you that you failed the class, because your performance in LAB was <50%. Try again next semester"
					<< endl;
			lol = false;
		}
		for (int a = 0; a < 5; a++) {
			if (array[3][a] < 50) {
				out
						<< "Im sorry to inform you that you failed the class, because your performance in LAB/HW was <50%. Try again next semester"
						<< endl;
				lol = false;
				break;
			}
		}
		if (lol == true) {
			out << "Congratulations! You passed the class!" << endl;
		}

	return 0;
}
/* output
 * enter 1 hw grades?
60
enter 2 hw grades?
90
enter 3 hw grades?
100
enter 4 hw grades?
80
enter 5 hw grades?
70
enter 1 test grades?
100
enter 2 test grades?
90
enter 3 test grades?
50
enter 4 test grades?
90
enter 5 test grades?
100
      1    2   3   4  5
    *********************
HW  GR 60 90 100  80  70            BEST HW:100      WORST HW:60   AVG HW:80
Lab GR100 90  50  90 100            BEST LAB:100    WORST LAB:90  AVG LAB:86
AVG    80 90  75  85  85
Congratulations! You passed the class!
 */
 /*output to text file
  *       1    2   3   4  5
    *********************
HW  GR 60 90 100  80  70            BEST HW:100      WORST HW:60   AVG HW:80
Lab GR100 90  50  90 100            BEST LAB:90    WORST LAB:100  AVG LAB:86
AVG    80 90  75  85  85
Congratulations! You passed the class!
  * */
