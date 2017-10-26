#include<iostream>
#include<math.h>
using namespace std;

int hypotenuse(int a, int b)
{
    int h;

    h = sqrt(a * a + b * b);

    return h;
}
int half_perimeter(int a, int b, int c)
{
    int p;

    p = (a + b + c) / 2;

    return p;
}

int area(int a, int b)
{
    int c, s, p;

    c = hypotenuse(a, b);

    p = half_perimeter(a, b, c);

    s = sqrt(p * (p - a) * (p - b) * (p - c));

    return s;
}

int main()
{
    int a, b;

    cout << "a, b?";
    cin >> a >> b;

    cout << "S = " << area(a,b);

}
