#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> table(8, vector<int>(8, 0));
    vector<vector<int>> black_positions(8, vector<int>(8, 0));
    int n;
    cin >> n;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        int x = tmp[0] - 97;
        int y = tmp[1] - 48 - 1;
        black_positions[x][y] = 1;
    }

    cin >> tmp;
    int pawn_x = tmp[0] - 97;
    int pawn_y = tmp[1] - 48 - 1;
    table[pawn_x][pawn_y] = 1;

    for (int j = 1; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (black_positions[i][j] == 1 && j > 0)
            {
                if (i > 0)
                {
                    table[i][j] += table[i - 1][j - 1];
                }
                if (i < 7)
                {
                    table[i][j] += table[i + 1][j - 1];
                }
            }
            else
            {
                table[i][j] += table[i][j - 1];
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        sum += table[i][7];
    }

    cout << sum << endl;
}