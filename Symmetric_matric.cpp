#include<iostream>
using namespace std;

template<class T>
class symmetric
{
	public:
		symmetric(int N=10);
		T get(int ,int )const;
		void set(int ,int , T&);
	private:
		int n;
		T  *arr;
};

template<class T>
symmetric<T>::symmetric(int N)
{
	if(N<1)
		cout<<"Matrix size must be greater than zero";
	n=N;
	arr=new T [n];
}

template<class T>
T symmetric<T>::get(int i,int j)const
{
	if(i<0||j<0||i>n||j>n)
		cout<<"Matrix Index out of bounds";

	if(i<=j)
		return arr[j*(j-1)/2+i-1];
	
	else if(i>j)
		return arr[i*(i-1/2+j-1)];
}

template<class T>
void symmetric<T>::set(int i,int j, T& val)
{
	if(i<0||j<0||i>n||j>n)
		cout<<"Matrix Index out of bounds";

	if(i<=j)
		arr[j*(j-1)/2+i-1]=val;

	else if(i>j)
		int x=get(j,i);
}

int main()
{
	int n;int val;
	cout<<"Enter the order of matrix"<<endl;
	cin>>n;int i,j;
	symmetric<int> d (n);
	int **arr;
	arr=new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"element at position"<<i<<j<<endl; 
			cin>>arr[i][j];
			d.set(i,j,arr[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	int choice;
	char opt;
	do
	{
		cout<<"***MENU***"<<endl;
		cout<<"1.Update a element"<<endl;
		cout<<"2.Get an element"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				cout<<"Enter the index of the element"<<endl;
				cin>>i>>j;
				cout<<"Enter the value"<<endl;
				cin>>val;
				d.set(i,j,val);
				break;
			}
			case 2:
			{
				cout<<"Enter the position of matrix you want to know the value of"<<endl;
				cin>>i>>j;
				cout<<"The value is : "<<d.get(i,j);
				cout<<endl;
				break;
			}
			default:
			{
				cout<<"Wrong choice"<<endl;
				break;
			}
		}
		cout<<"Do you want to continue(Y/N)?"<<endl;
		cin>>opt;
	}
	while(opt=='y'||opt=='Y');
	return 0;
}
