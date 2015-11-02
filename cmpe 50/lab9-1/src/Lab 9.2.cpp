#include <iostream>
#include "class.h"

using namespace std;

void myDraw(Figure *fig)
{
	fig->draw();
	cout << "\n myDraw: Derived class object calling center(). \n";
	fig->center();
}

int main(){
	Figure *fig;
	Triangle *tri = new Triangle;

	fig = tri;
	fig->draw();
	cout << "\n Derived class Triangle object calling center(). \n";
	fig->center();

	myDraw(tri);

	Circle *cir = new Circle;
	fig = cir;
	cir->draw();
	cout << "\n Derived class Circle object calling center(). \n";
	cir->center();

	myDraw(cir);
return 0;
}
/*Output with no virtual
 * Figure: draw

 Derived class Triangle object calling center().
Figure: center
Figure: draw

 myDraw: Derived class object calling center().
Figure: center
circle: draw

 Derived class Circle object calling center().
circle: center
Figure: draw

 myDraw: Derived class object calling center().
Figure: center
 *
 *
 * Output with virtual
 * triangle: draw

 Derived class Triangle object calling center().
triangle: center
triangle: draw

 myDraw: Derived class object calling center().
triangle: center
circle: draw

 Derived class Circle object calling center().
circle: center
circle: draw

 myDraw: Derived class object calling center().
circle: center
 *
 *
 *
 *
 * Difference:
 * Virtual functions allow the member functions to be accessed from child classes through the base class. In the output
 * with the virtual functions all of the member functions came from the child classes, while without the virtual functions
 * most of the member classes came from the  parent class.
 *
 *
 */
