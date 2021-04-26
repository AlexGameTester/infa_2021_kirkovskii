#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int W, N;
    cin >> W >> N;
    int *values = new int[N];
    int *masses = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> values[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> masses[i];
    }

    vector<vector<int>> table(W + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < W + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            if (i - masses[j - 1] < 0)
            {
                table[i][j] = table[i][j - 1];
            }
            else
            {
                int ip = i - masses[j - 1];
                table[i][j] = max(table[ip][j - 1] + values[j - 1], table[i][j - 1]);
            }
        }
    }

    cout << table[W][N];

    delete[] values;
    delete[] masses;
    return 0;
}