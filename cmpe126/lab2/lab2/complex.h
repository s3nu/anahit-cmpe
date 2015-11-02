//
//  complex.h
//  lab2
//
//  Created by senu on 12/9/14.
//  Copyright (c) 2014 Anahit Sarao. All rights reserved.
//

#ifndef __lab2__complex__
#define __lab2__complex__

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
using namespace std;
class complex {
public:
    complex();
    friend ostream& operator<< (ostream& outter, const complex & lol);
    friend istream& operator>> (istream& inside, complex & outski);
private:
    double real;
    double imag;
    char sign;
    char last;
};


#endif /* defined(__lab2__complex__) */
