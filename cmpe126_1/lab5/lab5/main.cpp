//
//  main.cpp
//  lab5
//
//  Created by senu on 10/23/14.
//  Copyright (c) 2014 senu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

class comp{
public:
    comp();
    friend istream& operator>>(istream& iner, comp& ob);
    friend ostream& operator<<(ostream& ot, const comp& obx);
private:
    int im;
    int rl;
    char sn;
};

int main() {
    ifstream in;
    in.open("insert.txt");
    if (in.fail()) {
        cout<<"didnotopen"<<endl;
        exit (1);
    }
    comp hello;
    while (!in.eof()) {
        in>>hello;
        cout<<hello<<endl;
    }
       return 0;
}
comp::comp(){
    im=0;
    rl=0;
}
istream& operator>>(istream& iner, comp& ob){
    iner>>ob.rl;
    iner>>ob.im;
    iner>>ob.sn;
    char a;
    iner>>a;
    return iner;
}
ostream& operator<<(ostream& ot, const comp& obx){
    cout<<obx.rl<<obx.sn<<obx.im<<"i"<<endl;
    return ot;
}