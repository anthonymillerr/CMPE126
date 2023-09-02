#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 17;

class Node {
public:
    int key;
    Node* next;
    Node(int k) : key(k), next(nullptr) {
    }
};

int hashFunction(int key) {
    return key % SIZE;
}

void insertSepChain(vector<Node*>&H, int key) {
    int index = hashFunction(key);
    Node* node = new Node(key);
    if (H[index] == nullptr) {
        H[index] = node;
    } else {
        Node* curr = H[index];
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

void print(vector<Node*>&H) {
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        Node* curr = H[i];
        while (curr != nullptr) {
            cout << curr->key << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}

int main() {
    vector<Node*> A(SIZE, nullptr);
    insertSepChain(A, 9);
    insertSepChain(A, 34);
    insertSepChain(A, 49);
    insertSepChain(A, 16);
    insertSepChain(A, 32);
    insertSepChain(A, 51);

    print(A);

    return 0;
}
