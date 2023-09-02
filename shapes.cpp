//============================================================================
// Name        : CMPE126-LAB-3-2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Part-Two
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

#define PI 3.14159

class Shape
{
public:
	virtual void area() = 0;
	virtual void getParameters()=0;
};

class Circle:public Shape
{
protected:
	int radius;
public:
	void getParameters(){
		cout<<"Enter The Radius Of The Circle: ";
		cin>>radius;
	}
	void area(){
		cout<<"The Area Of The Circle Is:" << PI*radius*radius<< "\n";
	}
};

class Rectangle:public Shape
{
protected:
	int length;
	int width;
public:
	void getParameters()
	{
		cout<<"Enter The Length For Rectangle: "<<endl;
		cin>>length;
		cout<<"Enter The Width For Rectangle: "<<endl;
		cin>>width;
	}
	void area(){
		cout<<"The Area Of The Rectangle Is: " << length*width <<"\n";
	}
};

class Triangle:public Shape
{
protected:
	int base;
	int height;
public:
	void getParameters()
	{
		cout<<"Enter The Base Length Of The Triangle: " <<endl;
		cin>>base;
		cout<<"Enter The Height Of Triangle: "<<endl;
		cin>>height;
	}
	void area()
	{
		cout<<"The Area Of This Triangle Is: " << 0.5*base*height<<"\n";
	}
};

int main() {
	int n;
	cout<<"Enter Size Of Vector Of Shape Pointers: "<<endl;
	cin>> n;

	vector<Shape*> shapes(n);

	cout<<"Choose Type For Each Shape\n";
	cout<<"1.Circle\n2.Rectangle\n3.Triangle\n\n";

	for(int i = 0; i<n; i++){
		int choice;
		cout<<"Enter Choice For Shape: " << i+1<< ": ";
		cin>>choice;
		while(choice <1 || choice >3)
		{
			cout<<"Choose Choices 1-3! ";
			cin>>choice;
		}
		if(choice==1) shapes[i] = new Circle;
		else if (choice==2) shapes[i] = new Rectangle;
		else if (choice==3) shapes[i] = new Triangle;

		shapes[i]->getParameters();
		shapes[i]->area();
		cout<<"\n";
	}
	return 0;
}
