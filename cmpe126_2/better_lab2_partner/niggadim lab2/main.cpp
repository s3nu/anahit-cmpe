//============================================================================
// Name        : Cmpe.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "complex.h"
using namespace std;


int main() {
    int size=0;
    string line;
    ifstream file;
    ofstream out;
    file.open("126import.txt");
    
    while(getline(file,line)){
        
        size++;
        
    }
    
    file.close();
    
    complex bars[10];
    file.open("126import.txt");
    
    if(file.fail()){
        
        cout<<"File is unable to open"<<endl;
    }
    
    out.open("126export.txt");
    
    if(out.fail()){
        
        cout<<"File is unable to open"<<endl;
    }
    
    out<<"Name: Nadim Sarras"<<endl;
    out<<"SJSU ID # 008382608"<<endl;
    out<<"Lab Section 2"<<endl;
    
    out<<endl;
    cout<<endl;
    
    cout<<"The Complex numbers read from the file are.."<<endl;
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
    //   OUTPUT TO FILE
    out<<"The magnitudes are..."<<endl;
    out<<endl;
    for(int p=0;p<size;p++){
        out<<value[p]<<endl;
        
    }
    
    
    
    
    
    
    
    // FUNCTIONS SORTED
    for(int k=1;k<size;k++){
        for(int i=0;i<size+-1-k;i++){
            if(value[i]>value[i+1]){
                double temp=value[i];
                value[i]=value[i+1];
                value[i+1]=temp;
            }
        }
    }
    
    //SORT ENDS
    cout<<endl;
    out<<endl;
    
    cout<<endl<<"The sorted magnitudes from least to greatest are"<<endl;
    out<<"The sorted magnitudes from least to greatest are"<<endl;
    for(int a=0;a<size;a++){
        cout<<value[a]<<endl;
        out<<value[a]<<endl;
    }
    
    
    complex end[10];
    
    cout<<endl<<"The magnitudes converted back into complex numbers.."<<endl;
    out<<endl<<"The magnitudes converted back into complex numbers.."<<endl;
    for(int v=0;v<size;v++){
        double r=0;
        r=2*sqrt(value[v]);
        cout<<r<<"+"<<r<<"i"<<endl;
        out<<r<<"+"<<r<<"i"<<endl;
        end[v].convert(value[v]);
        
    }
    
    
    
    
    return 0;
}
