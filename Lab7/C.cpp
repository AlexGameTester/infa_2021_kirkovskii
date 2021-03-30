#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double mean(vector<int> data, bool squared);
int main()
{
    vector<int> data;
    string tmp;
    while (cin >> tmp)
    {
        int val = stoi(tmp);
        if (val == 0)
        {
            break;
        }
        data.push_back(val);
    }
    double mean_ = mean(data, false);
    double mean_sq = mean(data, true);
    double dispersion = mean_sq - mean_ * mean_;
    mean_ = round(1000 * mean_) / 1000;
    dispersion = round(1000 * dispersion) / 1000;
    cout << mean_ << ' ' << dispersion << endl;

    return 0;
}

double mean(vector<int> data, bool squared)
{
    long sum = 0;
    for (int val : data)
    {
        if (squared)
        {
            sum += val * val;
        }
        else
        {
            sum += val;
        }
    }

    return ((double)sum) / ((double)data.size());
}
