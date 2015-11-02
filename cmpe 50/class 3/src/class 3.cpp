//============================================================================
// Name        : class.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctype.h>
using namespace std;
void drepeat(char arr[], int size);
int main() {
	char arr[]="to be or not to be, that is the question";
	int lenght;
	lenght=strlen(arr);
	drepeat(arr,lenght);

	return 0;
}
void drepeat(char arr[], int size) {

    int num = size;
    int start = 0;

    while(start < num)
    {
        char test = arr[start];
        for(int i = start+1; i <= num;i++)
        {
            if(test==arr[i])
            {
                for(int j = i;j<num;j++)
                    {
                    arr[j] = arr[j+1];
                    }
                num-=1;
            }
        }
    start +=1;
    }
    size = num;
cout<<"new array \n"<<arr<<endl;

}

//result
//new array
//to bern ,haisqu

