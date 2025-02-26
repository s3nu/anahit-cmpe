#include "clock.h"
#include <iostream>

int main()
{
    using namespace std;
    
    
    clocktype c1(15, 45, 30), c2(3, 20);  // hour, min, sec
    cout<<"original time"<<endl;
    cout << c1;
    cout << c2;
    cout<<"adding time"<<endl;
    cout <<  c1+c2;
    cout<<"final time"<<endl;
    c2 = c1+c1;
    cout << c2;
    
    return 0;
}
