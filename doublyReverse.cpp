#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList;

template <typename T>
class Node
{
    T elem;        
    Node<T> *next; 
    Node<T> *prev; 
	friend class DoublyLinkedList<T>;
	public:
    	Node()
    	{
        	elem = 0;
        	next = NULL;
        	prev = NULL;
    	}
};

template <typename T>
class DoublyLinkedList
{
    Node<T> *header;  
    Node<T> *trailer; 
	protected:
    	void add(Node<T> *v, const T &elem);
	public:
    	DoublyLinkedList();  
	    void add_to_head(T elem); 
    	void display();           
		void add_to_tail(T elem); 
    	void insert_at_position(int pos, T elem); 
    	Node<T>* reverse();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() 
{
    header = new Node<T>();
    trailer = new Node<T>();
    header->next = trailer;
    trailer->prev = header; 
}

template <typename T>
void DoublyLinkedList<T>::add(Node<T> *v, const T &elem) 
{
    Node<T> *u = new Node<T>(); 
    u->elem = elem;
    u->next = v;
    u->prev = v->prev;
    v->prev = u;
    u->prev->next = u;
}

template <typename T>
void DoublyLinkedList<T>::add_to_head(T elem)
{
    add(header->next, elem);
}

template <typename T>
void DoublyLinkedList<T>::add_to_tail(T elem)
{
    add(trailer, elem);
}

template <typename T>
void DoublyLinkedList<T>::insert_at_position(int pos, T elem)
{
    if (pos == 1)
    {
        add_to_head(elem);
        return;
    }
    Node<T> *tmp = header->next;
    int counter = 1;
    while (counter < pos - 1 && tmp != trailer)
    {
        tmp = tmp->next;
        counter++;
    }
    add(tmp->next, elem); 
}

template <typename T>
Node<T>* DoublyLinkedList<T>::reverse()
{
    Node<T>* ptr1 = header->next;
    Node<T>* ptr2 = ptr1->next;

    ptr1->next = trailer;
    ptr1->prev = ptr2;

    while (ptr2 != trailer)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    header->next = ptr1;
    return header->next;
    
}
template <typename T>
void DoublyLinkedList<T>::display()
{
    if (header->next == trailer)
    {
        cout << "Error: List is empty!!!" << endl;
        return;
    }
    Node<T> *tmp = header->next;
    while (tmp != trailer)
    {
        cout << tmp->elem << "\t";
        tmp = tmp->next;
    }
}
int main()
{
    DoublyLinkedList<int> a;

    int choice;
    int val;
    char repeat;

    do
    {
        cout << endl;
        cout << "**** MENU ****" << endl;
        cout << "1.Add in the beginning" << endl;
        cout << "2.Add in the last" << endl;
        cout << "3.Insert at position" << endl;
        cout << "4.Reverse of list "<<endl;
        cout << "5.Display the list" << endl;
        cout << "**Enter your choice**" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the value :" << endl;
            cin >> val;
            a.add_to_head(val);
            break;
        }
        case 2:
        {
            cout << "Enter the value :" << endl;
            cin >> val;
            a.add_to_tail(val);
            break;
        }
        case 3:
        {
            int pos; // position at which element to be insert
            cout << "Enter the position : " << endl;
            cin >> pos;
            cout << "Enter the value :" << endl;
            cin >> val;
            a.insert_at_position(pos, val);
            break;
        }
        case 4:
        {
            cout<<"Reverse list:"<<endl;
            a.reverse();
            a.display();
            break;
        }
        case 5:
        {
            cout << "The required list: " << endl;
            a.display();
            break;
        }
        default:
        {
            cout << "Wrong choice" << endl;
            break;
        }
        }
            cout << endl<< "Do you want to continue(Y/N) ? " ;
            cin >> repeat;
        
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
