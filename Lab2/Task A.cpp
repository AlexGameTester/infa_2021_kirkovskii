#include <iostream>
using namespace std;

int main()
{
    int n1, n2, a, b, r;
    cin >> n1 >> n2;
    a = n1 >= n2 ? n1 : n2;
    b = n1 < n2 ? n1 : n2;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    cout << a;

    return 0;
}