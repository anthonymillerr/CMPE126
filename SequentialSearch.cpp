#include <iostream>
using namespace std;

int sequentialSearchRecursive(int arr[], int left, int right, int x) {
    if (left > right) {
        return -1;
    }
    if (arr[left] == x) {
        return left;
    }

    return sequentialSearchRecursive(arr, left + 1, right, x);
}

int main() {
    int arr[] = {10, 5, 20, 15, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 15;

    int result = sequentialSearchRecursive(arr, 0, n - 1, x);

    cout<<endl;

    if (result == -1) {
        cout << "Element Not Found." << endl;
    }
    else {
        cout << "Element Found At Index " << result << endl;
    }

    return 0;
}
