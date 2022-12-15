#include<iostream>
using namespace std;

template<class T>
class sparselinked;

template<class T>
class node
{
	int i;
	int j;
	T value;

	node<T>* next;
	friend class sparselinked<T>;
	node(const T& val, int i,int j)
	{
		this->i=i;
		this->j=j;
		value=val;
	}
};

template<class T>
class sparselinked
{
private:
	node<T>* head;
public:
	sparselinked();
	bool empty() const;	
	void store(const T&,int , int);
	const T get(int ,int);
};

template<class T>
sparselinked<T>::sparselinked()
{
	head=NULL;	
}
template<class T>
bool sparselinked<T>::empty() const
{
	return head==NULL;
}

template<class T>
void sparselinked<T>::store(const T& val,int i,int j)
{
	node<T>* n=new node<T>(val,i,j);
	n->value=val;
	n->i=i;
	n->j=j;
	n->next=head;
	head=n;
}

template<class T>
const T
 sparselinked<T>::get(int i,int j)
{
	node<T>* n=head;
	while(n!=NULL)
	{
		if(n->i==i&&n->j==j)
			return n->value;
		n=n->next;
	}
	return 0;
}

int main()
{
	sparselinked<int> s;
	int val,i,j;
	int ch,n;
	cout<<"Enter the order of matrix"<<endl;
	cin>>n;

	int **a;
	a=new int*[n];
	for(int k=0;k<n;k++)
		a[k]=new int[n];

	cout<<"Enter the number of non-zero enteries"<<endl;
	cin>>ch;

	for(int k=0;k<ch;k++){
		cout<<"Enter the non zero value"<<endl;
		cin>>val;	
		cout<<"Enter the indexes"<<endl;
		cin>>i>>j;
		s.store(val,i,j);
	}

	cout<<"The matrix is :"<<endl;
	for(i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				cout<<s.get(i,j)<<" ";
			}
			cout<<endl;
		}

	return 0;
}
