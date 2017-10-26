#include<iostream>
using namespace std;
void swap(int *num1, int *num2) {
   int temp;
   temp = *num1;
   *num1 = *num2;
   *num2 = temp;
}
int main()
{
    int a, b;
    cout << "a, b: ";
    cin >> a >> b;
    swap(&a, &b);
    cout << a << endl << b;
}
