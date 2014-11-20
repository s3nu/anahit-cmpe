//
//  main.cpp
//  lab8
//
//  Created by senu on 11/19/14.
//  Copyright (c) 2014 senu. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;


int main() {
    int choice=0;
    int i=0;
    int position=0;
    int size=0;
    int *array;
    cout<<"How many Numbers?"<<endl;
    cin>>size;
    array=new int[size];
    cout<<"Enter your numbers: "<<endl;
    for (int i=0; i<size; i++) {
        cin>>array[i];
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
        cout<<"\nEnter 0 to exit.\nYour choice: ";
        cin>>choice;
        if (choice==0){
            break;
        }
        if (choice==1){
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
        if (choice==2){
            
        }
        if (choice==3){
            
        }
        if (choice==4){
            
        }
        if (choice==5){
            
        }
        
        
    } while(i!=0);

    
    
    
    
    
    return 0;
}
