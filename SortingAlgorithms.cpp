#include<iostream>
using namespace std;

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    int mid = size / 2;
    int left[mid];
    int right[size - mid];
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }
    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(arr, left, mid, right, size - mid);
}
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
void bubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main() {
    int arr[] = {12, 5, 99, 34, 23, 19, 33, 2, 90, 15, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, size);
    cout<< "Sorted Array For Merge Sort: "<<endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, size-1);
    cout << "Sorted Array For Quick Sort: "<<endl;
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;

    bubbleSort(arr, size);
    cout<<"Sorted Array For Bubble Sort: " <<endl;
    for (int i=0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    insertionSort(arr, size);
    cout<<"Sorted Array For Insertion Sort: " <<endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout<< endl;
    selectionSort(arr, size);
    cout << "Sorted Array For Selection Sort: " <<endl;
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;

    return 0;
}
