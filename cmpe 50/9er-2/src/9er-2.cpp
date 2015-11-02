//============================================================================
// Name        : 9er-2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
//#include <iostream>
//#include "figure.h"
//#include "circle.h"
//#include "triangle.h"
class figure {
public:
	void center();
	void erase();
	void draw();

private:

};

class triangle: public figure {
public:
	void center();
	void erase();
	void draw();
private:

};
class circle: public figure {
public:
	void center();
	void erase();
	void draw();

private:

};

void myDraw(figure *fig) {
	fig->draw();
	cout << "\n myDraw: Derived class object calling center(). \n";
	fig->center();
}

int main() {
	figure *fig;
	triangle *tri = new triangle;

	fig = tri;
	fig->draw();
	cout << "\n Derived class Triangle object calling center(). \n";
	fig->center();

	myDraw(tri);

	circle *cir = new circle;
	fig = cir;
	cir->draw();
	cout << "\n Derived class Circle object calling center(). \n";
	cir->center();

	myDraw(cir);

	return 0;

}
void circle::center(){
	cout<<"called center circle"<<endl;
}
void trianglecenter(){
	cout<<"called center triangle"<<endl;
}
void figure::center(){
	cout<<"called center"<<endl;

}
void figure::erase(){
	cout<<"called erase figure"<<endl;
}
void figure::draw(){
	cout<<"called draw figure"<<endl;
}
void triangle::erase(){
	cout<<"called erase triangle"<<endl;
}
void triangle::draw(){
	cout<<"called draw triangle"<<endl;
}
void circle::erase(){
	cout<<"called erase circle"<<endl;
}
void circle::draw(){
	cout<<"called circle draw"<<endl;
}
/*called draw figure

 Derived class Triangle object calling center().
called center
called draw figure

 myDraw: Derived class object calling center().
called center
called circle draw

 Derived class Circle object calling center().
called center circle
called draw figure

 myDraw: Derived class object calling center().
called center
 *
 */
