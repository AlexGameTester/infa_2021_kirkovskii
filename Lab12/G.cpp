#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int *heights = new int[N];
    int *min_energies = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> heights[i];
    }
    min_energies[0] = 0;
    min_energies[1] = abs(heights[1] - heights[0]);
    for (int i = 2; i < N; i++)
    {
        min_energies[i] = min(
            min_energies[i - 1] + abs(heights[i] - heights[i - 1]),
            min_energies[i - 2] + 3 * abs(heights[i] - heights[i - 2]));
    }
    cout << min_energies[N - 1] << endl;

    delete[] min_energies;
    delete[] heights;
    return 0;
}