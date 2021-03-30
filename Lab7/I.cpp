#include <iostream>
#include <list>
#include <vector>
using namespace std;

int is_greater(int a, int b)
{
    if (a % 2 == b % 2)
    {
        if (a > b)
        {
            return 1;
        }
        else if (a < b)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (a % 2 == 1)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

void selection_sort(vector<int> &vals)
{
    int N = vals.size();
    for (int i = 0; i < N; i++)
    {
        auto it = vals.begin();
        int min = vals.back();
        for (int j = 0; j < vals.size(); j++)
        {
            int current = *it;
            if (is_greater(min, current) == 1)
            {
                *it = min;
                min = current;
                vals.back() = current;
            }
            it++;
        }
        cout << min << endl;
        vals.pop_back();
    }
}

int main()
{
    vector<int> values;
    int tmp;
    while (cin >> tmp)
    {
        values.push_back(tmp);
    }
    selection_sort(values);

    return 0;
}