/*
 * clock.h
 *
 *  Created on: Sep 2, 2014
 *      Author: senu
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include <iostream>
using namespace std;


class clocktype {

public:
    clocktype();
    clocktype(int hr, int min, int sec);
    clocktype(int hr, int min);
    friend ostream& operator<<(ostream &os, const clocktype &obj);
    friend clocktype operator+(const clocktype &obj, const clocktype &obj1);


private:
    int hour;
    int minute;
    int second;
};



#endif /* CLOCK_H_ */
