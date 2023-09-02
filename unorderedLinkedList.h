#ifndef unorderedLinkedList_h
#define unorderedLinkedList_h

#include "LinkedList.h"

using namespace std;
template <class Type>
class unorderedLinkedList: public linkedListType<Type>{
    public:
    bool search(const Type& searchItem) const;
    void insertFirst(const Type& newItem);
    void insertLast(const Type& newItem);
    void deleteNode(const Type& deleteItem);
    void deleteAll(const Type& deleteItem);
    void deleteSmallest();
};
template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const{
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;
    current = this->first;
    while (current != NULL && !found){ //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link;
    return found;
    }//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem){
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = this->first;
    this->first = newNode;
    this->count++; //increment count
    if (this->last == NULL) //if the list was empty, newNode is also
//the last node in the list
this->last = newNode;
}//end insertFirst
template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
nodeType<Type> *newNode; //pointer to create the new node
newNode = new nodeType<Type>; //create the new node
newNode->info = newItem; //store the new item in the node
newNode->link = NULL; //set the link field of newNode
//to NULL
if (this->first == NULL) //if the list is empty, newNode is
//both the first and last node
{
this->first = newNode;
this->last = newNode;
this->count++; //increment count
}
else //the list is not empty, insert newNode after last
{
this->last->link = newNode; //insert newNode after last
this->last = newNode;
this->count++; //increment count
}
}//end insertLast
template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem){
while (current != NULL && !found){ //search the list
if (current->info == search) //searchItem is found
found = true;
else
current = current->link;
return 0;
}
};//end search
template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem){
nodeType<Type> *newNode; //pointer to create the new node
newNode = new nodeType<Type>; //create the new node
newNode->info = newItem; //store the new item in the node
newNode->link = this->first; //insert newNode before first
this->first = newNode; //make first point to the
this->count++; //increment count
if (this->last == NULL) //if the list was empty, newNode is also
this->last = newNode;
};//end insertFirst
template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem){
nodeType<Type> *newNode; //pointer to create the new node
newNode = new nodeType<Type>; //create the new node
newNode->info = newItem; //store the new item in the node
newNode->link = NULL; //set the link field of newNode
//to NULL
if (this->first == NULL) //if the list is empty, newNode is
//both the first and last node
{
this->first = newNode;
this->last = newNode;
this->count++; //increment count
}
else
{
this->last->link = newNode; //insert newNode after last
this->last = newNode; //make last point to the actual
//last node in the list
this->count++; //increment count
}
};//end insertLast
template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
nodeType<Type> *current;
nodeType<Type> *trailCurrent;
bool found;
if (this->first == NULL)
cout << "Cannot delete from an empty list."
<< endl;
else
{
if (this->first->info == deleteItem)
{
current = this->first;
this->first = this->first->link;
this->count--;
if (this->first == NULL)
this->last = NULL;
delete current;
}
else
{
found = false;
trailCurrent = this->first; //set trailCurrent to point
current = this->first->link; //set current to point to
while (current != NULL && !found)
{
if (current->info != deleteItem)
{
trailCurrent = current;
current = current-> link;
}
else
found = true;
}//end while
if (found) //Case 3; if found, delete the node
{
trailCurrent->link = current->link;
this->count--;
if (this->last == current)
this->last = trailCurrent;
delete current; //delete the node from the list
}
else
cout << "The item to be deleted is not in "
<< "the list." << endl;
}//end else
}//end else
}//end deleteNode
template <class Type>
void unorderedLinkedList<Type>::deleteAll(const Type& deleteItem){
// TBA
}; //end deleteAll
template <class Type>
void unorderedLinkedList<Type>::deleteSmallest(){
// TBA
}
#endif