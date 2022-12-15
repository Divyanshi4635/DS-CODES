#include<iostream>
using namespace std;
bool WinOrNot(int n)
{
 	if(n==42)  
        return true;
    if(n>42)
	{
        if(n%2==0)
            return WinOrNot(n/2);
        else if(n%3==0 || n%4==0)
		{
            int p=n%10;
            int q=(n%100)/10;
            return WinOrNot(n-p*q);
        }
        else if(n%5==0)
            return WinOrNot(n-42);
	}
	return false;
}
int main()
{
    int n;
    cout<<"Enter the number of bears:";
   	cin>>n;
    cout<<"The possibility to left with 42 bears is :"<<boolalpha<<WinOrNot(n);
    return 0;
}

