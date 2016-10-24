//
//  main.cpp
//  lab3
//
//  Created by senu on 9/30/14.
//  Copyright (c) 2014 senu. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct nodetype {
    int data;
    nodetype *second;
};
void random (nodetype *head);
void printer(nodetype *head);
void middle(nodetype *head);
void cut(nodetype *head);
void nuller(nodetype *head);
void loop(nodetype *head);
void sort(nodetype *head);
nodetype* mergeList(nodetype* head, nodetype* head1);
nodetype* splitList(nodetype *head);
nodetype* mergeSort(nodetype *head);
nodetype* sorting(nodetype* head, nodetype* head2);

int main() {
    nodetype *head= new nodetype;
    nodetype *head2=new nodetype;
    random(head);
    printer(head);
//    middle(head);
//    cut(head);
//    nuller(head);
//    loop(head);
    cout<<"new list#1"<<endl;
//    head2=mergeSort(head);
    head2=splitList(head);
    printer(head);
    cout<<"new list#1"<<endl;
    printer(head2);
    
    return 0;
}
nodetype* mergeSort(nodetype *head){
    nodetype *temp;
    //check NULL cases
    if(head == NULL){
        return NULL;
    }
    //	if list only has one node its already sorted
    else if (head->second == NULL){
        //when there's only one object in the list
        return head;
    }
    else{
        temp = splitList(head);
        return mergeList( mergeSort(head),mergeSort(temp) );
    }
}
nodetype* sorting(nodetype* head, nodetype* head2){
    nodetype* stored;
    if (head==NULL){
        return head2;
    }
    else if (head==NULL) {
        return head;
    }
    if (head->data<=head2->data) {
        stored=head;
        stored->second=sorting(head->second,head2);
    }
    else{
        stored=head2;
        stored->second=sorting(head, head2->second);
    }
    return stored;
}
nodetype* splitList(nodetype *head){
    nodetype *temp1=head;
    nodetype *temp2=head;
    nodetype *end;
    nodetype *newlist;
    while (temp2->second!= NULL) {
        temp2=temp2->second->second;
        temp1=temp1->second;
        if (temp2 == NULL){
            end=temp1;
            newlist=end->second;
            end->second=NULL;
            break;
        }
    }
    return newlist;
}
nodetype* mergeList(nodetype* head, nodetype* head1){
    
    
    return head;
}
void random(nodetype *head){
    nodetype *temp;
    nodetype *element=head;
    for (int i=0; i<19; i++){
        element->data=rand()%100;
        temp=new nodetype;
        element->second=temp;
        element=temp;
    }
    temp->second=NULL;
}
void printer(nodetype *head){
    int count=0;
    while (head != NULL) {
        cout<<" "<<head->data<<endl;
        head=head->second;
        count++;
    }
}
void middle(nodetype *head){
    nodetype *p1=head;
    nodetype *p2=head;
    while ( p2->second != NULL ) {
        p2 = p2->second;
        if (p2->second != NULL) {
            p2 = p2->second;
            p1 = p1->second;
        }
    }
        cout<<"the middle number is: "<<p1->data<<endl;
    cout<<endl;
}
void cut(nodetype *head){
    int *counter;
    counter=new int[1];
    nodetype *p1=head;
    nodetype *p2=head;
    int *adder;
    adder=new int[1];
    counter[1]=0;
    while ( p2->second != NULL ) {
        p2 = p2->second;
        if (p2->second != NULL) {
            p2 = p2->second;
            p1 = p1->second;
        }
        counter[1]++;
    }//p2 is at end //p1 is at middle
    p2=head;
    adder[1]=0;
    while (p2->data != p1->data){
        cout<<"first half of list is: " <<p2->data<<endl;
        adder[1]=adder[1]+p2->data;
        p2=p2->second;
    }//p2 is at mid //p1 is at mid
    cout<<"sum list 1: "<<adder[1]<<endl;
    cout<<endl;
    adder[1]=0;
    while (p2 != NULL){
        cout<<"second half of list is: " <<p2->data<<endl;
        adder[1]=adder[1]+p2->data;
        p2=p2->second;
    }
    cout<<"sum list 2: "<<adder[1]<<endl;
    cout<<endl;
}
void nuller(nodetype *head){
    nodetype *nuller=head;
    int counter=0;
    cout<<"nulled list"<<endl;
    while (nuller != NULL){
        nuller->data=0;
        nuller=nuller->second;
        cout<<head->data<<endl;
        counter++;
    }
    cout<<endl;

}
void sort(nodetype *head){
    
}
void loop(nodetype *head){
    nodetype  *p1 = head;
    int counter=0;
    int counter1=0;
    nodetype  *p2 = head;
    cout<<"loop assigned to list"<<endl;
    head->second->second->second->second->second->second->second = head->second->second->second->second;
    cout<<"Looking for loop:"<<endl;
    while (p1 && p2 && p2->second)
    {
        p1 = p1->second;
        p2  = p2->second->second;
        if (p1 == p2)
        {
            cout<<"loop found...finding positions of loop within list"<<endl;
            int dummy = 1;
            nodetype *ptr1=p2;
            nodetype *ptr2=p2;
            while (ptr1->second != ptr2)
            {
                ptr1 = ptr1->second;
                dummy++;
            }
            ptr1 = head;
            ptr2 = head;
            for(int i = 0; i < dummy; i++) {
                ptr2 = ptr2->second;
            }
            while(ptr2 != ptr1)
            {
                counter++;
                ptr1 = ptr1->second;
                ptr2 = ptr2->second;
            }
            ptr2 = ptr2->second;
            while(ptr2->second != ptr1){
                ptr2 = ptr2->second;
                counter1++;
            }
            counter1=counter+counter1;
            cout<<"loops starts at position: "<<counter<<endl;
             cout<<"loops ends at position: "<<counter1<<endl;
            exit(0);
        }
    }
    cout<<"no loop found exiting -1"<<endl;
}

