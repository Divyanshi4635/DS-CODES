#include<iostream>
using namespace std;

template <class T>
class uppertriangle
{
	public:
		uppertriangle(int N);
		T get(int ,int ,bool)const;
		void set(int ,int , T& ,bool);
	private:
		int n;
		T  *arr;
		bool flag;
};

template <class T>
uppertriangle<T>::uppertriangle(int N)
{
	if(N<1)
		cout<<"Matrix size should be greater than 0";
	n=N*(N+1)/2;
	arr=new int[n];
}

template <class T>
T uppertriangle<T>::get(int i,int j,bool flag)const
{
	if(i<0||j<0||i>n||j>n)
		cout<<"Array Index out of bounds";
	
	else if(flag==1)
	{
		if(i<=j)
			cout<< arr[j*(j+1)/2 +i]<<endl;
		else
			cout<<"0"<<endl;
	}
	
	else if(flag==0)
	{
		if(i<=j)
			cout<< arr[n*(n+1)/2 - (n-i+1)*(n-i+2)/2 +j-i]<<endl;
		else
			cout<<"0"<<endl;
	}
}

template <class T>
void uppertriangle<T>::set(int i,int j, T& val,bool flag)
{
	if(i<0||j<0||i>n||j>n)
		throw "Array Index out of bounds";
	else if(flag==1)
	{
		if(i<=j)
			arr[j*(j+1)/2 +i]=val;
		else
			if(val!=0)
			{
				cout<<"Value should be zero"<<endl;
				cout<<"enter the value at index "<<i<<j<<endl;
				cin>>val;
			}
	}
	else if(flag==0)
	{
		if(i<=j)
			arr[n*(n+1)/2 - (n-i+1)*(n-i+2)/2 +j-i]=val;
		else
			if(val!=0)
			{
				cout<<"Value should be zero"<<endl;
				cout<<"enter the value at index "<<i<<j<<endl;
				cin>>val;
			}
	}
}


int main()
{
	int n,val,i,j;
	bool flag;
	cout<<"Enter the order of matrix"<<endl;
	cin>>n;
	cout<<"Enter 0 for row major and 1 for column major : ";
	cin >> flag;
	uppertriangle<int> d (n);
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
			d.set(i,j,arr[i][j],flag);
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
				d.set(i,j,val,flag);
				break;
			}
			case 2:
			{
				cout<<"Enter the position of matrix you want to know the value of"<<endl;
				cin>>i>>j;
				cout<<"The value is ";
				d.get(i,j,flag);
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
