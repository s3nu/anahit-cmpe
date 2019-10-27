//============================================================================
// Name        : hw1.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "complex.h"
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
    string line;
    ifstream in;
    complex input[5];
    complex sorter;
    in.open("126import.txt");
    if (in.fail()) {
        cout << "file does not open" << endl;
        exit(1);
    }
    int siz=0;
    while (getline(in,line)) {
        siz++;
    }
    in.close();
    in.open("126import.txt");
    if (in.fail()) {
        cout << "file does not open" << endl;
        exit(1);
    }
    for (int i=0; i<siz;i++){
        in>>input[i];
    }
    out<<"The Complex numbers read from the file are.."<<endl;
    for(int i=0;i<size;i++){
        file>>bars[i];
        cout<<bars[i]<<endl;
        out<<bars[i]<<endl;
    }
    cout<<endl;
    double *value;
    value=new double[size];
    
    for(int y=0;y<size;y++){
        value[y] = bars[y].mag();
        
    }
    cout<<"The magnitudes are..."<<endl;
    cout<<endl;
    for(int p=0;p<size;p++){
        cout<<value[p]<<endl;
    }
    out<<"The magnitudes are..."<<endl;
    out<<endl;
    for(int p=0;p<size;p++){
        out<<value[p]<<endl;
        
    }
    for(int k=1;k<size;k++){
        for(int i=0;i<size+-1-k;i++){
            if(value[i]>value[i+1]){
                double temp=value[i];
                value[i]=value[i+1];
                value[i+1]=temp;
            }
        }
    }
    out<<"The sorted magnitudes from least to greatest are"<<endl;
    for(int a=0;a<size;a++){
        cout<<value[a]<<endl;
        out<<value[a]<<endl;
    }
    complex end[10];
    for(int v=0;v<size;v++){
        double r=0;
        r=2*sqrt(value[v]);
        cout<<r<<"+"<<r<<"i"<<endl;
        out<<r<<"+"<<r<<"i"<<endl;
        end[v].convert(value[v]);
    }
    return 0;}
