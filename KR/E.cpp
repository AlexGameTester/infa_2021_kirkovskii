#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    double M = 0;
    double F = 0;
    for (int i = 1; i <= N; i++)
    {
        M = 0.3 * (100 + 2 * F) + 10;
        F = 0.7 * (100 + 2 * F);
    }
    cout << static_cast<int64_t>(M) << endl;
    return 0;
}