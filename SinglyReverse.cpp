#include <iostream>
using namespace std;

template <typename T>
class LinkedList;

template <typename T>
class Node
{
	T elem;        
    Node<T> *next; 
	friend class LinkedList<T>;
	public:
    	Node(T a, Node *p)
    	{
        	elem = a;
        	next = p;
    	}
};

template <typename T>
class LinkedList
{
    Node<T> *head;
    Node<T> *tail;
	public:
    	LinkedList();  
    	void add_to_head(T elem); 
    	void display(); 
		void add_to_tail(T elem);
    	void insert_at_position(int pos, T elem);
		Node<T>* reverse();
};

template <typename T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    tail = NULL;
}

template <typename T>
void LinkedList<T>::add_to_head(T elem)
{
    if (head == NULL)
    {
        head = tail = new Node<T>(elem, NULL);
        return;
    }
    head = new Node<T>(elem, head);
}
template <typename T>
void LinkedList<T>::add_to_tail(T elem)
{
    if (tail == NULL)
    {
        head = tail = new Node<T>(elem, NULL);
        return;
    }
    tail->next = new Node<T>(elem, NULL);
    tail = tail->next;
}
template <typename T>
void LinkedList<T>::insert_at_position(int pos, T elem)
{
    if(pos == 1)
    {
    	add_to_head(elem);
    	return;
	}
	Node<T>* tmp = head;
	int counter = 1;
	while(counter < pos-1 && tmp != NULL)
	{
		tmp = tmp->next;
		counter++;
	}
	if(tmp == NULL)
	{
		cout<<"Error!!"<<endl;
		return;
	}
	tmp->next = new Node<T>(elem, tmp->next);
}

template <typename T>
Node<T>* LinkedList<T>::reverse()
{
    Node<T>* tmp = NULL;
    Node<T>* tmp1 = NULL; 
    while (head != NULL)
    {
        tmp1 = head->next;
        head->next = tmp;
        tmp = head;
        head = tmp1;
    }
    head = tmp;
    return head;
}
template <typename T>
void LinkedList<T>::display()
{
	if (head == NULL)
    {
        tail = NULL;
        cout << "Error: List is empty!!!" << endl;
        return;
    }
    Node<T> *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->elem << "\t";
        tmp = tmp->next;
    }
}
int main()
{
    LinkedList<int> a;
    int choice;
    int val;
    char opt;
    do
    {
        cout << endl;
        cout << "\tMENU" << endl;
        cout << "1.Add in the beginning(head)" << endl;
        cout << "2.Add in the last(tail)" << endl;
        cout << "3.Add at position" << endl;
        cout << "4.Reverse of list "<<endl;
        cout << "5.Display the list" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        	{
            	cout << "Enter the value : " ;
            	cin >> val;  
            	a.add_to_head(val);
            	break;
        	}
        case 2:
        	{
            	cout << "Enter the value : ";
            	cin >> val;
            	a.add_to_tail(val);
            	break;
        	}
        case 3:
        	{
        		int pos; 
        		cout<<"Enter the position : ";
        		cin>>pos;
				cout << "Enter the value :" ;
            	cin >> val;
            	a.insert_at_position(pos, val);
            	break;
        	}
        case 4:
        	{
            	cout<<"Reverse list : ";
            	a.reverse();
            	a.display();
            	break;
        	}
        case 5:
        	{
            	cout << "The required list : " ;
            	a.display();
            	break;
        	}
        default:
        	{
            	cout << "Wrong choice" << endl;
            	break;
        	}
        }
        cout << endl << "Do you want to continue(Y/N) ? " ;
        cin >> opt;
    } while (opt == 'y' || opt == 'Y');
    return 0;
}
