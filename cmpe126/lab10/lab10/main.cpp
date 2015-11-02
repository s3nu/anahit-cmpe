//
//  main.cpp
//  lab10
//
//  Created by senu on 12/2/14.
//  Copyright (c) 2014 Anahit Sarao. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
class roster {
public:
    roster();
    void read();
    void insertsort();
    void print();
    void startquick();
    void quick(vector<roster> &data,int left,int right);
    int partition(vector<roster> &a,int left,int right);
    void exch(vector<roster> &data,int i,int j);
    friend ostream& operator <<(ostream& os, const roster &obj);
    int id;
    string name;
    string level;
    string lastname;
    string firstname;
    vector<roster> people;
    
};



int main() {
    roster begin;
    begin.read();
    cout<<"insertion sort used to sort by id, list will reprint: "<<endl;
    begin.insertsort();
    begin.print();
    cout<<"quick sort used to sort by first name, list will reprint: "<<endl;
    begin.startquick();
    begin.print();

    
    return 0;
}
roster::roster(){
    
}
void roster::startquick(){
    quick(people,0, people.size());
}
ostream& operator <<(ostream& os, const roster &obj){
    cout<<obj.id<<obj.lastname<<obj.lastname<<obj.level<<endl;
    return os;
}

void roster::print(){
    for (int i=0; i<people.size(); i++) {
        cout<<people[i]<<endl;
    }
}
void roster::read(){
    ifstream in;
    string stemp;
    int counter=0;
    in.open("student.txt");
    if(in.fail()){
        cout<<"fail safe"<<endl;
        exit(1);
    }
    while (getline(in,stemp)) {
        counter++;
    }
    in.close();
    in.open("student.txt");
    if(in.fail()){
        cout<<"fail safe"<<endl;
        exit(1);
    }
    for (int i=0;i<counter;i++){
        roster temp;
        string id;
        string::size_type sz;
        getline(in,id, ',');
        temp.id=stoi(id,&sz,10);
        getline(in, temp.lastname, ',');
        getline(in, temp.firstname, ',');
        getline(in, temp.level, '\n');
        people.push_back(temp);
    }
}
void roster::insertsort(){
    int i, j, tmp;
    string tmp1,tmp2,tmp3;
    for (i=1; i<people.size(); i++)
    {
        j=i;
        tmp=people[i].id;
        tmp1=people[i].lastname;
        tmp2=people[i].firstname;
        tmp3=people[i].level;
        while (j>0 && tmp<people[j-1].id)
        {
            people[j].id=people[j-1].id;
            people[j].lastname=people[j-1].lastname;
            people[j].firstname=people[j-1].firstname;
            people[j].level=people[j-1].level;
            j--;
        }
        people[j].id=tmp;
        people[j].lastname=tmp1;
        people[j].firstname=tmp2;
        people[j].level=tmp3;
    }
}
void roster::quick(vector<roster> &data,int left,int right)
{
    if (right <= left){
        return ;
    }
    int pivot=partition(data,left,right);
    quick(data,left,pivot-1);
    quick(data,pivot+1,right);
    
}
int roster::partition(vector<roster> &a,int low,int high)
{
    int left=low;
    int right=high;
    char tempv=a[left].lastname[1];
    int v=atoi(&tempv);
    char temp11=a[left].lastname[1];
    int temp1=atoi(&temp11);
    char temp22=a[right].lastname[1];
    int temp2=atoi(&temp22);
    while(left<right){
        while(temp1<=v){
            left++;
            temp11=a[left].lastname[1];
            temp1=atoi(&temp11);
        }
        while(temp2>v){
            right--;
            temp22=a[right].lastname[1];
            temp2=atoi(&temp22);
        }
        if (left<right){
            exch(a,left,right);
        }
    }
    exch(a,low,right);
    return right;
}
void roster::exch(vector<roster> &data,int i,int j)
{
    char temp=data[i].lastname[1];
    int s=atoi(&temp);
    char temp1=data[j].lastname[1];
    data[i].lastname=atoi(&temp1);
    data[j].lastname=s;
    
}


