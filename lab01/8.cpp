#include<iostream>
using namespace std;

int avg(int a[], int tsize)
{
    int average = 0, i;
    for(i = 0; i < tsize; i++)
    {
        average += a[i];
    }
    average /= tsize;
    return average;
}
int main()
{
    int i, n, a[40];
    cout << "husnegtiin hemjee zaana uu: ";
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cout << "a[" << i+1 << "]: ";
        cin >> a[i];
    }
    cout << avg(a, n);
}
