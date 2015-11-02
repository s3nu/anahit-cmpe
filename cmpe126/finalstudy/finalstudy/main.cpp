//
//  main.cpp
//  finalstudy
//
//  Created by senu on 12/13/14.
//  Copyright (c) 2014 Anahit Sarao. All rights reserved.
//

#include <iostream>
#include <cstdlib>

using namespace std;

//insert sort
void insertsort(int dataset[], int n){
    int k,i;
    for(k=1;k<n;k++){
        cout<<"counter: "<<k<<endl;
        int pick_item=dataset[k];
        bool inserted=false;
        for(i=k-1;i>=0 && inserted!=true;){
            if(pick_item<dataset[i])
            {
                dataset[i+1]=dataset[i];
                i--;
                dataset[i+1]=pick_item;
            }
            else inserted=true;
        }
    }
}

//quick sort
int partition(int A[], int start, int end){
    int pivot,pindex, l,r;
    pindex=(start+end)/2; //index of pivot
    swap(A[end],A[pindex]); //move pivot to the end of list
    pivot=A[end];
    l=start;
    r=end-1;
    while(l<=r){
        while(A[l]<pivot){
            l++; //skip value less than pivot
        }
        while(A[r]>pivot){
            r--; //skip value greater than pivot
        }
        if(l<=r) {
            swap(A[l],A[r]); //swapping
        }
    }
    swap(A[end],A[l]); //swap pivot and the value at index l
    return l;
}
void quicksort(int A[], int start, int end){
    int q;
    while(start<end){
        q=partition(A,start,end);
        if(start<q){ //sort the left sub-list
            quicksort(A,start,q-1);
            start++;
        }
        else{ //sort the right sub-list
            quicksort(A, q+1, end);
            end--;
        }
    }
}
//selection sort
void selectsort(int A[],int n){
    int i,j,min;
    for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<n;j++)
            if(A[j]<A[min]){
                min=j;}//find min value
        int temp=A[i];//swapping
        A[i]=A[min];
        A[min]=temp;
    }
}


//binary search
int binarySearch (int list[],int item, int length){
    int first = 0;
    int last = length - 1;
    int mid;
    bool found = false;
    while (first <= last && !found)
    {
        mid = (first + last) / 2;
        if (list[mid] == item)
            found = true;
        else if (list[mid] > item)
            last = mid - 1;
        else
            first = mid + 1;
    }
    if (found)
        return mid;
    else
        return -1;
}//end binarySearch
//-----------------------------------------hash table---------------------------------------

int main(int argc, const char * argv[]) {
        cout<<"------selection sort------"<<endl;
//selection sort
    int A[]={7,28,31,40,5,20,88};
    selectsort(A,7);
    for(int i=0;i<7;i++){
        cout<<A[i]<<endl;
    }
//insert sort
    cout<<"------insert sort------"<<endl;
    int arr[7]={7,28,31,40,5,20,88}; //unsorted data set
    insertsort(arr,7); //sorting process using insertion sort
    for(int i=0;i<7;i++){
        cout<<arr[i]<<"\t"; //after sorting
    }
    cout<<endl;
//quick sort
    cout<<"------quick sort------"<<endl;
    int b[7]={7,28,31,40,5,20,88};
    quicksort(b,0,7); //sort the arry
    for(int i=0;i<7;i++){ //after sorting
        cout<<b[i]<<"\t";
    }
    cout<<endl;
//binary search
    cout<<"------binary search------"<<endl;
    int b2[7]={1,3,4,5,6,7};
    int result;
    result=binarySearch(b2,5,8);
    cout<<result<<endl;
    
    
    
    return EXIT_SUCCESS;
}
