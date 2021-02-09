#include <iostream>
using namespace std;

int main()
{
    int max, current;
    max = 0; // all elements of sequence are naturals
    while (true)
    {
        cin >> current;
        if (current == 0)
            break;
        if (current % 2 == 0 and current > max)
            max = current;
    }
    cout << max;
}