#include <iostream>
using namespace std;

main()
{
    int num;
    cin >> num;
    int t = 0;
    int t_1 = 0;
    int t_2 = 1;
    int n = 2;
    while (t_2 <= num)
    {
        int val = t + t_1 + t_2;
        t = t_1;
        t_1 = t_2;
        t_2 = val;
        n++;
    }
    cout << n << endl;

    return 0;
}