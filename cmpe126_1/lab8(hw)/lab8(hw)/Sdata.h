//
//  Sdata.h
//  lab8(hw)
//
//  Created by senu on 11/22/14.
//  Copyright (c) 2014 senu. All rights reserved.
//

#ifndef __lab8_hw___Sdata__
#define __lab8_hw___Sdata__

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
//linked list begin
struct list{
    string name;
    string capital;
    string area;
    string year;
    list *link;
};
//linked list end
//hash table begin
class hashT {
public:
    hashT();
    hashT createht(int size);
    list  **table;
    int htsize;
};
//hash table end
hashT::hashT(){

}
hashT hashT::createht(int size){
    hashT *newht;
    if (size<1){
        cout<<"Size can not be 0"<<endl;
        exit(1);
    }
    for (int i=0;i<size; i++) {
        newht->table[i]=NULL;
    }
    newht->htsize=size;
    return *newht;
}
class statedata:public hashT {
public:
    statedata();
    void getinfo();
    void setinfo(statedata &obj, int count, hashT newHT);
    void modify();
    int hashfunction(string name);
    void printer();
    void search();
    friend ostream& operator<<(ostream& os, const hashT *obj);
    friend istream& operator>>(istream& os, const hashT &obj);
    friend bool operator< (const hashT &lhs, const hashT &rhs);
    friend bool operator> (const hashT &lhs, const hashT &rhs);
    friend bool operator<=(const hashT &lhs, const hashT &rhs);
    friend bool operator>=(const hashT &lhs, const hashT &rhs);
    friend bool operator>=(const hashT &lhs, const hashT &rhs);
    friend bool operator==(const hashT &lhs, const hashT &rhs);
    friend bool operator!=(const hashT &lhs, const hashT &rhs);
protected:
    string name;
    string capital;
    string area;
    string year;
};
statedata::statedata(){
}
void statedata::getinfo(){
    statedata input;
    hashT newHT;
    int numberofstates=0;
    cout<<"State Data Aquisition Begin: "<<endl;
    cout<<"How Many States?"<<endl;
    cin>>numberofstates;
    newHT=createht(numberofstates);
    cout<<"Number of States Confirmed. Please provide the following info for each State:"<<endl;
    cout<<"1. Name (limited to 15 bits)\n"
    <<"2. Capital of State\n"
    <<"3. Area of State (per square meter)\n"
    <<"4. Entering year of State to Union\n"
    <<endl;
    for (int i=0; i<numberofstates; i++) {
        cout<<"State #"<<i<<": Begin"<<endl;
        cout<<"Name: ";
        cin>>input.name;
        cout<<"Capital: ";
        cin>>input.capital;
        cout<<"Area: ";
        cin>>input.area;
        cout<<"Year: ";
        cin>>input.year;
        cout<<"State #"<<i<<": End"<<endl;
        setinfo(input,i,newHT);
    }
}
void statedata::setinfo(statedata &obj, int count, hashT newHT){
    hashT *ht;
    list *head=new list;
    list *current=head;
    newHT.table[count]=head;
    for (int i=0; i<5; i++) {
        current->name=hashfunction(obj.name);
        current->capital=obj.capital;
        current->area=obj.area;
        current->year=obj.year;
        list *temp=new list;
        current->link=temp;
        current=current->link;
    }
    current->link=NULL;
}
int statedata::hashfunction(string name){
    hashT ht;
    int i,sum;
    unsigned long len;
    i=0;
    sum=0;
    len=name.length();
    for (int k=0; k<15-len; k++) {
        name=name+ ' ';
    }
    for (int k=0; k<5; k++) {
        sum= sum + static_cast<int>(name[i])*128*128 + static_cast<int>(name[i+1])*128 +static_cast<int>(name[i+2]);
        i=i+3;
    }
    return (sum%(ht.htsize));
}
void statedata::printer(){
    hashT *ht;
    for (int i=0; i<ht->htsize; i++) {
        cout<<ht->table
        <<endl;
    }
    
}
void statedata::modify(){
    int choice=0;
    statedata insidewelcome;
    do {
        cout<<"\n0. Exit Modification"<<endl;
        cout<<"1. Print"<<endl;
        cout<<"2. Search"<<endl;
        cout<<"3. Delete"<<endl;
        cin>>choice;
        if (choice==1) {
            insidewelcome.printer();
        }
        if (choice==2) {
            insidewelcome.search();
        }
        if (choice==3) {
            continue;
        }
        if (choice==4) {
            continue;
        }
    } while (choice!=0);
}
void statedata::search(){
    
}
ostream& operator<<(ostream& os, const hashT *obj){
    for (int r=0; r<obj->htsize;r++){
        list *head=new list;
        head=obj->table[r];
            for (int i=0; i<5;i++){
                cout<<head->name<<endl;
                cout<<head->capital<<endl;
                cout<<head->area<<endl;
                cout<<head->year<<endl;
            }
    }
    return os;
}
istream& operator>>(istream& is, const hashT &obj){
    return is;
}
bool operator< (const hashT& lhs, const hashT& rhs){
    /* actual comparison */
    
    return true;
}
bool operator> (const hashT& lhs, const hashT& rhs){
    return rhs < lhs;
}
bool operator<=(const hashT& lhs, const hashT& rhs){
    return !(lhs > rhs);
}
bool operator>=(const hashT& lhs, const hashT& rhs){
    return !(lhs < rhs);
}
//bool operator==(const X& lhs, const X& rhs){
/* actual comparison */
//return true;
//}
//bool operator!=(const X& lhs, const X& rhs){
//return !(lhs == rhs);
//}

#endif /* defined(__lab8_hw___Sdata__) */
