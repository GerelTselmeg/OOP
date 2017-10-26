#include<iostream>
using namespace std;
inline int test(int a)
{
    a += 100;
    return a;
}
int main()
{
    cout << test(100);
}
