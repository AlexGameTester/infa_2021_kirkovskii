#include <iostream>
using namespace std;

int main()
{
    int n;
    int sum = 0;
    double average = 0;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        average += (double)arr[i] / n;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > average)
        {
            sum += arr[i];
        }
    }

    cout << sum << endl;

    delete[] arr;
}