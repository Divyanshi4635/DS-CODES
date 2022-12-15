#include<iostream>
using namespace std;

template <class T>
class tridiagonal
{
	public:
		tridiagonal(int N)
		{
			if(N<1)
				cout<<"Matrix size should be greater than 0 :"<<endl;
			n=N;
			arr=new T [3*n-2];
		}
		T get(int ,int )const;
		void set(int,int,T& );
	private:
		int n;
		T *arr;;
};

template <class T>
T tridiagonal<T>:: get(int i,int j)const
{
	if(i<0||j<0||i>n-1||j>n-1)
		cout<<"Array index out of bound :"<<endl;
	else
	{
		switch(i-j)
		{
			case 1:
			{
				cout<<arr[i-1];
				break;
			}
			case 0:
			{
				cout<<arr[n+i-1];
				break;
			}
			case -1:
			{
				cout<<arr[2*n+i-1];
				break;
			}
			default:
			{
				cout<<"0";
				break;
			}
		}
	}
}

template <class T>
void tridiagonal<T>::set(int i,int j, T& val)
{
	if(i<0||j<0||i>n-1||j>n-1)
		cout<<"Array index Out of Bound :"<<endl;
	else 
	{
		switch(i-j)
		{
			case 1:
				arr[i-1]=val;
				break;
			
			case 0:
				arr[n+i-1]=val;
				break;
			
			case -1:
				arr[2*n+i-1]=val;
				break;
			
			default:
				{
					if(val!=0)
					{
						cout<<"Value should be zero enter again"<<endl;
						cin>>val;
					}
					arr[i]=val;
				}
				break;
		}
	}
}

int main()
{
	int n, val, i, j;
	cout<<"Enter the order of matrix "<<endl;
	cin>>n;
	tridiagonal<int> d (n);
	int **arr;
	arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"Enter the element at position "<<i<<j<<endl; 
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
		cout<<"\tMENU"<<endl;
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
					cout<<"The value is : ";
					d.get(i,j);
					cout<<endl;
					break;
				}
				
			default:
				cout<<"Wrong choice"<<endl;
				break;
		}
		cout<<"Do you want to continue ? ";
		cin>>opt;
	}
	while(opt=='y'||opt=='Y');
	return 0;
}
