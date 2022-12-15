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
    	Node(T data, Node<T> *n)
    	{
        	elem = data;
        	next = n;
    	}
};

template <typename T>
class LinkedList
{
    Node<T> *head;
	public:
    	LinkedList(); 
    	void insert(T elem);
    	void display();
};

template <typename T>
LinkedList<T>::LinkedList()
{
    head = NULL;
}

template <typename T>
void LinkedList<T>::insert(T data)
{
    Node<T> *tmp = head;
	if (tmp == NULL)
    {
        head = new Node<T>(data, NULL);
        return;
    }
	Node<T> *prev = NULL;
    while (tmp != NULL && tmp->elem < data)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (prev == NULL || tmp == head)
    {
        head = new Node<T>(data, tmp);
        return;
    }
    prev->next = new Node<T>(data, tmp);
	return;
}

template <typename T>
void LinkedList<T>::display()
{
    if (head == NULL)
    {
        cout << "Error: List is empty!!!" << endl;
        return;
    }
    Node<T> *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->elem << "  ";
        tmp = tmp->next;
    }
}

int main()
{
    LinkedList<int> a;
	int choice;
    int val;
    char repeat;
	do
    {
        cout << endl;
        cout << "\tMENU " << endl;
        cout << "1.Insert element in the list" << endl;
        cout << "2.Display the list" << endl;
        cout << endl <<"Enter your choice : ";
        cin >> choice;
		switch (choice)
        {
        case 1:
        	{
            	cout << "Enter the value :" ;
            	cin >> val;
            	a.insert(val);
            	break;
        	}
        case 2:
        	{
            	cout << "The required Ordered list :  ";
            	a.display();
            	break;
        	}
        default:
        	{
            	cout << "Wrong choice" << endl;
            	break;
        	}
        }
        cout << endl << "Do you want to continue(Y/N)?" << endl;
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');
	return 0;
}
