/*
 * class.h
 *
 *  Created on: May 1, 2014
 *      Author: nsarras
 */

#ifndef CLASS_H_
#define CLASS_H_

class Figure{

public:
	void virtual erase();
	void virtual draw();
	void virtual center();


private:


};

class Circle: public Figure{
public:
		void erase();
		void draw();
		void center();
protected:

};
class Triangle: public Figure{

public:
	void erase();
	void draw();
	void center();

protected:


};






#endif /* CLASS_H_ */
