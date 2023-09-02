/*
 * cashRegister.cpp
 *
 *  Created on: Feb 2, 2023
 *      Author: anthonymiller
 */

#include <iostream>
#include "cashRegister.h"

using namespace std;

int cashRegister::getBalance() const
{
	return initialCash;
}
void cashRegister::takeCash(int totalIn)
{
	initialCash = initialCash + totalIn;
}
cashRegister::cashRegister()
{
	initialCash = 0;
}
cashRegister::cashRegister(int cashInsert)
{
	if(cashInsert >= 0)
		initialCash = cashInsert;
	else
		initialCash = 0;
}

