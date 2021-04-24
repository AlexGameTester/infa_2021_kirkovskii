#include <iostream>
#include <vector>

int min(int x, int y)
{
    return x < y ? x : y;
}

int main()
{
    int s, n;
    std::cin >> s >> n;
    int *values = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> values[i];
    }

    std::vector<std::vector<int>> table(s + 1, std::vector<int>(n + 1, 0));
    for (int i = 0; i < s + 1; i++)
    {
        table[i][0] = s + 1;
    }
    for (int i = 1; i < s + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (i - values[j - 1] < 0)
            {
                table[i][j] = table[i][j - 1];

                // table[j][i] = table[j - 1][i];
            }
            else
            {
                table[i][j] = min(table[i][j - 1], table[i - values[j - 1]][j] + 1);
                // table[j][i] = min(table[j - 1][i], table[j][i - values[j - 1]] + 1);
            }
        }
    }

    std::cout << table[s][n] << std::endl;

    delete[] values;

    return 0;
}