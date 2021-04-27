#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int *numbers = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    int *sums = new int[N];
    sums[0] = numbers[0];
    sums[1] = max(numbers[1], numbers[0] + numbers[1]);
    for (int i = 2; i < N; i++)
    {
        sums[i] = max(numbers[i] + sums[i - 1], numbers[i] + sums[i - 2]);
    }

    cout << sums[N - 1] << endl;

    vector<int> stairs;
    stairs.reserve(N / 2);
    stairs.push_back(N);
    int i = N - 1;
    while (i >= 2)
    {
        int diff = sums[i] - numbers[i];
        if (diff == sums[i - 1])
        {
            stairs.push_back(i - 1 + 1);
            i -= 1;
        }
        else
        {
            stairs.push_back(i - 2 + 1);
            i -= 2;
        }
    }

    reverse(stairs.begin(), stairs.end());
    for (int i = 0; i < stairs.size(); i++)
    {
        cout << stairs[i] << " ";
    }

    delete[] sums;
    delete[] numbers;
    return 0;
}