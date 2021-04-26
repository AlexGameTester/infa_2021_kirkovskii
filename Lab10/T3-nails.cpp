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
    int N;
    cin >> N;
    int *coords = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> coords[i];
    }
    sort(coords, coords + N);
    int *lengths = new int[N - 1];
    for (int i = 1; i < N; i++)
    {
        lengths[i - 1] = (coords[i] - coords[i - 1]);
    }
    delete[] coords;

    int *mins = new int[N - 1];
    mins[0] = lengths[0];
    if (N > 2)
    {
        mins[1] = lengths[1] + lengths[0];
    }
    vector<int> tmp;
    for (int i = 2; i < N - 1; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            int sum = 0;
            for (int k = j + 1; k <= i; k++)
            {
                sum += lengths[k];
            }
            tmp.push_back(mins[j - 1] + sum);
        }

        mins[i] = vec_min(tmp);
        tmp.clear();
    }

    cout << mins[N - 2] << endl;
    delete[] lengths;
    delete[] mins;
    return 0;
}