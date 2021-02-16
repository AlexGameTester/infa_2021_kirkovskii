#include <iostream>
using namespace std;

void print_array(int *p);

int count_mines(int **field, int x, int y, int n, int m);

int main()
{
    int n, m, k;
    cin >> n >> m;
    int *__field = new int[n * m];
    int **field = new int *[n];
    for (int i = 0; i < n; i++)
    {
        field[i] = __field + i * m;
    }

    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            field[x][y] = 0;
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        field[--x][--y] = -1;
    }

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (field[x][y] == -1)
            {
                cout << -1 << ' ';
            }
            else
            {
                cout << count_mines(field, x, y, n, m) << ' ';
            }
        }
        cout << endl;
    }

    delete[] __field;
    delete[] field;
}

int count_mines(int **field, int x, int y, int n, int m)
{
    int total_mines = 0;
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int x_ = x + dx;
            int y_ = y + dy;
            if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < m)
            {
                if (field[x_][y_] == -1)
                {
                    total_mines++;
                }
            }
        }
    }

    return total_mines;
}