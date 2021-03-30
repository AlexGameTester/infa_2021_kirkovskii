#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int *arr = new int[N * N];
    for (int i = 0; i < N * N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            cout << arr[i + j * N] << ' ';
        }
        cout << endl;
    }

    delete[] arr;
    return 0;
}