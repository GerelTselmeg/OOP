#include <iostream>
using namespace std;

#define PI 3.14159 //програмийн хаана ч дуудсан PI утгууд хувилагдана
#define MIN(a,b) (((a)<(b)) ? a : b) //фүнкц шиг ашиглаж байгаа нь. 2 параметр аван MIN буцаах

int main ()
{
    cout << MIN(PI, 1) << endl;

    return 0;
}
