#include<iostream>
using namespace std;

template <class T>
class ArrayStack 
{
	public:
		ArrayStack(int cap)						// constructor 
		{
			size = cap;
			a = new T[cap];
			pointer = 0;
		}
		void display();							// display the stack 					
		void push(const T& e); 				 	// push element onto the stack
		void pop(); 							// pop the top element out of the stack
	private: 
		T* a; 									// array of stack elements
		int size; 								// stack capacity
		int pointer; 							// returns the index of the top of the stack
};

template<class T>
void ArrayStack<T>::display()
{
	int counter=0;
	while(counter!=pointer)
		cout<<a[counter++]<<" ";
	cout<<endl;
}

template<class T>
void ArrayStack<T>::push(const T& e) 
{
	if (pointer >= size) 
		cout<<"STACK IS FULL !"<<endl;
	else
		a[pointer++] = e;
}

template<class T>
void ArrayStack<T>::pop() 
{
	if (pointer==0) 
		cout<<"STACK IS EMPTY !"<<endl;
	else
	{
		a[pointer]=0;
		pointer--;
		cout<<"TOP IS DELETED !"<<endl;	
	}
}

int main()
	{
		int cap,choice,e;
		cout<<"Enter the capacity of stack"<<endl;
		cin>>cap;
		ArrayStack<int> st(cap);
		char opt;
		do{
			cout<<"\tMENU"<<endl;
			cout<<"1.PUSH"<<endl;
			cout<<"2.POP"<<endl;
			cout<<"3.GET THE STACK"<<endl;
			cout<<"Enter your choice"<<endl;
			cin>>choice;

			switch(choice)
			{
				case 1:
				{
					cout<<"Enter the value"<<endl;
					cin>>e;
					st.push(e);
					break;
				}
				case 2:
				{
					st.pop();
					break;
				}
				case 3:
				{
					cout<<"The Stack is : "<<endl;
					st.display();
					break;
				}
				default:
				{
					cout<<"Wrong choice"<<endl;
					break;
				}
			}
			cout<<"Do you want to continue (Y/N)?"<<endl;
			cin>>opt;
		}while(opt=='y'||opt=='Y');
	return 0;
}
