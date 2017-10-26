#include<iostream>
using namespace std;
void print(int a[], int tsize)
{
    int i;
    for(i = 0; i < tsize; i++)
        cout << a[i] << " ";
}
void desc(int a[], int tsize)
{
    int i, j, k;
    for(i = 0; i < tsize; ++i)
    {
        for(j = i + 1; j < tsize; ++j)
        {
            if(a[i] < a[j])
            {
                k = a[i];
                a[i] = a[j];
                a[j] = k;
            }
        }
    }
    cout << "\n buurah: ";
    print(a, tsize);

}
void asc(int a[], int tsize)
{
    int i, j, k;
    for(i = 0; i < tsize; ++i)
    {
        for(j = i + 1; j < tsize; ++j)
        {
            if(a[i] > a[j])
            {
                k = a[i];
                a[i] = a[j];
                a[j] = k;
            }
        }
    }
    cout << "\n osoh: ";
    print(a, tsize);
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
    asc(a, n);
    desc(a, n);


}
