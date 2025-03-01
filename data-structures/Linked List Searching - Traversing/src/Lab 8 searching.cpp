//============================================================================
// Name        : Lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int seqrecursive(int a[],int elem,int max_size);
void binarysrch(int a[],int elem,int size);
int binaryreq(int a[],int elem,int low,int high);


struct node{
	node *link;
	int data;


};
int reclink(node *head,int counter,int size,int key);
node* create(int a[],int size);
void linksearch(node *head,int size,int key);
int main() {

	int choice =0;
	int elem=0;
	int size=0;
	int *array;
	cout<<"INPUT INFO before selecting search method\n\n\n"<<endl;
	cout<<"Specify the number of elements to be searched"<<endl;
	cin>>size;
	array=new int[size];
	cout<<"Choose elements added to list"<<endl;
	for(int i=0;i<size;i++){
		cin>>array[i];
	}
	cout<<"Elements added to the array\n"<<endl;
	for(int i=0;i<size;i++){
		cout<<array[i];
	}

	cout<<"\nSpecify the element to be searched for: ";
	cin>>elem;

	cout<<"\n Searching for "<<elem<<"....."<<endl;

	do {
		cout<<"\nChoose your search type:";
		cout<<"\n1. Arrays: Sequential Search without recursion";
		cout<<"\n2. Arrays: Sequential Search with recursion";
		cout<<"\n3. Ordered Arrays: Binary Search without recursion";
		cout<<"\n4. Ordered Arrays: Binary Search with recursion";
		cout<<"\n5. Linked List: Search without recursion";
		cout<<"\n6. Linked List: Search with recursion";
		cout<<"\nEnter 0 to exit.\n";
		cin>>choice;
		cout<<"\nYour choice: "<<choice<<endl;

		if(choice==0){
			return 0;
		}

		if(choice==1){
			bool found=false;

			for(int i=0;i<size;i++){
				if(array[i]==elem){
					cout<<"\nElement found at index/position : "<<i<<endl;
					found=true;
				}

			}

			if(!found){
				cout<<"\nElement not found"<<endl;
			}
		}
		if(choice==2){


			cout<<"\nElement found at "<<seqrecursive(array,elem,size)<<endl;
		}
		if(choice==3){


			binarysrch(array,elem,size+1);

		}
		if(choice==4){

			int index=0;
			index=binaryreq(array,elem,0,size+1);
			if(array[index]==elem){
				cout<<"\nElement found at "<<index<<endl;

			}
			else{
				cout<<"\nElement not found... "<<endl;
			}


			//			char c;
			//
			//			cout<<"Would you like to search for another element in the list? \n Y/N \n "<<endl;
			//			cin>>c;
			//
			//			if(c=='Y'){
			//				cout<<"What element would you like to search for?"<<endl;
			//				cin>>elem;
			//
			//				int index=0;
			//				index=binaryreq(array,elem,0,size+1);
			//				if(array[index]==elem){
			//					cout<<"Element found at "<<index<<endl;
			//
			//				}
			//				else{
			//					cout<<"Element not found... "<<endl;
			//				}
			//
			//			}
			//			else if(c=='N'){
			//				return 0;
			//			}




		}

		if(choice==5){
			node *head;
			head=create(array,size);
			linksearch(head,size,elem);

		}
		if(choice==6){
			node*head;
			head=create(array,size);
			cout<<"\nElement Found at : "<<reclink(head,0,size,elem);




		}





	} while(choice!=0);





	return 0;
}
int seqrecursive(int a[],int elem,int max_size){

	if(max_size==0){
		cout<<"\nElement not found"<<endl;

		return 0;
	}

	if(a[max_size]==elem){
		return max_size;

	}
	else{
		return seqrecursive(a,elem,max_size-1);
	}



}

void binarysrch(int a[],int elem,int size){
	int p1=0;
	int p2=size-1;
	int counter=0;
	int mid=size/2;
	bool found=false;

	if(a[mid]==elem){
		counter=mid;
		found=true;
	}

	else if(a[mid]<elem){
		mid=mid+1;
		while(p2>=mid && !found){

			if(a[mid]==elem){
				counter=mid;
				found=true;
			}
			else{
				mid++;
			}

		}

	}
	else if(a[mid]>elem){
		mid=mid-1;
		while(p1<=mid && !found){

			if(a[mid]==elem){
				counter=mid;
				found=true;

			}
			else{
				mid--;
			}
		}


	}


	if(found){
		cout<<"Element found at position "<<counter<<endl;;
	}
	else {
		cout<<"Element not found"<<endl;
	}

}
int binaryreq(int a[],int elem,int low,int high){



	if(low>high || high<low){


		return 0;
	}

	int mid=(low+high)/2;


	mid +=low;

	if(a[mid] == elem){


		return mid;


	}

	else if(a[mid]<elem){



		return binaryreq(a,elem,(mid+1),high);

	}
	else if(a[mid]>elem){


		return binaryreq(a,elem,low,(mid-1));
	}




}

node* create(int a[],int size){



	node *head=new node;
	node *current=new node;
	current=head;

	for(int i=0;i<size;i++){
		node *temp=new node;
		current->link=temp;
		current->data=a[i];
		current=temp;

	}

	current->link=NULL;




	return head;




}
void linksearch(node *head,int size,int key){


	bool found=false;

	for(int i=0;i<size-1;i++){


		if(head->data==key){
			found=true;
			cout<<"\nElement found at position "<<i<<endl;
			head=head->link;
			break;
		}
		else{
			head=head->link;
		}

	}

	if(!found){

		cout<<"\nElement not found"<<endl;

	}

}

int reclink(node *head,int counter,int size,int key){

	if(counter==size-1){
		cout<<"\n Element not found"<<endl;

		return 0;
	}

	else if(head->data==key){

		return counter;

	}
	else{
		return reclink(head=head->link,counter+1,size,key);
	}



}










