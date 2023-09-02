/*
 * dispenserType.h
 *
 *  Created on: Feb 2, 2023
 *      Author: anthonymiller
 */

#ifndef DISPENSERTYPE_H_
#define DISPENSERTYPE_H_

#include <iostream>
#include <string>

class dispenserType
{
private:
	int numOfItems;
	int cost;
public:
	dispenserType();
	dispenserType(int setNumOfItems, int setCost);
	int getNumOfItems() const;
	int getCost() const;
	void sellItem();
};

#endif /* DISPENSERTYPE_H_ */
