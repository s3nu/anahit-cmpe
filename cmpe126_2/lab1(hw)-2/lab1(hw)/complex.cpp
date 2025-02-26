//
//  complex.cpp
//  lab1(hw)
//
//  Created by senu on 12/9/14.
//  Copyright (c) 2014 Anahit Sarao. All rights reserved.
//

#include "complex.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
complex::complex() {
    real=0;
    imag=0;
    sign=0;
}
void complex::set (double rl, double im){
    rl=real;
    im=imag;
}

istream& operator>> (istream& in, complex& obj)
{
    char c;
    in>>obj.real;
    in >> obj.sign;
    in >> obj.imag;
    in >> c;
    return in;
}
complex operator+(const complex& obj, const complex& obj2){
    complex result;
    result.real=obj.real+obj2.real;
    result.imag=obj.imag+obj2.imag;
    return result;
}

ostream& operator<< (ostream& out, const complex& obj)
{
    out <<obj.real<<obj.sign<<obj.imag<<"i";
    return out;
}


