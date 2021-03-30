#include <iostream>
using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}
int main()
{
    int N;
    cin >> N;
    int *slippers = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> slippers[i];
    }
    int min_distance = N + 1;
    for (int i = 0; i < N; i++)
    {
        if (slippers[i] > 0)
        {
            continue;
        }
        for (int j = i + 1; j < min(i + min_distance, N); j++)
        {
            if (slippers[j] + slippers[i] == 0)
            {
                // cout << "Checking pair: (" << slippers[i] << ", " << slippers[j] << ")" << endl;
                if (min_distance > j - i)
                {
                    min_distance = j - i;
                }
            }
        }
    }
    if (min_distance <= N)
    {
        cout << min_distance << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    delete[] slippers;

    return 0;
}