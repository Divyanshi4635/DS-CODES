#include<iostream>
using namespace std;

template <class T>
class lowercolumn
{
	public:
		lowercolumn(int N=10);  // constructor
		/*{
			if(N<1)
				cout << "MATRIX SIZE SHOULD BE GREATER THAN ZERO" << endl;
			n=N*(N+1)/2;
			arr=new int[n];	
		}*/

		T get(int ,int )const;
		void set(int ,int , T&);
	private:
		int n;
		T  *arr;
};

template <class T>
lowercolumn<T>::lowercolumn(int N)
{
	if(N<1)
		throw ("Matrix size should be greater than 0");
	n=N*(N+1)/2;
	arr=new int[n];
}

template <class T>
T lowercolumn<T>::get(int i,int j)const   // get function 
{
	if(i<0||j<0||i>n||j>n)
		cout << "Array index out of bound" ;
	if(i>=j)
		return arr[n*(n+1)/2 - (n-j+1)*(n-j+2)/2+i-j];
	else
		return 0;
}

template <class T>
void lowercolumn<T>::set(int i,int j, T& val)   // set function
{
	if(i<0||j<0||i>n||j>n)
	cout << "Array index out of bound" << endl;
	if(i>=j)

		arr[n*(n+1)/2 - (n-j+1)*(n-j+2)/2+i-j]=val;
	else
		if(val!=0)
			cout << "Value should be zero" << endl;
}

int main()
{
	int n,val,i,j;
	cout<<"Enter the order of matrix "<<endl;
	cin>>n;
	lowercolumn<int> d (n);
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
			cout<<"Element at position "<<i<<j<<endl; 
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
	
// choices : 
	int choice;
	char opt;
	do
	{
		cout<<"\t MENU "<<endl;
		cout<<"1.For updating an element : "<<endl;
		cout<<"2.For getting the value of an index : "<<endl;
		cout<<"Enter your choice : "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				cout<<"Enter the index of the element : "<<endl;
				cin>>i>>j;
				cout<<"Enter the new value : "<<endl;
				cin>>val;
				d.set(i,j,val);
				break;
			}
			case 2:
			{
				cout<<"Enter the index whose value is to be fetched : "<<endl;
				cin>>i>>j;
				cout<<" Value is :  "<<d.get(i,j)<<endl;
				break;
			}
			default:
			{
				cout<<"\tWRONG CHOICE "<<endl;
				break;
			}
		}
		cout<<"Press y/Y to continue and n/N to terminate : "<<endl;
		cin>>opt;
	}
	while(opt=='y'||opt=='Y');
	return 0;
}
