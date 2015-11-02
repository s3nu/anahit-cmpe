//============================================================================
// Name        : lecture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class StringVar {
public:
	StringVar(int size);
	StringVar();
	StringVar(const char a[]});
	StringVar(const StringVar& string_object);
	~StringVar();

	int lenght(); const;
	void input_lines(istream& ins);
	StringVar copy_place(int pos, int npos);
	char one_char(int pos);
	void set_char(int pos, char c);

};
int main() {


	return 0;
}
