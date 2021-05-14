#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *numbers = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    int *ways = new int[n];
    ways[0] = 1;
    ways[1] = 1;
    for (int i = 2; i < n; i++)
    {
        int tmp = 0;
        for (int j = 0; j < i - 1; j++)
        {
            if (numbers[j] == i - j)
            {
                tmp += ways[j];
                tmp %= 937;
            }
        }

        ways[i] = tmp + ways[i - 1];
        ways[i] %= 937;
    }

    cout << ways[n - 1] % 937 << endl;

    delete[] numbers;
    delete[] ways;
    return 0;
}