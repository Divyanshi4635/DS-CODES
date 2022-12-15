#include<iostream>
using namespace std;

template<class T>
class list;

template<class T>
class node
{
	private:
		T elem;
		node<T>* next;
	public:
		friend class list<T>;
		node(T val, node<T> *N=0)
		{
			elem = val;
			next = N;
		}
};

template<class T>
class list
{
private:
	node<T> *head;
	node<T> *tail;
public:
	list()																			//empty list constructor
	{		
		head=NULL;
	}

	~list()																			//destructor
	{
		while(!empty())
			removehead();
	}

	bool empty()const;																//checking if the list is empty
	void addhead(const T&);															//add an element at head
	void addtail(const T&);															//add an element at tail
	void removehead();																//remove from head
	void removetail();																//remove from tail
	void display();																	//display the list
	void add_at_index(const T&,int i);												//add a new node to the given index
	void remove_from_index(int i);													//remove a node from the given index
};

template<class T>
bool list<T>::empty()const
{
	return head==NULL;
}

template<class T>
void list<T>::display()
{
	node<T> *h=head;
	if(h==NULL)
		cout<<"list is empty!"<<endl;
	while(h!=0)
	{
		cout<<h->elem<<" ";
		h=h->next;
	}
	cout<<endl;
}

template<class T>
void list<T>::addhead(const T& val)
{
	if(head == NULL)
	{
		cout << " list is already empty " << endl;
		head = tail =  new node<T>(val);
		cout << " head added" << endl;
	}
	else
	{
		node<T> *temp = new node<T>(val,head);
		head = temp;
		cout << "head added to the list" << endl;
	}
}

template<class T>
void list<T>::addtail(const T& val)
{
	if(tail == NULL)
	{
		cout << "list is empty" << endl;
		head = tail = new node<T>(val);
		cout << "new node added" << endl;
	}
	else
	{
		tail->next = new node<T>(val);
		tail = tail->next;
		cout << "new tail added to the list " << endl;
	}
}

template<class T>
void list<T>::removehead()
{
	if(head == NULL)
	{
		cout << "error..list is empty" << endl;
	}
	node<T>*temp = head;
	head = head->next;
	delete temp;
	if(head == NULL)
	{
		tail = NULL;
		cout << "tail is also set to be zero" << endl;
	}
}

template<class T>
void list<T>::removetail()
{
	if(tail == NULL)
	{
		cout << "error...list is already empty" << endl;
	}
	node<T>*temp = head;
	while(temp->next->next!= NULL)
	{
		temp = temp->next; 
	}
	node<T>*t = temp->next;
	temp->next = NULL;
	delete t;
	tail=temp;
	cout << "tail is deleted from the list" << endl;
}

template<class T>
void list<T>::add_at_index(const T& val, int i)
{
	if(i==1)
	{
		addhead(val);
		return;
	}
	node<T> *n=head;
	int counter=1;
	while(counter<i-1)
	{
		n=n->next;
		if(n==0)
		{
			cout<<"Invalid position"<<endl;
			return;
		}
		counter++;
	}
	node <T>* m=n->next;
	n->next=new node<T>(val);
	n->next->next=m;
}

template<class T>
void list<T>::remove_from_index(int i)
{
	if(i==1)
	{
		removehead();
		return;
	}
	node<T> *n=head;
	int counter=1;
	while(counter<i-1)
	{
		n=n->next;
		if(n==0)
		{
			cout<<"Invalid position"<<endl;
			return;
		}
		counter++;
	}
	node <T>*m=n->next->next;
	delete n->next;
	n->next=m;
}

int main()
{
	list<int> n;
	list<int> m;
	int val;
	int i;
	int choice;
	char opt;
	do
	{
		cout<<"Menu"<<endl;
		cout<<"1.Add at the head"<<endl;
		cout<<"2.Add at a position"<<endl;
		cout<<"3.Delete from the head"<<endl;
		cout<<"4.Delete from a position"<<endl;
		cout<<"5.Display the list"<<endl;
		cout<<"6.Add at the tail"<<endl;
		cout<<"7.Delete from the tail"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;

		switch(choice)
		{
			case 1:
			{
				cout<<"Enter the value "<<endl;
				cin>>val;
				n.addhead(val);
				break;
			}
			case 2:
			{
				cout<<"Enter the value "<<endl;
				cin>>val;
				cout<<"Enter the index "<<endl;
				cin>>i;
				n.add_at_index(val,i);
				break;
			}
			case 3:
			{
				n.removehead();
				cout<<"Deleted from the head"<<endl;
				break;
			}
			case 4:
			{
				cout<<"Enter the index"<<endl;
				cin>>i;
				n.remove_from_index(i);
				cout<<"Deleted from "<<i<<endl;
				break;
			}
			case 5:
			{
				cout<<"Displaying the list "<<endl;
				n.display();
				break;
			}
			case 6: 
			{
				cout << "enter the value to be inserted at tail";
				cin >> val;
				n.addtail(val);
				break;
			}
			case 7:
			{
				cout << "enter the value at the tail that is to be delete : ";
				cin >> val;
				n.removetail();
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
