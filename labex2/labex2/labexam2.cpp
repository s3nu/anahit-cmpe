#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

struct personNodeType{
	string name;
	int year;
	personNodeType *link;

};
personNodeType* loadAndCreateList(string s);		//Read in from the file and created a forward-linked list. Should return the head of the list.
void print(personNodeType *current, ofstream &out);	//Print the name and year of each node in order.
personNodeType* sort(personNodeType *current);		//Sort the linked list from oldest to youngest person.
int setSize(personNodeType *current);	//Recursive function. Set and return the "size" integer for each node based on its distance from the NULL pointer. This should also return the list size when the head is passed in.
void reversePrint(personNodeType *current, ofstream &out);	//Recursive function. Print the name and year of birth for each person in reverse order (youngest to oldest).
personNodeType* removeAndPrint(string s, personNodeType *head, ofstream &out);	//Remove the specified person from the list and print their info. This includes name, year of birth, and "size" integer. Should return the head of the list.
void reversePrintFrom(int i, personNodeType *current, ofstream &out);	//Recursive function. Reverse-print from the node with a specified "size". Print the name, year of birth, and "size" integer.

personNodeType* loadAndCreateList(string s){
	personNodeType *head = new personNodeType;
	personNodeType *current = head;
	personNodeType *temp;
	ifstream in;
	in.open(s.c_str());
	if(in.fail()){
		cout << "Error reading file!" << endl;
		exit(1);
	}
	string tempname;
	int tempyear=0;
	while(!in.eof()){
		in>>tempname;
		in>>tempyear;
		current->name=tempname;
		current->year=tempyear;
		temp=new personNodeType;
		current->link=temp;
		current=temp;
	}
	current->link=NULL;
	return head;
}
void print(personNodeType *current, ofstream &out){
	while (current->link!=NULL){
		out<<current->name<<" ";
		out<<current->year<<endl;
		current=current->link;
	}
}
personNodeType* sort(personNodeType *current){

	personNodeType * temphead = current;
	int tempyear;
	string tempname;
	int counter = 0;
	while (temphead)
	{
		temphead = temphead->link;
		counter++;
	}
	temphead = current;
	for (int j=0; j<counter; j++)
	{
		while (temphead->link)
		{
			if (temphead->year > temphead->link->year)
			{
				tempyear = temphead->year;
				temphead->year = temphead->link->year;
				temphead->link->year = tempyear;

				tempname = temphead->name;
				temphead->name = temphead->link->name;
				temphead->link->name = tempname;
				temphead = temphead->link;
			}
			else
				temphead = temphead->link;
		}
		temphead = current;
	}
    if(current->year== 0){ //this gets rid of the extra 0 from *somewhere*
        			current = current->link;
        		}
	return current;
}

void reversePrint(personNodeType *current, ofstream &out){

	if (current->link == NULL){
		return;
	}
	personNodeType * temp = current->link;
	reversePrint(temp, out);
	out<< current->name <<" "<< current->year<<endl;
}
personNodeType* removeAndPrint(string s, personNodeType *head, ofstream &out){
	personNodeType * current = head;
	while (current->link!=NULL){
		if (current->name==s.c_str()){
			 out<<current->name<<" "<<current->year<<endl;
		}
		current=current->link;
	}
	personNodeType *curr,*prev;
    prev=curr=head;
	  if(curr==NULL)
	  {
	    cout<<"No Records to Delete";
	  }
	  while((curr!=NULL)&&(curr->name!=s.c_str()))
	  {
	    prev=curr;
	    curr=curr->link;
	  }
	  if(curr==NULL)
	  {
	    cout<<"\nRecord not Found!!!";
	    return head;
	  }
	  if(curr==head)
	  {
	    curr=curr->link;
	    cout<<"\nData deleted: "<<endl;
	  }
	  else
	  {
	    prev->link=curr->link;
	    if(curr->link==NULL)
	    {
	      curr=prev;
	    }

	  }
//	  delete(curr);
	return head;
}
int main() {
	ofstream fout;
	fout.open("exam2_5583.txt");//Replace #### with last four digits of ID
	fout << "My name is Anahit Sarao." << endl;							//Replace ---- with your first/last name
	fout << "The last 4 digits of my ID are 5583." << endl;		//Replace #### with last four digits of ID
	fout << "\n***Objective 1***" << endl;
	personNodeType *head = loadAndCreateList("personData.txt");
	fout << "List of people:" << endl;
	print(head, fout);
	head = sort(head);
	fout << "List of people from oldest to youngest:" << endl;
	print(head, fout);
	fout << "\n***Objective 2***" << endl;
	fout << "List of people from youngest to oldest:" << endl;
	reversePrint(head, fout);
	fout << "Removing Frank from the roster.\nFrank's information:" << endl;
	head = removeAndPrint("Frank", head, fout);
	fout << "Removing Freddy from the roster.\nFreddy's information:" << endl;
	head = removeAndPrint("Freddy", head, fout);
	fout << "Removing Bonnie from the roster.\nBonnie's information:" << endl;
	head = removeAndPrint("Bonnie", head, fout);
	fout << "New list of people from youngest to oldest:" << endl;
	reversePrint(head, fout);
	fout << "\n***Objective 3***" << endl;
//	fout << "List size: " << setSize(head) << endl;
//	fout << "List of people from the 5th youngest person to the oldest person:" << endl;
//	reversePrintFrom(5, head, fout);

    return 0;
}
