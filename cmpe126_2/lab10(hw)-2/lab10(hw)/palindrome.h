//
//  palindrome.h
//  lab10(hw)
//
//  Created by senu on 12/7/14.
//  Copyright (c) 2014 Anahit Sarao. All rights reserved.
//

#ifndef lab10_hw__palindrome_h
#define lab10_hw__palindrome_h
#include <iostream>
#include <stack>
#include <queue>
#include <cctype>
using namespace std;
bool ispali(string);
string lower(string);
bool ispali(string temp){
    
    queue<char> que;
    stack<char> s;
    int exception = 0;
    int counter = 0;
    while( temp[counter] ){
        s.push( temp[counter] );
        que.push( temp[counter] );
        
        counter++;
    }
    while ( (!que.empty()) && (!s.empty()) ){
        if (que.front() != s.top()){
            exception++;
        }
        que.pop();
        s.pop();
    }
    if( exception == 0 ){return true;}
    return false;
}
string lower(string temp){
    string low;
    for(int i = 0; i<temp.length(); i++){
        if(temp[i]  == ' ' ){
            i++;
        }
        low += tolower(temp[i]);
    }
    return low;
}

#endif
