#include <iostream>
using namespace std ;

template <class T>
class Vector
{
	private : 
		int n;              			//size of the vector array 
		int capacity;       			// capacity of the array
		T *arr;             			// the generic 1-d pointer 
			
	public :
		Vector(); 						// contructor 
		int size() const;				//just returns the size of the array
		T& at(int i);					//returns the element at i 
		T& operator[](int i) const;		//operator overloaded 
		bool empty ( ) const;          	// checks if the array is empty
		void erase(int j);				// removes an element 
		void reserve(int N);			//checks the capacity and if less then increases it by x2	
		void insert(int i, T& val);		//checks the capacity and if more then insert the value to the array
		void display();					// funtion to display the array	
};

template<class T>
Vector<T>::Vector() 
{                   		
	n=0;
	capacity =0;
	arr= NULL;
}	

template <class T>
int Vector<T>:: size() const			
{                   
	return n;
}

template <class T>
T& Vector<T> :: at(int i)			 
{               	
    if(i<0 || i>n)	 		
	 	cout<<"array index out of bound \n";
    return arr[i];
}

template<class T>
T& Vector <T>::operator[](int i) const		
{                   
	return arr[i];
}

template<class T>
bool Vector<T>:: empty ( ) const          	
{                   
    return size()==0;
}

template <class T>
void Vector<T>::erase(int j)				 
{		            
	for(int i=j; i<n ;i++)
		arr[i] = arr[i+1]; 
   	n--;	
} 

template<class T>
void Vector<T>::reserve(int N)	
{                  
	if(capacity>=N)
		return;
	T* Barry = new T[N];
	for(int i=0 ; i<n ; i++)
		Barry[i] = arr[i];
	if(arr != NULL)
		delete [] arr;
	arr = Barry;
	capacity = N;		  	 
}

template<class T>
void Vector<T>::insert(int i, T& val)		
{                    
	if(n>= capacity)
		reserve(max(1,2*capacity));
	for(int j=n-1; j>=i ; j--)
		arr[j+1] = arr[j];
	arr[i] = val;
	n++;
}

template<class T>
void Vector<T>::display()					
{                 
	for(int i=0 ; i< n; i++)
		cout<< arr[i]<<" ";	  	
}	

int main ()
{
	Vector<int> v1;
	int k,i,ch ;            			// all the variables needed 
	int val;                			// elements in array
	cout<<"enter the total number of elements you want to insert "<<endl;
	cin>> k;
	char repeat; 
	for(int i=0 ; i<k ; i ++)			// to take input
	{
		cout<<"enter the value at "<<i<<endl;
		cin>>val;
		v1.insert(i,val);
	}
	cout<<"The entered array is \n";
	v1.display();						// to display the array 
	do	
	{
		cout<<endl<<"**MENU**"<<endl;
		cout<<"1.insert an element"<<endl;
		cout<<"2.Get an element"<<endl;
		cout<<"3. erase an element"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"Enter the index of the element"<<endl;
				cin>>i;
				cout<<"Enter the value"<<endl;
				cin>>val;
				v1.insert(i,val);
				cout<<" the updated array is \n";
				v1.display();
				break;
			}
			case 2:
			{
				cout<<"Enter the position of matrix you want to know the value of"<<endl;
				cin>>i;
				cout<<"The value is "<<v1.at(i);
				break;
			}
			case 3: 
			{ 
				cout<<"enter the index whose value u want to erase "<<endl;
				cin>>i;
				if(i>=0 && i<v1.size())
					v1.erase(i);
				cout<<"\n The updated arrqy is \n";
				v1.display();
				break;
			}
			default:
			{
				cout<<"\n Wrong choice"<<endl;
				break;
			}
		}
		cout<<endl<<"Do you want to continue(Y/N)?"<<endl;
		cin>>repeat;
	}
	while(repeat=='y'||repeat=='Y');
	return 0;
}
