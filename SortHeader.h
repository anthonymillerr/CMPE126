#include <iostream>
#include <random>

using  namespace std;

class Sort {
public:
    int *arr;
    int size;
    Sort (int n){
        size = n;
        arr = new int [size];
    }
    ~Sort(){
        delete[] arr;
    }
    void randArray(){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 10000);
        for (int i = 0; i < size; i++) {
            arr[i] = dis(gen);
        }
    }
    void mergeSort( int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2; // Calculate the middle point
            mergeSort(l, m); // Recursively sort the left subarray
            mergeSort(m + 1, r); // Recursively sort the right subarray
            merge(l, m, r); // Merge the sorted subarrays
        }
    }

    void merge( int l, int m, int r) {
        int n1 = m - l + 1; //sizes of subarrays
        int n2 = r - m;

        int L[n1], R[n2];
        for (int i = 0; i < n1; i++) //left subarray
            L[i] = arr[l + i];
        for (int j = 0; j < n2; j++) //right subarray 
            R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) { //if element in left array is smaller than or equal to element in right array,
                arr[k] = L[i]; //copy to original array and move index to next element in left array 
                i++;
            }
            else {
                arr[k] = R[j]; //same but move index j to next element for right array 
                j++;
            }
            k++; //move to next position in array
        }

        while (i < n1) { //copy remaining left elements into original array
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) { //copy remaining right elements into original array 
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void quickSort( int low, int high) {
        if (low < high) { //checks for more than one element
            int pi = partition(low, high); //calls parition to find pivot and place in right position 
            quickSort(low, pi - 1); //subarray left of pivot 
            quickSort(pi + 1, high); //subarray right of pivot 
        }
    }

    int partition( int low, int high) {
        int pivot = arr[high]; //last element of array 
        int i = low - 1; //index before first element 
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]); //swap current element with element at ith postion 
            }
        }
        swap(arr[i + 1], arr[high]); //swap pivot with the element at i+1
        return i + 1; //return index of pivot element
    }

    void bubbleSort() {
        bool swapped;
        for (int i = 0; i < size - 1; i++) {
            // compare each pair of adjacent elements in the unsorted part of the array.
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // if the current element is greater than the next element, swap them.
                swap(arr[j], arr[j + 1]); // swap the two elements.
                }
            }
        }
    }

    void insertionSort() {
        int key, j;
        for (int i = 1; i < size; i++) {
            key = arr[i];
            // store the index of the element to the left of the current element
        j = i - 1;
        // move all the elements greater than the current element to the right by one index
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // place the current element at its sorted position
        arr[j + 1] = key;
    }
}
    void selectionSort() {
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) // Loop over the unsorted portion of the array to find the index of the minimum element
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]); // Swap the minimum element with the first element of the unsorted portion of the array
    }
}
};
