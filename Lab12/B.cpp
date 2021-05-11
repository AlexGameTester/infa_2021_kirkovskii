#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int *safe_ends_a = new int[N];
    int *safe_ends_b = new int[N];
    int *safe_ends_c = new int[N];
    safe_ends_a[0] = 1;
    safe_ends_b[0] = 1;
    safe_ends_c[0] = 1;

    for (int i = 1; i < N; i++)
    {
        safe_ends_a[i] = safe_ends_b[i - 1] + safe_ends_c[i - 1];
        safe_ends_b[i] = safe_ends_a[i - 1] + safe_ends_b[i - 1] + safe_ends_c[i - 1];
        safe_ends_c[i] = safe_ends_a[i - 1] + safe_ends_b[i - 1] + safe_ends_c[i - 1];
    }

    int res = safe_ends_a[N - 1] + safe_ends_b[N - 1] + safe_ends_c[N - 1];
    cout << res << endl;

    return 0;
}