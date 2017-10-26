#include<iostream>
using namespace std;

void evenCount(int a[], int tsize)
{
    int i, counter = 0;
    for(i = 0; i < tsize; i++)
    {
        if(a[i] % 2 == 0)
            counter++;
    }
    cout << endl << "niit tegsh toonii too: " << counter;
}
int main()
{
    int n, a[20], i;
    cout << "Husnegtiin hemjee?";
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cout << i+1 << "dahi too: ";
        cin >> a[i];
    }
    evenCount(a, n);
}
