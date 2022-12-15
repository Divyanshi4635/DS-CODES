#include<iostream>
using namespace std;

template <class T>
class ArrayQueue
{
	int size;
	T* a;
	int pointer;
	public:
		void add();
		void delete();
		void display();
}
