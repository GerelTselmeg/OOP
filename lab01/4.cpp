#include<iostream>
using namespace std;

int average(int s, int n)
{
    int a;

    a = s / n;

    cout << "avg: " << a;

}

int input_sum(int n)
{
    int sum = 0, x, i = 0;

    for(i; i < n; i++)
    {
        cout << "x?";
        cin >> x;

        sum += x;
    }

    average(sum, n);



    cout << endl << "sum : " << sum;
}

int main()
{
    int n;

    cout << "N?";
    cin >> n;

    input_sum(n);

}
