#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int *amounts = new int[N];
    int *min_amounts = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> amounts[i];
    }
    min_amounts[0] = amounts[0];
    min_amounts[1] = amounts[1];
    for (int i = 2; i < N; i++)
    {
        min_amounts[i] = amounts[i] + min(min_amounts[i - 1], min_amounts[i - 2]);
    }
    cout << min_amounts[N - 1] << endl;
    int i = N - 1;
    vector<int> indeces;
    indeces.reserve(N / 2);
    while (i >= 0)
    {
        indeces.push_back(i);
        int m = min_amounts[i] - amounts[i];
        if (i < 1)
        {
            break;
        }
        if (m == min_amounts[i - 1])
        {
            i -= 1;
        }
        else
        {
            i -= 2;
        }
    }
    reverse(indeces.begin(), indeces.end());
    for (int i = 0; i < indeces.size(); i++)
    {
        cout << indeces[i] << ' ';
    }
    cout << endl;

    delete[] amounts;
    delete[] min_amounts;
    return 0;
}