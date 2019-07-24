


#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{

	int data;
	node *link;

};

void random(node *head);
int print(node *head);
node* returnMiddleList(node *head);
void loopPosition(node *head);
void check(node *head);

void merge(node *head);
node *sort(node *a,node *b);
void mergesort(node *head);
void split(node *head);
void mergelist(node *head);

int main() {
	node *newptr=new node;
	// we use my  random function to create a new link list with random numbers from 0-99
	random(newptr);

	cout<<"CONSOLE OUTPUT:"<<endl;
	cout<<"Random List"<<endl;
	//We print the linked list
	print(newptr);

	cout<<"\n\n\n"<<endl;



	//We find where the middle number of the list is located and what the value of the number is
	//We also split the list into two different lists starting from the middle number to the end and another list from
	//the beggining to the middle number

	returnMiddleList(newptr);

	cout<<"\n\n\n"<<endl;
	//We set the entire linked list to 0

	loopPosition(newptr);

	//We create a never ending loop in our linked list in order to test our check function
	newptr->link->link->link->link=newptr;

	//Using our defined check function we find out at what position there is a never ending loop in our linked list,
	//if there is no loop found we return -1
	check(newptr);



	//------unable to get merge sort function to properly work
	//	mergesort(newptr);
	//	cout<<"recursion sorted list"<<endl;
	//	print(newptr);

	return 0;
}

void mergelist(node *head){

}

void split(node *head,node *p2,node *p3){

	node *fast;
	node *slow;


	if (head==NULL || head->link==NULL)
	{
		p2 = head;
		p3 = NULL;
	}
	else
	{
		slow = head;
		fast = head->link;

		while (fast != NULL)
		{
			fast = fast->link;
			if (fast != NULL)
			{
				slow = slow->link;
				fast = fast->link;
			}
		}

		p2 = head;
		p3 = slow->link;
		slow->link = NULL;
	}


}
node *sort(node *a,node *b){

	node *sorted;

	if(a==NULL){
		return b;
	}
	else if(b==NULL){
		return a;
	}

	if(a->data<=b->data){
		sorted=a;
		sorted->link=sort(a->link,b);
	}
	else{
		sorted=b;
		sorted->link=sort(a,b->link);
	}
	return (sorted);
}

void mergesort(node *head){

	node *p2;
	node *p3;

	if(head==NULL||head->link==NULL){

		return;
	}
	else{

		split(head,p2,p3);

		mergesort(p2);
		mergesort(p3);

		head=sort(p2,p3);
	}


}




void random(node *head){

	node *current=head;
	node *temp;
	for(int i=0;i<19;i++){

		current->data = rand() % 100;
		temp=new node;
		current->link=temp;
		current=temp;
	}
	temp->link=NULL;
}

int print(node *head){
	int count=0;
	while(head !=NULL){

		cout <<count+1<<" "<<head->data << endl;
		head=head->link;
		count++;
	}

	return count;
}


node* returnMiddleList(node *head){

	node *p1=head;
	node *p2=head;
	int counter=1;
	int sum1=0;
	int sum2=0;

	while(p2 != NULL && p2->link != NULL){
		p1 = p1->link;
		p2 = p2->link->link;
		counter++;
	}
	cout<<"The value of the middle number is "<<p1->data<<endl;

	cout<<"The position of the middle number is "<<counter<<endl<<endl;


	p2=head;
	cout<<"List 1"<<endl;
	while(p2->data!=p1->data){
		sum1+=p2->data;
		cout<<p2->data<<endl;
		p2=p2->link;
	}
	cout<<"sum of the first list... "<<sum1<<endl;

	cout<<endl;
	cout<<"List 2"<<endl;
	while(p2!=NULL){
		sum2+=p2->data;
		cout<<p2->data<<endl;
		p2=p2->link;
	}
	cout<<"Sum of the second list.. "<<sum2<<endl;
	return p2;



}


void loopPosition(node *head){

	node* loop=head;
	int count=1;
	cout<<" The zero list now is.."<<endl;
	while(loop!=NULL){

		loop->data=0;
		cout<<count<<" "<<loop->data<<endl;
		loop=loop->link;
		count++;

	}


}
void check(node *head){

	node *last=head;
	node *first=head;
	int count=0;
	cout<<endl;

	while(last&&first&&last->link){

		first=first->link;
		last=last->link->link;
		count++;
		if(first==last){
			cout<<"loopPosition at"<<endl;
			cout<<count;

			break;
		}


	}
	if(last!=first){
		cout<<"-1"<<endl;
	}


}













