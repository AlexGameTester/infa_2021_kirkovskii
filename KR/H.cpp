
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int K;
    cin >> K;
    int *data = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> data[i];
    }

    int min = 0;
    int max = N - 1;
    while (max - min > 1)
    {
        int pos = (min + max) / 2;
        if (data[pos] > K)
        {
            max = pos;
        }
        else
        {
            min = pos;
        }
    }
    if (data[min] == K)
    {
        cout << min + 1 << endl;
    }
    else if (data[max] == K)
    {
        cout << max + 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    // index + 1 выводить
    delete[] data;
    return 0;
}