#include <iostream>
#include <stack>
#include <string>
#include "mathExp.h"

using namespace std;

int main(){

	dispInstruct();
    string temp;
	string infx1 = " 5 + 5 - 1 ";
	string infx2 = "(2+3)^1";
	string infx3 = "(~1+~2)*(5-6)";
	string infx4 = "(3+1)*2-(28*1.5+1)/3";
	string infx5 = "3+1*2-(2*1+1)/33";
    temp= convertToPfx(infx1);
	cout << "Infix: " << infx1 << endl
			<<"  Postfix: " << convertToPfx(infx1) << endl
                <<"evaluated: "<< eval(temp)<< endl;
    temp= convertToPfx(infx2);
	cout << "Infix: " << infx2 << endl
			<<"  Postfix: " << convertToPfx(infx2) << endl
                <<"evaluated: "<< eval(temp)<< endl;
     temp= convertToPfx(infx3);
	cout << "Infix: " << infx3 << endl
			<<"  Postfix: " << convertToPfx(infx3) << endl;
     temp= convertToPfx(infx4);
	cout << "Infix: " << infx4 << endl
			<<"  Postfix: " << convertToPfx(infx4) << endl
                <<"evaluated: "<< eval(temp)<< endl;
     temp= convertToPfx(infx5);
	cout << "Infix: " << infx5 << endl
			<<"  Postfix: " << convertToPfx(infx5) << endl
                <<"evaluated: "<< eval(temp)<< endl;
    
    
}
/*This program is able to handle the following:
 - negative numbers denoted by '~'
 - basic operators: +,-,*,/
 - program uses STL stack implementation
 
 Infix:  5 + 5 - 1
 Postfix: 5 5 +1-
 evaluated: 9
 Infix: (2+3)^1
 Postfix: 2 3+ 1^
 evaluated: 5
 Infix: (~1+~2)*(5-6)
 Postfix: ~1 ~2+ 5 6-*
 Infix: (3+1)*2-(28*1.5+1)/3
 Postfix: 3 1+ 2 *28 1.5 *1+ 3/-
 evaluated: 8
 Infix: 3+1*2-(2*1+1)/33
 Postfix: 3 1 2 *+2 1 *1+ 33/-
 evaluated: 2
 Program ended with exit code: 0
*/
