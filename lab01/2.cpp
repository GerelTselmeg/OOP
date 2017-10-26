#include<iostream>
using namespace std;

int area(int r)
{
    int s;
    double pi;
    pi = 3,1415;

    s = pi * r * r;

    return s;
}
int main()
{
    int radius;

    cout << "Radius?";
    cin >> radius;

    cout << "S =" << area(radius);
}
