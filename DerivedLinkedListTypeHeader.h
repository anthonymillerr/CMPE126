#ifndef DERIVEDLINKEDLIST_H
#define DERIVEDLINKEDLIST_H

#include "BaseLinkedListType.h"

#include <iostream>
using namespace std;

template <class Type>
class DerivedLinkedListType : public BaseLinkedListType<Type>
{
public:
    
    void deleteAll(const Type& data)
    {
        Node<Type>* curr = this->head;
        Node<Type>* prev = nullptr;

        while (curr != nullptr)
        {
            if (curr->data == data)
            {
                if (prev == nullptr)
                {
                    this->head = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                }

                Node<Type>* temp = curr;
                curr = curr->next;
                delete temp;
                this->count--;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    void deleteSmallest()
    {
        if (this->head == nullptr)
        {
            cout << "Error: List is empty\n";
            return;
        }
    Node<Type>* currNode = this->head;
    Node<Type>* smallestNode = currNode;
    Node<Type>* prevNode = nullptr;
    Node<Type>* prevSmallestNode = nullptr;

    while (currNode != nullptr) {
        if (currNode->data < smallestNode->data) {
            smallestNode = currNode;
            prevSmallestNode = prevNode;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    // Remove the smallest node from the list
    if (smallestNode == this->head) {
        this->head = smallestNode->next;
    } else {
        prevSmallestNode->next = smallestNode->next;
    }

    delete smallestNode;
    this->count--;
}
}; 
#endif
