#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int *data = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> data[i];
    }
    for (int i = N - 1; i > 0; i--)
    {
        cout << data[i] << ' ';
    }
    cout << data[0] << endl;

    delete[] data;
    return 0;
}