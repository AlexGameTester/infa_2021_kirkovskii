#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string P;
    cin >> P;
    int N = P.size();
    string sub = "uddu";
    vector<vector<unsigned int>> occ(4, vector<unsigned int>(N, 0)); // occ[j][i] - число вхождений подстроки из первых j+1 символов строки sub в строку из первых i+1 символов строки P
    for (int i = 0; i < N; i++)
    {
        if (sub[0] == P[i])
        {
            occ[0][i]++;
        }
    }
    for (int j = 1; j < 4; j++)
    {
        for (int i = j; i < N; i++)
        {
            if (sub[j] == P[i])
            {
                for (int k = j - 1; k < i; k++)
                {
                    occ[j][i] += occ[j - 1][k];
                }
            }
        }
    }

    int res = 0;
    for (int i = 3; i < N; i++)
    {
        res += occ[3][i];
    }
    cout << res << endl;

    return 0;
}