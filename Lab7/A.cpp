#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, x;
    cin >> a >> b >> c >> d >> x;
    int sol1 = b - a;
    int sol2 = d / c;
    if ((x == sol1) && (x == sol2))
    {
        cout << 5 << endl;
    }
    else if ((x == sol1) || (x == sol2))
    {
        cout << 4 << endl;
    }
    else if (x == 1024)
    {
        cout << 3 << endl;
    }
    else
    {
        cout << 2 << endl;
    }
}