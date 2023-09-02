/*
 * cashRegister.h
 *
 *  Created on: Feb 2, 2023
 *      Author: anthonymiller
 */

#ifndef CASHREGISTER_H_
#define CASHREGISTER_H_

#include <iostream>

using namespace std;

class cashRegister
{
private:
	int initialCash;
public:
	cashRegister();
	cashRegister(int cashInsert);
	int getBalance() const;
	void takeCash(int totalIn);
};


#endif /* CASHREGISTER_H_ */
