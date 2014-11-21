//
//  main.cpp
//  lab8
//
//  Created by senu on 11/19/14.
//  Copyright (c) 2014 senu. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <list>
using namespace std;
void seqrecursion (int array[], int size, int spot);
void binsearch(int array[],int spot, int n);
void listsearch(list<int> newlist, int spot);
void listrecur(list<int> newlist,list<int>::iterator link, int spot);

int main() {
    int choice=0;
    int i=0;
    int position=0;
    int size=0;
    int *array;
    list<int> newlist;
    list<int>::iterator link;
    cout<<"How many Numbers?"<<endl;
    cin>>size;
    array=new int[size];
    cout<<"Enter your numbers: "<<endl;
    for (int i=0; i<size; i++) {
        cin>>array[i];
        newlist.push_back(array[i]);
    }
    cout<<"\n The Array contains:"<<endl;
    for (int i=0; i<size; i++) {
        cout<< "#"<<i<<": "<<array[i]<<endl;
    }
    do {
        cout<<"\nChoose your search type:";
        cout<<"\n1. Arrays: Sequential Search without recursion";
        cout<<"\n2. Arrays: Sequential Search with recursion";
        cout<<"\n3. Ordered Arrays: Binary Search without recursion";
        cout<<"\n4. Ordered Arrays: Binary Search with recursion";
        cout<<"\n5. Linked List: Search without recursion";
        cout<<"\n6. Linked List: Search with recursion";
        cout<<"\nEnter 0 to exit.";
        cout<<"\nSpecify the element to be searched for: ";
        cin>>position;
        cout<<"\nYour choice: "<<endl;
        cin>>choice;
        if (choice==0){
            break;
        }
        if (choice==1){//squential search
            bool check=true;
            for (int i=0; i<size; i++) {
                if (array[i]==position) {
                    cout<<"The number is at position# "<<i<<endl;
                    check=false;
                }
                else if (check==true){
                    cout<<"your number was not found"<<endl;
                }
            }
        }
        if (choice==2){//recursion squential search
            seqrecursion(array,size,position);
        }
        if (choice==3){//binary search
            binsearch(array,position,size);
        }
        if (choice==4){
            
        }
        if (choice==5){
            cout<<"A linked list has been initialized and filled using array data..."<<endl;
            cout<<"The linked list contains: "<<endl;
            link=newlist.begin();
            for (int i=0; i<newlist.size(); i++) {
                cout<< "#"<<i<<": "<<*link<<endl;
                link++;
            }
            listsearch(newlist,position);
            
        }
        if (choice==6){
            link=newlist.begin();
            listrecur(newlist,link,position);
        
        }
    
        }while(i!=0);
    return 0;
}

void seqrecursion (int array[], int size, int spot){
    if (size==0){
        cout<<"list is empty"<<endl;
    }
    if (array[size]==spot){
        cout<<"The number is at position# "<<spot-1<<endl;
    }
    else {
    seqrecursion(array, size-1, spot);
    }
}
void binsearch(int array[],int spot, int size){
    int pos=0;
    bool found=false;
    if(spot<array[size/2]){//look in the first half
        for(int i=0; i<size/2 && found!=true; i++){
            if(spot==array[i]){
                found=true;
                pos=i;
            }
        }
    }
    else{ //look in the second haft
        for(int i=size/2; i<size && found!=true; i++){
            if(spot==array[i]){
                found=true;
                pos=i;
            }
        }
    }
    if (found==true){
    cout<<"The Number is at position# "<<pos<<endl;
    }
    else{
        cout<<"Number was not found"<<endl;
    }
}
void listsearch(list<int> newlist, int spot){
    bool check=true;
    check=false;
    int i=0;
    for (list<int>::iterator link=newlist.begin(); link!=newlist.end(); ++link) {
                if (*link==spot) {
            cout<<"The number is at position# "<<i<<endl;
        }
        else if (check==true){
            cout<<"your number was not found"<<endl;
        }
        i++;

    }
}
//void listrecur(list<int> newlist, list<int>::iterator link, int spot){
//    if (*link<0){
//        cout<<"list is empty"<<endl;
//    }
//    if (*link==spot) {
//        cout<<"The number is at position# "<<&link<<endl;
//    }
//    else {
//    listrecur(newlist,link--,spot);
//    }
//    
//    
//    
//}






