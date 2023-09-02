
#ifndef ARRAYLISTTYPE_H_
#define ARRAYLISTTYPE_H_

#include <iostream>
#include <iomanip>
using namespace std;

template <class Type>
class arrayListType
{
protected:
    Type *list;
    int length;
    int maxSize;

public:
    const arrayListType<Type>& operator=
    (const arrayListType<Type>&);
    bool isEmpty() const      { return (length == 0); }
    bool isFull() const       { return (length == maxSize); }
    int listSize() const      { return length; }
    int maxListSize() const   { return maxSize; }
    void print();
    bool isItemAtEqual(int location, const Type& item) const
    { return(list[location] == item); }
    void insertAt(int location, const Type& insertItem);
    void insertEnd(const Type& insertItem);

    void retrieveAt(int location, Type& retItem) const;
    void replaceAt(int location, const Type& repItem);
    void clearList()          { length = 0; }
    void removeAt(int location);

    int sequentialSearch(const Type& item) const;

    arrayListType(int = 100);
    arrayListType(const arrayListType<Type>& otherList);
    ~arrayListType()          { delete [] list; }
};

template <class Type>
void arrayListType<Type>::print()
{

    for (int i = 0; i < length; i++)
    {
        cout << list[i] << endl;
    }
    cout << endl;
}

template <class Type>
void arrayListType<Type>::insertAt
(int location, const Type& insertItem)
{
    if (location < 0 || location >= maxSize)
        cerr << "The position of the item to be inserted "
        << "is out of range" << endl;
    else
        if (length >= maxSize)
            cerr << "Cannot insert in a full list" << endl;
        else
        {
            for (int i = length; i > location; i--)
                list[i] = list[i - 1];
            list[location] = insertItem;
            length++;
        }
}
template <class Type>
void arrayListType<Type>::insertEnd(const Type& insertItem)
{

    if (length >= maxSize)
        cerr << "Cannot insert in a full list" << endl;
    else
    {
        list[length] = insertItem;
        length++;
    }
}
template <class Type>
void arrayListType<Type>::removeAt(int location)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be removed "
        << "is out of range" << endl;
    else
    {
        for (int i = location; i < length - 1; i++)
            list[i] = list[i+1];
        length--;
    }
}
template <class Type>
void arrayListType<Type>::retrieveAt
(int location, Type& retItem) const
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be retrieved is "
        << "out of range." << endl;
    else
        retItem = list[location];
}
template <class Type>
void arrayListType<Type>::replaceAt
(int location, const Type& repItem)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be replaced is "
        << "out of range." << endl;
    else
        list[location] = repItem;

}
template <class Type>
arrayListType<Type>::arrayListType(int size)
{
    if (size < 0)
    {
        cerr << "The array size must be positive. Creating "
        << "an array of size 100. " << endl;
        maxSize = 100;
    }
    else
        maxSize = size;
    length = 0;
    list = new Type[maxSize];
}
template <class Type>
arrayListType<Type>::arrayListType
(const arrayListType<Type>& otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new Type[maxSize];
    for (int j = 0; j < length; j++)
        list [j] = otherList.list[j];
}
template <class Type>
const arrayListType<Type>& arrayListType<Type>::operator=
(const arrayListType<Type>& otherList)
{
    if (this != &otherList)
    {
        delete [] list;
        maxSize = otherList.maxSize;
        length = otherList.length;
        list = new Type[maxSize];
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }
    return *this;
}

template <class Type>
int arrayListType<Type>::sequentialSearch(const Type& item) const
{
	int location;
	bool found = false;
	for(location=0;location < maxSize; location++)
		if (list[location] == item)
		{
			found = true;
			break;
		}
	if(found){
		cout<<"Item In Location: " <<location<<endl;
		return location;
	}
	else
		cout<<"Failure: Item Not Found" <<endl;
		return -1;
}
#endif /* ARRAYLISTTYPE_H_ */
