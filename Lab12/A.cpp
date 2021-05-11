#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int *safe_ends_aa = new int[N];
    int *safe_ends_ab = new int[N];
    int *safe_ends_ba = new int[N];
    int *safe_ends_bb = new int[N];
    safe_ends_aa[1] = 1;
    safe_ends_aa[0] = 0;
    safe_ends_ab[1] = 1;
    safe_ends_ab[0] = 0;
    safe_ends_ba[1] = 1;
    safe_ends_ba[0] = 0;
    safe_ends_bb[1] = 1;
    safe_ends_bb[0] = 0;
    for (int i = 2; i < N; i++)
    {
        safe_ends_aa[i] = safe_ends_ba[i - 1];
        safe_ends_ab[i] = safe_ends_ba[i - 1] + safe_ends_aa[i - 1];
        safe_ends_bb[i] = safe_ends_bb[i - 1] + safe_ends_ab[i - 1];
        safe_ends_ba[i] = safe_ends_bb[i - 1] + safe_ends_ab[i - 1];
    }
    if (N == 1)
    {
        cout << 2;
    }
    else
    {
        int sum = safe_ends_aa[N - 1] + safe_ends_ab[N - 1] + safe_ends_ba[N - 1] + safe_ends_bb[N - 1];
        cout << sum << endl;
    }

    return 0;
}