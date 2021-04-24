#include <iostream>
using namespace std;

int find_int(string data, int start);

int main()
{
    string data;
    getline(cin, data);
    int max = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] >= '0' && data[i] <= '9')
        {
            int val = find_int(data, i);
            if (val > max)
            {
                max = val;
            }
        }
    }

    cout << max << endl;
    return 0;
}

int find_int(string data, int start)
{
    int size = 1;
    while (true)
    {
        if (data.size() <= start + size)
        {
            break;
        }
        if (data[start + size] < '0' || data[start + size] > '9')
        {
            break;
        }
        size++;
    }
    string sub = data.substr(start, size);
    int val = stoi(sub);

    return val;
}