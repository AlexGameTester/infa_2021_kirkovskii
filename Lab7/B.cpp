#include <iostream>
using namespace std;

bool check_number(int number);

int main()
{
    int N;
    bool cout_zero = true;
    cin >> N;
    int *numbers = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    for (int i = 0; i < N; i++)
    {
        if (!check_number(numbers[i]))
        {
            cout_zero = false;
        }
    }

    if (cout_zero)
    {
        cout << 0 << endl;
    }
}

bool check_number(int number)
{
    if ((number % 4 == 0) && (number / 1000 != 4) && (number / 1000 != 5))
    {
        cout << number << endl;
        return false;
    }
    if ((number % 7 == 0) && (number / 1000 != 7) && (number / 1000 != 1))
    {
        cout << number << endl;
        return false;
    }
    if ((number % 9 == 0) && (number / 1000 != 9) && (number / 1000 != 8))
    {
        cout << number << endl;
        return false;
    }
    return true;
}