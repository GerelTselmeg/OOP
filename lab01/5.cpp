#include<iostream>
using namespace std;

int input_sum_mult(int n)
{
    int sum = 0, x, i = 0, mult = 1;

    for(i; i < n; i++)
    {
        cout << "x?";
        cin >> x;

        sum += x;
        mult *= x;
    }

    cout << "sum : " << sum << "\nmult: " << mult;
}

int main()
{
    int n;

    cout << "Heden too boduulah ve?";
    cin >> n;

    input_sum_mult(n);

}
