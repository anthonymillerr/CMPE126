#include <iostream>
using namespace std;

const int SIZE = 17;

int hashFunction(int key) {
    return key % SIZE;
}

int probe(int H[], int key) {
    int index = hashFunction(key);
    int i = 0;
    while (H[(index + i) % SIZE] != 0) {
        i++;
    }
    return (index + i) % SIZE;
}

void insertLinear(int H[], int key) {
    int index = hashFunction(key);
    if (H[index] != 0) {
        index = probe(H, key);
    }
    H[index] = key;
}

int main() {
    cout<< "'0' = Empty Slot For Index" << endl;
    int A[SIZE] = {0};
    insertLinear(A, 9);
    insertLinear(A, 34);
    insertLinear(A, 49);
    insertLinear(A, 16);
    insertLinear(A, 32);
    insertLinear(A, 51);

    for (int i = 0; i < SIZE; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
