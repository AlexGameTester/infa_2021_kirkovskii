#include <iostream>
using namespace std;
struct Pair
{
    int f;
    int k;
};

Pair sp(Pair p1, Pair p2)
{
    Pair s;
    s.f = p1.f + p2.f;
    s.k = p1.k + p2.k;
    return s;
}

bool equal(Pair p1, Pair p2)
{
    return (p1.f == p2.f) && (p1.k == p2.k);
}

int main()
{
    int N;
    cin >> N;
    Pair *pairs = new Pair[N];
    for (int i = 0; i < N; i++)
    {
        int f, k;
        cin >> f >> k;
        pairs[i].f = f;
        pairs[i].k = k;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                Pair p1 = pairs[i];
                Pair p2 = pairs[j];
                Pair p3 = pairs[k];
                if (equal(p1, sp(p2, p3)) || equal(p2, sp(p1, p3)) || equal(p3, sp(p1, p2)))
                {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "NO" << endl;

    delete[] pairs;
    return 0;
}