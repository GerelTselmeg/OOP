#include<iostream>
using namespace std;
void swap(int &,int &);
int main()
{
    int a,b;
    a = 31, b = 1;
    cout<<a<<" "<<b << endl;
    swap(a,b);
    cout<<a<<" "<<b;
}
void swap(int &a,int &b)
{
    int c;
    c=a;
    a=b;
    b=c;
}
