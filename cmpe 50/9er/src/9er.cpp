//============================================================================
// Name        : lab9.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <string>
#include <iostream>
#include "admin.h"

int main() {
	admin ad1;
	ad1.setname();
	ad1.read();
	ad1.printer(ad1);
	ad1.print_check();
	return 0;
}
/*enter name of the BOSS
anahit
1-enter salary
2-enter admin second in command
3-enter company area of interest
4-exit
1
1-would u like use old salary
2-enter a new salary
2
enter new salary
10000
1-enter salary
2-enter admin second in command
3-enter company area of interest
4-exit
2
enter second in command name
anahit
1-enter salary
2-enter admin second in command
3-enter company area of interest
4-exit
3
enter companies interest
R&D
1-enter salary
2-enter admin second in command
3-enter company area of interest
4-exit
4
BOSS name: anahit
second in command : anahit
field of interest: R&D
salary: 10000.00



__________________________________________________
Pay to the order of anahit
The sum of 10000.00 Dollars
_________________________________________________
Check Stub NOT NEGOTIABLE
*/

