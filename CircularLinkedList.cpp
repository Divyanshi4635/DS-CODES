#include <iostream>
using namespace std;

template <typename T>
class CircularLinkedList;

template <typename T>
class Node
{
	private:
    	T elem;        
    	Node<T> *next; 
		friend class CircularLinkedList<T>;
	public:
    	Node()
    	{
        	elem = 0;
        	next = NULL;
    	}
};

template <typename T>
class CircularLinkedList
{
    Node<T> *cursor;

public:
    CircularLinkedList()  							// constructor
    {
		cursor = NULL;	
	}
	~CircularLinkedList() 							// destructor
    {
    	while (cursor != NULL)
    	{
        	remove_front();
    	}
	}
	void add_front(T info); 						// add element after the cursor
    void remove_front();    						// remove element after the cursor
    void display(); 								// display linked list
    void add_back(T info); 							// add element at cursor
    void remove_back(); 							// remove element from cursor
    void insert_at_position(int pos, T elem); 		// insert at particular position
    void remove_from_position(int pos);       		// delete from particular position
    Node<T>* search_ele(T elem);
    const T& back() const
	{
        return cursor->elem;
    }
};

template <typename T>
void CircularLinkedList<T>::add_front(T elem) 
{
    Node<T> *v = new Node<T>;
    v->elem = elem;

    if (cursor == NULL) 
    {
        v->next = v; 
        cursor = v; 
        return;
    }
    v->next = cursor->next;
    cursor->next = v;
}

template <typename T>
void CircularLinkedList<T>::add_back(T elem) 
{
    Node<T> *v = new Node<T>; 
    v->elem = elem;

    if (cursor == NULL) 
    {
        cursor = v;  
        cursor->next = v;
        return;
    }
    v->next = cursor->next;
    cursor->next = v;
    cursor = cursor->next;
}

template <typename T>
void CircularLinkedList<T>::remove_front() 
{
    Node<T>* v = cursor->next;
    if (v == cursor) 
    {
        cursor = NULL; 
        delete v;
        return;
    }
    cursor->next = v->next; 
    delete v;
}

template <typename T>
void CircularLinkedList<T>::remove_back()
{
    Node<T>* v = cursor;

    if (v->next == cursor)
    {
        cursor = NULL;
        delete v;
        return;
    }
    Node<T>* tmp = cursor->next;
    while (tmp->next != cursor)
    {
        tmp = tmp->next;
    }
    tmp->next = cursor->next;
    cursor = tmp;
    delete v;
}

template <typename T>
void CircularLinkedList<T>::insert_at_position(int pos, T elem)
{
    if(pos == 1)
    {
    	add_front(elem);
    	return;
	}
    Node<T>* tmp = cursor->next;
    int counter = 1;
    while (counter < pos-1 && tmp!= NULL)
    {
        tmp = tmp->next;
		counter++;
    }
    if (tmp == cursor)
    {
        add_back(elem);
        return;
    }
    
    Node<T>* t = new Node<T>;
    t->elem = elem;
    t->next = tmp->next;
    tmp->next = t; 
}

template <typename T>
void CircularLinkedList<T>::remove_from_position(int pos)
{
    if(pos == 1)
    {
    	remove_front();
    	return;
	}
    Node<T>* tmp = cursor->next;
    int counter = 1;
    while (counter < pos-1 && tmp!= NULL)
    {
        tmp = tmp->next;
		counter++;
    }
    if (tmp->next == cursor)
    {
        remove_back();
        return;
    }
    Node<T>* t = tmp->next;
    tmp->next = t->next;
    delete t;
}

template <typename T>
Node<T> *CircularLinkedList<T>::search_ele( T x)
{
    Node<T> *tmp = cursor->next;
    int j = 1; 
    while (tmp != cursor)
    {
        if (tmp->elem == x)
        {
            cout << "Element is found at position " << j << endl;
            return tmp->next;
        }
        tmp = tmp->next;
        j++;
    }
    if (tmp == cursor)
    {
        cout << "Element is found at position " << j << endl;
        return tmp->next;
    }
    cout << "Element is not found!!!" << endl;
    return 0;
}
template <typename T>
void CircularLinkedList<T>::display()
{
	if (cursor == NULL)
    {
        cout << "Error: List is empty!!!" << endl;
        return;
    }
    Node<T> *tmp = cursor->next;
    while (tmp != cursor)
    {
        cout << tmp->elem<< " ";
        tmp = tmp->next;
    }
    cout<<cursor->elem<<endl;
}

int main()
{
    CircularLinkedList<int> c;  
    int choice;
    int val;
    char opt;

    do
    {
        cout << endl;
        cout << "\tMENU " << endl;
        cout << "1.Insert element at front" << endl;
        cout << "2.Insert element at back" << endl;
        cout << "3.Insert element at position" << endl;
        cout << "4.Delete from the front" << endl;
        cout << "5.Delete from the back" << endl;
        cout << "6.Delete from the position" << endl;
        cout << "7.Search an element" << endl;
        cout << "8.Display the list" << endl;
        cout << "Enter your choice : " ;
        cin >> choice;
        switch (choice)
        {
        	case 1:
        	{
            	cout << "Enter the value :" ;
            	cin >> val;
            	c.add_front(val);
            	break;
        	}
        	case 2:
        	{
            	cout << "Enter the value :" ;
            	cin >> val;
            	c.add_back(val);
            	break;
        	}
        	case 3:
        	{
            	int pos; 
            	cout << "Enter the position : ";
            	cin >> pos;
            	cout << "Enter the value :";
            	cin >> val;
            	c.insert_at_position(pos, val);
            	break;
        	}
        	case 4:
        	{
            	c.remove_front();
            	cout << "Deleted from the front!!!" << endl;
            	break;
        	}
        	case 5:
        	{
            	c.remove_back();
            	cout << "Deleted from the back!!!" << endl;
            	break;
        	}
        	case 6:
        	{
            	int pos; 
            	cout << "Enter the position : ";
            	cin >> pos;
            	c.remove_from_position(pos);
            	cout << "Deleted from the position!!!" <<endl;
            	break;
        	}
        	case 7:
        	{
            	int i;  
            	cout << "Enter the element to be searched: " ;
            	cin >> i;
            	cout << "Address of element: " << c.search_ele(i) << endl;
            	break;
        	}
        	case 8:
        	{
            	cout << "The required list: " ;
            	c.display();
            	cout<<endl<<"The cursor is : "<<c.back()<<endl;
            	break;
        	}
        	default:
        	{
            	cout << "Wrong choice" << endl;
            	break;
        	}
        }
        cout << endl<< "Do you want to continue(Y/N) ? ";
        cin >> opt;    
    } while (opt == 'y' || opt == 'Y');
	return 0;
}
