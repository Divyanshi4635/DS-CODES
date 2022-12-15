#include<iostream>
using namespace std;
void printStar(int m)
{
    for(int i=0;i<m;i++)
	{
        cout<<"*";
    }
    cout<<endl;
}
void pattern(int n,int m)
{
    printStar(m);
    if(m<n)
	{
        pattern(n,m+1);
    }
    printStar(m);
}
int main()
{  
    int n,m;
    cout<<"Enter the minimum number of asterisks: ";
    cin>>m;
    cout<<"Enter the maximum number of asterisks: ";
    cin>>n;
    if(n>=m)
    	pattern(n,m);
    else
        cout<<"Incorrect Input!!!"<<endl;
    return 0;
}
