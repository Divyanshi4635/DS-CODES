#include <iostream>
#include <queue>
#include <stack>
using namespace std; 
template <class T>
class BST;
template <class T>
class BSTnode
{
    BSTnode<T> *left;
    BSTnode<T> *right;
    T info;

	public:
    	BSTnode()
    	{
        	left = right = 0;
    	}
    	BSTnode(BSTnode<T> *l, BSTnode<T> *r, T data)
    	{
    	    left = l;
    	    right = r;
    	    info = data;
    	}
    friend class BST<T>;
};

template <class T>
class BST
{
    BSTnode<T> *root;

	public:
    	BST()
    	{
    	    root = NULL;
    	}
    	void insert(T data);
    	void breadthfirst();
    	void rec_preorder(BSTnode<T> *);
    	void rec_inorder(BSTnode<T> *);
    	void rec_postorder(BSTnode<T> *);
    	void it_preorder();
    	void it_inorder();
    	void it_postorder();
    	T search(T data);
    BSTnode<T> *get_root()
    {
        return root;
    }
};

template <class T>
T BST<T>::search(T data)
{
    BSTnode<T> *p = root;
    while (p != NULL)
    {
        if (data == p->info)
            return p->info;
        else if (data < p->info)
            p = p->left;
        else
            p = p->right;
    }
}

template <class T>
void BST<T>::insert(T data)
{
    BSTnode<T> *p = root;
    BSTnode<T> *prev = NULL;
    if (root == NULL)
    {
        root = new BSTnode<T>(0, 0, data);
        return;
    }
    while (p != 0)
    {
        prev = p;
        if (data < prev->info)
            p = p->left;
        else
            p = p->right;
    }
    if (data < prev->info)
        prev->left = new BSTnode<T>(0, 0, data);
    else
        prev->right = new BSTnode<T>(0, 0, data);
}

template <class T>
void BST<T>::breadthfirst()
{
    queue<BSTnode<T> *> q;
    BSTnode<T> *p = root;
    if (p != 0)
    {
        q.push(p);
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            cout << p->info << "\t";
            if (p->left != 0)
                q.push(p->left);
            if (p->right != 0)
                q.push(p->right);
        }
    }
    else
        cout << "List is empty. " << endl;
}

template <class T>
void BST<T>::rec_preorder(BSTnode<T> *p)
{

    if (p != 0)
    {
        cout << p->info << "\t";
        rec_preorder(p->left);
        rec_preorder(p->right);
    }
}

template <class T>
void BST<T>::rec_postorder(BSTnode<T> *p)
{
    if (p != 0)
    {
        rec_postorder(p->left);
        rec_postorder(p->right);
        cout << p->info << "\t";
    }
}

template <class T>
void BST<T>::rec_inorder(BSTnode<T> *p)
{
    if (p != 0)
    {
        rec_inorder(p->left);
        cout << p->info << "\t";
        rec_inorder(p->right);
    }
}

template <class T>
void BST<T>::it_inorder()
{
    stack<BSTnode<T> *> s;
    BSTnode<T> *p = root;
    if (p == 0)
        cout << "List is empty." << endl;
    while (p != 0)
    {
        while (p != 0)
        {
            if (p->right)
                s.push(p->right);
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        while (!s.empty() && p->right == 0)
        {
            cout << p->info << "\t";
            p = s.top();
            s.pop();
        }
        cout << p->info << "\t";
        if (!s.empty())
        {
            p = s.top();
            s.pop();
        }
        else
            p = 0;
    }
}

template <class T>
void BST<T>::it_postorder()
{
    stack<BSTnode<T> *> s;
    BSTnode<T> *p = root, *q = root;
    if (p == 0)
        cout << "List is empty." << endl;
    while (p != 0)
    {
        for (; p->left != 0; p = p->left)
            s.push(p);
        while (p->right == 0 || p->right == q)
        {
            cout << p->info << "\t";
            q = p;
            if (s.empty())
                return;
            p = s.top();
            s.pop();
        }
        s.push(p);
        p = p->right;
    }
}

template <class T>
void BST<T>::it_preorder()
{
    stack<BSTnode<T> *> s;
    BSTnode<T> *p = root;
    if (p != 0)
    {
        s.push(p);
        while (!s.empty())
        {
            p = s.top();
            s.pop();
            cout << p->info << "\t";
            if (p->right != 0)
                s.push(p->right);
            if (p->left != 0)
                s.push(p->left);
        }
    }
    else
        cout << "List is empty." << endl;
}

int main()
{
    BST<int> a;
    int choice;
    char ch;
    int data;
    cout << "----------MENU----------" << endl;
    cout << "1. Insert the element." << endl;
    cout << "2. Breadth first transversal." << endl;
    cout << "3. Recursive inorder transversal." << endl;
    cout << "4. Recursive preorder transversal." << endl;
    cout << "5. Recursive postorder transversal." << endl;
    cout << "6. Iterative inorder transversal." << endl;
    cout << "7. Iterative preorder transversal." << endl;
    cout << "8. Iterative postorder transversal." << endl;
    cout << "9. Searching the element." << endl;
    do
    {
        cout << "Enter your choice :" << endl;
        cin >> choice;
        switch (choice)
        {
	        case 1:
	        {
    	        cout << "Enter the element you want to insert in tree." << endl;
        	    cin >> data;
            	a.insert(data);
            	break;
        	}
        	case 2:
        	{
            	cout << "Breadth first transversal is :" << endl;
            	a.breadthfirst();
            	break;
        	}
        	case 3:
        	{
        	    cout << "Recursive inorder transversal is :" << endl;
        	    if (a.get_root() == 0)
        	        cout << "List is empty." << endl;
        	    else
        	        a.rec_inorder(a.get_root());
        	    break;
        	}
        	case 4:
        	{
        	    cout << "Recursive preorder transversal is :" << endl;
        	    if (a.get_root() == 0)
            	    cout << "List is empty." << endl;
            	else
                	a.rec_preorder(a.get_root());
            	break;
        	}
        	case 5:
        	{
            	cout << "Recursive postorder transversal is :" << endl;
            	if (a.get_root() == 0)
            	    cout << "List is empty." << endl;
            	else
            	    a.rec_postorder(a.get_root());
            	break;
        	}
        	case 6:
        	{
            	cout << "Iterative inorder transversal is :" << endl;
        	  	a.it_inorder();
            	break;
        	}
        	case 7:
        	{
            	cout << "Iterative preorder transversal is :" << endl;
            	a.it_preorder();
            	break;
        	}
        	case 8:
        	{
        	    cout << "Iterative postorder transversal is :" << endl;
        	    a.it_postorder();
        	    break;
        	}
        	case 9:
        	{	
            	if (a.get_root() == 0)
                	cout << "List is empty." << endl;
            	else
            	{
                	int ele;
                	cout << "Enter element you want to search for :" << endl;
                	cin >> ele;
                	if (a.search(ele) != 0)
                	    cout << "Element found." << endl;
                	else
                    	cout << "Element not present in tree. " << endl;
            	}
            	break;
        	}
        	default:
        	{
            	cout << "Wrong choice." << endl;
            	break;
        	}
        }
        cout << endl
             << "Do you want to continue(Y/N)?" << endl;
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    return 0;
}
