#include <iostream>

using namespace std;

int main()
{
    unsigned long long N, K;
    cin >> N >> K;
    unsigned long long *counts = new unsigned long long[N];
    counts[0] = K - 1;
    counts[1] = K * (K - 1);
    for (int i = 2; i < N; i++)
    {
        counts[i] = (K - 1) * (counts[i - 1] + counts[i - 2]);
    }
    cout << counts[N - 1] << endl;

    return 0;
}