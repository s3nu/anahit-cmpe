//============================================================================
// Name        : hw1.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "complex.h"
int main() {
    ifstream in;
    ofstream out;
    in.open("complex.txt");
    if (in.fail()) {
        cout << "file does not open" << endl;
        exit(1);
    }
    complex obj;
    complex result;
    out.open("complexobj.txt");
    while (1){
        if (!in.eof()){
            in>>obj;
        }
        else {
            break;
        }
        out<<obj<<endl;
        result=result+obj;
    }
    out<<""<<endl;
    out<<"The sum of the real and imaginary part is: "<<" "<<result<<endl;
    out<<"STUDENT INFO\n"
    <<"ANAHIT SARAO\n"
    <<"008435583\n"
    <<"LAB SECTION #2\n"<<endl;
    return 0;
}
