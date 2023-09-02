/*
 * Rectangle.h
 *
 *  Created on: Feb 3, 2023
 *      Author: anthonymiller
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <iostream>
#include "BasicShape.h"

using namespace std;

class Rectangle:public BasicShape{
private:
	long width;
	long length;

public:
	Rectangle(long w, long l){
		if(w < 0 || l < 0){
			cout << "WIDTH/LENGTH CANNOT BE NEGATIVE VALUES!"<< endl;
		}

		width = w;
		length = l;

		calcArea();
	}
	long getWidth() const{
		return width;
	}
	long getLength() const{
		return length;
	}
	virtual void calcArea(){
		area = length * width;
	}
};



#endif /* RECTANGLE_H_ */
