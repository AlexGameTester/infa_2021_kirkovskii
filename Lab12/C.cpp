#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int vec_max(vector<int> vec)
{
    if (vec.empty())
    {
        return -10000;
    }
    else
    {
        int max = vec[0];
        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i] > max)
            {
                max = vec[i];
            }
        }
        return max;
    }
}

int main()
{
    int N;
    cin >> N;
    int *els = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> els[i];
    }
    vector<int> max_with_end(N, 0);
    max_with_end[0] = 1;
    vector<int> tmp;
    for (int i = 1; i < N; i++)
    {
        int current = els[i];
        for (int j = 0; j < i; j++)
        {
            if (els[j] < current)
            {
                tmp.push_back(max_with_end[j]);
            }
        }
        if (tmp.empty())
        {
            max_with_end[i] = 1;
        }
        else
        {
            max_with_end[i] = vec_max(tmp) + 1;
        }
        tmp.clear();
    }
    int res = vec_max(max_with_end);
    cout << res << endl;

    delete[] els;
    return 0;
}