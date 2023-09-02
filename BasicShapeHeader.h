/*
 * BasicShape.h
 *
 *  Created on: Feb 3, 2023
 *      Author: anthonymiller
 */

#ifndef BASICSHAPE_H_
#define BASICSHAPE_H_

#include <iostream>

using namespace std;

class BasicShape{
protected:
	double area;

public:
	double getArea() const{
		return area;
	}
	virtual void calcArea() = 0;
};

#endif /* BASICSHAPE_H_ */
