#include "matrix.h"
#include <iostream>
using namespace std;

template<class T>
matrix<T>::matrix(int theRows,int theColumns)
{
	if(theRows<0||theColumns<0)
		cout<<"Rows and Columns must be >=0"<<endl;
	if((theRows==0||theColumns==0)&&(theRows!=0||theColumns!=0))
		cout<<"Either both or neither rows and columns should be zero"<<endl;
	this->theRows=theRows;
	this->theColumns=theColumns;
	element=new T[theRows*theColumns];
}
template<class T>
matrix<T>::matrix(const matrix<T>& m)
{
	theRows=m.theRows;
	theColumns=m.theColumns;
	element=new T[theRows*theColumns];
	copy(m.element,m.element+theRows*theColumns,element);
}
template<class T>
matrix<T>& matrix<T>::operator=(const matrix<T>& m)
{
	if(this!=&m)
	{
		delete [] element;
		theColumns=m.theColumns;
		theRows=m.theRows;
		element=new T[theRows*theColumns];
		copy(m.element,m.element+theRows*theColumns,element);
	}
	return *this;
}
template<class T>
T& matrix<T>::operator()(int i,int j)const
{
	if(i<1||i>theRows||j<1||j>theColumns)
		cout<<"Out of bounds";
	return element[(i-1)*theColumns+j-1];
}
int main()
{
	int theRows,theColumns;
	cout<<"Enter the rows and columns";
	cin>>theRows>>theColumns;
	int *element=new int[theRows*theColumns];
	cout<<"Enter the matrix"<<endl;
	for (int i = 0; i < theColumns*theRows; ++i)
	{
	cin>>element[i];	
	}
	matrix<int> m (theRows,theColumns);
	m.operator()(0,3);

}