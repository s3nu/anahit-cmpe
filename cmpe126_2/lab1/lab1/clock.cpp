/*
 * clock.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: senu
 */

#include "clock.h"

clocktype::clocktype() {
	hour = 0;
	minute = 0;
	second = 0;
}
clocktype::clocktype(int hr, int min, int sec) {
	hour = hr;
	minute = min;
	second = sec;
}
clocktype::clocktype(int hr, int min) {
	hour = hr;
	minute = min;
	second = 0;
}
ostream& operator<<(ostream &os, const clocktype &obj) {
	cout << obj.hour << "::" << obj.minute << "::" << obj.second << endl;
	return os;
}

clocktype operator+(const clocktype &obj, const clocktype &obj1) {
	clocktype obj3;
	if (obj.hour + obj1.hour <= 24) {
		obj3.hour = obj.hour + obj.hour;
	}
	if (obj.hour + obj1.hour > 24) {
		obj3.hour = obj.hour + obj.hour - 24;
	}
	if (obj.minute + obj1.minute < 60) {
		obj3.minute = obj.minute + obj.minute;
	}
	if (obj.minute + obj1.minute >= 60) {
		obj3.minute = obj.minute + obj.minute - 60;
		obj3.hour++;
	}
	if (obj.second + obj1.second < 60) {
		obj3.second = obj.second + obj.second;
	}
	if (obj.second + obj1.second >= 60) {
		obj3.second = obj.second + obj.second - 60;
		obj3.minute++;
	}
return obj3;
}

