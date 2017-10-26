#include<iostream>
using namespace std;
int main()
{
    int ma, mi, n, i, x;
    cout << "heden too? ";
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cout << i + 1 << "dah toogoo oruulna uu: ";
        cin >> x;
        if(i == 0)
        {
            mi = ma = x;
        }
        else
        {
            if(mi > x)
                mi = x;
            if(ma < x)
                ma = x;
        }
    }
    cout << "max: " << ma << endl << "min: " << mi;

}
