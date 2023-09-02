/*
 * part_two.cpp
 *
 *  Created on: Feb 9, 2023
 *      Author: anthonymiller
 */

#include <iostream>

using namespace std;

void enterArrayData(int *arr, int n)
{
	cout<<"Enter Elements For Array Data" << endl;
	for(int i=0; i<n; i++)
	{
		cin >> *(arr + i);
	}
}
void outputArrayData(int *arr, int n){
	cout<< "The Array Data Is: "<< endl;
	for (int i = 0; i<n; i++){
		cout << *(arr + i)<< " ";
	}
	cout<<endl;
}
void sumArray(int* arr, int n){
	int sum = 0;
	cout<<"Sum Of Array Data Is: " << endl;
	for (int i = 0; i < n; i++)
	{
		sum += *(arr + i);
	}
	cout << sum << endl;
}

int main() {
	int n;
	cout<<"Enter Size For Array: " << endl;
	cin >> n;
	int* arr = new int[n];

	enterArrayData(arr, n);
	outputArrayData(arr, n);
	sumArray(arr, n);

	return 0;

}
