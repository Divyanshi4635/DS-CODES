#include <iostream>
using namespace std;

template<class T>
class Multiply{
	private:
		int rows;
		int columns;
		T *arr;
		int n;
		int value;
		
	public:
		void input();
//		Multiply<T>operator+(const Multiply<T> &)const;
		Multiply<T>operator*(const Multiply<T> &)const;
		void display();
//		T set(int i, int j, const &value);
//		T get(int i, int j);
};

template<class T>
void Multiply<T> :: input()
{
	int value;
	cout << "TAKING INPUT : " << endl;
	cout << "ENTER THE ELEMENTS OF AN ARRAY : " << endl;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cout << "ELEMENT AT " << i << j << endl;
			cin >> value;
		}
		cout << endl;
	}
}

//displaying the matrix
template <class T>
void Multiply<T>::display()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << value << "\t";
        }
        cout << endl;
    }
}
/*
template<class T>
T Multiply<T> :: set(int i, int j , const &value)
{
	cout << " SET FUNCTION IS CALLED : " << endl;
	if(i < 0 || j < 0 || i > || j > 0)
	{
		cout << " MATRIX INDEX OUT OF BOUND " << endl;
	}
	
	return arr[i *columns + j]; // returning value in row major form 
}

template <class T>
T Multiply<T> :: get(int i, int j)
{
	cout << " GET FUNCTION IS CALLED : " << endl;
	if(i < 0 || j < 0 || i > || j > 0)
	{
		cout << " MATRIX INDEX OUT OF BOUND " << endl;
	}
	
	return arr[i *columns + j]; // returning value in row major form 	
}
*/

template <class T>
Multiply<T> Multiply<T> :: operator *(const Multiply<T> & m)const
{
	if(columns != m.rows)
	{
		cout << "MATRIX SIZE MISMATCHED " << endl;
	}
	
	//creating resultant matrix, denoted by w 
	
	Multiply<T>w(rows, m.columns);
	int ct = 0; //for matrix 1
	int cm = 0; // for matrix 2
	int cw = 0;  // for matrix 3 i.e resultant matrix
	
	for(int i = 1; i < rows; i++)
	{
		for(int j = 1 ; i < m.columns; j++)
		{
			int sum = arr[ct] * arr[m.columns];   // storing the first element after multiplication 
			for(int k = 2; k < m.rows; k++)  // starting k from 2 since 1st element is already stored ahead
			{
				ct++;  
				cm+= m.columns;
				sum = arr[ct] * m.arr[cm];   // storing the elements in sum after multiplication
			} // k loop ends here
			w.arr[cw++] = sum; // post increment is here which means the it will return the previous value i.e it cw = 0;
			ct = ct- columns - 1; // reset the rows and columns
			cm = j ; // here since j becomes 1 , then cm also becomes 1 for stating the 2nd column
		} // j loop ends here
		cm = 0;  // so that we can return back to 1st column for further multiplication 
		ct = ct + columns; 
		return 0;
	}  // i loop ends here
} 

int main()
{
	int rows;
	int columns;
	int value;
	Multiply<int> d;
	int *arr;
	int n = rows * columns;
	arr = new int [n];

	cout << "     MATRIX 1      " << endl;
	cout << "ENTER THE ROWS : ";
	cin >> rows;
	cout << endl;
	cout << "ENTER THE COLUMNS: " ;
	cin >> columns;
	cout << endl;
	d.input();
	d.display();
		
	cout << "     MATRIX 2      " << endl;
	cout << "ENTER THE ROWS : ";
	cin >> rows;
	cout << endl;
	cout << "ENTER THE COLUMNS: " ;
	cin >> columns;
	cout << endl;
	d.input();
	d.display();	
}
