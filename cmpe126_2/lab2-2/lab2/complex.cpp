//
//  complex.cpp
//  lab2
//
//  Created by senu on 12/9/14.
//  Copyright (c) 2014 Anahit Sarao. All rights reserved.
//

#include "complex.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
using namespace std;
complex::complex() {
    real=0.0;
    imag=0.0;
}
istream& operator>> (istream& inside, complex &lol)
{
    inside.get(lol.real);
    inside >> lol.sign;
    inside >> lol.imag;
    inside >> lol.last;
    return inside;
}
ostream& operator<< (ostream& outter, const complex& outski)
{
    cout<<outski.real<<outski.sign<<outski.imag<<"i";
    return outter;
}
//void complex::sorting(complex *obj, int size){
//    ofstream out;
//    out.open("126export.txt");
//    double array2[size];
//    double tempreal=0;
//    double tempimag=0;
//    double temptotal=0;
//    double tempsum=0;
//    for (int i=0; i<size; i++) {
//        tempreal=obj[i].real*obj[i].real;
//        tempimag=obj[i].imag*obj[i].imag;
//        tempsum=tempreal+tempimag;
//        temptotal=sqrt(tempsum);
//        array2[i]=temptotal;
//    }
//    sort(array2, array2+size);
//    out<<"Sorted Magnitudes are:"<<endl;
//    for (int i4=0; i4<size; i4++){
//        out.precision(2);
//        out<<array2[i4]<<endl;
//    }
//    out<<""<<endl;
//    out<<"STUDENT INFO\n"
//    <<"ANAHIT SARAO\n"
//    <<"008435583\n"
//    <<"LAB SECTION #2\n"<<endl;
//}
