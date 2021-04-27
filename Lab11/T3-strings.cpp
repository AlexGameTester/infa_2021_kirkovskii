#include <iostream>
#include <vector>

using namespace std;

bool is_prefix(string pref, string str)
{
    if (pref.length() > str.length())
    {
        return false;
    }
    for (int i = 0; i < pref.length(); i++)
    {
        if (pref[i] != str[i])
        {
            return false;
        }
    }

    return true;
}

int vec_max(vector<int> data)
{
    int max = *data.begin();
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] > max)
        {
            max = data[i];
        }
    }

    return max;
}

int main()
{
    int m;
    cin >> m;
    string *words = new string[m];
    vector<int> lengths(m);
    for (int i = 0; i < m; i++)
    {
        cin >> words[i];
    }

    lengths[0] = 1;

    vector<int> tmp;
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (is_prefix(words[j], words[i]))
            {
                tmp.push_back(lengths[j]);
            }
        }
        if (tmp.empty())
        {
            lengths[i] = 1;
        }
        else
        {
            lengths[i] = 1 + vec_max(tmp);
        }

        tmp.clear();
    }

    int global_max = vec_max(lengths);
    cout << global_max << endl;

    delete[] words;
    return 0;
}