#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr){
        }
    };
    Node* frontPtr;
    Node* rearPtr;
public:
    Queue() : frontPtr(nullptr), rearPtr(nullptr){
    }

    void Insert(T value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            frontPtr = rearPtr = newNode; // make the new Node both the front and rear Node
        }
        else { 
            rearPtr->next = newNode; // add the new Node to the rear of the queue
            rearPtr = newNode; // update rearPtr to point to the new Node
        }
    }

    void Delete() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
        }
        else {
             Node* temp = frontPtr; // temporary pointer to the first Node of the queue
            frontPtr = frontPtr->next; // update frontPtr to point to the second Node of the queue
            delete temp; // delete the first 
            if (frontPtr == nullptr) { 
                rearPtr = nullptr; // update rearPtr to nullptr
            }
        }
    }

    void Show() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
        }
        else {
             Node* temp = frontPtr; // temporary pointer to the front Node of the queue
            while (temp != nullptr) { // loop through all the Nodes in the queue
                cout << temp->data << " "; // print the data of the current Node
                temp = temp->next; // move to the next Node
            }
            cout << std::endl;
        }
    }

    bool isEmpty() {
        return (frontPtr == nullptr);
    }
};

int main() {
    Queue<int> myQueue;
    myQueue.Insert(1);
    myQueue.Insert(2);
    myQueue.Insert(3);
    myQueue.Insert(4);
    myQueue.Insert(5);
    myQueue.Show();  
    myQueue.Delete();
    myQueue.Show();  
    myQueue.Delete();
    myQueue.Show();  
    myQueue.Delete();
    myQueue.Show();  
    
    return 0;
}
