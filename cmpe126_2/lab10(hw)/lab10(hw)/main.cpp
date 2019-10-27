//
//  main.cpp
//  lab10(hw)
//
//  Created by senu on 12/7/14.
//  Copyright (c) 2014 Anahit Sarao. All rights reserved.
//
#include <iostream>
#include <string.h>
#include <stack>
#include <queue>
#include <cctype>
#include "palindrome.h"
using namespace std;
int main(int argc, const char * argv[]) {
    string temp = "you aint ready";
        
        if( ispali( lower(temp) ) ){
            cout << temp <<": "<< "palindrome==true"<<endl;
        }
        else if( !ispali( lower(temp) ) ){
            cout << temp <<": "<< "palindrome==false"<<endl;
        }
    return 0;

}
    
    
    
