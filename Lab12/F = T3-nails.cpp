#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int vec_min(vector<int> data)
{
    int min = *data.begin();
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] < min)
        {
            min = data[i];
        }
    }

    return min;
}

int main()
{
    int tmp_i;
    vector<int> coords;
    while (cin >> tmp_i)
    {
        coords.push_back(tmp_i);
    }
    int N = coords.size();
    sort(coords.begin(), coords.end());
    int *lengths = new int[N - 1];
    for (int i = 1; i < N; i++)
    {
        lengths[i - 1] = (coords[i] - coords[i - 1]);
    }
    coords.clear();

    int *mins = new int[N - 1];
    mins[0] = lengths[0];
    if (N > 2)
    {
        mins[1] = lengths[1] + lengths[0];
    }
    for (int i = 2; i < N - 1; i++)
    {
        mins[i] = lengths[i] + min(mins[i - 1], mins[i - 2]);
    }

    cout << mins[N - 2] << endl;
    delete[] lengths;
    delete[] mins;
    return 0;
}