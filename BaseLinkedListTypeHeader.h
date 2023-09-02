#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream> // For cout
using namespace std;

template <class Type>
class Node
{
public:
    Type data;
    Node<Type>* next;
};

// Base class
template <class Type>
class BaseLinkedListType
{
protected:
    Node<Type>* head;
    Node<Type>* tail;
    int count;

public:
    BaseLinkedListType() : head(nullptr), count(0) {}
    virtual ~BaseLinkedListType() {}

    virtual void deleteAll(const Type& data) = 0;

    void deleteFirstOccurrence(const Type& data)
    {
        Node<Type>* curr = head;
        Node<Type>* prev = nullptr;

        while (curr != nullptr && curr->data != data)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr != nullptr)
        {
            if (prev == nullptr)
            {
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            if (curr == tail)
            {
              tail = prev;
            }

            delete curr;
            count--;
        }
    }

    Type getKthElement(int k)
    {
        if (k <= 0 || k > count)
        {
            cout << "Error: Invalid index\n";
            exit(EXIT_FAILURE);
        }

        Node<Type>* curr = head;
        int index = 1;

        while (curr != nullptr && index < k)
        {
            curr = curr->next;
            index++;
        }

        if (curr == nullptr)
        {
            cout << "Error: Invalid index\n";
            exit(EXIT_FAILURE);
        }

        return curr->data;
    }

    void deleteKthElement(int k)
    {
        if (k <= 0 || k > count)
        {
            cout << "Error: Invalid index\n";
            return;
        }

        Node<Type>* curr = head;
        Node<Type>* prev = nullptr;
        int index = 1;

        while (curr != nullptr && index < k)
        {
            prev = curr;
            curr = curr->next;
            index++;
        }

        if (curr == nullptr)
        {
            cout << "Error: Invalid index\n";
            return;
        }

        if (prev == nullptr)
        {
            head = curr->next;
        }
        else
        {
            prev->next = curr->next;
        }
        if(curr == tail)
        {
          tail = prev;
        }

        delete curr;
        count--;
    }

    void display()
    {
        Node<Type>* curr = head;

        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    void insertLast(const Type& data)
  {
    Node<Type>* newNode = new Node<Type>();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
    } else
    {
      tail -> next = newNode;
      tail = newNode;
    }
    count++;
}
};

#endif
