#include <iostream>
using namespace std;

int main()
{
    string boss_number = "A999AA";
    int wage = 0;
    int speed;
    string number;
    while (true)
    {
        cin >> speed >> number;

        if (number == boss_number)
            break;

        if (speed <= 60)
            continue;
        if (number[1] == number[2] && number[1] == number[3])
        {
            wage += 1000;
        }
        else if (number[1] == number[2] || number[1] == number[3] || number[2] == number[3])
        {
            wage += 500;
        }
        else
        {
            wage += 100;
        }
    }

    cout << wage;

    return 0;
}