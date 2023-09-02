#include <iostream>
using namespace std;

int findPeak(int a[], int length) {
    int low = 0;
    int high = length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if ((mid == 0 || a[mid] >= a[mid-1]) &&
            (mid == length-1 || a[mid] >= a[mid+1])) {
            return mid;
        }
        else if (mid > 0 && a[mid-1] > a[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int a[] = {0, 100, 200, 300, 250, 150, 50};
    int length = sizeof(a) / sizeof(a[0]);
    int peakPos = findPeak(a, length);
    if (peakPos == -1) {
        cout << "Peak Not Found" << endl;
    }
    else {
        cout << "Peak Found At Position " << peakPos << endl;
    }
    return 0;
}
