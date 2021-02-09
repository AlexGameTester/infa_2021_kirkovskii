#include <iostream>
using namespace std;

int main()
{
    int current, max, occurences;
    max = 0;
    occurences = 0;
    while (true)
    {
        cin >> current;
        if (current == 0)
            break;
        if (current == max)
            occurences++;
        if (current > max)
        {
            max = current;
            occurences = 1;
        }
    }

    cout << occurences;
    return 0;
}