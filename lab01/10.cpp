#include<iostream>
using namespace std;

int isPrime(int a)
{
    int i, flag = 0;
    for(i = 2; i <= a / 2; ++i)
    {
        if(a % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        cout << "mon\n";
    }
    else
    {
        cout << "bish\n";
    }
    return 0;

}
int caller()
{
    int a;
    char answer;
    cout << "shalgah toogoo oruulna uu:";
    cin >> a;
    isPrime(a);
    cout << "oor too shalgah? shalgah bol 'y' oruulna uu:";
    cin >> answer;
    if(answer == 'y')
        caller();
    else
        return 0;

}

int main()
{

    caller();

}
