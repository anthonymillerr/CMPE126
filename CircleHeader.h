/*
 * Circle.h
 *
 *  Created on: Feb 3, 2023
 *      Author: anthonymiller
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <iostream>
#include "BasicShape.h"

using namespace std;

class Circle:public BasicShape{
private:
	long centerX;
	long centerY;
	double radius;
public:
	Circle(long X,long Y,double r){
		if(radius < 0){
			cout<<"RADIUS CANNOT BE NEGATIVE"<<endl;
		}
		centerX = X;
		centerY = Y;
		radius = r;

		calcArea();
	}
	long getCenterX() const{
		return centerX;
	}
	long getCenterY() const{
		return centerY;
	}
	virtual void calcArea(){
		area = 3.14159 * radius * radius;
	}
};

#endif /* CIRCLE_H_ */
