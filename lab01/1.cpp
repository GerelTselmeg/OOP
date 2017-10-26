#include<iostream>
using namespace std;

int maxi(int a, int b, int c)
{
    int max;
    if(a > b)
    {
        if(a > c)
            max = a;
        else
            max = c;
    }
    else if(b > c)
        max = b;
    else
        max = c;

    return max;
}
int main()
{
    int a, b, c;

    cout << "a, b, c =?";
    cin >> a >> b >> c;

    cout << "maximum:" << maxi(a, b, c);
    return 0;
}
