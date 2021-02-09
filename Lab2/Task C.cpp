#include <iostream>
using namespace std;

int main()
{
    int el;
    int n = 0;
    while (true)
    {
        cin >> el;
        if (el == 0)
            break;
        if (el % 2 == 0)
            n++;
    }
    cout << n;
    return 0;
}