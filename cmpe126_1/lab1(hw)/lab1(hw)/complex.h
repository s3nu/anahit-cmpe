//
//  complex.h
//  lab1(hw)
//
//  Created by senu on 12/9/14.
//  Copyright (c) 2014 Anahit Sarao. All rights reserved.
//

#ifndef __lab1_hw___complex__
#define __lab1_hw___complex__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class complex {
public:
    complex();
    void set (double rl, double im);
    friend ostream& operator<< (ostream& out, const complex&);
    friend istream& operator>> (istream& in, complex& obj);
    friend complex operator+(const complex& obj, const complex& obj2);
    
private:
    double real;
    double imag;
    char sign;
};


#endif /* defined(__lab1_hw___complex__) */
