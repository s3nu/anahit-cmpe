//
//  main.cpp
//  lab6
//
//  Created by senu on 11/9/14.
//  Copyright (c) 2014 senu. All rights reserved.
//
#include <iostream>
#include <stack>
#include <string>
using namespace std;


string convertToPostfix(string expression);
int pre(char operator1, char operator2);
bool check(char C);
bool other(char C);
int sort(char val);
int sides(char val);

int main() {
    string expression1="A + B - C";
    string postfix1;
    postfix1=convertToPostfix(expression1);
    cout<<" Infix Expression:"<<expression1<<endl;
    postfix1=convertToPostfix(expression1);
    cout<<" Postfix Expression:\n"<<postfix1<<endl;
    
    string expression2="(A + B ) * C";
    string postfix2;
    postfix2=convertToPostfix(expression2);
    cout<<" Infix Expression:"<<expression2<<endl;
    postfix2=convertToPostfix(expression2);
    cout<<" Postfix Expression:\n"<<postfix2<<endl;
    
    string expression3="(A + B) * (C - D)";
    string postfix3;
    postfix3=convertToPostfix(expression3);
    cout<<" Infix Expression:"<<expression3<<endl;
    postfix3=convertToPostfix(expression3);
    cout<<" Postfix Expression:\n"<<postfix3<<endl;
    
    string expression4="A + ((B + C) * (E - F) - G) / (H - I)";
    string postfix4;
    postfix4=convertToPostfix(expression4);
    cout<<" Infix Expression:"<<expression4<<endl;
    postfix4=convertToPostfix(expression4);
    cout<<" Postfix Expression:\n"<<postfix4<<endl;
    string expression5="A + B * (C + D ) - E / F * G + H";
    string postfix5;
    postfix5=convertToPostfix(expression5);
    cout<<" Infix Expression:"<<expression5<<endl;
    postfix5=convertToPostfix(expression5);
    cout<<" Postfix Expression:\n"<<postfix5<<endl;
    return 0;
}
string convertToPostfix(string expression){
    stack<char> S;
    int size=expression.length();
    string postfix = "";
    for(int i = 0;i<size;i++) {
        
        
        if(expression[i] == ' ' || expression[i] == ',') continue;
        
        else if(check(expression[i]))
        {
            while(!S.empty() && S.top() != '(' && pre(S.top(),expression[i]))
            {
                postfix+= S.top();
                S.pop();
            }
            S.push(expression[i]);
        }
        
        else if(other(expression[i]))
        {
            postfix +=expression[i];
        }
        
        else if (expression[i] == '(')
        {
            S.push(expression[i]);
        }
        
        else if(expression[i] == ')')
        {
            while(!S.empty() && S.top() !=  '(') {
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
    }
    
    while(!S.empty()) {
        postfix += S.top();
        S.pop();
    }
    
    return postfix;
    
}
bool check(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
        return true;
    
    return false;
}
bool other(char C)
{
    
    if(C >= 'A' && C <= 'Z') return true;
    return false;
}
int sort(char val)
{
    int weight = -1;
    
    if(val=='+'||val=='-'){
        weight =1;
    }
    if(val=='*' || val=='/'){
        weight=2;
    }
    if(val=='$'){
        weight=3;
    }
    return weight;
}
int sides(char val)
{
    if(val == '$') return true;
    return false;
}

int pre(char p1, char p2)
{
    int c1 = sort(p1);
    int c2 = sort(p2);
    
    if(c1 == c2)
    {
        if(sides(p1)) return false;
        else return true;
    }
    if(c1>c2){
        return true;
    }
    else{
        return false;
    }
    
}
