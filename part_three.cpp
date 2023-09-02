//============================================================================
// Name        : CMPE126-LAB-2-3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : part_three
//============================================================================

#include <iostream>
using namespace std;

template<typename T>
T *reverse_array(T *arr, int size){
T *result = new T[size];
for(int i = 0; i < size; ++i){
	result[i] = arr [size - i - 1];
}
return result;
}
template<typename T>
void print_arr(T *arr, int size){
	for (int i = 0; i < size; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {1,2,3,4,5};
	int size = 5;

	cout<< "Intial Array List: " << endl;
	print_arr(arr, size);
	cout<< "\nReversed Array List: " << endl;
	print_arr(reverse_array(arr,size),size);

	return 0;
}
