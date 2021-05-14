#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;
    unsigned long mod = (unsigned long)pow(2, 31) - 1;
    unsigned long *ends_s = new unsigned long[N];
    unsigned long *ends_u = new unsigned long[N];
    unsigned long *ends_d = new unsigned long[N];
    ends_s[0] = 1;
    ends_d[0] = 1;
    ends_u[0] = 1;
    for (int i = 1; i < N; i++)
    {
        ends_s[i] = (ends_s[i - 1] + ends_u[i - 1] + ends_d[i - 1]) % mod;
        ends_d[i] = (ends_s[i - 1] + ends_u[i - 1]) % mod;
        ends_u[i] = (ends_s[i - 1] + ends_d[i - 1]) % mod;
    }
    unsigned long sum = (ends_s[N - 1] + ends_d[N - 1] + ends_u[N - 1]) % mod;
    cout << sum << endl;

    delete[] ends_s;
    delete[] ends_u;
    delete[] ends_d;
    return 0;
}