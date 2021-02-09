#include <iostream>
using namespace std;

int main()
{
    int place_power = 60;
    int n;
    cin >> n;

    string s = "";
    while (true)
    {
        int r = n % place_power;
        r /= place_power / 60;
        int n_1 = r % 10;
        int n_10 = r / 10;
        for (int i = 0; i < n_1; i++)
        {
            s += "v";
        }
        for (int i = 0; i < n_10; i++)
        {
            s += "<";
        }

        n -= r * (place_power / 60);
        if (n > 0)
        {
            s += ".";
            place_power *= 60;
        }
        else
        {
            break;
        }
    }
    for (int i = s.length() - 1; i >= 0; i--)
    {
        cout << s[i];
    }

    return 0;
}