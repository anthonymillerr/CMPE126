/*
 * dispenserType.cpp
 *
 *  Created on: Feb 2, 2023
 *      Author: anthonymiller
 */

#include <iostream>
#include "dispenserType.h"

using namespace std;

dispenserType::dispenserType()
{
	numOfItems = 0;
	cost = 0;
}
dispenserType::dispenserType(int setNumOfItems, int setCost)
{
	if(setNumOfItems >= 0)
		numOfItems = setNumOfItems;
	else
		numOfItems = 0;
	if(setCost>=0)
		cost = setCost;
	else
		cost = 0;
}
int dispenserType::getNumOfItems() const
{
	return numOfItems;
}
int dispenserType::getCost() const
{
	return cost;
}
void dispenserType::sellItem()
{
	numOfItems--;
}
