//============================================================================
// Name        : CMPE126-LAB-2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : LAB 2
//============================================================================

#include <iostream>
using namespace std;

void switchOperands(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main() {
	int x, y;
	cout << "Enter First Integer: " << endl;
	cin >> x;
	cout << "Enter Second Integer: " << endl;
	cin >> y;

	switchOperands(&x, &y);

	cout<<"First Integer Now Becomes: " << x << endl;
	cout<<"Second Integer Now Becomes: " << y << endl;

	return 0;
}
