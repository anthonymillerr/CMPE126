#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int left, int right, int x) {
   
    if (left > right) {
        return -1;
    }
    int mid = (left + right) / 2;

    if (arr[mid] == x) {
        return mid;
    }

    if (arr[mid] > x) {
        return binarySearchRecursive(arr, left, mid - 1, x);
    }
    return binarySearchRecursive(arr, mid + 1, right, x);
}

int main() {
    int arr[] = {10, 15, 20, 25, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 25;
    int result = binarySearchRecursive(arr, 0, n - 1, x);

    cout<<endl;

    if (result == -1) {
        cout << "Element Not Found." << endl;
    }
    else {
        cout << "Element Found At Index " << result << endl;
    }

    return 0;
}
